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

        bool getAlive();
        char getSign();

		// komentarz: czemu board element wie cokolwiek o swoich sasiadach?
        // pytanie: jak to rozwiazac?
        int numberOfNeighbours = 0;

};

#endif // BOARDELEMENT_H
