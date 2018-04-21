//instances generator for sorting algorithms
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <fstream>
#include <math.h>
using namespace std;
int main() 
{
	int number, lengh, lmin, lmax, lstep, lnum, i, j, k, b, a, e;
	unsigned int c, d;
	std::string p;
	std::cout<<"podaj nazwê pliku"<<std::endl;
	std::cin>>p;
	std::fstream plik;
	plik.open( p.c_str(), std::ios::app );
	srand(time(NULL));
	std::cout<<"Podaj numer interesujacego Ciê kszta³tu instancji:"<<std::endl<<"1 . Losowa."<<std::endl<<"2 . Rosn¹ca"<<std::endl<<"3. Malej¹ca"<<std::endl<<"4. 11111"<<std::endl<<"5. V-kszta³tna"<<std::endl<<"6. A kszta³tna"<<std::endl;
	std::cin>>a;
	std::cout<<"Podaj d³ugoœæ najkrótszej instancji"<<std::endl;
	std::cin>>lmin;	
	std::cout<<"Podaj wzrost d³ugoœci intancji"<<std::endl;
	std::cin>>lstep;
	std::cout<<"Podaj d³ugoœæ masymaln¹ instancji"<<std::endl;
	std::cin>>lmax;
	std::cout<<"podaj liczbê instancji"<<std::endl;
	std::cin>>number;
	lnum = lmax/lstep;	
	for (k=0; k<=lnum; k++)
	{
		lengh = lmin + (k * lstep);	
		plik<<lengh<<" "<<number<<" "<<a<<std::endl;
		c = log10(lengh) * 1000;
		switch (a)
		{
			case 1:
				for (j=0; j<number; j++)
				{
					b=std::rand();
					for(i=0; i<lengh; i++)
					{
						b = std::rand();
						plik<<b;
						plik<<" ";
					}
					plik<<std::endl;
				}
				plik<<std::endl;
			break;
			case 2:
				for (j=0; j<number; j++)
				{
					b=std::rand();
					for(i=0; i<lengh; i++)
					{
						d = std::rand() % c;
						b += d;
						plik<<b;
						plik<<" ";
					}
					plik<<std::endl;
				}
				plik<<std::endl;
			break;
			case 3:
				for (j=0; j<number; j++)
				{
					b=std::rand();
					for(i=0; i<lengh; i++)
					{
						d = std::rand() % c;
						b -= d;
						plik<<b;
						plik<<" ";
					}
					plik<<std::endl;
				}	
				plik<<std::endl;
			break;				
			case 4:
				for (j=0; j<number; j++)
				{
					for(i=0; i<lengh; i++)
					{
						plik<<"1 ";
					}
					plik<<std::endl;
				}
				plik<<std::endl;
			break;	
			case 5:
				for (j=0; j<number; j++)
				{
					b=std::rand();
					for(i=0; i<lengh; i++)
					{
						d = std::rand() % c;
						if (i <= (lengh/2 + lengh % 2))
						{
							b -= d;
						}
						else
						{
							b += d;
						}
						plik<<b;
						plik<<" ";
					}
					plik<<std::endl;
				}
				plik<<std::endl;
			break;
			case 6:
				for (j=0; j<number; j++)
				{
					b=std::rand();
					for(i=0; i<lengh; i++)
						{
							d = std::rand() % c;
							if (i >= (lengh / 2 + lengh % 2))
							{
								b -= d;
							}
							else
							{
							b += d;
						}
						plik<<b;
						plik<<" ";
					}
					plik<<std::endl;
				}
				plik<<std::endl;
			break;			
		}
	}
	void close(void);
	return 0;
}
