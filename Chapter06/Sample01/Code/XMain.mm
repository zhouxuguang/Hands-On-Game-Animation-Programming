#include <iostream>
#include "PreDefine.h"
#include "CrossWindow/CrossWindow.h"
#include "CrossWindow/Graphics.h"
#include "Util.h"
#include "Application.h"
#include "Sample.h"

Application* gApplication = 0;
GLuint gVertexArrayObject = 0;

int main(int argc, const char** argv)
{
    //初始化，这里必须是平台相关的
    xwin::init(argc, argv, getApplication());
    
    // 🖼️ Create Window Description
    xwin::WindowDesc windowDesc;
    windowDesc.name = "GameAnimation";
    windowDesc.title = "GameAnimation";
    windowDesc.visible = true;
    windowDesc.width = 800;
    windowDesc.height = 600;

    bool closed = false;

    // 🌟 Initialize
    xwin::Window window;
    xwin::EventQueue eventQueue;

    if (!window.create(windowDesc, eventQueue))
    { return; }

    xgfx::OpenGLDesc desc;
    xgfx::OpenGLState state = xgfx::createContext(&window, desc);

    // ⬇️ Set the context
    xgfx::setContext(state);
    
    const char* szVersion = (const char*)glGetString(GL_VERSION);

    gApplication = new Sample();
    gApplication->Initialize();

    glGenVertexArrays(1, &gVertexArrayObject);
	glBindVertexArray(gVertexArrayObject);

    // 🏁 Engine loop
    bool isRunning = true;
    
    uint64_t lastTick = GetTickCount();

    while (isRunning)
    {
        // ♻️ Update the event queue
        eventQueue.update();

        uint64_t thisTick = GetTickCount();
        float deltaTime = float(thisTick - lastTick) * 0.001f;
        lastTick = thisTick;
        if (gApplication != 0)
        {
            gApplication->Update(deltaTime);
        }
        if (gApplication != 0)
        {
            int clientWidth = windowDesc.width;
            int clientHeight = windowDesc.height;
            glViewport(0, 0, clientWidth, clientHeight);
            glEnable(GL_DEPTH_TEST);
            glEnable(GL_CULL_FACE);
            glPointSize(5.0f);
            glBindVertexArray(gVertexArrayObject);

            glClearColor(0.5f, 0.0f, 0.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

            float aspect = (float)clientWidth / (float)clientHeight;
            gApplication->Render(aspect);
        }
        if (gApplication != 0)
        {
            xgfx::swapBuffers(state);
        }

        // 🎈 Iterate through that queue:
        while (!eventQueue.empty())
        {
            const xwin::Event& event = eventQueue.front();

            if (event.type == xwin::EventType::MouseInput)
            {
                const xwin::MouseInputData mouse = event.data.mouseInput;
            }
            if (event.type == xwin::EventType::Close)
            {
                window.close();
                isRunning = false;
            }

            eventQueue.pop();
        }
    }
    
    return 0;
}
