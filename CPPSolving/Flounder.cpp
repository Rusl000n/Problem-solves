#include <iostream>
#include <vector>
#include <algorithm>

int mD = 0;
int d = 0;
int mV = 0;
int num = 0;

void dfs(int v, std::vector<std::vector<int> >& gr, std::vector<int>& used) {
    used[v] = num + 1;
    if (++d > mD) {
        mD = d;
        mV = v;
    }
    for (auto to : gr[v]) {
        if (used[to] == num) {
            dfs(to, gr, used);
            --d;
        }
    }
}

int main() {
    int n = 0;
    int m = 0;
    std::cin >> n >> m;
    std::vector<std::vector<int> > gr(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int a = 0;
        int b = 0;
        std::cin >> a >> b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    std::vector<int> used(n + 1, num);
    int s = 1;
    dfs(s, gr, used);
    ++num;
    s = mV;
    mD = 0;
    d = 0;
    dfs(s, gr, used);
    std::cout << std::min(std::min(n, m + 1), (m + mD - 1) / 2 + 1);
}