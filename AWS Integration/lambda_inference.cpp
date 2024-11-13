#include <aws/lambda-runtime/runtime.h>
#include "model.h"

using namespace aws::lambda_runtime;

invocation_response my_handler(invocation_request const &request) {
    // Assume request contains features as JSON; parse and predict
    std::vector<float> features = {0.5, 0.3};  // Example features
    float weight = 0.8;  // Assume a pre-trained weight

    float prediction = predict(features, weight);
    return invocation_response::success(std::to_string(prediction), "application/json");
}

int main() {
    run_handler(my_handler);
    return 0;
}
