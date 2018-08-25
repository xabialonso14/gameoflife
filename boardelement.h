#ifndef BOARDELEMENT_H
#define BOARDELEMENT_H

class BoardElement
{
    public:
        BoardElement();

		// komentarz: czemu board element wie cokolwiek o swoich sasiadach?
        int numberOfNeighbours = 0;

		// komentarz: brak enkapsulacji
        bool alive = false;
        bool nextAlive = false;

        char sign = '|';

		// komentarz: next*? przechowywanie przyszłego stanu w tym obiekcie
		// jest nadmiarowe -> single object responsibility
        char nextSign = '|';
};

#endif // BOARDELEMENT_H
