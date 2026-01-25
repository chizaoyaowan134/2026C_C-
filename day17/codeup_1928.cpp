#include <cstdio>

// 1. 定义一个辅助数组，存储每个月的天数
// 下标0我们不用，从下标1开始对应1月，这样代码更直观
int monthDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// 2. 判断闰年的函数
bool isLeap(int year) {
    // 四年一闰且百年不闰，或者四百年又闰
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
    int date1, date2;
    scanf("%d %d", &date1, &date2);

    // 确保 date1 是较小的那个日期，方便后面循环
    if (date1 > date2) {
        int temp = date1;
        date1 = date2;
        date2 = temp;
    }

    // 3. 拆解起始日期
    int y = date1 / 10000;
    int m = (date1 % 10000) / 100;
    int d = date1 % 100;

    int count = 1; // 包含起始当天，所以计数器从1开始

    // 4. 核心模拟：当 当前日期 不等于 目标日期 时，一直循环
    // 我们每次循环结束判断是否到了 date2
    // 为了方便比较，我们在循环里并不把 y/m/d 拼回整数，而是直接看是否追上
    // 但为了逻辑最简单，我们可以每次拼回去比较，或者稍微换个思路：

    while (true) {
        // 将当前的 y, m, d 组合回整数形式，看看是不是到了终点
        int currentFullDate = y * 10000 + m * 100 + d;
        if (currentFullDate == date2) {
            break; // 到了就退出
        }

        count++; // 还没到，天数+1
        d++;     // 日子往前走一天

        // --- 检查有没有越界 ---

        // 先看当月有多少天
        int daysInThisMonth = monthDays[m];
        // 特殊处理：如果是闰年的2月，天数改为29
        if (isLeap(y) && m == 2) {
            daysInThisMonth = 29;
        }

        // 如果日子超过了当月最大天数（比如1月32号）
        if (d > daysInThisMonth) {
            d = 1;  // 变成下个月1号
            m++;    // 月份加1
        }

        // 如果月份超过了12月（比如13月）
        if (m > 12) {
            m = 1;  // 变成明年1月
            y++;    // 年份加1
        }
    }

    printf("%d\n", count);

    return 0;
}