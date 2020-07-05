include_directories(${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/util/include)
add_library(Common
BaseApplication.cpp
StackAllocator.cpp
GraphicsManager.cpp
main.cpp
)