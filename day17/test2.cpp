// #include <cstdio>
//
// int main() {
//
//    int n;
//
//    scanf("%d", &n);
//
//    if (n <= 3) {
//
//       for (int i = 1; i <= n; i ++) {
//          for (int j = 1; j <= i; j ++) {
//             printf("*");
//          }
//
//          printf("\n");
//       }
//    } else {
//
//       for (int i = 1; i <= n; i ++) {
//          for (int j = 1; j <= i; j ++) {
//             // 我们先判断出在哪些情况下，要输出“*”，
//             // 观察图形可知，当是直角边时候， 斜边的时候以及最后一条边的时候要输出“*”
//             if (j == 1 || j == i || i == n) {
//                printf("*");
//             } else {
//                printf(" ");
//             }
//          }
//          printf("\n");
//       }
//
//    }
//
//    return 0;
// }


#include <cstdio>
#include <cstring> // 使用 memset 需要这个头文件

int main() {
    int n;
    scanf("%d", &n);

    // 定义一个足够大的二维数组，初始化为全 0
    // 这里的 105 是防止越界，题目说 n<=100
    char s[105][105];

    // 1. 初始化：先把所有位置都填成空格
    // 虽然这一步不做也可以（依靠 \0 截断），但为了逻辑清晰通常会做
    memset(s, ' ', sizeof(s));

    // 2. 处理“空心”部分（从第0行 到 第n-2行）
    // 注意：题目如果是输出 N 行，这里循环到 n-2 是指处理前 N-1 行
    for (int i = 0; i < n - 1; i++) {
        s[i][0] = '*';      // 左边框
        s[i][i] = '*';      // 斜边框
        s[i][i + 1] = '\0'; // 字符串结束符，相当于剪刀，把这一行剪断

        printf("%s\n", s[i]); // 直接把这一行作为字符串打印出来
    }

    // 3. 处理“实心”底边（最后一行）
    for (int i = 0; i < n; i++) {
        printf("*");
    }
    printf("\n");

    return 0;
}