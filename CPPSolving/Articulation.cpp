#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

std::set<int> answer;
int timer = 0;

void DFS(int v, int p, std::vector<std::vector<int> >& gr, std::vector<int>& used, std::vector<int>& tin,
         std::vector<int>& tout) {
    used[v] = 1;
    ++timer;
    int cnt = 0;
    tin[v] = timer;
    tout[v] = timer;
    for (const auto& to : gr[v]) {
        if (used[to] == 0) {
            DFS(to, v, gr, used, tin, tout);
            ++cnt;
            tout[v] = std::min(tout[to], tout[v]);
            if (p != -1 && tin[v] <= tout[to]) {
                answer.insert(v);
            }
        } else if (to != p) {
            tout[v] = std::min(tout[v], tin[to]);
        }
    }
    if (cnt >= 2 && p == -1) {
        answer.insert(v);
    }
}

int main() {
    int n = 0;
    int m = 0;
    std::cin >> n >> m;
    std::vector<std::vector<int> > gr(n + 1);
    for (int i = 0; i < m; ++i) {
        int u = 0;
        int v = 0;
        std::cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    std::vector<int> used(n + 1, 0);
    std::vector<int> tin(n + 1, 0);
    std::vector<int> tout(n + 1, 0);
    DFS(1, -1, gr, used, tin, tout);
    std::cout << answer.size() << "\n";
    for (auto i = answer.begin(); i != answer.end(); ++i) {
        std::cout << *i << "\n";
    }
}
