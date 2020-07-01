#include "GraphicsManager.hpp"

namespace My {
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