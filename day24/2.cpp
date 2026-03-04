#include <cstdio>

// 判断是否为闰年
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 获取某年某月的天数
int getDaysInMonth(int year, int month) {
    // 数组下标 1-12 对应 1-12 月，0 占位
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // 如果是闰年且是2月，返回29天
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return days[month];
}

int main() {
    int year, month, day;
    int n;

    // 使用 scanf 匹配 "%d-%d-%d" 格式直接提取年月日
    if (scanf("%d-%d-%d", &year, &month, &day) != 3) {
        return 0;
    }
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    // 将 n 天直接加到当前日上
    day += n;

    // 当 day 超过当前月份的最大天数时，持续进位
    while (day > getDaysInMonth(year, month)) {
        // 减去当前月的天数
        day -= getDaysInMonth(year, month);
        // 月份进位
        month++;

        // 如果月份超过12，年份进位
        if (month > 12) {
            month = 1;
            year++;
        }
    }

    // 使用 %04d 和 %02d 确保输出格式为 YYYY-MM-DD（不足补零）
    printf("%04d-%02d-%02d\n", year, month, day);

    return 0;
}