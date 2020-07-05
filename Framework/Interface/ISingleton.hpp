#pragma once
#include <IRuntimeModule.hpp>
#include <exception>
namespace Saber{
template<typename T>
class ISingleton:public IRuntimeModule {
    public:
        static T& getInstance() noexcept(std::is_nothrow_constructible<T>::value) {
            static T inst{emu()};
            return inst;
        }
        ~ISingleton() = default;
        ISingleton(ISingleton&) = delete;
        ISingleton(ISingleton&&) = delete;
        ISingleton& operator=(const ISingleton &) = delete;
    protected:
        struct emu{};
        ISingleton() noexcept = default;
};
}
