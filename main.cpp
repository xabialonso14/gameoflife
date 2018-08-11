#include <QCoreApplication>
#include <iostream>

#include <windows.h>
#pragma comment(lib, "user32")

#include "boardelement.h"
#include "board.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // make console full screen
    // why '::' in front of methods?
    ::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);

    // create an instance of Board
    Board MyMap;

    // set its dimensions to 50 rows and 100 columns
    MyMap.setDimensions(50,100);

    // add glider
    MyMap.addGlider(5,20);
    MyMap.addGlider(5,30);
    MyMap.addGlider(5,50);
    MyMap.addGlider(15,40);

    // add dakota
    MyMap.addDakota(15,5);
    MyMap.addDakota(25,35);

    // display initial board
    MyMap.initMap();

    while(1)
    {
        // time delay
        Sleep(500);

        // calculate next board
        MyMap.checkMap();

        // display next board
        MyMap.displayMap();
    }

    return a.exec();
}



