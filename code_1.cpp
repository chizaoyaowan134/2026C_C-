#include <cstdio>

int main() {
    int n, u, d;

    scanf("%d%d%d", &n, &u, &d);


    int ans = 0;
    int sum = 0;
    while(1) {

        sum += u;
        ans ++;

        if(sum >= n) break;

        sum -= d;

    }

    printf("%d", ans);




}