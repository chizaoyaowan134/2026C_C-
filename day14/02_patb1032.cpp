#include <cstdio>

const int MAXN = 100010;
int a[MAXN];

int main() {

    int N;
    scanf("%d", &N);

    int x = N;

    int score, num;
    while (N--) {

        scanf("%d%d", &num, &score);
        a[num]  += score;
        // printf("%d\n", a[num]);

    }



    int maxscore = -1;
    int maxNum = -1;
    for (int i = 1; i <= x; i++) {
        if (a[i] > maxscore) {
            maxscore = a[i];
            maxNum = i;
        }
    }

    printf("%d %d", maxNum, maxscore);

    return 0;

}

