// #include <iostream>
// #include <iomanip>
//
// using namespace std;
//
// const int MAXN = 110;
// char str[MAXN];
//
//
// int main() {
//
//     int n;
//     double d;
//     cin >> n >> d;
//     getchar();
//     cin.getline(str, MAXN);
//
//     cout << n << endl;
//     cout << fixed << setprecision(2) << d << endl;
//     cout << str;
//
//
//
//
// }


#include <cstdio>
#include <cmath>


const double eps = 1e-8;

#define Equ(a, b) (fabs((a) - (b)) < (eps))
#define More(a, b) ((a) - (b) > (eps))
#define Less(a, b) ((a) - (b) < (-eps))

int main() {

    int A, B, C, D;
    scanf("%d %d %d %d", &A, &B, &C, &D);

    double x1 = A * asin(sqrt(B) / 2);
    double x2 = C * asin(sqrt(D) / 2);

    if (More(x1, x2))
        printf("1");
    else if (Less(x1, x2)) {
        printf("2");
    } else {
        printf("0");
    }

    return 0;
}