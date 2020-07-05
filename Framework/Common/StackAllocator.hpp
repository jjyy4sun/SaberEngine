#include <Allocator.hpp>
#include <vector>
namespace Saber {
    #define ORIGINAL_MEMORY_SIZE 1024
    #define MAX(a,b) ((a) > (b) ? (a) : (b))
    struct stack_mem {
        uint8_t* addr{nullptr};
        size_t own_mark{0};
        size_t size;

        void *get() {
            return addr;
        }
    };
    class StackAllocator:public AllocatorBase
    {
    private:
        std::vector<uint8_t> baseMem;
        std::vector<stack_mem> vStack;
        size_t mark; 
    public:
        StackAllocator():baseMem((0,ORIGINAL_MEMORY_SIZE)),mark(0){};
        virtual ~StackAllocator() {};
        void* Allocate(size_t allocate_size) override;
        int dellocate(void* addr) override;
        int rellocate(void* addr,size_t allocate_size) override{};
    };
}