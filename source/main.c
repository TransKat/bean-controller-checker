// Include the most common headers from the C standard library
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Include the main libnx system header, for Switch development
#include <switch.h>

// Main program entrypoint
int main(int argc, char* argv[])
{
    // This example uses a text console, as a simple way to output text to the screen.
    // If you want to write a software-rendered graphics application,
    //   take a look at the graphics/simplegfx example, which uses the libnx Framebuffer API instead.
    // If on the other hand you want to write an OpenGL based application,
    //   take a look at the graphics/opengl set of examples, which uses EGL instead.
    consoleInit(NULL);

    // Configure our supported input layout: a single player with standard controller styles
    padConfigureInput(1, HidNpadStyleSet_NpadStandard);

    // Initialize the default gamepad (which reads handheld mode inputs as well as the first connected controller)
    PadState pad;
    padInitializeDefault(&pad);

    // Other initialization goes here. As a demonstration, we print hello world.
    printf("Press + to return to hbmenu\r");

    // Main loop
    while (appletMainLoop())
    {
        // Scan the gamepad. This should be done once for each frame
        padUpdate(&pad);

        // padGetButtonsDown returns the set of buttons that have been
        // newly pressed in this frame compared to the previous one
        u64 kDown = padGetButtonsDown(&pad);

        if (kDown & HidNpadButton_Plus){
            break; // break in order to return to hbmenu
        }
        if (kDown & HidNpadButton_A){
            printf("\e[1;1H\e[2J");
            printf("You pressed the A button\r");
        }
        if (kDown & HidNpadButton_B){
            printf("\e[1;1H\e[2J");
            printf("You pressed the B button\r");
        }
        if (kDown & HidNpadButton_X){
            printf("\e[1;1H\e[2J");
            printf("You pressed the X button\r");
        }
        if (kDown & HidNpadButton_Y){
            printf("\e[1;1H\e[2J");
            printf("You pressed the Y button\r");
        }
        if (kDown & HidNpadButton_Plus){
            printf("\e[1;1H\e[2J");
            printf("You pressed the + button\r");
        }
        if (kDown & HidNpadButton_Minus){
            printf("\e[1;1H\e[2J");
            printf("You pressed the - button\r");
        }
       if (kDown & HidNpadButton_Left){
            printf("\e[1;1H\e[2J");
            printf("You pressed the left dpad button\r");
        }
       if (kDown & HidNpadButton_Right){
            printf("\e[1;1H\e[2J");
            printf("You pressed the right dpad button\r");
        }
       if (kDown & HidNpadButton_Down){
            printf("\e[1;1H\e[2J");
            printf("You pressed the down dpad button\r");
        }
       if (kDown & HidNpadButton_Up){
            printf("\e[1;1H\e[2J");
            printf("You pressed the up dpad button\r");
        }
       if (kDown & HidNpadButton_ZR){
            printf("\e[1;1H\e[2J");
            printf("You pressed ZR\r");
        }
       if (kDown & HidNpadButton_ZL){
            printf("\e[1;1H\e[2J");
            printf("You pressed ZL\r");
        }
       if (kDown & HidNpadButton_L){
            printf("\e[1;1H\e[2J");
            printf("You pressed L\r");
        }
       if (kDown & HidNpadButton_R){
            printf("\e[1;1H\e[2J");
            printf("You pressed R\r");
        }
       if (kDown & HidNpadButton_StickL){
            printf("\e[1;1H\e[2J");
            printf("You pressed the left stick\r");
        }
       if (kDown & HidNpadButton_StickR){
            printf("\e[1;1H\e[2J");
            printf("You pressed the right stick\r");
        }

        // Update the console, sending a new frame to the display
        consoleUpdate(NULL);
    }

    // Deinitialize and clean up resources used by the console (important!)
    consoleExit(NULL);
    return 0;
}
