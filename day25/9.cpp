#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 9;
string str[MAXN], s;    // 字符串矩阵、待寻找的字符串

bool findStr() {        // 在横向的字符串中寻找s
    for (int i = 0; i < MAXN; i++) {    // 遍历横向字符串
        if (str[i].find(s) != -1) {     // 如果能找到s，那么返回true
            return true;
        }
    }
    return false;       // 所有横向字符串中都找不到s，那么返回false
}

int main() {
    // 1. 读取 9x9 的字符矩阵
    for (int i = 0; i < MAXN; i++) {
        cin >> str[i];
    }
    
    // 2. 读取待寻找的字符串 S
    cin >> s;
    
    // 3. 先检查横向字符串中是否存在 S
    bool checkResult = findStr();           
    
    // 4. 如果横向找不到，那么检查竖向
    if (!checkResult) {                     
        // 竖向的情况下，通过二重循环对矩阵进行对角线转置
        for (int i = 0; i < MAXN; i++) {    
            for (int j = i + 1; j < MAXN; j++) {
                swap(str[i][j], str[j][i]);
            }
        }
        // 对转置后的矩阵再次检查横向，这等价于在原矩阵中检查竖向
        checkResult = checkResult || findStr();     
    }
    
    // 5. 输出检查结果
    cout << (checkResult ? "Yes" : "No") << endl;   
    
    return 0;
}