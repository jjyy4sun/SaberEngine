#include <stdio.h>
#include "debugtool.h"
#include "IApplication.hpp"
using namespace Saber;
namespace Saber{
    extern IApplication * g_pApp;
}

int main(int argc,char **argv){
    int ret = 0;
    ASSERT(0 != ret);
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