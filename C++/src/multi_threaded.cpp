#include "multi_threaded.hpp"
#include "image_processing.hpp"
#include <opencv2/imgcodecs.hpp>
#include <thread>
#include <vector>

namespace multi_threaded
{

  void processImage(cv::Mat &img)
  {
    int numberOfThreads = std::thread::hardware_concurrency();
    std::vector<std::thread> threads;
    threads.reserve(numberOfThreads);

    int imgHeight = img.rows / numberOfThreads;
    int imgWidth = img.cols;

    for (int i = 0; i < numberOfThreads; ++i)
    {
      threads.emplace_back([&, i]()
                           { color_changer::recolorImage(img, img, 0, i * imgHeight, imgWidth, imgHeight); });
    }

    for (auto &thread : threads)
    {
      thread.join();
    }

    cv::imwrite("../../result_image/multi-threaded.jpg", img);
  }

} // namespace multi_threaded
