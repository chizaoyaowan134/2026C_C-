#include <cstdio>

int main() {

    int a, b;

    scanf("%d%d", &a, &b);

    bool flag = false;
    for (int i = a; i <= b; i ++) {
        int x = i;

        int c = x / 100;
        int d = (x / 10) % 10;
        int e = x % 10;

        if ((c * c * c + d * d * d + e * e * e == x)) {
            if (flag) {
                // 如果之前已经找到过数字（说明这不是第一个），
                // 就要在当前数字前面加一个空格
                printf(" ");
            }
            // 打印数字本身
            printf("%d", i);
            // 将标记设为 true，表示已经找到过数字了
            // 下次再找到数字时，上面的 if(hasFound) 就会生效，打印空格
            flag = true;

        }
    }

    if (!flag) printf("NO");

    return 0;
}