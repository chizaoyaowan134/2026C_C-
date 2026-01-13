#include <cstdio>

const int MAXN = 1010;
int a[MAXN];

int main() {

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int k;
    scanf("%d", &k);

    int count = 0;
    for (int i = 0; i < n; i ++) {

        for (int j = i + 1; j < n; j ++) {
            if (a[i] + a[j] == k) {
                count ++;
            }
        }
    }

    printf("%d", count);

    return 0;


}