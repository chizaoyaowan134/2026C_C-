#include <cstdio>
#include <cstring>
#include <algorithm> // 为了使用 reverse 函数

using namespace std;

int main() {
    // 题目说字符串长度最大 1000，我们开大一点防止越界
    char s[1005];

    // 读取字符串
    scanf("%s", s);

    // 循环 8 次读取操作并翻转
    for (int i = 0; i < 8; i++) {
        int l, r;
        scanf("%d %d", &l, &r);

        // reverse 函数接收两个指针，表示要翻转的范围 [起始指针, 结束指针)
        // 刚好与题目的 [Li, Ri) 完美契合
        // s + l 指向第 l 个字符，s + r 指向第 r 个字符
        reverse(s + l, s + r);
    }

    // 输出最终的字符串
    printf("%s\n", s);

    return 0;
}