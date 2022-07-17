#include <iostream>
#include "Time.h"

using namespace std;

int main() {

	
	Time t1(200);
	cout << t1 << endl; // wyswietli 00h:03m:20s
	Time t2;
	cin >> t2; // wprowadzamy wartosc "10h:12m:01s"

	Time t3 = t2 - t1;
	cout << t3 << endl; // wyswietli 10h:08m:41s
	int t3s = t3;
	cout << t3s << endl; // wyswietli czas w sekundach 36521


	return 0;

}
