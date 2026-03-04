#include <cstdio>

// 每个月的天数表：第一维0表示平年，1表示闰年
int dayOfMonth[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

// 判断是否是闰年
bool isLeapYear(int year) {
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

// 给当前日期加1天（引用参数以同步修改）
void addOneDay(int &year, int &month, int &day) {
    day++;                                           // 日份+1
    if (day > dayOfMonth[isLeapYear(year)][month]) { // 若超过当月天数
        month++;                                     // 月份+1
        day = 1;                                     // 日份置1
    }
    if (month > 12) {                                // 若超过12月
        year++;                                      // 年份+1
        month = 1;                                   // 月份置1
    }
}

// 给当前日期减1天（引用参数以同步修改）
void subOneDay(int &year, int &month, int &day) {
    day--;                                           // 日份-1
    if (day < 1) {                                   // 若小于1号
        month--;                                     // 月份-1
    }
    if (month < 1) {                                 // 若小于1月
        year--;                                      // 年份-1
        month = 12;                                  // 月份置12
    }
    if (day < 1) {                                   // 若仍小于1号
        day = dayOfMonth[isLeapYear(year)][month];   // 日份设为上月最后一天
    }
}

// 比较日期1是否在日期2之前
bool isBefore(int y1, int m1, int d1, int y2, int m2, int d2) {
    if (y1 != y2) return y1 < y2;                    // 年份先后
    if (m1 != m2) return m1 < m2;                    // 月份先后
    return d1 < d2;                                  // 日份先后
}

// 比较日期1是否在日期2之后
bool isAfter(int y1, int m1, int d1, int y2, int m2, int d2) {
    if (y1 != y2) return y1 > y2;                    // 年份先后
    if (m1 != m2) return m1 > m2;                    // 月份先后
    return d1 > d2;                                  // 日份先后
}

int main() {
    int year1 = 2021, month1 = 5, day1 = 1;              
    int dayOfWeek = 6;                              // 参考日期2021-05-01为周六(6)
    
    int year2, month2, day2;
    scanf("%d-%d-%d", &year2, &month2, &day2);      // 读取目标日期
    
    if (isBefore(year1, month1, day1, year2, month2, day2)) {
        while (isBefore(year1, month1, day1, year2, month2, day2)) {
            addOneDay(year1, month1, day1);                     
            dayOfWeek = (dayOfWeek + 1) % 7;        // 向后推进星期
        }
    } else if (isAfter(year1, month1, day1, year2, month2, day2)) {
        while (isAfter(year1, month1, day1, year2, month2, day2)) {
            subOneDay(year1, month1, day1);
            dayOfWeek = (dayOfWeek - 1 + 7) % 7;    // 向前退星期
        }
    }
    
    printf("%d", dayOfWeek);                        // 输出最终星期
    
    return 0;
}