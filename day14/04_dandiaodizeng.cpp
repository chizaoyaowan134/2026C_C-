#include <stdio.h>

const int MAXN = 15;
int a[MAXN] = {0};

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    bool flag = false;

    for (int i = 1; i < n; i ++) {
        if (a[i + 1] < a[i]) {
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