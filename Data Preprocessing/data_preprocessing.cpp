#include "data_preprocessing.h"
#include <fstream>
#include <sstream>
#include <iostream>

// Preprocess crime data
std::vector<std::vector<float>> preprocessCrimeData(const std::string &filePath) {
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
    return data;
}

// Load additional data (e.g., weather, economic indicators)
std::vector<std::vector<float>> loadExternalData(const std::string &filePath) {
    std::vector<std::vector<float>> data;
    // Implement similar logic as above for loading external data
    return data;
}
