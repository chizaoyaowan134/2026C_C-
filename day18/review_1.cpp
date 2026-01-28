// #include <iostream>
// #include <algorithm>
//
// using namespace std;
//
// int main() {
//     long long n, u, d;
//     cin >> n >> u >> d;
//
//     // 特殊情况：第一次飞升就直接过顶
//     if (u >= n) {
//         cout << 1 << endl;
//         return 0;
//     }
//
//     // 需要通过“飞升+下降”循环来覆盖的高度
//     long long target = n - u;
//     // 每次循环的净高度
//     long long net_gain = u - d;
//
//     // 计算需要多少次完整的循环 (k-1)
//     // 向上取整公式：(target + net_gain - 1) / net_gain
//     long long k_minus_1 = (target + net_gain - 1) / net_gain;
//
//     // 总次数 k = (k-1) + 最后一次飞升
//     long long k = k_minus_1 + 1;
//
//     cout << k << endl;
//
//     return 0;
// }


// #include <cstdio>  // 提供输入输出函数：scanf, getchar, fgets, puts
// #include <cstring> // 提供字符串操作函数：strcspn
//
// int main() {
//
//     // 声明一个字符数组作为缓冲区
//     // 大小为 55，意味着最多能存储 54 个可见字符 + 1 个结束符 '\0'
//     char str[55];
//
//     int n;
//     // 从标准输入读取一个整数 n，表示接下来要处理的行数
//     // 注意：scanf 读取数字后，输入缓冲区中还会残留一个回车符 ('\n')
//     scanf("%d", &n);
//
//     // 【关键步骤】吞掉缓冲区里遗留的那个回车符
//     // 为什么这么做：scanf 读取整数时遇到回车结束，但回车符留在了缓冲区。
//     // 如果不加这行，下面的第一次 fgets 会直接读到这个回车符，导致读入一个空行（或仅包含换行符的字符串）。
//     getchar();
//
//     // 循环处理 n 次输入
//     for (int i = 0; i < n; i ++) {
//
//         // 使用 fgets 读取一整行数据
//         // 参数说明：
//         // 1. str: 存储读入数据的数组
//         // 2. 55: 最多读取 55-1 个字符，防止缓冲区溢出（比 gets 安全）
//         // 3. stdin: 从标准输入读取
//         // 特点：fgets 会连同末尾的换行符 '\n' 一起读入（除非缓冲区满了）
//         fgets(str, 55, stdin);
//
//         // 【关键技巧】去除字符串末尾的换行符
//         // 为什么这么做：fgets 读入的字符串通常以 "\n\0" 结尾。
//         // strcspn(str, "\n") 会计算从字符串开头到第一个 "\n" 字符的长度（也就是换行符的下标）。
//         // 将该位置赋值为 0 (即 '\0')，相当于截断字符串，去掉了换行符。
//         // 这样做的目的是为了让输出更干净，或者方便后续字符串比较。
//         str[strcspn(str, "\n")] = 0;
//
//         // 输出字符串，并自动在末尾添加一个换行符
//         // 为什么用 puts：puts 用于输出字符串非常方便，它自带换行功能。
//         // 因为我们在上面去掉了原带的换行符，这里用 puts 刚好补上一个新的换行，格式对其。
//         puts(str);
//     }
//
//     return 0; // 这是一个良好的编程习惯，表示程序正常结束
// }

#include <cstdio>
#include <cstring>


int main() {

    int A, B, C;


    char str[110];

    fgets(str, 110, stdin);

    if (sscanf(str, "%d is greater than %d", &A, &B) == 2) {
        if (A > B) {
            printf("Yes");
        } else {
            printf("No");
        }

    } else if (sscanf(str, "%d is equal to %d plus %d", &A, &B, &C) == 3) {
        if (A == (B + C)) {
            printf("Yes");
        } else {
            printf("No");
        }
    } else {
        printf("???");
    }

    return 0;


}














