#include <cstdio>

bool isLeap(int year) {

    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) return true;

    return false;


}


int main() {

    int year;
    scanf("%d", &year);

    if (isLeap(year)) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;


}