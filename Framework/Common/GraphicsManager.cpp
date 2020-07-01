#include "GraphicsManager.hpp"

namespace Saber {
class GraphicsManager
{
private:
    static GraphicsManager& get() {
        static GraphicsManager Instance;
        return Instance;
    }
public:
    GraphicsManager();
    ~GraphicsManager();
};

GraphicsManager::GraphicsManager()
{
}

GraphicsManager::~GraphicsManager()
{
}

}