#include <cstdio>

// 辅助函数：判断是否是闰年
bool isLeapYear(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

// 辅助函数：获取某年某个月的天数
int getDaysInMonth(int y, int m) {
    // 默认的每个月天数（1月到12月，第0个位置不用）
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // 如果是闰年且是2月，天数变成29
    if (m == 2 && isLeapYear(y)) {
        return 29;
    }
    return days[m];
}

int main() {
    int y, m, d;

    // 读取输入的年月日
    if (scanf("%d %d %d", &y, &m, &d) != 3) return 0;

    // --- 第一步：计算距离 2000年1月1日 的总天数 ---
    int total_days = 0;

    // 1. 累加走过的完整年份
    for (int i = 2000; i < y; i++) {
        if (isLeapYear(i)) total_days += 366;
        else total_days += 365;
    }

    // 2. 累加今年走过的完整月份
    for (int i = 1; i < m; i++) {
        total_days += getDaysInMonth(y, i);
    }

    // 3. 累加当月走过的天数
    total_days += (d - 1);

    // 计算当前是星期几 (0是周日, 1-6是周一到周六)
    // 因为2000-1-1是周六(6)，所以加上偏移量后取模
    int current_dow = (6 + total_days) % 7;

    // --- 第二步：计算还要几天到周日，并推演日期 ---
    int add_days = (7 - current_dow) % 7;

    // 一天一天地往后推演
    for (int i = 0; i < add_days; i++) {
        d++; // 天数+1

        // 如果天数超过了当月的最大天数，产生进位
        if (d > getDaysInMonth(y, m)) {
            d = 1;   // 天数变成下个月1号
            m++;     // 月份+1

            // 如果月份超过12月，跨年
            if (m > 12) {
                m = 1; // 月份变成1月
                y++;   // 年份+1
            }
        }
    }

    // 输出最终结果
    printf("%d %d %d\n", y, m, d);

    return 0;
}