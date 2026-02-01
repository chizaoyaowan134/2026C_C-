#include <cstdio>

int monthDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeap(int year) {

    return (year % 100 != 0 && year % 4 == 0) || (year % 400 == 0);

}



int main() {

    int data1, data2;
    scanf("%d%d", &data1, &data2);

    if (data1 > data2) {

        int temp = data1;
        data1 = data2;
        data1 = temp;

    }

    int y = data1 / 10000;
    int m = (data1 / 100) % 100;
    int d = data1 % 100;

    int count = 1;

    while (true) {

        int currentDay = y * 10000 + m * 100 + d;

        if (currentDay == data2) {
            break;
        }

        count ++;
        d ++;

        // 检查日期是否合法
        int dayInMonth = monthDays[m];

        if (isLeap(y) && m == 2) {
            dayInMonth = 29;
        }

        // 如果当前日超过了当前月的合法日期，则月需要进1
        if (d > dayInMonth) {

            // 重置当前日
            d = 1;
            m ++;
        }

        // 同理判断月
        if (m > 12) {

            m = 1;
            y ++;

        }


    }

    printf("%d", count);


}