#include <cstdio>

int main() {

    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);

    if (A + B > C && A + C > B && B + C > A) {
        printf("YES");
    } else {
        printf("NO");
    }


    return 0;


}