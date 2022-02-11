int read_digit(); // funkcja wczytuje liczbe jezeli dane sa niepoprawne zwraca zero include<string>

int read_digit() {
	string data;
	cin >> data;
	cin.clear();
	cin.ignore();
	cin.sync();
	for(int x=0;x<data.length();x++)
		if (!((data[x] == '0') || (data[x] == '1') || (data[x] == '2') || (data[x] == '3') || (data[x] == '4') || (data[x] == '5')
			|| (data[x] == '6') || (data[x] == '7') || (data[x] == '8') || (data[x] == '9')))
			return 0;
	int result = stoi(data);
	return result;
}
