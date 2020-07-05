#pragma once

#include "ISingletion.hpp"


namespace Saber{
    class GraphicsManager: public ISingletion<GraphicsManager>
    {
        public:
            int Initialize() override;
            void Finalize() override;
            void Tick() override;
        public:
            GraphicsManager(emu){};
            ~GraphicsManager();
            GraphicsManager(const GraphicsManager&) = delete;
            GraphicsManager &operator=(const GraphicsManager &) = delete;
    };
}