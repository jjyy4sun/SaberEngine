#pragma once
#include <IRuntimeModule.hpp>
#include <exception>
namespace Saber{
template<typename T>
class ISingletion:public IRuntimeModule {
    public:
        static T& getInstance() noexcept(std::is_nothrow_constructible<T>::value) {
            static T inst{emu()};
            return inst;
        }
        ~ISingletion() = default;
        ISingletion(ISingletion&) = delete;
        ISingletion(ISingletion&&) = delete;
        ISingletion& operator=(const ISingletion &) = delete;
    protected:
        struct emu{};
        ISingletion() noexcept = default;
};
}
