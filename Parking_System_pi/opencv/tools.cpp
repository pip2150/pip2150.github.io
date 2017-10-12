#include "tools.hpp"
#include "ocr.hpp"

bool tools::readImage(const std::string fn, cv::Mat& image, int flags) {
	image = cv::imread(fn, flags);

	return image.empty();
}

bool tools::writeImage(const std::string fn, const cv::Mat &image) {
	return cv::imwrite(fn, image);
}

tools::Dicider::Dicider() {
	keyStr = "";
	match = -1;
}

bool tools::Dicider::decide(const std::string str) {
	match++;
	if (match == 0) {
		keyStr = str;
		return false;
	}
	else if (keyStr == str) {
		if (match == LEASTMATCH) {
			match = -1;
			return true;
		}
		else
			return false;
	}
	match = -1;
	return false;
}

tools::Analyzer::Analyzer(const std::string answer) {
	totalCorrect = 0;
	totalTry = 0;
	this->answer = answer;
}

void tools::Analyzer::analyze(const std::string str) {

	// TEXTSIZE���� �ؽ�Ʈ �� ��ġ�� Ƚ��
	int correct = 0;
	for (int j = 0; j < TEXTSIZE; j++)
		if (str[j] == answer[j])
			correct++;

	totalTry++;
	totalCorrect += correct;

	// �ϳ��� ��ȣ�ǿ��� ������ �ؽ�Ʈ�� ��������� ���� Ƚ��
	double average = (double)correct / TEXTSIZE;
	// ��� �õ����� ������ �ؽ�Ʈ�� ��������� ���� Ƚ��
	double totalAverage = (double)totalCorrect / (totalTry * TEXTSIZE);
	std::cout << "\t\tCorrect Answer Rate : " << average * 100 << "%";
	std::cout << "\tTotal Correct Answer Rate : " << totalAverage * 100 << "%" << std::endl;
}

