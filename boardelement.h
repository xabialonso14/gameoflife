#ifndef BOARDELEMENT_H
#define BOARDELEMENT_H

class BoardElement
{
    private:
        bool alive = false;
        char sign = '|';

    public:
        BoardElement();

        void setAlive(bool alive);
        void setSign(char sign);

        const bool getAlive();
        const char getSign();
};

#endif // BOARDELEMENT_H
