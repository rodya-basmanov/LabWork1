/* ## LabWork1
## Author
Basmanov Rodion B81-mm
## Contacts
st135699@student.spbu.ru
## Description
LabWork1 */

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <functional>
#include <omp.h>
#include "image.h"
#include "turnimage.h"

double measureExecutionTime(std::function<void()> func) {
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    return elapsed.count();
}

void printUsage(const char* programName) {
    std::cout << "Usage: " << programName << " [options]" << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "  -t, --threads <num>   Set number of threads (default: max available)" << std::endl;
    std::cout << "  -s, --sequential      Run sequential version for comparison" << std::endl;
    std::cout << "  -p, --parallel        Run parallel version (default)" << std::endl;
    std::cout << "  -b, --both            Run both sequential and parallel versions for comparison" << std::endl;
    std::cout << "  -h, --help            Show this help message" << std::endl;
}

int main(int argc, char* argv[])
{
    int num_threads = omp_get_max_threads();
    bool run_sequential = false;
    bool run_parallel = true;
    
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        if (arg == "-t" || arg == "--threads") {
            if (i + 1 < argc) {
                num_threads = std::stoi(argv[++i]);
            } else {
                std::cerr << "Error: Thread count not specified" << std::endl;
                printUsage(argv[0]);
                return 1;
            }
        } else if (arg == "-s" || arg == "--sequential") {
            run_sequential = true;
            run_parallel = false;
        } else if (arg == "-p" || arg == "--parallel") {
            run_sequential = false;
            run_parallel = true;
        } else if (arg == "-b" || arg == "--both") {
            run_sequential = true;
            run_parallel = true;
        } else if (arg == "-h" || arg == "--help") {
            printUsage(argv[0]);
            return 0;
        }
    }
    
    omp_set_num_threads(num_threads);
    
    std::cout << "Enter path to image file, radius (int), and sigma (float) for Gaussian blur:" << std::endl;
    
    std::string path;
    std::getline(std::cin, path);
    
    int radius;
    float sigma;
    std::cin >> radius >> sigma;

    std::cout << "Running with " << num_threads << " threads" << std::endl;

    double total_parallel_time = 0.0;
    double total_sequential_time = 0.0;

    if (run_parallel) {
        std::cout << "\n--- Running parallel version ---" << std::endl;
        double rightTurnTime = measureExecutionTime([&]() {
            Turn_Image::RightTurn(path.c_str());
        });
        std::cout << "Right turn execution time: " << rightTurnTime << " ms" << std::endl;

        double leftTurnTime = measureExecutionTime([&]() {
            Turn_Image::LeftTurn(path.c_str());
        });
        std::cout << "Left turn execution time: " << leftTurnTime << " ms" << std::endl;

        Image leftImage(0, 0);
        leftImage.Read("Left_rotated_image.bmp");
        double leftBlurTime = measureExecutionTime([&]() {
            leftImage.ApplyGaussianBlur(radius, sigma);
        });
        std::cout << "Left image blur execution time: " << leftBlurTime << " ms" << std::endl;
        leftImage.Export("Blurred_Left_Rotated_Image.bmp");

        Image rightImage(0, 0);
        rightImage.Read("Right_rotated_image.bmp");
        double rightBlurTime = measureExecutionTime([&]() {
            rightImage.ApplyGaussianBlur(radius, sigma);
        });
        std::cout << "Right image blur execution time: " << rightBlurTime << " ms" << std::endl;
        rightImage.Export("Blurred_Right_Rotated_Image.bmp");

        total_parallel_time = rightTurnTime + leftTurnTime + leftBlurTime + rightBlurTime;
        std::cout << "Total parallel execution time: " << total_parallel_time << " ms" << std::endl;
    }

    if (run_sequential) {
        std::cout << "\n--- Running sequential version ---" << std::endl;
        
        double rightTurnTime = measureExecutionTime([&]() {
            Turn_Image::RightTurnSequential(path.c_str());
        });
        std::cout << "Right turn execution time: " << rightTurnTime << " ms" << std::endl;

        double leftTurnTime = measureExecutionTime([&]() {
            Turn_Image::LeftTurnSequential(path.c_str());
        });
        std::cout << "Left turn execution time: " << leftTurnTime << " ms" << std::endl;

        Image leftImage(0, 0);
        leftImage.Read("Left_rotated_image_sequential.bmp");
        double leftBlurTime = measureExecutionTime([&]() {
            leftImage.ApplyGaussianBlurSequential(radius, sigma);
        });
        std::cout << "Left image blur execution time: " << leftBlurTime << " ms" << std::endl;
        leftImage.Export("Blurred_Left_Rotated_Image_sequential.bmp");

        Image rightImage(0, 0);
        rightImage.Read("Right_rotated_image_sequential.bmp");
        double rightBlurTime = measureExecutionTime([&]() {
            rightImage.ApplyGaussianBlurSequential(radius, sigma);
        });
        std::cout << "Right image blur execution time: " << rightBlurTime << " ms" << std::endl;
        rightImage.Export("Blurred_Right_Rotated_Image_sequential.bmp");

        total_sequential_time = rightTurnTime + leftTurnTime + leftBlurTime + rightBlurTime;
        std::cout << "Total sequential execution time: " << total_sequential_time << " ms" << std::endl;
    }

    if (run_parallel && run_sequential) {
        double speedup = total_sequential_time / total_parallel_time;
        std::cout << "\n--- Performance comparison ---" << std::endl;
        std::cout << "Sequential execution time: " << total_sequential_time << " ms" << std::endl;
        std::cout << "Parallel execution time: " << total_parallel_time << " ms" << std::endl;
        std::cout << "Speedup: " << speedup << "x" << std::endl;
        std::cout << "Efficiency: " << (speedup / num_threads) * 100 << "%" << std::endl;
    }

    return 0;
}