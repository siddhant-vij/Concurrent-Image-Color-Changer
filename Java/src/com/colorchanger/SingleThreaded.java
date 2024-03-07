package com.colorchanger;

import org.opencv.core.Mat;
import org.opencv.imgcodecs.Imgcodecs;

public class SingleThreaded {
  private static final String OUTPUT_IMAGE = "result_image/single-threaded.jpg";

  public static void singleThreaded(Mat img) {
    int width = img.width();
    int height = img.height();
    ImageProcessing.recolorImage(img, img, 0, 0, width, height);
    Imgcodecs.imwrite(OUTPUT_IMAGE, img);
  }
}
