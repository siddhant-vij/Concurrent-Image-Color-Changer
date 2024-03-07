package com.colorchanger;

import org.opencv.core.Mat;

public class TimeComparison {
  public static void timeComparison(Mat img) {
    long startTime = System.currentTimeMillis();
    SingleThreaded.singleThreaded(img);
    long endTime = System.currentTimeMillis();
    System.out.println("Sequential time: " + (endTime - startTime) + "ms");

    startTime = System.currentTimeMillis();
    MultiThreaded.multiThreaded(img);
    endTime = System.currentTimeMillis();
    System.out.println("Concurrent time: " + (endTime - startTime) + "ms");
  }
}
