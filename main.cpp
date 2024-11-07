/* ## LabWork1
## Author
Basmanov Rodion B81-mm
## Contacts
st135699@student.spbu.ru
## Description
LabWork1 */

#include <iostream>
#include "bmp.h"
#include "image.h"

int main() {
    BMPHeader header;
    std::vector<uint8_t> imageData;

    if (!loadBMP("image.bmp", header, imageData)) {
        return 1;
    }

    size_t memorySize = calculateMemorySize(header);
    std::cout << "Required amount of memory: " << memorySize << " bytes." << std::endl;

    auto rotatedClockwise = rotate90Clockwise(header, imageData);
    saveBMP("rotated_clockwise.bmp", header, rotatedClockwise);

    auto rotatedCounterClockwise = rotate90CounterClockwise(header, imageData);
    saveBMP("rotated_counterclockwise.bmp", header, rotatedCounterClockwise);

    auto filteredImage = applyGaussianFilter(header, rotatedClockwise);
    saveBMP("filtered_gaussian.bmp", header, filteredImage);

    std::cout << "Processing is complete!" << std::endl;
    return 0;
}