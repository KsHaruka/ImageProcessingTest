#include <iostream>	//
#include <memory>	// ユニークポインタ用
#include <cmath>	// 計算用
#include <Windows.h>
#include <chrono>	//時間計測
#include <opencv2/opencv.hpp> // OpenCV 


// Opencvで画像処理を学ぶ
// 目的:画像処理の基本的な処理・アクセスに関して勉強する.
// 関数なんて使えばなんとでも、ただ別途用途では使えない.

//  using namespace cv;　と書くとcv:: を書かなくてもopencvの命令使える.
//	個人的には cv::とか書いていた方が、使っている名前空間が理解できてスマートだと思う.

void main() {

	cv::Mat src = cv::imread("lena0.bmp");
	if (!src.data) {
		std::cout << "no image." << std::endl;
		Sleep(4000);
		return;
	}
	cv::Mat dst = cv::Mat::zeros(src.rows, src.cols, src.type());		//rows , cols の順

	auto start = std::chrono::system_clock::now();		//時間計測はじめ, 型推論 auto型

		//---メイン処理

	src.copyTo(dst);	//	データのコピー
	

		//---メイン処理終了
	auto end = std::chrono::system_clock::now();		//時間計測終わり(読み込み・保存・表示は含めない)

														// 経過時間をミリ秒単位で表示
	auto diff = end - start;
	std::cout << "elapsed time = " << std::chrono::duration_cast<std::chrono::milliseconds>(diff).count() << " msec." << std::endl;

	cv::imwrite("dst.bmp", dst);
	Sleep(4000);
	return;
}