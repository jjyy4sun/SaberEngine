#include "IRuntimeModule.hpp"

namespace Saber{
    class AllocatorBase:public IRuntimeModule
    {
    private:
        /* data */
    public:
        virtual AllocatorBase();
        virtual ~AllocatorBase();
        virtual Allocate(size_t allocate_size);
        virtual rellocate(void* addr,size_t allocate_size);
        virtual dellocate(void* addr);
    };    
}