#include <cstdio>

// 1. 定义一个辅助数组，存储平年每个月的天数
// 下标0不使用，从下标1开始对应1月，这样使用 monthDays[m] 就能直接获取 m 月的天数
int monthDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// 2. 判断闰年的函数
// 规则：能被4整除但不能被100整除，或者能被400整除的年份是闰年
bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
    int date1, date2;
    // 输入两个形如 YYYYMMDD 的整数，例如 20230101
    scanf("%d %d", &date1, &date2);

    // 确保 date1 是较早的日期，始终让时间从 date1 走到 date2
    if (date1 > date2) {
        int temp = date1;
        date1 = date2;
        date2 = temp;
    }

    // 3. 拆解起始日期 date1 为年、月、日
    int y = date1 / 10000;          // 取前四位作为年份
    int m = (date1 % 10000) / 100;  // 取中间两位作为月份
    int d = date1 % 100;            // 取后两位作为日期

    // 初始化计数器
    // 题目通常要求连续的天数差，包含起始当天和结束当天
    // 例如：1月1日到1月2日是2天，所以从1开始计数
    int count = 1;

    // 4. 核心模拟循环：日期一天天增加，直到追上 date2
    while (true) {
        // 每次循环先判断当前组合出的日期是否等于目标日期
        int currentFullDate = y * 10000 + m * 100 + d;
        if (currentFullDate == date2) {
            break; // 如果到了目标日期，退出循环
        }

        count++; // 还没追上，说明需要再过一天，计数器+1
        d++;     // 将当前的日加1（比如从1号变成2号）

        // --- 检查日期是否合法（进位逻辑） ---

        // 先获取当前月份应该有多少天
        int daysInThisMonth = monthDays[m];
        
        // 特殊处理：如果是闰年的2月，天数强行改为29
        if (isLeap(y) && m == 2) {
            daysInThisMonth = 29;
        }

        // 如果 当前日(d) 超过了 当月最大天数(daysInThisMonth)
        // 说明该月过完了，需要进位到下个月
        if (d > daysInThisMonth) {
            d = 1;  // 重置为下个月的1号
            m++;    // 月份加1
        }

        // 如果 月份(m) 超过了12
        // 说明这一年过完了，需要进位到下一年
        if (m > 12) {
            m = 1;  // 重置为明年的1月
            y++;    // 年份加1
        }
    }

    // 输出最终统计的天数
    printf("%d\n", count);

    return 0;
}