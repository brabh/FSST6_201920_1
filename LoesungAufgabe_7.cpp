#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class M {
public:
	int mNum;
	string vName;
	string nName;
	int gebDatum;
	double gehalt; 
	int eintrDatum;
};


int main() {

	vector<M> vM;

	M m1{ 1,"Franz", "Mueller", 19861221, 3800.75, 20190601 };

	vM.push_back(m1);
	vM.push_back(M { 2,"Herbert", "Meier", 19851028, 3500.25, 20190701 });
	vM.push_back(M { 3,"Luise", "Schneider", 19871028, 3400.50, 20170101 });

	for (auto e : vM) 
		cout << typeid(e).name() << " " << e.vName << endl;
	
	cout << "vM.size() = " << vM.size() << endl;
	
	double gehaltMax = 0.0;
	string vNameGehaltMax;

	for (int n = 0; n < (int) vM.size(); ++n)
		if (vM[n].gehalt > gehaltMax) {
			gehaltMax = vM[n].gehalt;
			vNameGehaltMax = vM[n].vName;
		}
	cout << "gehaltMax = " << gehaltMax << " vName " << vNameGehaltMax << endl;



	return 0;
}



