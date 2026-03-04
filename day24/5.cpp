#include <cstdio>

int main() {

    int year1, month1, day1;
    int year2, month2, day2;
    scanf("%d-%d-%d", &year1, &month1, &day1);
    scanf("%d-%d-%d", &year2, &month2, &day2);

    if (year1 < year2) {
        printf("YES");
    } else if (year2 < year1) {
        printf("NO");
    } else {
        if (month1 < month2) {
            printf("YES");
        } else if (month2 < month1) {
            printf("NO");
        } else {
            if (day1 < day2) {
                printf("YES");
            } else {
                printf("NO");
            }

        }
    }

    return 0;

}