#include "feature_engineering.h"

std::vector<float> extractFeatures(const std::vector<float> &dataRow) {
    std::vector<float> features;

    // Example feature: Population density adjustment
    float densityFactor = dataRow[0] * 0.8;
    features.push_back(densityFactor);

    // Additional feature: Seasonal adjustment
    float seasonalFactor = (dataRow[1] > 0.5) ? 1.2 : 0.8;
    features.push_back(seasonalFactor);

    // Crime rate by area as a proxy feature
    features.push_back(dataRow[2]);

    return features;
}
