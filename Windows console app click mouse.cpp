#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

void help();
void klikacz();

void click(); // klika w aktualne polozenie myszki
int read_digit(); // Wczytuje liczbe z ekranu jezeli dane sa niepoprawne zwraca 0

int main() {

	cout << endl << endl << "          PROGRAM DO KLIKANIA MYSZKA NA ROZNE SPOSOBY I MIEJSCA" << endl << endl;

	help();

	string komenda;

	while (true)
	{
		cout << "-> ";
		cin >> komenda;
		cin.ignore();
		cin.clear();
		cin.sync();
		
		if (komenda == "exit")
			break;
		else if (komenda == "help")
			help();
		else if (komenda == "clear")
			system("cls");
		else if (komenda == "klikacz")
			klikacz();
		else
			cout << "Nie znana komenda: " << komenda << endl;
	}

	return 0;
}

void help() {
	cout << "-------------------------------------\n";
	cout << "help    - wyswietla pomoc" << endl;
	cout << "exit    - konczy program" << endl;
	cout << "clear   - czysci ekran" << endl;
	cout << "klikacz - modul klikania mysza" << endl;
	cout << "-------------------------------------\n";
}

int read_digit() {
	string data;
	cin >> data;
	cin.clear();
	cin.ignore();
	cin.sync();
	if (data.length() <= 0)
		return 0;
	for(int x=0;x<data.length();x++)
		if (!((data[x] == '0') || (data[x] == '1') || (data[x] == '2') || (data[x] == '3') || (data[x] == '4') || (data[x] == '5')
			|| (data[x] == '6') || (data[x] == '7') || (data[x] == '8') || (data[x] == '9')))
			return 0;
	int result = stoi(data);
	return result;
}

void klikacz() {
	cout << endl << "Modul klika z ustalonym intervalem w aktualne polozenie myszki. Robi to tyle razy ile zadeklarujemy" << endl << endl;

	cout << "Co ile klikniecie (milisekundy 200-10 000): ";
	int czas = read_digit();

	if ((czas < 200) || (czas > 10000))
	{
		cout << "Nie poporawna wartosc\n";
		return;
	}
	czas = czas;

	cout << "\n-Aby zakonczyc wprowadz inna wartosc niz liczba\n\n";

	cout << "Ile razy kliknac: ";

	int licznik = 1;

	while (licznik = read_digit())
	{
		for (int x = 1;x <= licznik;x++)
		{
			click();
			cout << "||" << x << "/" << licznik << char(13);
			Sleep(czas);
		}
		cout << "Ile razy kliknac: ";
	}
	cout << "[KONIEC MODULU KLIKACZ]" << endl << endl;
}


void click() {
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}




