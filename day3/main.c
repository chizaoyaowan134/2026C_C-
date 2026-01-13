#include <stdlib.h> // 用于 qsort, llabs
#include <limits.h> // 用于 LLONG_MAX
#include <math.h>   // 用于 llabs (或者在 stdlib.h 中)
#include <stdio.h>

/**
 * qsort 的比较函数
 */
int compare(const void* p1, const void* p2) {
    // 将 void 指针转换为 long long 以进行安全的比较，防止溢出
    long long val1 = *(const int*)p1;
    long long val2 = *(const int*)p2;

    if (val1 < val2) {
        return -1;
    } else if (val1 > val2) {
        return 1;
    } else {
        return 0;
    }
}

int smallestDifference(int* a, int aSize, int* b, int bSize) {
    // 1. 对两个数组进行排序
    qsort(a, aSize, sizeof(int), compare);
    qsort(b, bSize, sizeof(int), compare);

    // 2. 初始化双指针和最小差值
    int i = 0;
    int j = 0;
    long long min_diff = LLONG_MAX;

    // 3. 遍历数组
    while (i < aSize && j < bSize) {
        // 使用 long long 防止计算差值时溢出
        long long val_a = (long long)a[i];
        long long val_b = (long long)b[j];

        long long current_diff = val_a - val_b;
        long long abs_diff = llabs(current_diff); // 计算绝对值

        // 更新最小差值
        if (abs_diff < min_diff) {
            min_diff = abs_diff;
        }

        // 如果差值为 0，直接返回
        if (current_diff == 0) {
            return 0;
        }
        // 移动指向较小元素的指针
        else if (current_diff < 0) { // a[i] < b[j]
            i++;
        }
        else { // a[i] > b[j]
            j++;
        }
    }

    return (int)min_diff;
}


int main(void) {
    int a[] = {1, 3, 15, 11, 2};
    int b[] = {23, 127, 235, 19, 8};
    int aSize = sizeof(a) / sizeof(a[0]);
    int bSize = sizeof(b) / sizeof(b[0]);

    int result = smallestDifference(a, aSize, b, bSize);
    printf(":\n");
    printf("a = {1, 3, 15, 11, 2}\n");
    printf("b = {23, 127, 235, 19, 8}\n");
    printf(": %d\n", result); // 预期输出: 3

    return 0;
}