// image_processing.cpp

#include <algorithm>

#include "image_processing.hpp"

namespace color_changer
{

  void recolorImage(cv::Mat &originalImage, cv::Mat &resultImage, int leftCorner, int topCorner, int width, int height)
  {
    for (int x = leftCorner; x < leftCorner + width; ++x)
    {
      for (int y = topCorner; y < topCorner + height; ++y)
      {
        recolorPixel(originalImage, resultImage, x, y);
      }
    }
  }

  void recolorPixel(cv::Mat &originalImage, cv::Mat &resultImage, int x, int y)
  {
    cv::Vec3b pixelValues = originalImage.at<cv::Vec3b>(y, x);
    auto [red, green, blue] = std::tie(pixelValues[0], pixelValues[1], pixelValues[2]);

    auto newPixelValues = handleColor(red, green, blue);

    resultImage.at<cv::Vec3b>(y, x) = cv::Vec3b(static_cast<uchar>(newPixelValues[0]), static_cast<uchar>(newPixelValues[1]), static_cast<uchar>(newPixelValues[2]));
  }

  std::vector<double> handleColor(double red, double green, double blue)
  {
    if (isShadeOfGray(red, green, blue, 30))
    {
      double newRed = std::min(255.0, red + 10);
      double newGreen = std::max(0.0, green - 80);
      double newBlue = std::max(0.0, blue - 20);
      return {newRed, newGreen, newBlue};
    }
    else
    {
      return {red, green, blue};
    }
  }

  bool isShadeOfGray(double red, double green, double blue, double range)
  {
    return std::abs(red - green) <= range && std::abs(red - blue) <= range;
  }

} // namespace color_changer
