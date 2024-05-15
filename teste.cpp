#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    unsigned seed = time(0);

    srand(seed);
    for( int i = 0 ; i < 5 ; i++ )
    {
        cout << rand() << endl;
    }

    return 0;
}