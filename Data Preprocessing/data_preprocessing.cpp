#include "data_preprocessing.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<std::vector<float>> preprocessData(const std::string &filePath) {
    std::vector<std::vector<float>> data;
    std::ifstream file(filePath);
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return data;
    }

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::vector<float> row;
        std::string value;

        while (std::getline(ss, value, ',')) {
            try {
                row.push_back(std::stof(value));  
            } catch (const std::invalid_argument&) {
                row.push_back(0);  
            }
        }
        data.push_back(row);
    }
    file.close();

  
    for (size_t col = 0; col < data[0].size(); ++col) {
        float maxVal = 0;
        for (const auto &row : data) {
            if (row[col] > maxVal) maxVal = row[col];
        }
        for (auto &row : data) {
            row[col] /= maxVal;
        }
    }

    return data;
}
