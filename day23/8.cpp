#include <cstdio>
#include <cstring>

int main() {

    char str[256];

    if (scanf("%s", str) == EOF) return 0;

    int len = strlen(str);
    bool isPalindrome = true;

    for (int i = 0, j = len - 1; i < j; i ++, j --) {

        if (str[i] != str[j]) {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome) {

        printf("YES\n");

    } else {

        printf("NO\n");

    }

    return 0;


}