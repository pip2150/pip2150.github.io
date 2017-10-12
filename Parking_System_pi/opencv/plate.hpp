#ifndef PLATE_HPP_
#define PLATE_HPP_

#include <opencv2/opencv.hpp>

/**
	@brief ��ȣ��
	��ȣ�� �̹����� ����� ��ġ�� ������ Ŭ����
*/
class Plate {
private:

	bool debug;		//!< @brief debug ����

	/** 
		@brief ��ħ �˻�
		@param A ��ħ �˻縦 �� �簢��1
		@param B ��ħ �˻縦 �� �簢��2
		@return A�� B�� ��ġ���� ���θ� ���. ��ġ�� true �׷��� ������ false
	*/
	bool isOverlap(const cv::Rect &A, const cv::Rect &B);

	/** 
		@brief �ٻ� �ּҿ��� �簢��
		@param contour �ٻ� �ּҿ��� �簢���� ���ϱ� ���� ���� Contour
		@return �ٻ�ȭ ���� Contour ���� �����ϴ� �ּ� ������ �簢��
	*/
	static cv::RotatedRect minApproxRect(const std::vector<cv::Point> &contour);

	/** 
		@brief ũ�� �˻�
		@param mr ũ�� �˻縦 �� RotatedRect
		@return ������ ũ���� ��� true �׷��� ������ false
	*/
	static bool verifySizes(const cv::RotatedRect &mr);

public:

	/** 
		@brief �ؽ�Ʈ
		��ȣ���� �����ϴ� �ؽ�Ʈ�� �� �ϳ�
	*/
	class Text {
	public:

		cv::Mat img;		//!< @brief �ؽ�Ʈ�� ��Ÿ���� �̹���

		/** 
			@brief Text�� �̹��� �ʱ�ȭ
			@param src �ʱ�ȭ �� �̹���
		*/
		Text(const cv::Mat &src);

		/** 
			@brief img�� ����ȭ�� �̹��� ���
			@param sampleSize ����ȭ�ϱ� ���� ���� ������ ũ��
			@return ����ȭ�� �̹���
		*/
		cv::Mat canonical(int sampleSize);
	};

	cv::Mat img;					//!< @brief Plate�� ��Ÿ���� ��Ʈ����
	cv::Point position;				//!< @brief ���� �̹����� ���� ������� Plate�� ��ġ
	std::vector<Text> texts;		//!< @brief Plate�� ���Ե� Texts

	/** 
		@brief Plate �ʱ�ȭ		
		@param img Plate�� ��Ÿ���� ��Ʈ����
		@param position ���� �̹����� ���� ������� Plate�� ��ġ
		���� �̹����� Plate::find �� �Ű����� input�̴�. @see find
	*/
	Plate(const cv::Mat &img, const cv::Point &position);

	/** 
		@brief debug ��� ����
		@param debug ���̸� true �׷��� ������ false
		�߰� ó�� ������ â���� ����� ���θ� ���Ѵ�.
	*/
	void setDebug(bool debug);

	/** 
		@brief Plate���� Text �̹��� ����
		@param textSize Plate�� �����ϴ� Text ���� ������ ����
		@return Plate���� ������ Text�� ������ textSize�� ���� �� true �׷��� ������ false
	*/
	bool findTexts(const int textSize);

	/** 
		@brief �Է¹��� �̹����� ���� Plate ����
		@param input Plate�� ã�� ���� �̹���
		@param PossiblePlates ���� �̹����� ���� ã�� Plate
	*/
	static void find(const cv::Mat &input, std::vector<Plate> *PossiblePlates);

	/** 
		@brief �Է¹��� �̹����� RotatedRect �׸���
		@param img �Է¹��� RotatedRect�� �׸��� �̹���
		@param roRec �׷����ϴ� RotatedRect
		@param color �׸��� RotatedRect�� ��
		@param thickness �׸��� RotatedRect�� �β�
	*/
	static void drawRotatedRect(const cv::Mat &img, const cv::RotatedRect &roRec, const cv::Scalar color, int thickness = 1);

	/** 
		@brief img�� ����ȭ�� �̹��� ���
		@return ����ȭ�� �̹���
	*/
	cv::Mat canonical();

};

#endif
