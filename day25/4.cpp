#include <cstdio>

void change_data(int &x, int &y) {

    if (x > y) {
        int temp = x;
        x = y;
        y = temp;
    }

}

int main() {

    int x1, y1;
    int x2, y2;

    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &x2, &y2);

    if (x1 > x2) change_data(x1, x2);
    if (y1 > y2) change_data(y1, y2);

    printf("%d", (y2 - y1) * (x2 - x1));

    return 0;




}