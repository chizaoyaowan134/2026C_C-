#include <stdio.h>
#include <stdlib.h> // For malloc and free

// 辅助函数：交换两个整数的值
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 小顶堆的下沉调整（堆化）
// a: 存储堆的数组
// heapSize: 堆的大小
// i: 需要进行下沉调整的节点索引
void minHeapify(int* a, int heapSize, int i) {
    int smallest = i;     // 假设当前节点是最小的
    int left = 2 * i + 1; // 左子节点
    int right = 2 * i + 2; // 右子节点

    // 如果左子节点存在且比当前节点小，更新 smallest
    if (left < heapSize && a[left] < a[smallest]) {
        smallest = left;
    }

    // 如果右子节点存在且比当前节点小，更新 smallest
    if (right < heapSize && a[right] < a[smallest]) {
        smallest = right;
    }

    // 如果最小的不是当前节点 i，则交换它们，并继续对被交换的子节点进行下沉调整
    if (smallest != i) {
        swap(&a[i], &a[smallest]);
        minHeapify(a, heapSize, smallest);
    }
}

// 构建小顶堆
// a: 存储堆的数组
// heapSize: 堆的大小
void buildMinHeap(int* a, int heapSize) {
    // 从最后一个非叶子节点开始，自下而上进行堆化
    for (int i = heapSize / 2 - 1; i >= 0; i--) {
        minHeapify(a, heapSize, i);
    }
}

int findKthLargest(int* nums, int numsSize, int k) {
    if (k > numsSize || k <= 0) {
        // 无效输入处理
        return -1;
    }

    // 1. 创建一个大小为 k 的堆，并用数组前 k 个元素初始化
    int* heap = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        heap[i] = nums[i];
    }

    // 2. 将这 k 个元素构建成一个小顶堆
    buildMinHeap(heap, k);

    // 3. 遍历数组中剩余的元素
    for (int i = k; i < numsSize; i++) {
        // 如果当前元素比堆顶（k个元素中的最小值）大
        if (nums[i] > heap[0]) {
            // 替换堆顶元素
            heap[0] = nums[i];
            // 重新调整堆，保持小顶堆性质
            minHeapify(heap, k, 0);
        }
    }

    // 4. 遍历结束后，堆顶元素就是第 k 大的元素
    int result = heap[0];

    // 释放动态分配的内存
    free(heap);

    return result;
}

// 主函数，用于测试
int main() {
    // 示例 1
    int nums1[] = {3, 2, 1, 5, 6, 4};
    int k1 = 2;
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    int result1 = findKthLargest(nums1, size1, k1);
    printf("%d\n", k1);
    printf("%d\n\n", result1); // 预期输出: 5

    // 示例 2
    int nums2[] = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k2 = 4;
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    int result2 = findKthLargest(nums2, size2, k2);
    printf("%d\n", k2);
    printf("%d\n\n", result2); // 预期输出: 4

    return 0;
}