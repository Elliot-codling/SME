#include "runtime/runtime.h"

static int windowWidth = 1280, windowHeight = 720;
int main()
{
    // Create runtime which will create the application
    // Runtime will control the flow of the code
    Runtime app("SFML Works!", windowWidth, windowHeight);
    app.update();
    app.end();

    return 0;
}
