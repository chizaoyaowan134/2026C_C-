#include <iostream>
#include <iomanip> // 必须引入这个头文件，才能使用 setprecision 格式化浮点数
#include <string>

using namespace std;

int main() {
    int n;
    double d;
    string s;

    // 1. 读取整数和浮点数
    cin >> n;
    cin >> d;

    // 2. 清理缓冲区中的换行符（关键！）
    // cin >> d 读取完浮点数后，按下的回车键产生的 '\n' 留在了缓冲区
    // cin.ignore() 的作用就相当于 C 语言里的 getchar()，用来吃掉这个换行符
    cin.ignore();

    // 3. 读取带有空格的字符串
    // 在 C++ 中，读取带空格的一整行字符串通常使用 getline
    getline(cin, s);

    // 4. 输出整数
    cout << n << endl;

    // 5. 格式化输出浮点数，保留两位小数
    // fixed 表示使用固定的小数位数显示，setprecision(2) 设置位数为 2
    cout << fixed << setprecision(2) << d << endl;

    // 6. 输出字符串
    cout << s << endl;

    return 0;
}