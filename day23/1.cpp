#include <cstdio>

const int N = 15;

int a[N];

int main() {

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i ++) {

        scanf("%d", &a[i]);

    }

    bool flag = true;

    for (int i = 0; i < n - 1; i ++) {

        if (a[i + 1] < a[i]) {

            flag = false;
            break;

        }

    }

    if (flag) {

        printf("YES");

    } else {

        printf("NO");

    }

    return 0;



}