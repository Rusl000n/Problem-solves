#include <iostream>
#include <string>
#include <vector>

bool isCycle = false;

void dfs(int v, std::vector<std::vector<int> >& gr, std::vector<int>& used) {
    used[v] = 1;
    for (int to : gr[v]) {
        if (used[to] == 0) {
            dfs(to, gr, used);
        } else if (used[to] == 1) { 
            isCycle = true;
        }
    }
    used[v] = 2;
}


int main() {
    int n = 0;
    std::cin >> n;
    std::vector<std::vector<int> > gr(n + 1);
    for (int i = 1; i < n; ++i) {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < n - i; ++j) {
            if (s[j] == 'R') {
                gr[i].push_back(j + i + 1);
            } else if (s[j] == 'B') {
                gr[j + i + 1].push_back(i);
            }
        }
    }
    std::vector<int> used(n + 1, 0);
    for (int i = 1; i < n + 1; ++i) {
        if (used[i] == 0) {
            dfs(i, gr, used);
        }
    }
    if (isCycle) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
    }
}