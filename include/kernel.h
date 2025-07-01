/* ## LabWork1
## Author
Basmanov Rodion B81-mm
## Contacts
st135699@student.spbu.ru
## Description
LabWork1 */

#ifndef KERNEL_H
#define KERNEL_H

#include <vector>

namespace Gauss_Kernel
{
    std::vector<std::vector<float>> GenerateGaussianKernel(int radius, float sigma);
}

#endif