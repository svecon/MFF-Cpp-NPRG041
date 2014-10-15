#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char ** argv){

	//cout << "Hello, debile!" << endl;
	//cout << argc << endl;
	//cout << argv[0] << endl;

	vector<string> v;

	for (int i = 0; i < argc; i++)
		v.push_back(argv[i]);

	for (size_t i = 0; i < v.size(); i++)
		cout << v.at(i) << endl;

	for (auto const & s : v)
		cout << s << endl;

	for (auto c = v.cbegin(); c != v.end(); c++) // vector<string>::const_iterator
		cout << *c << endl;

	// ForEach je funkce -> potøebuje lambda výraz místo tìla


	return 0;
}