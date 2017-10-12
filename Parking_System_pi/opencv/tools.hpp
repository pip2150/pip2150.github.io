#ifndef TOOLS_HPP_
#define TOOLS_HPP_

#include <opencv2/opencv.hpp>

/**
	@brief tools
	���� ó�� �� ������ tool ����
*/
namespace tools {
	
	/**
		@brief File System���� ���� �̹��� �ҷ�����
		@param fn �̹��� ���� ���
		@param image File System���� �ҷ��� �̹����� ������ ����
		@param flags cv::ImreadModes �� ���� ����
		@return ���� �� true �׷��� ������ false
	*/
	bool readImage(const std::string fn, cv::Mat& image, int flags = 1);

	/**
		@brief File System���� Image�� ����
		@param fn �̹��� ���� ���
		@param image File System�� �� �̹��� ����
		@return ���� �� true �׷��� ������ false
	*/
	bool writeImage(const std::string fn, const cv::Mat& image);

	/**
		@brief �ʱ⿡ �Էµ� ���ڿ��� ���Ͽ� tools::Dicider::LEASTMATCH �� �Ѿ��� ��� ����� �����Ѵ�.
	*/
	class Dicider {
	private:
		
		std::string keyStr;		//!< @brief �ʱ� ���ڿ�
		int match;				//!< @brief ��ġ�� Ƚ��

	public:

		static const int LEASTMATCH = 5;		//!< @brief �ּ����� ��ġ Ƚ��

		/**
			@brief Dicider �ʱ�ȭ
			���� ���ڿ��� �����Ѵ�.
		*/
		Dicider();

		/**
			@brief �������� ���� Ƚ������ ���� ���ڿ��� �Է¹����� ���� ����� ���
			@param str �� ���ڿ�
			@return  str�� �ʱ� ���ڿ��� LEASTMATCH �� Ƚ�� �̻� ��ġ�� ��� true �׷��� ������ false �� ��ȯ
		*/
		bool decide(std::string str);
	};

	/**
		@brief ��� �м� ��� ��� Ŭ����
		�Էµ� �ʱ� ���� ���ڿ��� �������κ��� ����� ���ڿ��� ����� �񱳵� ����� ����Ѵ�.
	*/
	class Analyzer {
	private:

		int totalCorrect;		//!< @brief �� ���� Ƚ��
		int totalTry;			//!< @brief �� �õ��� Ƚ��
		std::string answer;		//!< @brief ���� ����

	public:

		/**
			@brief Analyzer �ʱ�ȭ
			@param answer ������ ����
		*/
		Analyzer(const std::string answer);

		/**
			@brief �Է¹��� ���ڿ��� ����� ���ϸ� ����� ��� ����� ���
			@param str ����� ���� ���ڿ�
		*/
		void analyze(const std::string str);
	};

};

#endif
