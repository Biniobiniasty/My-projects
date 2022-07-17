#pragma once

#include <iostream>
#include <string>

using namespace std;

//[ KLASA Time OPERUJE NA CZASIE DOBOWYM OD "00:00:00" DO "23:59:59" ]

class Time
{
private:
	unsigned int HOURS;
	unsigned int MINUTES;
	unsigned int SECONDS;
	unsigned int ALL_TIME_IN_SECONDS;
	string TIME;	  // Przechowuje czas w formacie (--h:--m:--s)

	bool check_digit(char); // Funkcja zwarac true jezeli podany znak jest cyfra
	int StrToInt(string);   // Konwrtuje zmienna string do intiger w przypadku niepoprawnych danych zwraca 0
public:
	Time(int = 0);				// konstruktor przyjmuje czas w sekundach i konwertuje do zmiennych czasowych klasy
	Time(int, int);			// konstruktor przyjmujacy czas w formacie (minuty, sekundy)
	Time(int, int, int);	// konstruktor przyjmujacy czas w fomacie (godziny, minuty, sekundy)

	void set_time(int, int, int); // ustawia czas (godz, min, sec)  min 00:00:00 - max 23:59:59 dla blednie wprowadzonej danej przyjmuje 0
	void set_time(string);		  // przyjmuje stringa do ustawienia czasu w fomacie (--h:--m:--s) dla blednych danych nic nie zmienia
	string get_time();			  // funkcja zwraca stringa w postaci (--h:--m:--s)

	Time operator+(const Time&); // max wartosc osiagana 23:59:59 to co ponad jest dodawane do wartosci 00:00:00
	Time operator-(const Time&); // min wartosc osiagana 00:00:00 reszta jest odejmowana od 23:59:59
	friend ostream& operator<<(ostream&, const Time&);
	friend istream& operator>>(istream&, Time&);
	operator int() const;
};
