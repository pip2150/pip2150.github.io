#ifndef OCR_HPP_
#define OCR_HPP_

#include <opencv2/opencv.hpp>


#define SAMPLESIZE 20		//!< �Ʒ� �������� ����, ������ �ȼ� ũ��
#define NLAYERS 30			//!< OCR�� ���� ��
#define TEXTSIZE 7			//!< ��ȣ���� ���� ��

//! OCR�� �ν��� ����
enum FORMAT {
	CHARACTER = 13,		//!< OCR�� ������ ����
	NUMBER = 10			//!< OCR�� ������ ����
};

/** 
	@brief Artificial Neural Networks�� �ٷ�� ���� Ŭ����
*/
class OCR {
private:

	//! Histogram ���� ���� ����
	enum ORIENTATION {
		VERTICAL = 0,		//!< ����
		HORIZONTAL = 1		//!< ����
	};

	cv::Ptr<cv::ml::ANN_MLP> ann;		//!< @brief Artificial Neural Networks
	cv::Mat classes;					//!< @brief trainingData�� ������ ��µ� vector��
	cv::Mat trainingData;				//!< @brief �Ʒ��� ���� Sample��
	std::string strCharacters = "0123456789BCDEFGNSTVWXY";		//!< @brief classes�� �����Ǵ� ���ڿ�

	/** 
		@brief TrainNumber���� �Ʒ� ������ �ҷ�����
		'TrainNumber'�� ��ο��� ��� �̹��� ������ �о�鿩 �Ʒ� �����͸� �����Ѵ�.
	*/
	void collectTrainImages();

	/** 
		@brief �Ʒ� �����͸� File System�� Json ���Ϸ� ����
		@param fn josn ������ ���
	*/
	void writeTraindata(const std::string fn);

	/** 
		@overload
		@brief �Ʒ� �����͸� File System���� Json ���Ϸκ��� �ҷ�����
		@param fn Josn ������ ���
	*/
	void readTraindata(const std::string fn);

	/**
		@overload
		@brief �Ʒ� �����͸� File System���� Json ���Ϸκ��� �ҷ�����
		@param fn Josn ������ ���
		@param format Json OCR�� �ν��� ����
	*/
	void readTraindata(const std::string fn, const FORMAT format);

	/** 
		@brief Histogram ����
		@param img Histogram�� ������ �̹���		
		@param t Histogram ���� ���� ����
		@return ����� Histogram�� ��Ʈ����
	*/
	static cv::Mat getHistogram(const cv::Mat &img, const ORIENTATION t);

public:

	//! �Ʒ� �����͸� �ٷ� ��� 
	enum MODE {
		READDT = 0b00,		//!< Json File���� �б� @see readTraindata
		COLLECT = 0b01,		//!< TrainImage���� �б� @see collectTrainImages
		WRITEDT = 0b11		//!< Json File�� ���� @see writeTraindata
	};

	int numCharacters;		//!< @brief ��µ� vector�� ũ��

	/** 
		@brief OCR �ʱ�ȭ
		@param format OCR�� �ν��� ����
		@param mode �Ʒ� �����͸� �ٷ� ���
	*/
	OCR(const FORMAT format, const int mode);

	/** 
		@brief �Էµ� Sample�� �Ʒõ� Artificial Neural Networks���� ������ ����� ���
		@param img �Է��� Sample
		@param out ������ ����� ��Ʈ����
		@return OCR�� ���� ������ ���
	*/
	float predict(const cv::Mat &img, cv::Mat *out);

	/** 
		@brief ������ ��� �� ���� ���ɼ��� ���� ���ڸ� ����
		@param output ���ڸ� ������ ��� ��Ʈ����
		@return ���ɼ� ���� ����
	*/
	char classify(cv::Mat *output);

	/** 
		@brief features ����
		@param texts features�� ������ �̹���
		@param sizeData ����� features�� ���� ���� ũ��
		@return �Է¹��� �̹����� ���� features
	*/
	static cv::Mat features(const cv::Mat &texts, const int sizeData);
};

/** 
	@brief OCR::collectTrainImages ���� �� �ʿ��� image�� �����ϴ� Ŭ����
*/
class OCRTrainer {
private:

	int fileIndexs[NUMBER + CHARACTER];		//!< @brief File �˻��� ���� Index ����
	std::string answer;						//!< @brief �����н��� ���� ����

public:

	/**
		@brief OCRTrainer �ʱ�ȭ
		@param answer ���� �н��� ���� ����
	*/
	OCRTrainer(const std::string answer);

	/**
		@brief OCR Ŭ�������� ������ �̹����� File System�� ����
		�Է¹��� �̹����� 'TrainImage'��ο� File System�� ����.
	*/
	void train(const std::vector<cv::Mat> &sample);
};

#endif