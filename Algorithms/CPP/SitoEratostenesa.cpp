#include <iostream>
#include <cmath>

using namespace std;

int tabLength = 200;

int main() {

        int *tab = new int[tabLength];
        for(int x=0;x<tabLength;x++)
                tab[x] = 0;

        int index = 2;


        for(int x=2;x<=(int)sqrt(tabLength);x++)
        {
                index = x*2;
                while(index < tabLength)
                {
                        tab[index] = 1;
                        index = index+x;
                }
        }


        for(int x=2;x<tabLength;x++)
                if(tab[x] == 0)
                        cout << x << ", ";

        return 0;
}
