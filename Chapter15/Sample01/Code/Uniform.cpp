#include "Uniform.h"
#include "PreDefine.h"
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "quat.h"
#include "mat4.h"
#include "DualQuaternion.h"

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

template<>
void Uniform<mat4>::Set(unsigned int slot, mat4* inputArray, unsigned int arrayLength) {
	glUniformMatrix4fv(slot, (GLsizei)arrayLength, false, (float*)&inputArray[0]);
}

template<>
void Uniform<DualQuaternion>::Set(unsigned int slot, DualQuaternion* inputArray, unsigned int arrayLength) {
	glUniformMatrix2x4fv(slot, arrayLength, false, inputArray[0].v);
}

template <typename T>
void Uniform<T>::Set(unsigned int slot, const T& value) {
	Set(slot, (T*)&value, 1);
}

template <typename T>
void Uniform<T>::Set(unsigned int slot, std::vector<T>& value) {
	Set(slot, &value[0], (unsigned int)value.size());
}

template class Uniform<int>;
template class Uniform<ivec4>;
template class Uniform<ivec2>;
template class Uniform<float>;
template class Uniform<vec2>;
template class Uniform<vec3>;
template class Uniform<vec4>;
template class Uniform<quat>;
template class Uniform<mat4>;
template class Uniform<DualQuaternion>;
