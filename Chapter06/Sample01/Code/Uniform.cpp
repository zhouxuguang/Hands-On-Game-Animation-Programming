//#include "Uniform.h"

//template class Uniform<int>;
//template class Uniform<ivec4>;
//template class Uniform<ivec2>;
//template class Uniform<float>;
//template class Uniform<vec2>;
//template class Uniform<vec3>;
//template class Uniform<vec4>;
//template class Uniform<quat>;
//template class Uniform<mat4>;
//
//#define UNIFORM_IMPL(gl_func, tType, dType) \
//template<> \
//void Uniform<tType>::Set(unsigned int slot, tType* data, unsigned int length) { \
//    gl_func(slot, (GLsizei)length, (dType*)&data[0]); \
//}

//UNIFORM_IMPL(glUniform1iv, int, int)
//UNIFORM_IMPL(glUniform4iv, ivec4, int)
//UNIFORM_IMPL(glUniform2iv, ivec2, int)
//UNIFORM_IMPL(glUniform1fv, float, float)
//UNIFORM_IMPL(glUniform2fv, vec2, float)
//UNIFORM_IMPL(glUniform3fv, vec3, float)
//UNIFORM_IMPL(glUniform4fv, vec4, float)
//UNIFORM_IMPL(glUniform4fv, quat, float)

