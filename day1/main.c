#include <stdio.h>
#include <stdlib.h> // 用于 malloc 和 free

// 声明函数
void merge(int arr[], int left, int mid, int right);
void mergeSort(int arr[], int left, int right);
void printArray(int A[], int size);

// 主函数，用于测试
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7, 2, 9};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("给定的数组是 \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\n排序后的数组是 \n");
    printArray(arr, arr_size);
    return 0;
}

/**
 * @brief 合并两个已排序的子数组
 * * @param arr 原始数组
 * @param left 左边子数组的起始索引
 * @param mid 中间点索引
 * @param right 右边子数组的结束索引
 */
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1; // 左边子数组的长度
    int n2 = right - mid;    // 右边子数组的长度

    // 1. 创建临时数组来存储左右两个子数组
    // 使用 malloc 动态分配内存
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    // 检查内存分配是否成功
    if (L == NULL || R == NULL) {
        printf("内存分配失败\n");
        exit(1); // 异常退出
    }

    // 2. 将数据拷贝到临时数组 L[] 和 R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // 3. 归并临时数组到原数组 arr[left...right]
    i = 0; // 初始化左边子数组的索引
    j = 0; // 初始化右边子数组的索引
    k = left; // 初始化归并后的主数组的索引

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // 4. 处理剩余的元素
    // 如果 L[] 中还有剩余元素，拷贝它们
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    // 如果 R[] 中还有剩余元素，拷贝它们
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // 5. 释放动态分配的内存
    free(L);
    free(R);
}

/**
 * @brief 归并排序主函数（递归）
 * * @param arr 要排序的数组
 * @param left 数组的起始索引
 * @param right 数组的结束索引
 */
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // 1. 分解：找到中间点，防止 (left+right) 溢出
        int mid = left + (right - left) / 2;

        // 2. 解决：递归地对左右两个子数组进行排序
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // 3. 合并：将两个已排序的子数组合并
        merge(arr, left, mid, right);
    }
}

/**
 * @brief 打印数组的辅助函数
 * * @param A 数组
 * @param size 数组大小
 */
void printArray(int A[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}