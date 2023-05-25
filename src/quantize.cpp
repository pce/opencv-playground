#include <iostream>
#include <thread>
#include <vector>
#include <iostream>
#include <filesystem>

#include <opencv2/opencv.hpp> // Basic OpenCV 

using namespace std;
using namespace cv;

namespace fs = std::filesystem;

int main()
{

    string inputImageName = "data/paris.jpg";

    // read the image
    cv::Mat image = cv::imread(inputImageName);

    Size targetSize = Size(image.cols, image.rows);
    

    // Convert the image to the desired color space for quantization (e.g., RGB to grayscale):
    cv::Mat grayImage;
    cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);

    int numLevels = 4; // quantization levels 
    int range = 256 / numLevels;

    // Quantize the image
    cv::Mat quantizedImage;
    cv::divide(grayImage, range, quantizedImage);
    cv::multiply(quantizedImage, range, quantizedImage);

    cv::imshow("Quantized Image", quantizedImage);
    cv::waitKey(0);

    return 0;
}
