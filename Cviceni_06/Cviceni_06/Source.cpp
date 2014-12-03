/*
*** ALGORITMY

=== nemodifikujici
for_each
count
count_if

min_element
max_element
find
find_if

equal

=== modifikujici
for_each ~~ for(auto && v : c)
		for_each lepsi, kdyz mam kousek kontejneru
		F for_each(begin, end, F f);
		funktor trida vs lambda
copy
copy_if
move
transform (!)
		void transform(begin, end, back_inserter(cd), F) kde cd je cilovy kontejner (zatim prazdny)

=== odstranujici
remove
remove_if
remove_copy 
		(uzitecny) vyrezu z jednoho, ale strkam je jinam
remove_copy_if

unique
		odstranuje duplikaty v rozsahu (odsune na konec!) ===> unique && remove
		vrati iterator na prvni, ktery neni unikatni

=== mutujici
reverse
rotate
shuffle

sort
		ocekava operator "<" definovany na typu kontejneru
stable_sort

=== numericke
binary_search
accumulate

*/


/*
OPERATORY

class C
{
public:
	C & operator=(const C& c){ ...; return *this; }
	C & operator+=(const C& c){ ...; return *this; }
private:
	int c_;
friend bool operator<(...);
}

ALE: binarni operatory uz nejsou memberi tridy, ale globalni funkce!!

		// pozor vraci hodnotu (reference nejde)
C operator+(const C & l, const C & r){ C c(l); *copy constructor* c += r; return c; }

bool operator<(const C & l, const C & r){ return l.c_ < r.c_; }

*/

/*
UKOL

vyplnit kontejner nejakymi duplicitnimi integery

= transform (int -> C) // back_inserter
= unique (nad C)
= sort (nad C)

*/


int main(int argc, char** argv)
{

}