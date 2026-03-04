#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 20;      // 最大字符串数量
const int MAXL = 51;      // 最大字符串长度+1
char str[MAXN][MAXL];     // 存储所有字符串

int main() {
    int n, minL = MAXL;   // n: 字符串数量    minL: 最短字符串长度

    cin >> n;             // 读取字符串数量
    getchar();            // 读取留在缓冲区的换行符

    for (int i = 0; i < n; i++) {
        cin.getline(str[i], MAXL);            // 读取第 i 个字符串
        minL = min(minL, (int)strlen(str[i]));// 更新最短字符串长度
    }

    for (int j = 0; j < minL; j++) {          // 对每个字符位置进行检查
        bool isSame = true;                   // 标记当前位置字符是否全部相同
        for (int i = 1; i < n; i++) {
            if (str[i][j] != str[0][j]) {     // 若发现不相同
                isSame = false;               // 则设置标记为 false
                break;                        // 并跳出内层循环
            }
        }
        if (isSame) {                         // 若该位置字符相同
            printf("%c", str[0][j]);          // 输出该字符
        } else {
            break;                            // 否则退出外层循环
        }
    }

    printf("\n");                             // 输出换行
    return 0;
}