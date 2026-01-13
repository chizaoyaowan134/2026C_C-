#include <cstdio>

typedef long long ll;

int main() {

    int n;
    scanf("%d", &n);

    ll x = 1;

    for (int i = 0; i < n; i++) {
        x *= 2;
        x %= 1007;
    }

    printf("%d", x);

    return 0;


}