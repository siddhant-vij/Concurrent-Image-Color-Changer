package com.colorchanger;

import org.opencv.core.Mat;
import org.opencv.imgcodecs.Imgcodecs;

import java.util.ArrayList;
import java.util.List;

public class MultiThreaded {
  private static final String OUTPUT_IMAGE = "result_image/multi-threaded.jpg";

  public static void multiThreaded(Mat img) {
    int numberOfThreads = Runtime.getRuntime().availableProcessors();
    int imgHeight = img.height() / numberOfThreads;
    int imgWidth = img.width();

    List<Thread> threads = new ArrayList<>();
    for (int num = 0; num < numberOfThreads; num++) {
      final int threadNumber = num;
      Thread thread = new Thread(() -> ImageProcessing
          .recolorImage(
              img,
              img,
              0,
              threadNumber * imgHeight,
              imgWidth,
              imgHeight));
      threads.add(thread);
    }
    for (Thread thread : threads) {
      thread.start();
    }
    for (Thread thread : threads) {
      try {
        thread.join();
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
    }
    Imgcodecs.imwrite(OUTPUT_IMAGE, img);
  }
}