#include <iostream>
#include <windows.h>
// #include <WinUser.h>


int main()
{
    int vx = 1;
    int vy = 1;
    int rx, ry;

    INPUT inputs[1] = {};
    inputs[0].type = INPUT_MOUSE;

    while (true) {
        if (GetAsyncKeyState(VK_ESCAPE))
            break;

        rx = rand();
        if (rx < 32767 / 2) vx *= -1;
        ry = rand();
        if (ry < 32767 / 2) vy *= -1;

        inputs[0].mi.dx = vx;
        inputs[0].mi.dy = vy;
        inputs[0].mi.dwFlags = 0x0001;

        UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
        if (uSent != ARRAYSIZE(inputs))
        {
            std::cout << "SendInput failed: 0x" << HRESULT_FROM_WIN32(GetLastError()) << std::endl;
        }

        Sleep(1000);
    }

    

    /*
    int vx = 1;
    int vy = 1;
    LPPOINT point = new POINT;
    // std::cout << "Hello World!\n";
    int x, y, rx, ry;
    
    while (true) {
    // for (int i=0; i<10; i++) {

        if (GetAsyncKeyState(VK_ESCAPE))
            break;

        GetCursorPos(point);

        x = point->x;
        y = point->y;

        rx = rand();
        if (rx < 32767 / 2) vx *= -1;
        ry = rand();
        if (ry < 32767 / 2) vy *= -1;

        // std::cout << point->x << std::endl;

        SetCursorPos(x + vx, y + vy);

        Sleep(1000);

    }
    */

}
