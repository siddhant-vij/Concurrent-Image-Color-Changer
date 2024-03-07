import cv2
import numpy as np
import threading
import multiprocessing
from typing import Final

from imageproc_utils import recolor_image

OUTPUT_IMAGE: Final[str] = 'result_image/multi-threaded.jpg'


def multi_threaded(img: np.ndarray) -> None:
    number_of_threads: Final[int] = multiprocessing.cpu_count()
    img_height: Final[int] = img.shape[0] // number_of_threads
    img_width: Final[int] = img.shape[1]

    threads: list[threading.Thread] = []
    for thread_number in range(number_of_threads):
        thread = threading.Thread(
            target=recolor_image,
            args=(
                img,
                img,
                0,
                thread_number * img_height,
                img_width,
                img_height,
            )
        )
        threads.append(thread)

    for thread in threads:
        thread.start()

    for thread in threads:
        thread.join()

    cv2.imwrite(OUTPUT_IMAGE, img)
