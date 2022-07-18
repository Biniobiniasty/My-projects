#include <iostream>

using namespace std;

int main() {
	
	int x = 4;
	int y = 3;
	int result = 0;

	__asm {
		xor eax, eax
		xor ebx, ebx
		mov eax, x
		mov ebx, y
		add eax, ebx
		mov result, eax
	}
	cout << x << " + " << y << " = " << result << endl;
	return 0;
}
