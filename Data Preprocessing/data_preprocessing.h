#ifndef DATA_PREPROCESSING_H
#define DATA_PREPROCESSING_H

#include <vector>
#include <string>

std::vector<std::vector<float>> preprocessCrimeData(const std::string &filePath);
std::vector<std::vector<float>> loadExternalData(const std::string &filePath);

#endif // DATA_PREPROCESSING_H
