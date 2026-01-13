#include <cstdio>
#include <cmath>

// 定义一个极小值 eps，用于浮点数比较时的误差范围
const double eps = 1e-8;

// 定义宏用于比较两个浮点数
// 判断 a 是否等于 b (差的绝对值小于 eps)
#define Equ(a, b) (fabs((a) - (b)) < (eps))
// 判断 a 是否大于 b (a 减 b 的差值大于 eps)
#define More(a, b) ((a) - (b) > (eps))
// 判断 a 是否小于 b (a 减 b 的差值小于 -eps)
#define Less(a, b) ((a) - (b) < (-eps))

int main() {

    int A, B, C, D;
    // 从标准输入读取四个整数 A, B, C, D
    scanf("%d %d %d %d", &A, &B, &C, &D);

    // 计算第一个值 x1: A * arcsin(sqrt(B)/2)
    // 注意：输入数据需要保证 sqrt(B)/2 在 [-1, 1] 范围内，否则 asin 返回 NaN
    double x1 = A * asin(sqrt(B) / 2);

    // 计算第二个值 x2: C * arcsin(sqrt(D)/2)
    double x2 = C * asin(sqrt(D) / 2);

    // 比较 x1 和 x2 的大小并输出结果
    if (More(x1, x2))
        printf("1"); // 如果 x1 > x2，输出 1
    else if (Less(x1, x2)) {
        printf("2"); // 如果 x1 < x2，输出 2
    } else {
        printf("0"); // 如果 x1 == x2，输出 0
    }

    return 0;

}
