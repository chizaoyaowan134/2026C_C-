#include <cstdio>

int main() {
    int L, R;
    
    // 读取输入的区间左端点 L 和右端点 R
    scanf("%d %d", &L, &R);
    
    int total_ones = 0; // 用于记录数字 1 出现的总次数
    
    // 遍历区间 [L, R] 里的每一个整数
    for (int i = L; i <= R; ++i) {
        int temp = i;
        
        // 利用循环将当前数字 temp 的每一位分离出来
        while (temp > 0) {
            // 对 10 取余，可以得到当前数字的个位数
            if (temp % 10 == 1) {
                total_ones++; // 如果个位数是 1，总次数加 1
            }
            // 除以 10，去掉刚才判断过的个位数，把十位推到个位的位置
            temp /= 10; 
        }
    }
    
    // 输出最终统计的总次数
    printf("%d\n", total_ones);
    
    return 0;
}#include <cstdio>

int main() {
    int L, R;

    // 读取输入的区间左端点 L 和右端点 R
    scanf("%d %d", &L, &R);

    int total_ones = 0; // 用于记录数字 1 出现的总次数

    // 遍历区间 [L, R] 里的每一个整数
    for (int i = L; i <= R; ++i) {
        int temp = i;

        // 利用循环将当前数字 temp 的每一位分离出来
        while (temp > 0) {
            // 对 10 取余，可以得到当前数字的个位数
            if (temp % 10 == 1) {
                total_ones++; // 如果个位数是 1，总次数加 1
            }
            // 除以 10，去掉刚才判断过的个位数，把十位推到个位的位置
            temp /= 10;
        }
    }

    // 输出最终统计的总次数
    printf("%d\n", total_ones);

    return 0;
}