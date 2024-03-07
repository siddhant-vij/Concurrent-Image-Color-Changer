import numpy as np
from typing import Tuple


def recolor_image(
    original_image: np.ndarray,
    result_image: np.ndarray,
    left_corner: int,
    top_corner: int,
    width: int,
    height: int,
) -> None:
    for x in range(left_corner, left_corner + width):
        for y in range(top_corner, top_corner + height):
            recolor_pixel(original_image, result_image, x, y)


def recolor_pixel(
    original_image: np.ndarray,
    result_image: np.ndarray,
    x: int,
    y: int,
) -> None:
    red, green, blue = original_image[y, x]
    new_red, new_green, new_blue = handle_color(red, green, blue)
    result_image[y, x] = (new_red, new_green, new_blue)


def handle_color(red: int, green: int, blue: int) -> Tuple[int, int, int]:
    if is_shade_of_gray(red, green, blue):
        new_red = min(255, red + 10)
        new_green = max(0, green - 80)
        new_blue = max(0, blue - 20)
    else:
        new_red = red
        new_green = green
        new_blue = blue
    return new_red, new_green, new_blue


def is_shade_of_gray(red: int, green: int, blue: int, range: int = 30) -> bool:
    red, green, blue = int(red), int(green), int(blue)
    return abs(red - green) <= range and abs(red - blue) <= range
