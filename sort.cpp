//Plik: sort.cpp

#include <windows.h>
#include "sort.hpp"



time_t inss (int tab[], int lengh)
// InsertsionSort
{
	using namespace std;
		int a, b, key;
	time_t start, stop, tim;
	start = clock() ;
	for (b=1; b < lengh; b++)
	{
		key = tab[b];
		a = b - 1;
		while (a > -1 && tab[a] > key)
		{
			tab[a + 1] = tab[a];
			a = a - 1;
		}
		tab[a + 1] = key;
	}
	stop = clock();
	tim = (stop - start);
	return tim;
}

time_t sels (int tab[], int lengh)
//SelectionSort
{
	using namespace std;
	int a, b, max, sel;
	time_t start, stop, tim;
	start = clock() ;
	for (b=lengh - 1; b > 0; b--)
	{
		max=b;
		for (a=b - 1; a > -1; a--)
		{
			if (tab[a] > tab[max])
			{
				max=a;
			}
		}
		sel=tab[max];
		tab[max]=tab[b];
		tab[b]=sel;
	}
	stop = clock();
	tim = (stop - start);
	return tim;
}

void zamien (int tab[], int a, int b)
{
	int c;
	c=tab[a];
	tab[a]=tab[b];
	tab[b]=c;
}

int part (int tab[], int first, int last, int p)
//Partition
{
	srand(time(NULL));
	int a, b, c, piv;
	switch (p)
	{
		case 1:
			piv=last;
		break;
		case 2:
			piv=first;
		break;
		case 4:
			piv=(std::rand() % (last - first)) + first;
		break;		
		case 3:
			piv=(first+last)/2;
		break;
	}
	a=first;
	zamien(tab, piv, last);
	b= first;
	for (a = first; a < last; a++)
	{
		if (tab[a]<tab[last])
		{
			zamien(tab, a, b);
			b++;
		}
	}
	zamien (tab, b, last);
	return b;
}
/*	a=first;
	b=last;
	while (true)
	{
		while (tab[b]>piv)
		{
			--b;
		}
		while (tab[a]<piv)
		{
			++a;
		}
		if (a<b)
		{
			c=tab[a];
			tab[a]=tab[b];
			tab[b]=c;
			a++;
			b--;
		}
		else
		{
			return b;
		}
	}
	return 0;
}*/


int q (int tab[], int first, int last)
//QuickSort
{
	int sep;
	if (first < last)
	{
		sep = part(tab, first, last);
		q(tab, first, sep);
		sep += 1;
		q(tab, sep, last);
	}
}

	
time_t qs (int tab[], int lengh)
//QuickSorrt-MAIN
{
	time_t start, stop, tim;
	start = clock() ;
	q(tab, 0, lengh - 1), lengh;
	stop = clock();
	tim = (stop - start);
	return tim;
}

void hippy (int tab[], int a, int lengh)
//Hipyfy
{
	int l, r, lar;
	l = a * 2;
	r = a * 2 + 1;
	if (l <= lengh && tab[l] > tab[a])
	lar = l;
	else
	lar = a;
	if (r <= lengh && tab[r] > tab[lar])
	lar = r;
	if (lar != a)
	{
		l = tab[a];
		tab[a] = tab[lar];
		tab[lar] = l;
		hippy(tab, lar, lengh);
	} 
}

void buildheap (int tab[], int lengh)
//BuildHeap
{
	int a;
	for (a = lengh/2; a >= 0; a --)
	{
		hippy(tab, a, lengh);
	}
}

time_t hs (int tab[],int lengh)
//HeapSort
{
	int a, b;
	time_t start, stop, tim;
	start = clock();
	buildheap(tab, lengh);
	for (a = lengh; a>=1; a--)
	{
		tab[a] = b;
		tab[a] = tab[1];
		tab[1] = b;
		lengh -= 1;
		hippy(tab, 1, lengh);
	}
	stop = clock();
	tim = (stop - start);
	return tim;	
}

time_t qsi (int tab[], int lengh, int piv)
{
	int last=lengh - 1, first = 0, q=0;
	time_t start, stop, tim;
	start = clock();
	Sleep(1);
	stos stos;
	Sleep(1);
	while (first<last || !stos.pusty())
	{
			if(first<last)
			{
				q=part(tab, first, last, piv);
				stos.dodaj(last);
				last = q - 1;
			}
			else
			{
				first = last + 2;
				last = stos.pobierz();
				
			}
		}	
	stop = clock();
	tim = (stop - start);
	return tim;
}

void reset_tab (int tab[],int t2[], int lengh)
//Reset tabeli pomocniczej
{
	memcpy(t2, tab, lengh * sizeof(int));
}
void print_tab (int tab[], int lengh)
{
	int i=0;
	for (i = 0; i<lengh; i++)
	{
		std::cout<<tab[i]<<"	";
	}
	std::cout<<std::endl<<std::endl;
}

void stos::Resize()  
// zmienia maksymalny rozmiar stosu
{
	MaxSize *= 10;
	int *Temp = new int[MaxSize]; 	
	for( unsigned int i = 0; i < Size; ++i ) Temp[i] = S[i];
		S = Temp;
	//delete[] Temp;
}
 
void stos::dodaj( int a ) 
// dodaje do stosu
{
	if( Size == MaxSize ) Resize();
	S[Size] = a;
	++Size;
}
 
int stos::pobierz()  
// pobiera ze stosu
{
	 --Size;
	 return S[Size];
}

void stos::print()
{
	for(int x=0; x<Size; x++) std::cout<<x<<"	"<<S[x]<<std::endl;
}

bool stos::pusty()    
// Sprawdza czy stos zawiera jakieœ elementy
{
	if(Size == 0 ) return true;
	else return false;
}

stos::stos()     
	// generator stosu
{
	MaxSize = 1;
	Size = 0;
	Resize();
}
