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

bool BoardElement::getAlive() const
{
    return alive;
}

char BoardElement::getSign() const
{
    return sign;
}
