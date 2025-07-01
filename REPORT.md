# Laboratory Work Report

## Parallel Image Processing Implementation

In this laboratory work, parallel processing was added to an existing image processing program. Parallelization was implemented using OpenMP technology.

## What was done

1. Added parallel processing to functions:
   - Rotating images left and right
   - Gaussian blur

2. Added ability to compare with sequential version

3. Added execution time measurement

## Test Results

Testing was conducted on image.bmp with different parameters:

### Test 1: Blur Radius = 5, Sigma = 1.5

| Number of threads | Sequential time (ms) | Parallel time (ms) | Speedup |
|-------------------|----------------------|-------------------|---------|
| 1 | 167.9 | 162.5 | 1.03x |
| 2 | 145.1 | 135.8 | 1.07x |
| 4 | 163.2 | 150.8 | 1.08x |
| 8 | 218.5 | 102.5 | 2.13x |

### Test 2: Blur Radius = 15, Sigma = 2.0

| Number of threads | Sequential time (ms) | Parallel time (ms) | Speedup |
|-------------------|----------------------|-------------------|---------|
| 4 | 1103.1 | 738.5 | 1.49x |
| 8 | 1113.1 | 499.5 | 2.23x |

### Image Rotation Results

| Operation | Threads | Sequential time (ms) | Parallel time (ms) | Speedup |
|-----------|---------|----------------------|-------------------|---------|
| Left Turn | 1 | 11.68 | 14.14 | 0.83x |
| Left Turn | 4 | 28.88 | 39.72 | 0.73x |
| Left Turn | 8 | 1.59 | 7.59 | 0.21x |
| Right Turn | 1 | 1.08 | 1.28 | 0.84x |
| Right Turn | 4 | 19.30 | 16.38 | 1.18x |
| Right Turn | 8 | 6.66 | 6.48 | 1.03x |

*Note: For small images, the overhead of creating and managing threads can sometimes exceed the performance benefits, resulting in speedup factors less than 1.*

## Visual Results Comparison

Both sequential and parallel versions produce identical visual results:

### Original Image
![Original Image](./docs/images/original.png)

### After Gaussian Blur (Sequential vs Parallel)
![Sequential Blur](./docs/images/sequential_blur.png)
![Parallel Blur](./docs/images/parallel_blur.png)

### After Left Rotation (Sequential vs Parallel)
![Sequential Left Turn](./docs/images/sequential_left.png)
![Parallel Left Turn](./docs/images/parallel_left.png)

### After Right Rotation (Sequential vs Parallel)
![Sequential Right Turn](./docs/images/sequential_right.png)
![Parallel Right Turn](./docs/images/parallel_right.png)

## Conclusions

1. The parallel version works faster than the sequential one, especially with a larger blur radius
2. The greatest speedup (2.23x) is achieved when using 8 threads with Gaussian blur
3. For small images and simple operations, the effect of parallelization is less noticeable and may even be negative due to thread management overhead
4. The larger the blur radius, the greater the benefit from parallel processing
5. Both sequential and parallel versions produce identical visual results, confirming the correctness of the parallel implementation
