#pragma once

#include "IApplication.hpp"

namespace Saber{
    class BaseApplication : implements IApplication
    {
        public:
            virtual int Initialize();
            virtual void Finalize();
            virtual void Tick();
            virtual bool IsQuit();
        protected:
            //Flag if need quit the main loop of then application
            bool m_bQuit;
    };
}