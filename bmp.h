/* ## LabWork1
## Author
Basmanov Rodion B81-mm
## Contacts
st135699@student.spbu.ru
## Description
LabWork1 */

#ifndef BMP_H
#define BMP_H

#include <string>
#include <vector>
#include <cstdint>
#include <iostream>
#include <fstream>

#pragma pack(push, 1)
struct BMPHeader {
    uint16_t fileType;
    uint32_t fileSize;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offsetData;
    uint32_t size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bitCount;
    uint32_t compression;
    uint32_t sizeImage;
    int32_t xPixelsPerMeter;
    int32_t yPixelsPerMeter;
    uint32_t colorsUsed;
    uint32_t colorsImportant;
};
#pragma pack(pop)

bool loadBMP(const std::string &filename, BMPHeader &header, std::vector<uint8_t> &data);
bool saveBMP(const std::string &filename, const BMPHeader &header, const std::vector<uint8_t> &data);
size_t calculateMemorySize(const BMPHeader &header);

#endif