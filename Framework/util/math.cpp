#include <cmath>
#include <cstdint>
#include <fstream>

#define U32 uint32_t
#define U16 uint16_t
#define F32 float_t
class Stream {
public:
    Stream(){
        file.open("output.txt",std::fstream::out | std::fstream::binary | std::fstream::app); 
    }
    void writeU32(U32 v) {
        if(file.is_open()) {
            file << v;
        }
    }
    void writeU16(U16 v) {
        if(file.is_open()) {
            file << v;
        }
    }
private:
    std::fstream file;
};


struct Example
{
    U32 m_a;
    U16 m_b;
    U32 m_c;
};

inline U16 swapU16(U16 value) {
    return ((value & 0x00FF) << 8)
        | ((value & 0xFF00) >> 8);
}

inline U32 swapU32(U32 value) {
    return ((value & 0x000000FF) << 24)
        | ((value & 0x0000FF00) << 8)
        | ((value & 0x00FF0000) >> 8)
        | ((value & 0xFF000000) >> 24);
}

void writeExampleStruct(Example& ex, Stream& stream) {
    stream.writeU32(swapU32(ex.m_a));
    stream.writeU16(swapU16(ex.m_b));
    stream.writeU32(swapU32(ex.m_c));
}

union U32F32 {
    U32 m_asU32;
    F32 m_asF32;
};

inline F32 swapF32(F32 value) {
    U32F32 u;
    u.m_asF32 = value;
    u.m_asU32 = swapU32(u.m_asU32);
    return u.m_asF32;
}