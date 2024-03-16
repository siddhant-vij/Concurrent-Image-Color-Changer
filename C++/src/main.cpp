#include <iostream>

#include <opencv2/opencv.hpp>
#include "time_comparison.hpp"

int main()
{
  std::string inputImage = "../../input_image/many-flowers.jpg";
  // Relative to .exe file

  cv::Mat im = cv::imread(inputImage,
                          cv::ImreadModes::IMREAD_UNCHANGED);
  if (im.empty())
  {
    std::cout << "Cannot open image!" << std::endl;
    return -1;
  }

  time_comparison::compareExecutionTimes(im);

  return 0;
}

// Sequential time : 13888ms
// Concurrent time : 16876ms

// Tried with MSYS2 (msys64/ucrt64)
//  - Configure & Build successful but dynamic linking of DLLs (present in uctr64/bin/) fails:
//    - Circular dependency with g++ & clang++
//        (dependency walker)
//    - linker error with MSVC

// Tried with vcpkg
//    - Build error with opencv4::x64-windows

// Working with MSVC & pre-built opencv binary (from website) on Windows Machine
//    - This is failing with g++ & clang++