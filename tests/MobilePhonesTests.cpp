#include "../src/MobilePhones/MobilePhones.h"
#include <gtest/gtest.h>

TEST(MobilePhonesTest, SamsungMessage) {
    MobilePhonesExample::Samsung samsung;
    testing::internal::CaptureStdout();
    samsung.sendMessage();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Samsung Selected\n");
}

TEST(MobilePhonesTest, IPhoneMessage) {
    MobilePhonesExample::IPhone iphone;
    testing::internal::CaptureStdout();
    iphone.sendMessage();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "IPhone Selected\n");
}

TEST(MobilePhonesTest, FactoryValidTypes) {
    MobilePhonesExample::MobileFactory factory;
    
    testing::internal::CaptureStdout();
    factory.getType("Samsung")->sendMessage();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Samsung Selected\n");

    testing::internal::CaptureStdout();
    factory.getType("iPhone")->sendMessage();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "IPhone Selected\n");
}

TEST(MobilePhonesTest, FactoryInvalidType) {
    MobilePhonesExample::MobileFactory factory;
    auto mobile = factory.getType("Huawei");
    EXPECT_EQ(mobile, nullptr);
}
