#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    int current = 1, maxResult = 1;
    for (int i = 1; i < s.length(); i++) {
        if (s[i] != s[i - 1]) {
            current++;
            maxResult = max(maxResult, current);
        } else {
            current = 1;
        }
    }
    cout << maxResult;
    return 0;
}