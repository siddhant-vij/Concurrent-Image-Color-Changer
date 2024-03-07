import cv2
import numpy as np
from typing import Final

from imageproc_utils import recolor_image


OUTPUT_IMAGE: Final[str] = 'result_image/single-threaded.jpg'


def single_threaded(img: np.ndarray) -> None:
    Width: Final[int] = img.shape[1]
    Height: Final[int] = img.shape[0]
    recolor_image(img, img, 0, 0, Width, Height)

    cv2.imwrite(OUTPUT_IMAGE, img)
