#include <cstdio>

int main() {
    int n, q;
    // 读取 n (人数) 和 q (关系组数)
    scanf("%d %d", &n, &q);

    // 定义一个二维数组来记录喜欢关系。
    // 因为 n 最大是 10，我们开一个 15x15 的数组就足够安全了。
    // 初始化全为 0，表示一开始大家互相都没有记录喜欢关系。
    int likes[15][15] = {0};

    // 定义一个布尔变量，用来标记是否找到了双向喜欢的情况
    bool has_mutual = false;

    // 循环读取 q 组关系
    for (int i = 0; i < q; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);

        // 记录单向喜欢：x 喜欢 y
        likes[x][y] = 1;

        // 核心判断：查表看看 y 之前有没有登记过喜欢 x ？
        if (likes[y][x] == 1) {
            has_mutual = true; // 如果有，说明找到了双向喜欢！
        }
    }

    // 根据标记的结果输出 Yes 或 No
    if (has_mutual) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}