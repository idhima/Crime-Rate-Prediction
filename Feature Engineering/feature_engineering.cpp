#include "feature_engineering.h"
#include <cmath>

std::vector<float> extractAdvancedFeatures(const std::vector<float> &dataRow, const std::vector<float> &externalDataRow) {
    std::vector<float> features;

    float crimeRate = dataRow[0];
    float populationDensity = externalDataRow[0];
    float incomeLevel = externalDataRow[1];

    // Advanced feature engineering
    float adjustedCrimeRate = crimeRate * std::log(populationDensity);
    features.push_back(adjustedCrimeRate);

    float socioeconomicImpact = incomeLevel * 0.7;  // Example weight factor
    features.push_back(socioeconomicImpact);

    // Other features such as time-based seasonality, etc.
    return features;
}
