#ifndef PREDEFINE_INCLUDE_H
#define PREDEFINE_INCLUDE_H

#include <OpenGL/gl3.h>


inline char const* gl_error_string(GLenum const err)
{
    switch (err)
    {
        // opengl 2 errors (8)
        case GL_NO_ERROR:
            return "GL_NO_ERROR";

        case GL_INVALID_ENUM:
            return "GL_INVALID_ENUM";

        case GL_INVALID_VALUE:
            return "GL_INVALID_VALUE";

        case GL_INVALID_OPERATION:
            return "GL_INVALID_OPERATION";

        case GL_OUT_OF_MEMORY:
            return "GL_OUT_OF_MEMORY";

            // opengl 3 errors (1)
        case GL_INVALID_FRAMEBUFFER_OPERATION:
            return "GL_INVALID_FRAMEBUFFER_OPERATION";

        case GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT:
            return "GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT";

        case GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT:
            return "GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT";

//        case GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS:
//            return "GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS";

        case GL_FRAMEBUFFER_UNSUPPORTED:
            return "GL_FRAMEBUFFER_UNSUPPORTED";

            // gles 2, 3 and gl 4 error are handled by the switch above
        default:
            //assert(!"unknown error");
            return nullptr;
    }
}

#define _OPENGL_CHECK_ERROR_

#ifdef _OPENGL_CHECK_ERROR_
    inline void GL_CHECK_ERROR()
    {
        GLuint err = glGetError();
        if (err != 0)
        {
            printf("error = %s\n", gl_error_string(err));
            abort();
        }
    }

    inline void GL_CHECK_ASSERT(bool cond)
    {
        if (!(cond))
        {
            abort();
        }
    }
#else
    #define GL_CHECK_ERROR() ((void)0)
    #define GL_CHECK_ASSERT(cond) ((void)0)
#endif

#endif
