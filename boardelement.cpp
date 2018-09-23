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

const bool BoardElement::getAlive()
{
    return alive;
}

const char BoardElement::getSign()
{
    return sign;
}
