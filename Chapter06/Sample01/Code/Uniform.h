#ifndef _H_UNIFORM_
#define _H_UNIFORM_

#include <vector>
#include "PreDefine.h"
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "quat.h"
#include "mat4.h"

template <typename T>
class Uniform {
private:
	Uniform();
	Uniform(const Uniform&);
	Uniform& operator=(const Uniform&);
	~Uniform();
public:
	static void Set(unsigned int slot, const T& value)
    {
        Set(slot, (T*)&value, 1);
    }
    
	static void Set(unsigned int slot, T* inputArray, unsigned int arrayLength)
    {
        glUniformMatrix4fv(slot, (GLsizei)arrayLength, false, (float*)&inputArray[0]);
    }
    
	static void Set(unsigned int slot, std::vector<T>& inputArray)
    {
        Set(slot, &inputArray[0], (unsigned int)inputArray.size());
    }
};

#define UNIFORM_IMPL(gl_func, tType, dType) \
template<> \
void Uniform<tType>::Set(unsigned int slot, tType* data, unsigned int length) { \
    gl_func(slot, (GLsizei)length, (dType*)&data[0]); \
}

UNIFORM_IMPL(glUniform1iv, int, int)
UNIFORM_IMPL(glUniform4iv, ivec4, int)
UNIFORM_IMPL(glUniform2iv, ivec2, int)
UNIFORM_IMPL(glUniform1fv, float, float)
UNIFORM_IMPL(glUniform2fv, vec2, float)
UNIFORM_IMPL(glUniform3fv, vec3, float)
UNIFORM_IMPL(glUniform4fv, vec4, float)
UNIFORM_IMPL(glUniform4fv, quat, float)

#endif
