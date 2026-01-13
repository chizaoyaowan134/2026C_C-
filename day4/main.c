#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

//辅助函数：反转一个链表，并返回新的头节点
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while (curr != NULL) {
        struct ListNode* nextTemp = curr->next;     //暂存下一个节点
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}


void reorderList(struct ListNode* head) {
    if (head == NULL || head->next == NULL || head->next->next == NULL) {
        return;
    }

    //使用快慢指针找到链表的中间节点
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode* second_half = reverseList(slow->next);
    slow->next = NULL;

    struct ListNode* first_half = head;
    while (second_half != NULL) {
        struct ListNode* temp1 = first_half->next;
        struct ListNode* temp2 = second_half->next;

        // 进行穿插连接
        // 1. 前半部分的当前节点指向后半部分的当前节点
        first_half->next = second_half;
        // 2. 后半部分的当前节点指向前半部分的原下一个节点
        second_half->next = temp1;

        // 移动指针到下一个位置，准备下一次合并
        first_half = temp1;
        second_half = temp2;
    }
}

int main(void) {
    printf("Hello, World!\n");
    return 0;
}