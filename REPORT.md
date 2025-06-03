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

## Conclusions

1. The parallel version works faster than the sequential one, especially with a larger blur radius
2. The greatest speedup (2.23x) is achieved when using 8 threads
3. For small images, the effect of parallelization is less noticeable
4. The larger the blur radius, the greater the benefit from parallel processing
