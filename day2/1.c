#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 10000
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool inOrderCheck(struct TreeNode* node, int *prev) {
    if (node == NULL) {
        return true;
    }

    //遍历左子树
    if (!inOrderCheck(node->left, prev)) {
        return false;
    }

    if (node->val <= *prev) {
        return false;
    }

    *prev = node->val;

    //遍历右子树
    return inOrderCheck(node->right, prev);
}

bool isValidBST(struct TreeNode* root) {
    int prev = -1;
    return inOrderCheck(root, &prev);
}

int main() {


    return 0;

}
