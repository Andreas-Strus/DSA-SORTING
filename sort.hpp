//Plik: sort.hpp
#ifndef sort_hpp
#define sort_hpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <fstream>
#include <math.h>

time_t inss (int tab[], int lengh);
time_t sels (int tab[], int lengh);
void zamien (int tab[], int a, int b);
int part (int tab[], int first, int last, int p=3);
int q (int tab[], int first, int last);
time_t qs (int tab[], int lengh);
void hippy (int tab[], int a, int lengh);
void buildheap (int tab[], int lengh);
time_t hs (int tab[],int lengh);
time_t qsi (int tab[], int lengh, int piv);
void reset_tab (int tab[],int t2[], int lengh);
void print_tab (int tab[], int lengh);
class stos
{
	private: int *S;
	private: unsigned int Size, MaxSize;
	private:
		void Resize();
	public:
		void dodaj(int a);
		int pobierz();
		void print();
		bool pusty();
		stos();
};





#endif
