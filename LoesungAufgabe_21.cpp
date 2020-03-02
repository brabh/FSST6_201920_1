
#include <iostream>
#include <fstream>
#include <string>
#include <boost/algorithm/string.hpp>
#include <vector>

using std::cout;
using std::string;
using std::ifstream;
using std::istream;
using std::ostream;

/*
** Aufgabe 21
**
** Fname	Vname	GebDatum	Gehalt	Plz
** string	string	YYYYMMTT	double	int
**
** Wir speichern ein excel file in obiger Auslegung als .csv file
** und lesen es mit C++ ein und geben den Inhalt am Bildschirm aus.
**
*/

class ma {

	string fName;
	string vName;
	int gebDatum;
	double gehalt;
	int plz;

public:
	friend istream& operator>> (istream& is, ma& dt);
	friend ostream& operator<< (ostream& os, ma& dt);

};

istream& operator>> (istream& is, ma& dt)
{
	std::vector<string> sv;
	string i;

	if (std::getline(is, i)) {
		boost::split(sv, i, boost::is_any_of(";")); // , boost::token_compress_on);
		dt.fName = sv[0];
		dt.vName = sv[1];
		dt.gebDatum = std::stoi(sv[2]);
		dt.gehalt = std::stod(sv[3]);
		dt.plz = std::stoi(sv[4]);
	}

	return is;
}

ostream& operator<< (ostream& os, ma& a) {

	return os << a.fName << " " << a.vName << " " << a.gebDatum <<
		" " << a.gehalt << " " << a.plz << std::endl;
}


int main() {

	std::ifstream fi("C:\\Users\\Hans Brabenetz\\Documents\\Book1.csv");

	ma m;
	std::vector<ma> vm;

	while (fi >> m)
		vm.push_back(m);

	for (auto a : vm)
		cout << a;

	return 0;
}


