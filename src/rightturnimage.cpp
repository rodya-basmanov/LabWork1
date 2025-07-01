/* ## LabWork1
## Author
Basmanov Rodion B81-mm
## Contacts
st135699@student.spbu.ru
## Description
LabWork1 */

#include <iostream>
#include <omp.h>
#include "../include/image.h"
#include "../include/turnimage.h"
#include <vector>

void Turn_Image::RightTurn(const char* path)
{
    Image image(0, 0);
    image.Read(path);
    int height = image.GetHeight();
    int width = image.GetWidth();
    Image rotatedImage(height, width);

    #pragma omp parallel for collapse(2)
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            rotatedImage.SetColor(image.GetColor(x, y), height - y - 1, x);
        }
    }

    rotatedImage.Export("Right_rotated_image.bmp");
}

void Turn_Image::RightTurnSequential(const char* path)
{
    Image image(0, 0);
    image.Read(path);
    int height = image.GetHeight();
    int width = image.GetWidth();
    Image rotatedImage(height, width);

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            rotatedImage.SetColor(image.GetColor(x, y), height - y - 1, x);
        }
    }

    rotatedImage.Export("Right_rotated_image_sequential.bmp");
}