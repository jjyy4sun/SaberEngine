#include <StackAllocator.hpp>
#include <iostream>

namespace Saber {
    void* StackAllocator::Allocate(size_t allocate_size) {
        std::cout<<"before dellocate mark is:"<<mark;
        std::cout<<"vector cap is:"<<baseMem.capacity()<<std::endl;// TODO(jjyy) : protect by mutex
        if(mark == baseMem.capacity()) {
            size_t new_size = MAX(mark*2,baseMem.capacity()+allocate_size);
            baseMem.reserve(new_size);
        }
        stack_mem tmp_mem;
        tmp_mem.addr = &baseMem[mark];
        tmp_mem.own_mark = mark;
        tmp_mem.size = allocate_size;
        vStack.push_back(tmp_mem);
        mark = mark + allocate_size;
        return reinterpret_cast<void*>(&vStack.back());
    }
    int StackAllocator::dellocate(void * addr) {
       // TODO(jjyy) : protect by mutex
       if (mark == 0) {
           return 0;
       } 
       stack_mem *oper_mem = reinterpret_cast<stack_mem *>(addr);
       if(mark == oper_mem->own_mark + oper_mem->size) {
           do {
               mark = mark - oper_mem->size;
               vStack.pop_back();
               oper_mem = &vStack.back();
           }
           while(oper_mem->own_mark == -1);
       }
       else
       {
           oper_mem->own_mark = -1;
       }
       size_t newsize = MAX(mark*2,ORIGINAL_MEMORY_SIZE);
       if (baseMem.capacity() > newsize) {
           baseMem.reserve(newsize);
       }
       std::cout<<"after dellocate mark is:"<<mark;
       std::cout<<"vector cap is:"<<baseMem.capacity()<<std::endl;

    }
} // namespace Saber