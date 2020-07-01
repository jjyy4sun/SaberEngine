#pragma once

#include "Interface.hpp"

namespace Saber{
    Interface IRuntimeModule{
        public:
            virtual ~IRuntimeModule(){};
            virtual int Initialize() = 0;
            virtual void Finalize() = 0;
            virtual void Tick() = 0;//用来让驱动模块驱动本模块执行
    };
}