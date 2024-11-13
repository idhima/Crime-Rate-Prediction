#include "data_preprocessing.h"
#include "feature_engineering.h"
#include "model.h"
#include <iostream>

int main() {
    // Preprocess the data
    auto data = preprocessData("data/crime_data.csv");

    // Extract features and prepare training data
    std::vector<std::vector<float>> trainData;
    for (const auto &row : data) {
        trainData.push_back(extractFeatures(row));
    }

    // Train model
    float modelWeight = trainModel(trainData);

    // Predict using a sample feature set
    std::vector<float> sampleFeatures = {0.6, 0.4};  // Example features
    float prediction = predict(sampleFeatures, modelWeight);

    std::cout << "Crime rate prediction: " << prediction << std::endl;
    return 0;
}
