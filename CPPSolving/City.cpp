#include <iostream>
#include <vector>

std::vector<int> parent;
int MaxD;
int max;

void dfs(int v, int d, std::vector<std::vector<int> >& gr, std::vector<int>& used) {
    used[v] = 1;
    if (d > MaxD) {
        MaxD = d;
        max = v;
    }
    for (int to : gr[v]) {
        if (used[to] == 0) {
            parent[to] = v;
            dfs(to, d + 1, gr, used);
        }
    }
}

int main() {
    int n = 0;
    std::cin >> n;
    std::vector<std::vector<int> > gr(n + 1);
    parent.resize(n + 1, -1);
    for (int i = 0; i < n - 1; ++i) {
        int u = 0;
        int v = 0;
        std::cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    MaxD = -1;
    std::vector<int> used(n + 1, 0);
    dfs(1, 0, gr, used);
    std::vector<int> us(n + 1, 0);
    parent.assign(n + 1, -1);
    MaxD = -1;
    dfs(max, 0, gr, us);
    std::vector<int> ans;
    for (int i = max; i != -1; i = parent[i]) {
        ans.push_back(i);
    }
    std::vector<int> center;
    if (ans.size() % 2 == 1) {
        center.push_back(ans[ans.size() / 2]);
    } else {
        center.push_back(ans[ans.size() / 2 - 1]);
        center.push_back(ans[ans.size() / 2]);
    }
    std::cout << ((MaxD % 2) == 0 ? MaxD / 2 : (MaxD + 1) / 2) << " " << center.size() << " ";
    for (int i : center) {
        std::cout << i << " ";
    }
}