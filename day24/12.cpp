#include <cstdio>
#include <cstring> // 为了使用 strlen 函数

int main() {
    char word[15]; // 这次只需要一个一维数组，装当前正在处理的这一个单词就行
    bool isFirst = true; // 用来记录是不是第一个单词，方便控制空格

    // 还是那个熟悉的配方：只要没到文件末尾，就一直读
    while (scanf("%s", word) != EOF) {
        
        // 如果不是第一个单词，就在前面加个空格隔开
        if (!isFirst) {
            printf(" ");
        }
        isFirst = false; // 处理完第一个单词后，把标记设为 false

        // 获取当前单词的长度
        int len = strlen(word);
        
        // 核心逻辑：从单词的最后一个字母开始，倒着往前打印
        for (int i = len - 1; i >= 0; i--) {
            printf("%c", word[i]); 
        }
    }

    return 0;
}