
/* Aufgabe 17:
** Übergib eine beliebige, variable Anzahl int als Parameter an den Konstruktor einer Klasse N
** und drucke diese vomm Konstruktor in der Konsole aus.
** Verwende dazu eine std::initializer_list
*/

using topologie = std::initializer_list<int>;

class N {
	const topologie& myTop; 
public:
	N(const topologie& t);

};

N::N(const topologie& top) : myTop{ top } {

	using std::cout, std::endl;

	cout << "topologie ";
	for (auto e : top) // or myTop
		cout << e << " ";
	cout << endl;

	int Nlay = static_cast<int> (top.size()); // (int) // or myTop

	cout << "Nlayer = " << Nlay << endl;

}

int main() {

	topologie top{ 2,3,1 };
	N n2(top);

	N n { topologie { 2, 3, 1, 5, 10, 20, 30 } }; // benötigt const 

	return 0;
