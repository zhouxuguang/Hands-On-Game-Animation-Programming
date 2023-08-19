set(target chapter01)

set( chapter01_SOURCES
	Sample00/Code/glad.c
	Sample00/Code/XMain.cpp
	Sample00/Code/Util.mm )

add_executable(${target} ${chapter01_SOURCES})

# 🔗 Link CrossWindow to your project:
target_link_libraries(
    chapter01
    CrossWindow
)
