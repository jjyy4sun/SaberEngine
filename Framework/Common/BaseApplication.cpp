#include "BaseApplication.hpp"

//Parse command lilne ,read configuration,initialize all sub modules
int Saber::BaseApplication::Initialize()
{
    m_bQuit = false;
    return 0;
}

//Finalize all sub modules and clean up all runtime temporary files.
void Saber::BaseApplication::Finalize()
{

}

//One cycle of the main loop 
void Saber::BaseApplication::Tick()
{

}

bool Saber::BaseApplication::IsQuit()
{
    return m_bQuit;
}