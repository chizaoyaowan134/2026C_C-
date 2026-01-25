#include <cstdio>

const int MAXN = 20;
int a[MAXN];

int main() {

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n - 1; i ++) {
        scanf("%d", &a[i]);
    }

    bool flag = false;
    for (int i = 0; i < n; i ++) {
        if (a[i] > a[i + 1]) {
            flag = true;
            break;
        }
    }

    if (flag) {
        printf("NO");
    } else {
        printf("YES");
    }

    return 0;


}