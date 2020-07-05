#include <cstddef>
namespace Saber{
    class AllocatorBase
    {
    private:
        /* data */
    public:
        AllocatorBase(){};
        virtual ~AllocatorBase(){};
        virtual void* Allocate(size_t allocate_size) = 0;
        virtual int rellocate(void* addr,size_t allocate_size) = 0;
        virtual int dellocate(void* addr) = 0;
    };    
}