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

    // create an instance of GameOfLifeMap
    GameOfLifeMap MyMap;

    // set its dimensions to 30 rows and 50 columns
    MyMap.setDimensions(30,50);

    // add glider
    MyMap.addGlider(5,20);
    MyMap.addGlider(5,30);
    MyMap.addGlider(15,10);
    MyMap.addGlider(15,40);

    // add dakota
    MyMap.addDakota(15,5);
    MyMap.addDakota(20,35);

    // display initial board
    MyMap.initMap();

    while(1)
    {
        // time delay
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        // calculate next board
        MyMap.checkMap();

        // display next board
        // could clear console here
        MyMap.displayMap();
    }

    return a.exec();
}



