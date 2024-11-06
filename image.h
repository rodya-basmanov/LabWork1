#ifndef IMAGE_H
#define IMAGE_H

#include <vector>
#include "bmp.h"

std::vector<uint8_t> rotate90Clockwise(const BMPHeader &header, const std::vector<uint8_t> &data);
std::vector<uint8_t> applyGaussianFilter(const BMPHeader &header, const std::vector<uint8_t> &data);

#endif