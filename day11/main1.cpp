#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>

using namespace std;

int main() {

    int n;
    double d;
    char str[100];

    cin >> n >> d;

    getchar();

    scanf("%[^\n]%*c", str);

    cout << n << endl;
    cout << fixed << setprecision(2) << d << endl;
    cout << str << endl;

    return 0;
}