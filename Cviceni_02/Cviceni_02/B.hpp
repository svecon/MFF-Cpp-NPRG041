// DYNAMICKE ROZHRANI
// potomci by meli jenom byt vice specifictejsi
// ale musi mit stejne rozhrani jako otec!!!
// nesmi je rozsirovat dalsi interface!

#ifndef HEADER_B_HPP
#define HEADER_B_HPP

#include "A.hpp"

class B : public A { // B ma vsechno, co A, krome konstruktoru
	
	virtual int f(int i);

	//A* pa = &b;
	//pa->f(1); ---- > B::f

	//B b;
	//A& a = b;
	//a.f(1); ----> B::f

// NVI !!!
// vsechny public funkce NEJSOU virtualni
// vytvori se nova virtualni PRIVATE metoda

};

#endif
