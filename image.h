/* ## LabWork1
## Author
Basmanov Rodion B81-mm
## Contacts
st135699@student.spbu.ru
## Description
LabWork1 */

#ifndef IMAGE_H
#define IMAGE_H

#include <vector>
#include "bmp.h"

std::vector<uint8_t> rotate90Clockwise(BMPHeader &header, const std::vector<uint8_t> &data);
std::vector<uint8_t> rotate90CounterClockwise(BMPHeader &header, const std::vector<uint8_t> &data);
std::vector<uint8_t> applyGaussianFilter(BMPHeader &header, const std::vector<uint8_t> &data);

#endif