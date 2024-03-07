package com.colorchanger;

import org.opencv.core.Core;
import org.opencv.core.Mat;

import static org.opencv.imgcodecs.Imgcodecs.imread;
import static org.opencv.imgcodecs.Imgcodecs.IMREAD_UNCHANGED;

public class Main {
  private static final String INPUT_IMAGE = "input_image/many-flowers.jpg";

  public static void main(String[] args) {
    System.loadLibrary(Core.NATIVE_LIBRARY_NAME);
    Mat img = imread(INPUT_IMAGE, IMREAD_UNCHANGED);
    TimeComparison.timeComparison(img);
  }
}

// Sequential time:2106ms
// Concurrent time:562ms