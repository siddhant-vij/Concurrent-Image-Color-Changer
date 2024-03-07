import cv2
import numpy as np
from typing import Final

from time_comparison import time_comparison


INPUT_IMAGE: Final[str] = 'input_image/many-flowers.jpg'


def load_image() -> np.ndarray:
    return cv2.imread(INPUT_IMAGE, cv2.IMREAD_UNCHANGED)


def run() -> None:
    img = load_image()
    time_comparison(img)


if __name__ == '__main__':
    run()

# Sequential: 64.27615s
# Multithreaded: 37.40261s
