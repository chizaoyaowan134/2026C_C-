#include <cstdio>

// 直接复用你之前的判断闰年函数
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 直接复用你之前的获取天数函数
int getDaysInMonth(int year, int month) {
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return days[month];
}

int main() {
    int year, month, day;

    // 继续使用你熟练的安全读取法
    if (scanf("%d-%d-%d", &year, &month, &day) != 3) {
        return 0; 
    }

    int totalDays = 0;

    // 核心逻辑：用一个循环，把当前月份之前的“完整月份”天数全加起来
    for (int i = 1; i < month; i++) {
        totalDays += getDaysInMonth(year, i);
    }

    // 最后加上当前月份的“日”
    totalDays += day;

    // 题目要求只输出一个整数
    printf("%d\n", totalDays);

    return 0;
}