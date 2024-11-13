#include <aws/core/Aws.h>
#include <aws/s3/S3Client.h>
#include <aws/s3/model/PutObjectRequest.h>
#include <fstream>

void uploadToS3(const std::string &filePath, const std::string &bucketName) {
    Aws::S3::S3Client s3Client;
    Aws::S3::Model::PutObjectRequest request;
    request.WithBucket(bucketName.c_str()).WithKey(filePath.c_str());

    auto input_data = Aws::MakeShared<Aws::FStream>("UploadFileStream", filePath.c_str(), std::ios_base::in | std::ios_base::binary);
    request.SetBody(input_data);

    auto outcome = s3Client.PutObject(request);
    if (outcome.IsSuccess()) {
        std::cout << "File uploaded successfully!" << std::endl;
    } else {
        std::cerr << "File upload failed: " << outcome.GetError().GetMessage() << std::endl;
    }
}
