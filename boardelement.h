#ifndef BOARDELEMENT_H
#define BOARDELEMENT_H

class BoardElement
{
    public:
        BoardElement();

        int numberOfNeighbours = 0;

        bool alive = false;
        bool nextAlive = false;

        char sign = '|';
        char nextSign = '|';
};

#endif // BOARDELEMENT_H
