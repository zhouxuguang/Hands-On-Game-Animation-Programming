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



#endif
