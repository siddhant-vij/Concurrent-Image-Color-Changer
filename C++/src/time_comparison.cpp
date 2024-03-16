#include "time_comparison.hpp"
#include "single_threaded.hpp"
#include "multi_threaded.hpp"
#include <chrono>
#include <iostream>

namespace time_comparison
{

  void compareExecutionTimes(cv::Mat &img)
  {
    using namespace std::chrono;

    auto startTime = high_resolution_clock::now();
    single_threaded::processImage(img);
    auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(endTime - startTime).count();
    std::cout << "Sequential time: " << duration << "ms\n";

    startTime = high_resolution_clock::now();
    multi_threaded::processImage(img);
    endTime = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(endTime - startTime).count();
    std::cout << "Concurrent time: " << duration << "ms\n";
  }

} // namespace time_comparison
