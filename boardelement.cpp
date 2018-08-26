#include "boardelement.h"

BoardElement::BoardElement()
{

}

void BoardElement::setAlive(bool alive)
{
    this->alive = alive;
}

void BoardElement::setSign(char sign)
{
    this->sign = sign;
}

bool BoardElement::getAlive()
{
    return alive;
}

char BoardElement::getSign()
{
    return sign;
}
