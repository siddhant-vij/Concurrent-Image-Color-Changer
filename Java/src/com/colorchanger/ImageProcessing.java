package com.colorchanger;

import org.opencv.core.Mat;

public class ImageProcessing {
  public static void recolorImage(
      Mat originalImage,
      Mat resultImage,
      int leftCorner,
      int topCorner,
      int width,
      int height) {
    for (int x = leftCorner; x < leftCorner + width; x++) {
      for (int y = topCorner; y < topCorner + height; y++) {
        recolorPixel(originalImage, resultImage, x, y);
      }
    }
  }

  public static void recolorPixel(
      Mat originalImage,
      Mat resultImage,
      int x,
      int y) {
    double[] pixelValues = originalImage.get(y, x);
    double red = pixelValues[0];
    double green = pixelValues[1];
    double blue = pixelValues[2];

    double[] newPixelValues = handleColor(red, green, blue);

    resultImage.put(y, x, newPixelValues);
  }

  public static double[] handleColor(
      double red,
      double green,
      double blue) {
    if (isShadeOfGray(red, green, blue, 30)) {
      double newRed = Math.min(255, red + 10);
      double newGreen = Math.max(0, green - 80);
      double newBlue = Math.max(0, blue - 20);
      return new double[] { newRed, newGreen, newBlue };
    } else {
      return new double[] { red, green, blue };
    }
  }

  public static boolean isShadeOfGray(
      double red,
      double green,
      double blue,
      double range) {
    return Math.abs(red - green) <= range && Math.abs(red - blue) <= range;
  }
}
