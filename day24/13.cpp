#include <cstdio>
#include <cstring>

int main() {

    char word[1005];

    int count = 0;
    while (scanf("%s", word) != EOF) {
        count ++;
    }

    printf("%d", count);

    return 0;

}