#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <memory>

// my objects
#include "Circle.h"
#include "Rectangle.h"
#include "Shape.h"
#include "Triangle.h"

#include <limits>

using namespace std;

float parseNextFloat(string& line){
	try {
		float a = stof(line.substr(line.find_first_of('=') + 1, line.find_first_of(',') - line.find_first_of('=') - 1));
		line = line.substr(line.find_first_of(',') + 1);
		return a;
	}
	catch (invalid_argument){
		cout << "There was an error parsing your input." << endl;
	}
	return numeric_limits<float>::quiet_NaN();
}

std::ostream& operator<<(std::ostream& o, Shape* s){
	return o << s->toString();
}

int main(int argc, char ** argv) {

	string line;
	ifstream myfile(argv[1]);

	vector<unique_ptr<Shape>> list;

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			float a, b, c;
			switch (line[0])
			{
			case 'K':
				a = parseNextFloat(line);
				list.push_back(unique_ptr<Shape>(new Circle(a)));
				break;
			case 'T':
				a = parseNextFloat(line);
				b = parseNextFloat(line);
				c = parseNextFloat(line);
				list.push_back(unique_ptr<Shape>(new Triangle(a, b, c)));
				break;
			case 'O':
				a = parseNextFloat(line);
				b = parseNextFloat(line);
				list.push_back(unique_ptr<Shape>(new Rectangle(a, b)));
				break;
			default:
				cout << "Unrecognized object." << endl;
				continue;
				break;
			}
		}
		myfile.close();

		for (const auto & o : list){
			cout << o.get() << endl;
		}
	}
	else cout << "The file " << argv[1] << " couldnt be opened.";
}
