#include <vector>

using namespace std;

// VYTVARENI KONTEJNERU

class C {
public:
	typedef vector<int> cont_type;
	typedef cont_type::size_type size_type;
	typedef cont_type::difference_type difference_type;
	typedef cont_type::value_type value_type; // typ polozky vektoru

	typedef cont_type::reference reference;
	typedef cont_type::const_reference const_reference;

	typedef cont_type::iterator iterator;
	typedef cont_type::const_iterator const_iterator;

	typedef cont_type::pointer;
	typedef cont_type::const_pointer const_pointer;

	bool empty() const { return v_.empty(); }
	size_t size() const;
	
	iterator begin() { return v_.begin(); }
	iterator end() { return v_.end(); }

	const_iterator begin() const { return v_.cbegin(); }
	const_iterator end() const { return v_.cend(); }

	const_iterator cbegin() { return v_.cbegin(); }
	const_iterator cend() { return v_.cend(); }


private:
	cont_type v_;
};



/* FORWARD ITERATOR

*it				// reference na objekt
it->member		// pointer na typ kontejneru
++it
it++
==
!=
=

*/

/* BI-DIRECTIONAL ITERATOR

[FORWARD]
--it
it--
*/

/* RANDOM ACCESS ITERATOR

it[n]
+=
-=
it+n
n+it
it-n
it1-it
<
>
<=
>=

*/

/* TYPY PRO VLASTNI ITERATORY

iterator_category [forward_iterator]_teg
value type
difference_type
pointer			D*
reference		D&

*/

/* Ukol: implementovat vlastni vektor integeru

defaultni konstruktor
push_back
[]

*/