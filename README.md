# Concurrent Image Color Changer

Aimed at demonstrating the application of concurrency in performing image color transformations. By implementing this project in Java, C++, Go, and Python, it showcases the unique concurrency models of each language and their effectiveness in processing large image files.
<br>
<br>
The project not only provides insights into parallel computing across different programming environments but also offers a practical tool for image processing tasks.

<br>

## Table of Contents

1. [Features](#features)
1. [Technical Scope](#technical-scope)
1. [Installation and Usage](#installation-and-usage)
1. [Contributing](#contributing)
1. [License](#license)

<br>

## Features

- Support for basic color transformation.
- Concurrent processing of image segments to speed up transformations.
- Performance metrics to compare concurrent vs serial processing times across languages.
- Multi-language support to highlight different approaches to concurrency.

<br>

## Technical Scope

- **Java**: Utilization of ForkJoinPool for parallel processing of image segments.
- **C++**: Employment of std::thread and std::async for concurrent image processing tasks.
- **Go**: Implementation with goroutines and channels for efficient parallel processing.
- **Python**: Use of concurrent.futures and multiprocessing for threading and process-based parallelism.

<br>

## Installation and Usage

1. **Clone the Repository**:
    ```bash
    git clone https://github.com/siddhant-vij/Concurrent-Image-Color-Changer.git
    ```
2. **Navigate to Language Directory**:
    ```bash
    cd Concurrent-Image-Color-Changer/[language]
    ```
3. **Install Dependencies**: Standard instructions to be followed for each language, if any external dependency.
4. **Build and Run the Application**: Standard instructions to be followed for each language.

<br>

## Contributing

Contributions are what make the open-source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

1. **Fork the Project**
2. **Create your Feature Branch**: 
    ```bash
    git checkout -b feature/AmazingFeature
    ```
3. **Commit your Changes**: 
    ```bash
    git commit -m 'Add some AmazingFeature'
    ```
4. **Push to the Branch**: 
    ```bash
    git push origin feature/AmazingFeature
    ```
5. **Open a Pull Request**

<br>

## License

Distributed under the MIT License. See [`LICENSE`](https://github.com/siddhant-vij/Concurrent-Image-Color-Changer/blob/main/LICENSE) for more information.
