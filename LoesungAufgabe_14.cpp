
/* 
** Aufgabe 14:
** Schreiben ie die definition einer funktion,
** deren deklaration lautet:
** void tanhSigmoid(double * p_val);
** und wenden sie diese zumindest einmal aus der main funktion an.
** Es soll dabei der übergebene Wert in den tanh umgewandelt werden.
** Machen sie sich gedanken über den Verlauf dieser Funktion, auf einem Blatt Papier
** oder in Excel oder als Graphik programmiert.
** Ist die Bezeichnung Sigmoid gerechtfertigt?
*/

#include <iostream>
#include <math.h>

void tanhSigmoid(double* p_val) { 

	*p_val = tanh(*p_val);

	return; //  0.0; //  *d_val;
}

int main() {

	for (double i = -3.5; i < 3.5; i += 0.1) {
		double v = i;
		tanhSigmoid( &v);
			std::cout << v << std::endl;
	}
		
	return 0;
}

