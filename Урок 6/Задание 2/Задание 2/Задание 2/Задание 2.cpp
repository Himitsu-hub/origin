#include <iostream>
using namespace std;
#define SUB(x, y) ((x) - (y))

int main(int argc, char** argv)
{
    int a = 6;
    int b = 5;
    int c = 2;
    cout << SUB(a, b) << endl;           
    cout << SUB(a, b) * c << endl;       
    cout << SUB(a, b + c) * c << endl;   

    return 0;
}