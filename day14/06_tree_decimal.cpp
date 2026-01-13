#include <cstdio>

int main() {

    int n;

    scanf("%d", &n);

    int a = n % 10;
    int b = (n / 10) % 10;
    int c = n / 100;

    printf("%d %d %d", c, b, a);

    return 0;


}