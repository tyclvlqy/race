#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
string variableName;
int main() { 
        queue<int> q;
        string ans;
        cin >> variableName;
        int len = variableName.size();
        for (int i = 0; i < len; i++) {
                if (variableName[i] == '_')
                q.push(i);
            }
            while(q.size()) {
                variableName[q.front() + 1] -= 32;
                q.pop();
            }
            for (int i = 0; i < len; i++) {
                if(variableName[i] == '_')
                variableName.erase(i, 1);
            }
            cout << variableName;
}