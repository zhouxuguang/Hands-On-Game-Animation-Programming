#include "CrossWindow/CrossWindow.h"
#include "Util.h"

int main(int argc, const char** argv)
{
    //初始化，这里必须是平台相关的
    xwin::init(argc, argv, getApplication());
    
    // 🖼️ Create Window Description
    xwin::WindowDesc windowDesc;
    windowDesc.name = "Test";
    windowDesc.title = "My Title";
    windowDesc.visible = true;
    windowDesc.width = 1280;
    windowDesc.height = 720;

    bool closed = false;

    // 🌟 Initialize
    xwin::Window window;
    xwin::EventQueue eventQueue;

    if (!window.create(windowDesc, eventQueue))
    { return; }

    // 🏁 Engine loop
    bool isRunning = true;

    while (isRunning)
    {
        // ♻️ Update the event queue
        eventQueue.update();

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
