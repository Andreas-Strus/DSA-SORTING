#include "sort.hpp"

using namespace std;

int main()
{
//deklaracje wstêpne
	std::string p, p2;
	int lengh, LiczbaInstancji, IndexLiczby, NumerInstancji,Powtorzono, NumAlg, Ksztalt, PopKsztalt, Powtorzen, Pivot, i=1, j;
	char c;
	double SrCzas, SumaCzRozmiaru, SumaCzInst;
	bool Wszystkie=false, AllQsi=false;
//pobranie warunow analizy
	std::cout<<"podaj œcierzkê pliku instancji"<<std::endl;
	std::cin>>p;
	std::cout<<"podaj œcierzkê pliku wyjœciowego"<<std::endl;
	std::cin>>p2;
	std::cout<<"Wybierz stosowany algorytm:"<<std::endl<<"1. Insertion Sort"<<std::endl<<"2. Selsction Sort"<<std::endl<<"3. Quick Sort"<<std::endl<<"4. Heap Sort"<<std::endl<<"5. Quick Sort Iteacyjny"<<std::endl<<"6. 1-4"<<std::endl<<"7. Quick Sort Iteacyjny po wszystkich pivotach"<<std::endl;
	std::cin>>NumAlg;
	std::cout<<"Podaj liczbê powtórzeñ dla ka¿dej instancji"<<std::endl;
	std::cin>>Powtorzen;
	if (NumAlg == 5)
	{		
		std::cout<<"Wybierz ustawienie pivotu"<<std::endl<<"1. Prawy"<<std::endl<<"2. Lewy"<<std::endl<<"3. Œrodkowy"<<std::endl<<"4. Losowy"<<std::endl;
		std::cin>>Pivot;
	}
	if (NumAlg == 6)
	{
		Wszystkie = true;
		i=4;
	}
	if (NumAlg == 7)
	{
		AllQsi = true;
		NumAlg = 5;
		i=4;
	}
	for (j=0; j<i; j++)
	{
//otwarcie plików wejœcia i wyjscia
		std::fstream PlikIn, PlikOut, Pl;
		PlikIn.open(p.c_str(), std::ios::in);
		PlikOut.open(p2.c_str(), std::ios::app);
//Pobranie danych o pierwszej instancji
		PlikIn >> lengh >> LiczbaInstancji >> Ksztalt;
		PopKsztalt = 0;
		if (Wszystkie)
		{
			NumAlg = j + 1;
			PlikOut<<NumAlg<<std::endl;
		}
		if (AllQsi) 
		{
			Pivot = j + 1;
			PlikOut<<Pivot<<std::endl;
		}
		while (LiczbaInstancji != 0 || lengh != 0)		//Pêtla wykonawcza, powtarzana póki w pliku wejœcowym s¹ jakieœ instancje do pobrania
		{
			if (PopKsztalt != Ksztalt)					//Zapisanie zmiany kszta³tu rozk³adu danych nstancji
			{
				PlikOut<<Ksztalt<<std::endl;
				PopKsztalt = Ksztalt;
			}
			SrCzas=0;		
			int* TabGl = new int[lengh];				//Deklaracja tabel dla instancji
			int* TabPom = new int[lengh];
			SumaCzRozmiaru=0;
			for (NumerInstancji=0; NumerInstancji<LiczbaInstancji; NumerInstancji++) //Pêtla przechodz¹ca przez instancje o stalym rozmiarze i kszta³cie
			{
				for (IndexLiczby=0; IndexLiczby<lengh; IndexLiczby++) //Pêtla pobierania danych instancji do tabeli g³ownej
				{
					PlikIn>>TabGl[IndexLiczby];
				}
				SumaCzInst = 0;
				switch(NumAlg)
				{
					case 1:								//Wyo³anie IS
						for (Powtorzono=0; Powtorzono<Powtorzen; Powtorzono++)
						{
							reset_tab(TabGl, TabPom, lengh);
							SumaCzInst = SumaCzInst + inss(TabPom, lengh);
						}
						SumaCzRozmiaru=SumaCzRozmiaru + SumaCzInst/Powtorzono;
					break;
					case 2:								//Wywolanie SS
						for (Powtorzono=0; Powtorzono<Powtorzen; Powtorzono++)
						{
							reset_tab(TabGl, TabPom, lengh);
							SumaCzInst = SumaCzInst + sels(TabPom, lengh);
						}
						SumaCzRozmiaru=SumaCzRozmiaru + SumaCzInst/Powtorzono;
					break;
					case 3:								//Wywo³anie QS
						for (Powtorzono=0; Powtorzono<Powtorzen; Powtorzono++)
						{
							reset_tab(TabGl, TabPom, lengh);
							SumaCzInst = SumaCzInst + qs(TabPom, lengh);
						}
						SumaCzRozmiaru=SumaCzRozmiaru + SumaCzInst/Powtorzono;
					break;
					case 4:								//Wywo³anie HS
						for (Powtorzono=0; Powtorzono<Powtorzen; Powtorzono++)
						{	
							reset_tab(TabGl, TabPom, lengh);
							SumaCzInst = SumaCzInst + hs(TabPom, lengh);
						}
						SumaCzRozmiaru=SumaCzRozmiaru + SumaCzInst/Powtorzono;
					break;
					case 5:								//Wywo³anie QSIteracyjnego
						for (Powtorzono=0; Powtorzono<Powtorzen; Powtorzono++)
						{
							reset_tab(TabGl, TabPom, lengh);
							SumaCzInst = SumaCzInst + qsi(TabPom, lengh, Pivot);
						}					
						SumaCzRozmiaru=SumaCzRozmiaru + SumaCzInst/Powtorzono;
					break;
				}
			}
			SrCzas=SumaCzRozmiaru/LiczbaInstancji;
			PlikOut<<lengh<<"	"<<SrCzas<<std::endl;	//Zapis d³ugoœci instancji i œredniego czasu jej sortowania
			LiczbaInstancji = 0;
			lengh = 0;
			PlikIn>>lengh>>LiczbaInstancji>>Ksztalt;	//Pobranie danych o nastêpnej instancji
		}
		void close(void);
	}
	return 0;
}
