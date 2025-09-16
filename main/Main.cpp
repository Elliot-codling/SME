#include "runtime/Runtime.h"

static int windowWidth = 1280, windowHeight = 720;
int main()
{
    Logger::setMinLogLevel(LogLevel::Debug);
    // Create runtime which will create the application
    // Runtime will control the flow of the code
    LOG_INFO("Main.cpp", "Starting program...");
    Runtime app("SFML Works!", windowWidth, windowHeight);
    app.update();
    app.end();
    LOG_INFO("Main.cpp", "Program terminated. Goodbye.");

    return 0;
}
