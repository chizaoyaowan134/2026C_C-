#include <cstdio>
#include <cstring>

int main() {

    int A, B, C;
    char str[100];

    fgets(str, 100, stdin);

    if (sscanf(str, "%d is greater than %d", &A, &B) == 2) {
        if (A > B)
            printf("Yes");
        else
            printf("No");
    } else if (sscanf(str, "%d is equal to %d plus %d", &A, &B, &C) == 3) {
        if (A == (B + C))
            printf("Yes");
        else
            printf("No");
    } else
        printf("???");

    return 0;

}