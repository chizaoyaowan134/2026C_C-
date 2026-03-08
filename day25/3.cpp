#include <cstdio>

int main() {
    int n, q;
    // 读取人数 n 和关系数 q
    scanf("%d %d", &n, &q);

    // 定义并初始化二维数组，全设为 0
    int likes[15][15] = {0}; 
    
    // 1. 读取数据，填写“喜欢关系表”
    for (int i = 0; i < q; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        likes[x][y] = 1; // 记录 x 喜欢 y
    }

    bool has_triangle = false; // 标记是否找到三方欢喜

    // 2. 暴力枚举所有可能的三人组合 (i, j, k)
    // 因为人是从 1 到 n 编号的，所以循环从 1 开始
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                // 3. 核心判断：如果 i喜欢j，且 j喜欢k，且 k喜欢i
                if (likes[i][j] == 1 && likes[j][k] == 1 && likes[k][i] == 1) {
                    has_triangle = true; // 找到了！打上标记
                }
            }
        }
    }

    // 根据标记输出结果
    if (has_triangle) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}