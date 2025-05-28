#ifndef MOBILE_PHONES_H
#define MOBILE_PHONES_H

#include <memory>
#include <string>

namespace MobilePhonesExample {

    class IMobile {
    public:
        virtual ~IMobile() = default;
        virtual void sendMessage() = 0;
    };

    class Samsung : public IMobile {
    public:
        void sendMessage() override;
    };

    class IPhone : public IMobile {
    public:
        void sendMessage() override;
    };

    class MobileFactory {
    private:
        std::shared_ptr<IMobile> m_mobile;
    public:
        MobileFactory();
        std::shared_ptr<IMobile> getType(std::string str);
    };

    void test_mobile_phones_01();
    void test_mobile_phones_02();
}

#endif // MOBILE_PHONES_H
