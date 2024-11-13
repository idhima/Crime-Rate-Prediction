#include <aws/sagemaker/SageMakerClient.h>
#include <aws/sagemaker/model/CreateTrainingJobRequest.h>

void startSageMakerTraining(const std::string &trainingDataPath, const std::string &modelOutputPath) {
    Aws::SageMaker::SageMakerClient sagemaker;
    Aws::SageMaker::Model::CreateTrainingJobRequest request;

    request.WithTrainingJobName("crime-rate-prediction")
           .WithAlgorithmSpecification({/* Algorithm details */})
           .WithInputDataConfig({/* S3 Input path for training data */})
           .WithOutputDataConfig({modelOutputPath.c_str()});

    auto outcome = sagemaker.CreateTrainingJob(request);
    if (outcome.IsSuccess()) {
        std::cout << "Training started successfully!" << std::endl;
    } else {
        std::cerr << "Training failed: " << outcome.GetError().GetMessage() << std::endl;
    }
}
