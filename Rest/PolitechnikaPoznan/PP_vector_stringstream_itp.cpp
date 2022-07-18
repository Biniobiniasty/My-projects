#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <list>
#include <map>


using namespace std;

void Using_vector();
void Using_string();
void Using_list();
void Using_map();
void Lambda();
void Read_File_CSV();

int main() {

	cout << "Using vector:" << endl;
	Using_vector();
	cout << endl << endl;

	cout << "Using string: " << endl;
	Using_string();
	cout << endl << endl;

	cout << "Using list: " << endl;
	Using_list();
	cout << endl << endl;

	cout << "Using map: " << endl;
	Using_map();
	cout << endl << endl;

	Lambda();

	Read_File_CSV();

	return 0;
}

void Using_map() {

	map<string, int> cyferki;
	cyferki["jeden"] = 1;
	cyferki["dwa"] = 2;
	cyferki["trzy"] = 3;

	cout << cyferki["dwa"] << endl; // wyswietli 2

	cout << cyferki.size() << endl; // Wyswietli dlugosc czyli 3


	map<int, int> mapa;
	int liczba;

	cout << "Podaj liczby bez duplikatow\n";

	while (cin >> liczba)
	{
		int powt = ++mapa[liczba];
		if (powt > 1)
			cout << "Podales " << liczba << " juz " << powt << " razy!\n";
	}
}

void Using_list() {
	// Dziala podobnie jak vector z paroma roznicami
}

void Lambda() {
	// [<capture>](<argument>) -> <return_type> { <body> }

		//	<capture> --lista zmiennych z zasięgu lokalnego / globalnego jakie mają być przekazane(przechwycone) do wyrażenia lambda.
	//	<arguments> --lista argumentów wyrażenia lambda(funkcji anonimowej), analogiczna jak przy klasycznych funkcjach,
	//	<return_type> --opcjonalnie zdefiniowany typ wartości zwracanej z wyrażenia.Część -> <return_type> jest opcjonalna.
	//	<body> --ciało funkcji, sekwencja instrukcji jakie mają być wykonane podczas wywołania lambdy.

	int x = 5;
	int y = 10;

	auto sum = [](int var1, int var2) { return var1 + var2; };

	int result = sum(x, y);
	cout << x << " + " << y << " = " << result << endl;
}

void Read_File_CSV() {

	// Wczytujemy dane z pliku CSV pierwsza linia to naglowek reszta lini jako dane oddzielone przecinkami zakladamy 3 kolumny

	struct Data {
		string one;
		string two;
		string three;
		double digit;
	};

	fstream file("C:\\Users\\Rambo\\Desktop\\Plik.txt", fstream::in);
	vector<Data> Data_of_File; // Vector z struktorami danych (do wczytania z pliku)

	if (file.is_open()) {
		string line;
		getline(file, line); // pierwsza linijka wczytana z naglowkiem (pomijamy ja)

		while (getline(file, line)) // Wczytujemy dane az do skonczenia sie pliku
		{
			stringstream str(line); // Tworzymy strumien ktorego zrodlem jest wczytana linia

			Data temp; // tymczasowa struktora "Data" do wczytania danych

			getline(str, temp.one, ','); // Funkcja getline wczytuje dane z strumienia do wskazanego miejsca az do podanego znaku
			// nastepnie w strumieniu przesuwa wskaznik odczytania strumienia
			getline(str, temp.two, ',');
			getline(str, temp.three, ',');

			string Dig;
			getline(str, Dig, ',');
			temp.digit = stod(Dig); // funkcja stod konwertuje stringa na typ double kropka jako separator czesci dziesietnej

			Data_of_File.emplace_back(temp); // Dodaje odczytana struktore do vectora
		}
	}
	file.close();

	for (Data& x : Data_of_File) {
		cout << "|" << x.one << " | " << x.two << " | " << x.three << "|" << x.digit << "|\n";
	}

}

void Using_string() {

	string text = "ala ma kota";

	size_t position = text.find('a'); // Zwroci pierwsze wystapienie litery a w ciagu znakow
	size_t position2 = text.find('a', position + 1); // Zwroci kolejne wystapienie litery a (drugi argument pozycja startu wyszukiwania)

	// Jezeli nie znajdzie znaku zwraca wartosc: string::npos


	// [ZNALEZIENIE WSZYSTKICH POZYCJI W TEKSCIE]
	position = text.find('a');
	do
	{
		cout << position << endl;
		position++;
	} while ((position = text.find('a', position + 1)) != string::npos);


	// Funkcja substr zwraca fragment tekstu podajemy pozycje i dlugosc tekstu
	string text2 = text.substr(2, 3); // zwroci "a m"
	cout << text2 << endl;

	text2 = text.substr(7); // Od pozycji 7 do konca
	cout << text2 << endl;  // Zwroci "kota"

	// Funkcja wycina wskazany fragment tekstu i zastepuje go innym

	text = "0123456789";
	cout << "Orginal: " << text << endl;
	text.replace(3, 0, "Dupa"); // Wstawi "Dupa" miedzy 3 a 4 znak wynik "012Dupa3456789"
	cout << text << endl;

	text = "0123456789";
	cout << "Orginal: " << text << endl;
	text.replace(3, 5, "Dupa"); // Za 3cim znakiem wstawi tekst i obetnie piec znakow dalszego tekstu wynik "012Dupa89"
	cout << text << endl;

	text = "0123456789";
	cout << "Orginal: " << text << endl;
	text.replace(text.length(), 0, 3, '!'); // Wstawi na koncu trzy wykrzykniki Wynik: "0123456789!!!"
	cout << text << endl;

}

void Using_vector() {


	vector<double> My_vector = { 4, 3.14, 10, 25 }; // deklaracja wektora

	cout << "Element z indeksem 2: " << My_vector[2] << endl; // Wyswietlanie vectora. Wyswietli: 10

	My_vector[2] = 11; // modyfikacja elementu

	// [PETLA PO ELEMENTACH VECTORA]
	for (int x = 0;x < My_vector.size();x++)
		My_vector[x] = My_vector[x];

	// [PETLA SKROCONA]
	for (double& x : My_vector) {
		cout << x << endl;
	};

	// [PETLA Z ITERATOREM]
	for (vector<double>::iterator it = My_vector.begin(); it != My_vector.end(); it++)
		cout << *it << endl;

	My_vector.emplace_back(23.4); // dodaje wartosc na koncu vectora
	My_vector.resize(20);         // Zmienia wielkosc vectora na podana ilosc elementy sa rowne 0
	My_vector.clear();            // Usuwa wszystkie elementy i zmienia rozmiar na 0



}
