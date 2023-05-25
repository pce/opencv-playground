#include <iostream>
#include <thread>
#include <vector>
#include <iostream>
#include <filesystem>

#include <opencv2/opencv.hpp> // Basic OpenCV

using namespace std;
// using namespace cv;

namespace fs = std::filesystem;

int main()
{
    vector<string> imageNames = {
        "data/paris.jpg",
        "data/paris-quantized.jpg",
    };
    // create a CompuServe Graphics Interchange Format 
    string outputGifFilename = "output.gif";
    string outputMovFilename = "output.mp4";
    // Video codec
    string fourcc = "MJPG"; // MJPG, XVID, H264
    int fps = 10;           // Frames per second
    int IMG_INPUT_INDEX = 0;
    string inputImageName = imageNames[IMG_INPUT_INDEX];
    // read the image
    cv::Mat image = cv::imread(inputImageName);
    cv::Size targetSize = cv::Size(image.cols, image.rows);
    // Convert the image to the desired color space for quantization (e.g., RGB to grayscale):
    cv::Mat grayImage;
    cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);

    int numLevels = 4; // quantization levels
    int range = 256 / numLevels;

    // Quantize the image
    cv::Mat quantizedImage;
    cv::divide(grayImage, range, quantizedImage);
    cv::multiply(quantizedImage, range, quantizedImage);
    // save the quantized image
    string outputFilePath = "data/paris-quantized.jpg";
    cv::imwrite(outputFilePath, quantizedImage);

    // VideoWriter object to write video
    cv::VideoWriter videoWriter(outputMovFilename, cv::VideoWriter::fourcc(fourcc[0], fourcc[1], fourcc[2], fourcc[3]), fps, cv::Size(targetSize.width, targetSize.height));

    // Iterate over the sequence of images and write them to the video file
    for (const auto& imageName : imageNames)
    {
        cv::Mat image = cv::imread(imageName);
        videoWriter.write(image);
    }
    videoWriter.release();

    string command = "ffmpeg -i " + outputMovFilename + " "  + outputGifFilename;
    int result = system(command.c_str());

    if (result == 0)
    {
        cout << "create gif over a system call" << endl;
    }
    else
    {
        cerr << "file not written" << endl;
        // try string command = "convert -delay 100 -loop 0 image*.jpg output.gif";
    }

    // cv::imshow("Quantized Image", quantizedImage);
    // cv::waitKey(0);

    return 0;
}
