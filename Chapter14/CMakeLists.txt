set(chapter14_1_SOURCES
	Sample01/Code/XMain.mm
	Sample01/Code/Util.mm
    Sample01/Code/Application.h
    Sample01/Code/Attribute.h
    Sample01/Code/Attribute.cpp
    Sample01/Code/Draw.h
    Sample01/Code/Draw.cpp
    Sample01/Code/glad.h
    Sample01/Code/glad.c
    Sample01/Code/IndexBuffer.h
    Sample01/Code/IndexBuffer.cpp
    Sample01/Code/mat4.h
    Sample01/Code/mat4.cpp
    Sample01/Code/quat.h
    Sample01/Code/quat.cpp
    Sample01/Code/Shader.h
    Sample01/Code/Shader.cpp
    Sample01/Code/stb_image.h
    Sample01/Code/stb_image.cpp
    Sample01/Code/Texture.h
    Sample01/Code/Texture.cpp
    Sample01/Code/Transform.h
    Sample01/Code/Transform.cpp
    Sample01/Code/TransformTrack.h
    Sample01/Code/TransformTrack.cpp
    Sample01/Code/Uniform.h
    Sample01/Code/Uniform.cpp
    Sample01/Code/vec2.h
    Sample01/Code/vec3.h
    Sample01/Code/vec3.cpp
    Sample01/Code/vec4.h
    Sample01/Code/cgltf.h
    Sample01/Code/cgltf.c
    Sample01/Code/Frame.h
    Sample01/Code/GLTFLoader.h
    Sample01/Code/GLTFLoader.cpp
    Sample01/Code/Interpolation.h
    Sample01/Code/Track.h
    Sample01/Code/Track.cpp
    Sample01/Code/Clip.h
    Sample01/Code/Clip.cpp
    Sample01/Code/Pose.h
    Sample01/Code/Pose.cpp
    Sample01/Code/Skeleton.cpp
    Sample01/Code/Skeleton.h
    Sample01/Code/Mesh.cpp
    Sample01/Code/Mesh.h
    Sample01/Code/RearrangeBones.cpp
    Sample01/Code/RearrangeBones.h
    Sample01/Code/Sample.cpp
    Sample01/Code/Sample.h
    Sample01/Code/CrossFadeController.cpp
    Sample01/Code/CrossFadeController.h
    Sample01/Code/CrossFadeTarget.h
    Sample01/Code/Blending.cpp
    Sample01/Code/Blending.h
    Sample01/Code/CCDSolver.cpp
    Sample01/Code/CCDSolver.h
    Sample01/Code/FABRIKSolver.cpp
    Sample01/Code/FABRIKSolver.h
    Sample01/Code/DualQuaternion.cpp
    Sample01/Code/DualQuaternion.h)

add_executable(chapter14_1 ${chapter14_1_SOURCES})

# 🔗 Link CrossWindow to your project:
target_link_libraries(
    chapter14_1
    CrossWindow
	CrossWindowGraphics
	${OPENGL_LIBRARIES}
)
