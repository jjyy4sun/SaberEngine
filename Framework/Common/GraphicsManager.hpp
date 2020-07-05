#pragma once

#include "ISingleton.hpp"


namespace Saber{
    class GraphicsManager: public ISingleton<GraphicsManager>
    {
        public:
            int Initialize() override;
            void Finalize() override;
            void Tick() override;
        public:
            GraphicsManager(emu){};
            ~GraphicsManager(){};
            GraphicsManager(const GraphicsManager&) = delete;
            GraphicsManager &operator=(const GraphicsManager &) = delete;
    };
}