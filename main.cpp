#include <QCoreApplication>
#include <iostream>

#include <chrono>
#include <thread>

#include "boardelement.h"
#include "board.h"
#include "gameoflifemap.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // create an instance of GameOfLifeMap and set its dimensions to 30 rows and 50 columns
    GameOfLifeMap MyMap(30,50);

    // add gliders
    MyMap.addGlider({5,20});
    MyMap.addGlider({5,30});
    MyMap.addGlider({15,10});
    MyMap.addGlider({15,40});

    // add dakotas
    MyMap.addDakota({15,5});
    MyMap.addDakota({20,35});
    MyMap.addGlider({25,45});

    while(1)
    {
        // could clear console here, but it would be windows-only

        // display current board
        MyMap.displayMap();

        // calculate next board
        MyMap.updateMap();

        // time delay
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    return a.exec();
}



