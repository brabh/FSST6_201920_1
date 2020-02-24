
/*
 ** Aufgabe  16:
 ** kreieren sie in der Klasse N die funktion
 ** // Normalization function
 ** void N::norm(double& p_v_orig) {
 **                                  p_v_orig = (p_v_orig - A_min) * (new_A_max - new_A_min) / (A_max - A_min) + new_A_min;
 ** }
 ** und
 ** // Denormalization function
 ** double N::denorm(double& p_v_norm) {
 **                                    	return (p_v_norm - new_A_min) * (A_max - A_min) / (new_A_max - new_A_min) + A_min;
 ** }
 ** Erstellen Sie in main ein tuple
 ** normalization{ 1.0, 0.0, 1.0, 0.0 };
 ** und übergeben es mit dem Konstruktor an die Klasse N.
 ** Testen sie dann aus main, was die fuktionen norm und denorm der Klasse N tun, mit verschiedenen double Werten.
 */


#include <iostream>
#include <tuple>

using normalization = std::tuple<double, double, double, double>;

class N {
	double A_max, A_min, new_A_max, new_A_min;
public:
	N(normalization nP = { 1.0, 0.0, 1.0, 0.0 });
	void norm(double& p_v_orig);
	double denorm(double& p_v_norm);
};


N::N(normalization normParam) {

	auto [amax, amin, namax, namin] = normParam;

	A_max = amax;
	A_min = amin;
	new_A_max = namax;
	new_A_min = namin;

}

void N::norm(double& p_v_orig) {

	p_v_orig = (p_v_orig - A_min) * (new_A_max - new_A_min) / (A_max - A_min) + new_A_min;

}


double N::denorm(double& p_v_norm) {

	return (p_v_norm - new_A_min) * (A_max - A_min) / (new_A_max - new_A_min) + A_min;

}


int LA16_main() {

	normalization nor{ 100.0, -100.0, 1.0, 0.0 };

	N n { nor };

	double x = 50.0;
	n.norm(x);
	std::cout << x << std::endl;

	std::cout << n.denorm(x) << std::endl;

	return 0;
}
