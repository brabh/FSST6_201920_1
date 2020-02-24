
/* Aufgabe 15:
** Schreiben sie die definition einer funktion,
** deren deklaration lautet:
** double derivative_tanhSigmoid(double * p_val);
** und wenden sie diese zumindest einmal aus der main funktion an.
** Es soll dabei 1.0 - dem Quadrat des übergebenen Wertes retour gegeben werden.
*/

#include <iostream>
#include <math.h>

double derivative_tanhSigmoid(double* p_val) {

// output is the first derivative but calculated from y and not from x, 
// y = f(x) -> instead of y' = f'(x) here y' = f'(y) 
// since we are moving backwards and what we have is y!

	return (1.0 - *p_val * *p_val);
}


int main() {

	for (double i = -1.0; i < 1.0; i += 0.1) {
		double v = derivative_tanhSigmoid(&i);
		// gives 0...1...0
		std::cout << v << std::endl;
	}

	return 0;
}

