#ifndef MODEL_H
#define MODEL_H

#include <vector>

float trainModel(const std::vector<std::vector<float>> &trainData);
float predict(const std::vector<float> &features, float weight);

#endif // MODEL_H
