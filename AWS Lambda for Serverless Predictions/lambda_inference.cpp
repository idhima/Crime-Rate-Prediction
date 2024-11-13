#include <aws/lambda-runtime/runtime.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include "model.h"  // Load the trained model weights

using namespace aws::lambda_runtime;

invocation_response my_handler(invocation_request const &request) {
    Aws::Utils::Json::JsonValue json(request.payload);
    auto input_features = json.GetArray("features");

    // Parse features and predict
    std::vector<float> features = {/* Parsed features */};
    float prediction = predict(features, /* Trained weight */);

    return invocation_response::success(std::to_string(prediction), "application/json");
}

int main() {
    run_handler(my_handler);
    return 0;
}
