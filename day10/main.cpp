#include <cstdio>
#include <cstring>

int main() {

    int A, B, C;
    char str[55];
    char str1[55];

    scanf("%[^\n]%*c", str);

    sscanf(str, "%d %d %d %s", &A, &B, &C, str1);

    if (A > B) {
        printf("Yes");
    } else if (A > (B + C)) {
        printf("Yes");
    } else if (!strcmp(str1, "No Information")) {
        printf("???");
    } else {
        printf("No");
    }

    return 0;


}