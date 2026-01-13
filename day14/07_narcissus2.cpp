#include <cstdio>

int main() {

    int a, b;

    scanf("%d%d", &a, &b);

    bool first = false;

    for (int i = a; i <= b; i ++) {

        int o = i % 10;
        int p = (i / 10) % 10;
        int q = i / 100;

        if (o * o * o + p * p * p + q * q * q == i) {

            //如果之前已经输出过数字，则先输出一个空格（说明不是第一个）
            if (first) printf(" ");

            printf("%d", i);

            // 标记已经输出过数字
            // 下次再找到数字时，上面的if条件会成立，输出空格
            first = true;
        }
    }

    if (!first) printf("NO");




    // printf("%d %d %d", c, b, a);



    return 0;


}