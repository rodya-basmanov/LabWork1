# Parallel Image Processing Documentation

## Overview

This project implements parallel image processing operations using OpenMP. The main focus is on comparing the performance of sequential and parallel implementations of common image manipulation tasks.

## Project Structure

- **include/** - Header files
- **src/** - Source files
- **tests/** - Unit tests
- **docs/** - Documentation
- **build/** - Build artifacts (created during compilation)

## Components

### Image Class

The core class for image representation and manipulation.

**Key methods:**
- `Read(const char* path)` - Load an image from a BMP file
- `Export(const char* path)` - Save an image to a BMP file
- `ApplyGaussianBlur(int radius, float sigma)` - Apply Gaussian blur with parallel processing
- `ApplyGaussianBlurSequential(int radius, float sigma)` - Apply Gaussian blur sequentially

### RightTurnImage and LeftTurnImage Classes

Classes that extend the Image class to implement image rotation operations.

**Key features:**
- Inheritance from Image class
- Parallel implementation of rotation operations
- Sequential implementation for performance comparison

### Kernel Class

Implements Gaussian kernel calculations for the blur operation.

## Building and Running

See the main [README.md](../README.md) for build and run instructions.

## Performance Considerations

- For small images, the overhead of thread creation may exceed the benefits of parallelization
- The optimal number of threads depends on the hardware and the size of the data
- Operations with higher computational complexity (like Gaussian blur with large radius) benefit more from parallelization

## Implementation Details

### Parallelization Strategy

- For image rotation, parallelization is applied across rows or columns
- For Gaussian blur, parallelization is applied to the outer loop that iterates over pixels
- The number of threads can be controlled via command-line arguments

### Thread Management

- The application uses OpenMP's dynamic scheduling by default
- Thread count can be specified or the program will use the maximum available

## Testing

The project includes unit tests implemented with Google Test framework. The tests verify:
- Basic image creation and manipulation
- Color operations
- Rotation functionality
- Gaussian blur application 