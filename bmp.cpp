/* ## LabWork1
## Author
Basmanov Rodion B81-mm
## Contacts
st135699@student.spbu.ru
## Description
LabWork1 */

#include "bmp.h"

bool loadBMP(const std::string &filename, BMPHeader &header, std::vector<uint8_t> &data) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Error: The file could not be opened" << std::endl;
        return false;
    }

    file.read(reinterpret_cast<char*>(&header), sizeof(BMPHeader));
    if (header.fileType != 0x4D42) {
        std::cerr << "Error: This is not a BMP file" << std::endl;
        return false;
    }

    size_t dataSize = calculateMemorySize(header);
    data.resize(dataSize);
    file.seekg(header.offsetData, std::ios::beg);
    file.read(reinterpret_cast<char*>(data.data()), data.size());

    return true;
}

bool saveBMP(const std::string &filename, const BMPHeader &header, const std::vector<uint8_t> &data) {
    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Error: The file could not be saved" << std::endl;
        return false;
    }

    file.write(reinterpret_cast<const char*>(&header), sizeof(BMPHeader));
    file.write(reinterpret_cast<const char*>(data.data()), data.size());

    return true;
}

size_t calculateMemorySize(const BMPHeader &header) {
    int bytesPerPixel = header.bitCount / 8;
    return header.width * header.height * bytesPerPixel;
}