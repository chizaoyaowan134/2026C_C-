#include <cstdio>

int main() {
    int n;
    // 读取项数 n
    if (scanf("%d", &n) != 1) return 0;

    // 定义一个数组当“收纳盒”，coef[i] 专门用来存放 x^i 这一项的总系数
    // 指数最大是 10，数组开 15 足够了，初始化为 0
    long long coef[15] = {0}; 

    // 1. 读取输入，并合并同类项
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        coef[b] += a; // 把系数加到对应指数的格子里
    }

    bool all_zero = true; // 报警器：记录是不是所有项求导后都变成了 0

    // 2. 计算五次导数并输出
    // 题目要求从高次到低次输出，所以我们从最高可能的指数 10 往下遍历。
    // 因为指数小于 5 的项求五次导必然为 0，所以我们遍历到 5 就停下。
    for (int b = 10; b >= 5; --b) {
        if (coef[b] != 0) { // 如果这一项存在
            // 套用规则：新系数 = a * b * (b-1) * (b-2) * (b-3) * (b-4)
            long long new_a = coef[b] * b * (b - 1) * (b - 2) * (b - 3) * (b - 4);
            int new_b = b - 5;  // 新指数
            
            // 如果求导后的系数不为 0，才输出
            if (new_a != 0) {
                printf("%lld %d\n", new_a, new_b);
                all_zero = false; // 找到了非零项，报警器解除
            }
        }
    }

    // 3. 收尾判断：如果全军覆没，输出 0 0
    if (all_zero) {
        printf("0 0\n");
    }

    return 0;
}