// image_processing.hpp

#ifndef IMAGE_PROCESSING_HPP
#define IMAGE_PROCESSING_HPP

#include <opencv2/opencv.hpp>

namespace color_changer
{
  void recolorImage(cv::Mat &originalImage, cv::Mat &resultImage, int leftCorner, int topCorner, int width, int height);
  void recolorPixel(cv::Mat &originalImage, cv::Mat &resultImage, int x, int y);
  std::vector<double> handleColor(double red, double green, double blue);
  bool isShadeOfGray(double red, double green, double blue, double range);
}

#endif // IMAGE_PROCESSING_HPP
