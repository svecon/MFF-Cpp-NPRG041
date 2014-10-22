
// std::unique_ptr(A) = make_unique<A>(...params...);
// ...make_shared<A>(...)

#include <iostream>
#include <fstream>

//std::istream
//std::ostream
//std::iostream

//iofstream
//ifstram
//ofstream
// ofstream.of("i.txt");

// cin, cout, cerr // standard opened streams

// count << "Message" << i << endl;
// cin >> i >> f;

// wcin, wcout, wcerr -- rozšíøení znakové sady na unikódovı stream (záleí na OS - 2/4 bajty)

class C {

public:


	int p1;
	int print(){ return 5; };


	friend std::ostream& operator>>(std::ostream& o, const C& c);

};

std::ostream& operator<<(std::ostream& o, const C& c){
	return o << c.p1;
	//o << c.print();
}

int main(int arc, char** argv){

	C c;
	std::cout << "Vypis C: " << c << std::endl;

	std::ofstream myfile("i.txt");
	myfile.close();

	return 0;
};

// MANIPULATORS
//count << hex << i;
//count << setn(4) << setfill('0') << i;

// getline(istream & i, string & to);

// {X} sto{X}(const string & s [, size_t *p [, int base]]);
