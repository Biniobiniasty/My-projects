#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

struct okno {
	HWND uchwyt_okna;
	string nazwa_okna;

	void wprowadz_nazwe(string data) {

		string result = data;

		if (data.length() > 32)
			result = data.substr(0, 32);
		if (data.length() < 32)
		{
			for (int x = data.length();x < 32;x++)
				result.append(" ");
		}

		this->nazwa_okna = result;
	}
};

void help();
void klikacz();
void klikacz_gwiazda();
void set_okno();
void click_blick();

void click(); // klika w aktualne polozenie myszki
int read_digit(); // Wczytuje liczbe z ekranu jezeli dane sa niepoprawne zwraca 0

okno okienko;

int main() {

	okienko.wprowadz_nazwe("Brak okna - ustaw - kommand okno");
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
		else if (komenda == "klikacz*")
			klikacz_gwiazda();
		else if (komenda == "okno")
			set_okno();
		else if (komenda == "click_blick")
			click_blick();
		else
			cout << "Nie znana komenda: " << komenda << endl;
	}

	return 0;
}

void help() {

	cout << "*--------------------------------------------*\n";
	cout << "| help    - wyswietla pomoc                  |" << endl;
	cout << "| exit    - konczy program                   |" << endl;
	cout << "| clear   - czysci ekran                     |" << endl;
	cout << "|                                            |" << endl;
	cout << "|      [ " << okienko.nazwa_okna << " ]  |" << endl;
	cout << "|                                            |" << endl;
	cout << "|   ***[MODULY]***                           |" << endl;
	cout << "|                                            |" << endl;
	cout << "| klikacz      - modul klikania mysza        |" << endl;
	cout << "| klikacz*     - modul klik i trzymaj        |" << endl;
	cout << "| click_blick  - klikanie w ustalone miejsce |" << endl;
	cout << "*--------------------------------------------*\n";
}

int read_digit() {
	string data;
	cin >> data;
	cin.clear();
	cin.ignore();
	cin.sync();
	if (data.length() <= 0)
		return 0;
	for (int x = 0;x < data.length();x++)
		if (!((data[x] == '0') || (data[x] == '1') || (data[x] == '2') || (data[x] == '3') || (data[x] == '4') || (data[x] == '5')
			|| (data[x] == '6') || (data[x] == '7') || (data[x] == '8') || (data[x] == '9')))
			return 0;
	int result = stoi(data);
	return result;
}

void click_blick() {

	cout << "Modul click_blick klika w wybrane miejsce w oknie bez uzywania myszki. \n\n";

	if (!(IsWindow(okienko.uchwyt_okna)))
	{
		cout << "Modul wymaga zdefiniowania okna \n wydaj polecenie \'okno\'\n";
		return;
	}

	cout << "Ustaw kursor w wybranym oknie na pozycje ktora ma byc klikana [enter]...";
	getchar();

	RECT prostokat_okna;
	POINT poz;

	GetWindowRect(okienko.uchwyt_okna, &prostokat_okna);
	GetCursorPos(&poz);

	int poz_x, poz_y;

	poz_x = poz.x - prostokat_okna.left;
	poz_y = poz.y - prostokat_okna.top;

	cout << "Odczytana pozycja do klikania to [" << poz_x << "; " << poz_y << "]\n";
	cout << "[enter] - narysuje okrag w miejscu klikania \n Okrag czasem moze byc niewidoczny jezeli okno jest caly czas odswiezane \n";
	getchar();

	HDC hdcOkno;
	hdcOkno = GetDC(okienko.uchwyt_okna);

	for (int x = 0;x < 100;x++)
	{
		HBRUSH pedzel;
		pedzel = CreateSolidBrush(0x00FF00);

		Ellipse(hdcOkno, poz_x + 10, poz_y + 10, poz_x - 10, poz_y-10);
		Sleep(10);
	}

	ReleaseDC(okienko.uchwyt_okna, hdcOkno);

	cout << "Co ile klikniecie (milisekundy 50 - 10 000): ";
	int czas = read_digit();

	if ((czas < 50) || (czas > 10000))
	{
		cout << "Nie poporawna wartosc\n";
		return;
	}

	cout << "Aby zakonczyc wpisz cokolwiek oprucz liczby\n";
	cout << "Ile razy kliknac: ";

	int licznik = 1;

	while (licznik = read_digit())
	{
		for (int x = 1;x <= licznik;x++)
		{


			// Tu naprawic kod bo nie dziala klikanie 

			int pozycja = LOWORD(poz_x) + HIWORD(poz_y);
			SendMessage(okienko.uchwyt_okna, WM_LBUTTONDOWN, NULL, pozycja);
			SendMessage(okienko.uchwyt_okna, WM_LBUTTONUP, NULL, pozycja);
			cout << "||" << x << "/" << licznik << char(13);
			Sleep(czas);
		}
		cout << "Ile razy kliknac: ";
	}
	cout << "[KONIEC MODULU CLICK_BLICK]" << endl << endl;

}
void klikacz_gwiazda() {
	cout << endl << "Modul klika w aktualna pozycje myszki i puszcz po ustalonym czasie." << endl << endl;

	cout << "Co ile klikniecie (milisekundy 50 - 10 000): ";
	int czas = read_digit();

	if ((czas < 50) || (czas > 10000))
	{
		cout << "Nie poporawna wartosc\n";
		return;
	}

	int odstep = 0;

	cout << "Ile czasu trzmac przycisniete (milisekundy 50 - 10 000): ";
	cin >> odstep;

	if ((odstep < 50) || (odstep > 10000))
	{
		cout << "Nie poprawna wartosc \n";
		return;
	}

	cout << "\n-Aby zakonczyc wprowadz inna wartosc niz liczba\n\n";

	cout << "Ile razy kliknac: ";

	int licznik = 1;

	while (licznik = read_digit())
	{
		for (int x = 1;x <= licznik;x++)
		{
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			Sleep(odstep);
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			cout << "||" << x << "/" << licznik << char(13);
			Sleep(czas);
		}
		cout << "Ile razy kliknac: ";
	}
	cout << "[KONIEC MODULU KLIKACZ*]" << endl << endl;

}

void klikacz() {
	cout << endl << "Modul klika z ustalonym intervalem w aktualne polozenie myszki. Robi to tyle razy ile zadeklarujemy" << endl << endl;

	cout << "Co ile klikniecie (milisekundy 50 - 10 000): ";
	int czas = read_digit();

	if ((czas < 50) || (czas > 10000))
	{
		cout << "Nie poporawna wartosc\n";
		return;
	}

	cout << "\n-Aby zakonczyc wprowadz inna wartosc niz liczba\n\n";

	cout << "Ile razy kliknac: ";

	int licznik = 1;

	while (licznik = read_digit())
	{
		for (int x = 1;x <= licznik;x++)
		{
			click();
			cout << "     " << x << "/" << licznik << char(13);
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

void set_okno() {
	string nazwa;
	cout << "Uwaga na duze i male literki\n";
	cout << "Wprowadz nazwe okna lub fraze nazwy\n";
	cout << "Max(1000 znakow): ";
	cin >> nazwa;


	for (int x = 0;x <= 100000000;x++)
		if (IsWindow((HWND)x))
		{

			char buffor[1000];
			GetWindowTextA((HWND)x, &buffor[0], 1000);

			for (int y = 0;y <= 1000 - nazwa.length();y++)
				if (buffor[y] == nazwa[0])
				{
					int licznik = 0;
					bool czy_ok = true;

					for (int z = y;z < y + nazwa.length();z++)
					{

						if (buffor[z] != nazwa[licznik])
						{
							czy_ok = false;
							break;
						}
						licznik++;
					}

					if (czy_ok)
					{
						okienko.wprowadz_nazwe(buffor);
						okienko.uchwyt_okna = (HWND)x;
						cout << "[SUCCESS]" << endl;
						cout << "Nazwa okna: \"" << buffor << "\"" << endl;
						return;
					}
				}
		}

	cout << "Okno z podana fraza nie zostalo odnalezione.\n";
}
