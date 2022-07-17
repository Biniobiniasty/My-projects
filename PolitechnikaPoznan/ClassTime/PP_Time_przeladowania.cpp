#include "Time.h"

bool Time::check_digit(char sign) {
	for (int x = 0;x <= 9;x++)
		if (to_string(x)[0] == sign)
			return true;
	return false;
}

int Time::StrToInt(string data) {
	for (int x = 0;x < data.length();x++)
		if (!check_digit(data[x]))
			return 0;
	return stoi(data);
}

Time::Time(int sec) : TIME("00h:00m:00s") {
	int amount_hour = sec / (60 * 60);
	int amount_min = (sec - (amount_hour * 60 * 60)) / 60;
	int amount_second = sec - (amount_hour * 60 * 60) - (amount_min * 60);
	set_time(amount_hour, amount_min, amount_second);
}

Time::Time(int min, int sec) : TIME("00h:00m:00s") {
	set_time(0, min, sec);
}

Time::Time(int hour, int min, int sec) : TIME("00h:00m:00s") {
	set_time(hour, min, sec);
}

void Time::set_time(int hour, int min, int sec) {
	
	if ((hour >= 0) && (hour <= 23))
		HOURS = hour;
	else
		HOURS = 0;

	if ((min >= 0) && (min <= 59))
		this->MINUTES = min;
	else
		this->MINUTES = 0;

	if ((sec >= 0) && (sec <= 59))
		this->SECONDS = sec;
	else
		this->SECONDS = 0;

	this->TIME = get_time();
	this->ALL_TIME_IN_SECONDS = (this->HOURS * 60 * 60) + (this->MINUTES * 60) + this->SECONDS;
}

void Time::set_time(string time) {
	
	//[SPRAWDZENIE CZY CIAG MA ODPOWIEDNIA DLUGOSC ZNAKOW "--h:--m:--s" - 11 znakow ]
	if (time.length() != 11)
		return;

	//[ SPRAWDZENIE CZY NA ODPOWIEDNICH MIEJSCACH ZNAJDUJA SIE LICZBY ]
	if (!check_digit(time[0]) || !check_digit(time[1]))
		return;
	if (!check_digit(time[4]) || !check_digit(time[5]))
		return;
	if (!check_digit(time[8]) || !check_digit(time[9]))
		return;

	//[ SPRAWDZENIE CZY ZGADZAJA SIE ZNAKI h, m, s, : ]
	if (!(time[2] == 'h' && time[3] == ':' && time[6] == 'm' && time[7] == ':' && time[10] == 's'))
		return;
	
	//[ JEZELI DANE SA OK TO KONWERTUJEMY ODPOWIEDNIE POLA NA GODZINY MINUTY I SEKUNDY ]
	string convert;
	convert.clear();
	convert = "00";

	convert[0] = time[0];
	convert[1] = time[1];
	int hours = StrToInt(convert);

	convert[0] = time[4];
	convert[1] = time[5];
	int minutes = StrToInt(convert);

	convert[0] = time[8];
	convert[1] = time[9];
	int seconds = StrToInt(convert);

	set_time(hours, minutes, seconds);

}

string Time::get_time() {

	string result;
	result.clear();

	//[ FUNKCJE IF DODAJA ZERO NA POCZATKU JEZELI JEST LICZBA JEDNOCYFROWA ]
	if (this->HOURS < 10)
		result.append("0");
	result.append(to_string(this->HOURS)+"h:");

	if (this->MINUTES < 10)
		result.append("0");
	result.append(to_string(MINUTES)+"m:");
	
	if (this->SECONDS < 10)
		result.append("0");
	result.append(to_string(SECONDS)+"s");

	return result;
}

Time Time::operator+(const Time &val) {
	
	int seconds = this->SECONDS + val.SECONDS;
	int minutes = this->MINUTES + val.MINUTES;
	int hours = this->HOURS + val.HOURS;
	
	//[ PRZELICZENIE WARTOSCI CZASOWYCH NP. JEZELI PO ZSUMOWANIU WYSZLO 70 SEKUND TO ZAMIANA NA "1 MINUTA 10 SECUND"
	if (seconds >= 60)
	{
		minutes++;
		seconds = seconds - 60;
	}

	if (minutes >= 60)
	{
		hours++;
		minutes = minutes - 60;
	}

	if (hours >= 24)
	{
		hours = hours - 24;
	}

	Time ret(hours, minutes, seconds);
	return ret;
}

Time Time::operator-(const Time &val) {
	
	int seconds = this->SECONDS - val.SECONDS;
	int minutes = this->MINUTES - val.MINUTES;
	int hours = this->HOURS - val.HOURS;

	//[ PRZELICZENIE WARTOSCI CZASOWYCH NP. JEZELI PO ODEJMOWANIU WYSZLO "2 MINUT -5 SEKUND" TO ZAMIANA NA "1 MINUTA 55 SECUND"
	if (seconds < 0)
	{
		minutes--;
		seconds = 60 + seconds;
	}

	if (minutes < 0)
	{
		hours--;
		minutes = 60 + minutes;
	}

	if (hours < 0)
		hours = 24 + hours;

	Time ret(hours, minutes, seconds);
	return ret;
}

Time::operator int() const {
	return this->ALL_TIME_IN_SECONDS;
}

ostream& operator<<(ostream& stream, const Time& data) {
	return stream << data.TIME;
}

istream& operator>>(istream& enter, Time& data) {

	string Enter_Data;
	Enter_Data.clear();

	enter >> Enter_Data;
	data.set_time(Enter_Data);

	return enter;
}





