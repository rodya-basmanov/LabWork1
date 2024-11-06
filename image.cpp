// image_processor.cpp
#include "image.h"

std::vector<uint8_t> rotate90Clockwise(const BMPHeader &header, const std::vector<uint8_t> &data) {
    int width = header.width;
    int height = header.height;
    int bytesPerPixel = header.bitCount / 8;

    std::vector<uint8_t> rotatedData(width * height * bytesPerPixel);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            for (int c = 0; c < bytesPerPixel; ++c) {
                rotatedData[(x * height + (height - y - 1)) * bytesPerPixel + c] =
                    data[(y * width + x) * bytesPerPixel + c];
            }
        }
    }
    return rotatedData;
}

std::vector<uint8_t> applyGaussianFilter(const BMPHeader &header, const std::vector<uint8_t> &data) {
    int width = header.width;
    int height = header.height;
    int bytesPerPixel = header.bitCount / 8;

    std::vector<uint8_t> filteredData(width * height * bytesPerPixel);

    float kernel[3][3] = {
        {1 / 16.0f, 2 / 16.0f, 1 / 16.0f},
        {2 / 16.0f, 4 / 16.0f, 2 / 16.0f},
        {1 / 16.0f, 2 / 16.0f, 1 / 16.0f}
    };

    for (int y = 1; y < height - 1; ++y) {
        for (int x = 1; x < width - 1; ++x) {
            for (int c = 0; c < bytesPerPixel; ++c) {
                float newValue = 0.0f;
                for (int ky = -1; ky <= 1; ++ky) {
                    for (int kx = -1; kx <= 1; ++kx) {
                        int pixelIndex = ((y + ky) * width + (x + kx)) * bytesPerPixel + c;
                        newValue += data[pixelIndex] * kernel[ky + 1][kx + 1];
                    }
                }
                filteredData[(y * width + x) * bytesPerPixel + c] = static_cast<uint8_t>(newValue);
            }
        }
    }
    return filteredData;
}