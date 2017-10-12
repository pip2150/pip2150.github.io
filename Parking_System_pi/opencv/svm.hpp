#ifndef SVM_HPP_
#define SVM_HPP_

#include <opencv2/opencv.hpp>

/**
	@brief Support Vector Machines�� �ٷ�� ���� Ŭ����
*/

class Svm {
private:

	cv::Ptr<cv::ml::SVM> svm;		//!< @brief Support Vector Machines
	cv::Mat classes;				//!< @brief trainingData�� ������ ��µ� vectors
	cv::Mat trainingData;			//!< @brief �Ʒ��� ���� Samples

	/**
		@brief trainimage���� �Ʒ� ������ �ҷ�����
		'trainimage'�� ��ο��� ��� �̹��� ������ �о�鿩 �Ʒ� �����͸� �����Ѵ�.
	*/
	void collectTrainImages();

	/**
		@brief �Ʒ� �����͸� File System�� Json ���Ϸ� ����
		@param fn Josn ������ ���
	*/
	void writeTraindata(const std::string fn);

	/** 
		@brief �Ʒ� �����͸� File System���� Json ���Ϸκ��� �ҷ�����
		@param fn Josn ������ ���
	*/
	void readTraindata(const std::string fn);

public:

	//! �Ʒ� �����͸� �ٷ� ��� 
	enum MODE {
		READDT = 0b00,		//!< Json File���� �б� @see readTraindata
		COLLECT = 0b01,		//!< trainimage���� �б� @see collectTrainImages
		WRITEDT = 0b11		//!< Json File�� ���� @see writeTraindata
	};

	/**
		@brief Svm �ʱ�ȭ
		@param mode Svm ��� ���� @see MODE
	*/
	Svm(const int mode);

	/**
		@brief �Էµ� Sample�� �Ʒõ� Support Vector Machines���� ������ ����� ���
		@param img �Է��� Sample
		@return Svm�� ���� 0 ~ 1�� �з��� ���
	*/
	float predict(const cv::Mat &img);
};

/**
	@brief Svm::collectTrainImages ���� �� �ʿ��� image�� �����ϴ� Ŭ����
*/
class SVMTrainer {
private:

	int fileIndex;		//!< @brief File �˻��� ���� Index ����

public:

	/**
		@brief SVMTrainer �ʱ�ȭ
	*/
	SVMTrainer();

	/** 
		@brief Svm Ŭ�������� ������ �̹����� File System�� ����
		@param sample File System�� �� �̹���
		�Է¹��� �̹����� 'TrainImage'��ο� File System�� ����.
	*/
	void train(const cv::Mat &sample);
};

#endif