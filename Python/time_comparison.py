import numpy as np
import time

from single_threaded import single_threaded
from multi_threaded import multi_threaded


def time_comparison(img: np.ndarray) -> None:
    start_time = time.time()
    single_threaded(img)
    end_time = time.time()
    print(f"Sequential: {end_time - start_time:.5f}s")

    start_time = time.time()
    multi_threaded(img)
    end_time = time.time()
    print(f"Multithreaded: {end_time - start_time:.5f}s")
