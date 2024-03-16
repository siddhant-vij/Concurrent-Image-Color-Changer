#include "single_threaded.hpp"
#include "image_processing.hpp"
#include <opencv2/imgcodecs.hpp>

namespace single_threaded
{

  void processImage(cv::Mat &img)
  {
    color_changer::recolorImage(img, img, 0, 0, img.cols, img.rows);
    cv::imwrite("../../result_image/single-threaded.jpg", img);
  }

} // namespace single_threaded
