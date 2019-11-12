#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>

//
// Aufgaben 3.2
//

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

int L3_2main() {
	vector<vector<string>> inputList;

	std::ifstream fi("C:\\TGM201920\\horsesDNA\\input_tree.csv");
	std::string line;

	while (std::getline(fi, line)) {

		std::vector<string> sV;
		boost::split(sV, line, boost::is_any_of(";"), boost::token_compress_on);

		inputList.push_back(sV);
	}

	for(int n = 0; n < inputList.size(); ++n) // works
		cout << inputList[n][0] << " " << inputList[n][1] << " " << inputList[n][2] << endl;

	return 0;


	getchar();
	return 0;
}
