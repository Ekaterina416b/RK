#include "MobilePhones.h"
#include <iostream>

namespace MobilePhonesExample {

    void Samsung::sendMessage() {
        std::cout << "Samsung Selected" << std::endl;
    }

    void IPhone::sendMessage() {
        std::cout << "IPhone Selected" << std::endl;
    }

    MobileFactory::MobileFactory() : m_mobile(nullptr) {}

    std::shared_ptr<IMobile> MobileFactory::getType(std::string str) {
        if (str == "Samsung") {
            m_mobile = std::make_shared<Samsung>();
        }
        else if (str == "iPhone") {
            m_mobile = std::make_shared<IPhone>();
        }
        return m_mobile;
    }

    void test_mobile_phones_01() {
        MobileFactory factory;
        factory.getType("Samsung")->sendMessage();
    }

    void test_mobile_phones_02() {
        MobileFactory factory;
        std::shared_ptr<IMobile> mobile = factory.getType("Huawei");
        if (!mobile) {
            std::cout << "Wrong Type" << std::endl;
        }
    }
}
