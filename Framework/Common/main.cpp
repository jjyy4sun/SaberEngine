#include <stdio.h>
#include "debugtool.h"
#include "IApplication.hpp"
#include "StackAllocator.hpp"
using namespace Saber;
namespace Saber{
    extern IApplication * g_pApp;
}

int main(int argc,char **argv){
    int ret = 0;
    StackAllocator *allocator = new StackAllocator();
    void *allocate_mem = allocator->Allocate(5*sizeof(int));
    int *tmpArray = (int *)(((stack_mem *)allocate_mem)->get());
    tmpArray[0] = 1; 
    tmpArray[1] = 2; 
    tmpArray[2] = 3; 
    tmpArray[3] = 4; 
    tmpArray[4] = 5;
    for(size_t i = 0;i<5;i++){
        std::cout<<tmpArray[i]<<std::endl;
    }
    allocator->dellocate(allocate_mem);
    delete allocator;
    if((ret = g_pApp->Initialize()) != 0){
        printf("App Initialize failed,will eixt now.");
        return ret;
    }

    while(!g_pApp->IsQuit()){
        g_pApp->Tick();
    }

    g_pApp->Finalize();

    return 0;
}