/* 
KONTEJNERY - asociativni / obycejne

//// Zakladni kontejnery
vector - pro pridavani dat na konec, data jsou v pameti za sebou! obcas se musi prealokovat
deque - pridavani a ubirani na konec i zacatek
list - obousmerny spojak - vkladani a odebirani z libovolne pozice - iteratory zustanou platne i pri modifikaci
// c++11
array = vektor konstatni velikosti
forward_list - jednosmerny spojak (uspornejsi)
// adaptery
stack


// metody
bool empty() const;
size_t size() const; - pocet prvku

push_back(T i); - prida na konec
void pop_back();

push_front(T i); - prida na zacatek
void push_back();

insert
erase

// modifiujici iteratory
begin() - iterator
end() - iterator

*it = 5*5;

// konstatni iteratory - na cteni
cbegin()
cend()

// ve.begin() vs begin(ve)

//// Asociativni kontejnery
- vkladani a hledani je logaritmicke
- jsou setrideny podle "<" na klici => klic musi mit deklarovany "<"
- od begin() k end() je v setridenem poradi

// unikatni klice
set - mnozina dat (snadne hledani podle klice)
map - dvojice klic/hodnota

// neunikatni klice
multiset
multimap

// c++11
- hashovana verze - vkladani a hledani je konstatni
- nema setridene prvky

unordered_map
unordered_set
unordered_multimap
unordered_multiset

// funkce (na vsech asoc)

bool insert(T i)
bool insert(std::pair<K,V> p) --- make_pair(K,V)

it find(K k) -- kdyz nic nenajde, vrati iterator end()

// multi verze
lower_bound(K k)
upper_bound(K k)
*/

/*
Telefonni seznam

{
   JMENO
   PRIJMENI
   ADRESA
   TELEFON
}

chci rychle hledat podle prijmeni a telefonu
prijmeni nemusi byt unique

1) find
2) add
3) del
4) save

*/


#include <string>
#include <regex>
#include <iostream>
#include <fstream>

int main(int argc, char** args)
{
	std::string str = "Mem(100)=120";
	std::regex regex("^Mem\\([0-9]+\\)=[0-9]+$");
	std::smatch m;

	std::cout << std::regex_match(str, regex) << std::endl;
	std::cout << std::regex_match(str, m, regex) << std::endl;


	for (auto result : m) {
		std::cout << result << std::endl;
	}
}