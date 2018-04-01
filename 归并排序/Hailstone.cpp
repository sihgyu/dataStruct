#include "iostream"
using namespace std;

int hailstone(int n)
{
    int length = 1;
    while (n > 1)
    {
        (n % 2) ? n = 3 * n + 1 : n /= 2;
        length ++;
    }

    return length;
}

void hailstoneView(int n)
{
    while (n > 1)
    {
        cout << n;
        (n % 2) ? hailstoneView(3 * n + 1) : hailstoneView(  n /= 2);
        
    }
}
int main()
{
    
    int n;
    cin >> n;
    cout << hailstone(n) << endl;
    return 0;
}