#include <cstdio>

int main() {

    int n;
    int a[11];

    scanf("%d", &n);

    for (int i = 0; i < n; i ++) 
        scanf("%d", &a[i]);
    
    for (int i = 0; i < n - 1; i ++) 
        printf("%d ", a[i]);

    printf("%d", a[n - 1]);

    return 0;

}