#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void showTab(vector<double>*);					 // FUNKCJA WYSWIETLAJACA ELEMENTY VECTORA NA EKRANIE
void randomTab(unsigned int, vector<double>*);   // FUNKCJA PRZYPISUJACA DO VEKTORA PSEUDOLOSOWE LICZBY OD 1 DO 100 (Parametr int dlugosc jaka chcemy uzyskac)
void sortTab(vector<double>*);					 // FUNKCJA SORTUJACA PODANY VECTOR

int main() {

	// Inicjacja programu

	srand(time(NULL));
	vector<double> tab;

	// Wylosowanie liczb i wyswietlenie na ekranie
	randomTab(15, &tab);
	showTab(&tab);

	// Posortowanie liczb i wyswietlenie na ekranie
	sortTab(&tab);
	showTab(&tab);
	
	//Koniec programu
	return 0;
}

void showTab(vector<double>* tab) {

	bool pierwsza = true;

	cout << "VECTOR = {";
	
	if (tab->empty())
		cout << (char)232;	// 232 - znak zbioru pustego
	else
		for (int x : *tab)
			if (!pierwsza)
				cout << ", " << x;
			else
			{
				cout << x;			//WYSWIETLI PIERWSZA WARTOSC BEZ PRZECINKA Z PRZODU
				pierwsza = false;
			}

	cout << "}" << endl;

}
void randomTab(unsigned int Length, vector<double>* tab) {

	if (Length > 0)
		for (int x = 0;x < Length;x++)
			tab->push_back((rand() % 99) + 1);

}
void sortTab(vector<double>* tab) {

	int x = tab->size(); // x - rozmiar vectora
	int auxiliary;		// zmienna pomocnicza
	bool exchange;

	do {

		exchange = false;

		for (int y = 0;y < x-1;y++)
			if ((*tab)[y] > (*tab)[y + 1])
			{
				exchange = true;
				auxiliary = (*tab)[y];
				(*tab)[y] = (*tab)[y + 1];
				(*tab)[y + 1] = auxiliary;
			}
		x--;

	} while (exchange);

}
