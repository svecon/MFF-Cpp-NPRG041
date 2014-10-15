#ifndef HEADER_A_HPP
#define HEADER_A_HPP

class A {
public:
	int pricti(int i);

	A() :cislo_(0){} // inicializace

	A(); // KONSTRUKTOR SE VOLA PRI DEKLACI: "A a;" **automaticky
	A(int i, float f);

	explicit A(int i); // explicit zakazuje konverzi (viz fce sezer)
	// void sezer(A a);
	// sezer(1); ---- > sezer(A(1));

	A(const A& a){ cislo_ = a.cislo_; } // copy constructor **automaticky
	A&operator=(const A& a){ cislo_ = a.cislo_; } // copy assignment constructor **automaticky

	// zakazat kopii objektu
	A(const A& a) = delete;
	A&operator=(const A& a) = delete;

	// move constructory si prekladac nevymsli - zbytek jo
	A(A&&a); // move constructor
	A&&operator=(A&&a); // move assignment constructor

	~A(); // destruktor (bezparametricky!) - nesmi vyvolat vyjimku
	// automaticky se vygeneruje destruktor, ktery nici datove polozky tridy

	virtual ~A(){} // MUSI EXISTOVAT VIRTUALNI DESTRUKTOR, KVULI DEDENI
	// jinak by se nedestruktovali privatni polozky syna
	virtual int f(int i);

	void sezer(A && a); // move semantika - vykradani (temporary objects)


protected:

private:
	int cislo_; // datovy member tridy ma podrtrzitko na konci (konvence)

	virtual int f_int_(int i) = 0; /// abstraktni metoda!!!
};


#endif