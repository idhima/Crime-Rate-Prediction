#include "data_preprocessing.h"
#include "feature_engineering.h"
#include "model.h"
#include <iostream>

int main() {
    // Preprocess and load data
    auto crimeData = preprocessCrimeData("data/crime_data.csv");
    auto externalData = loadExternalData("data/external_data.csv");

    // Extract features for each row
    std::vector<std::vector<float>> trainData;
    for (size_t i = 0; i < crimeData.size(); ++i) {
        auto features = extractAdvancedFeatures(crimeData[i], externalData[i]);
        trainData.push_back(features);
    }

    // Call SageMaker for training
    startSageMakerTraining("s3://your-bucket/train-data", "s3://your-bucket/model-output");

    std::cout << "Advanced Crime Rate Prediction setup complete." << std::endl;
    return 0;
}

