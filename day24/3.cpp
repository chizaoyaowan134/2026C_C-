#include <cstdio>

// 判断是否为闰年（和加法题完全一样）
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 获取某年某月的天数（和加法题完全一样）
int getDaysInMonth(int year, int month) {
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return days[month];
}

int main() {
    int year, month, day;
    int n;

    // 继续使用你截图里的安全读取法
    if (scanf("%d-%d-%d", &year, &month, &day) != 3) {
        return 0; 
    }
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    // 直接减去 n 天
    day -= n;

    // 只要天数小于等于 0，就不断向前面借月份
    while (day <= 0) {
        // 月份退回上一个月
        month--;
        
        // 如果月份退到了 0，说明跨年了，回到上一年的 12 月
        if (month == 0) {
            month = 12;
            year--;
        }
        
        // 把退回到的这个月的天数，借过来补给 day
        day += getDaysInMonth(year, month);
    }

    // 依然用 %04d 和 %02d 保证输出格式
    printf("%04d-%02d-%02d\n", year, month, day);

    return 0;
}