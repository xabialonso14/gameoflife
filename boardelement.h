#ifndef BOARDELEMENT_H
#define BOARDELEMENT_H

#include "mysharedlib_global.h"

class MYSHAREDLIB_EXPORT BoardElement
{
    private:
        bool alive = false;
        char sign = '|';

    public:
        BoardElement();

        void setAlive(bool alive);
        void setSign(char sign);

        bool getAlive() const;
        char getSign() const;
};

#endif // BOARDELEMENT_H
