#include <iostream>
#include <vector>
#include <algorithm>

bool dfs(int v, std::vector<std::vector<int> >& gr, std::vector<int>& used,
         std::vector<int>& path, std::vector<int>& cycle, bool& IsCycle) {
    used[v] = 1;
    path.push_back(v);
    for (int u : gr[v]) {
        if (used[u] == 0) {
            if (dfs(u, gr, used, path, cycle, IsCycle)) {
                return true;
            }
        } else if (used[u] == 1) {
            IsCycle = true;
            auto it = std::find(path.begin(), path.end(), u);
            cycle.assign(it, path.end());
            cycle.push_back(u);
            return true;
        }
    }
    used[v] = 2;
    path.pop_back();
    return false;
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
    }
    std::vector<int> used(n + 1, 0); 
    std::vector<int> path;
    std::vector<int> cycle;
    bool IsCycle = false;
    for (int i = 1; i <= n; ++i) {
        if (used[i] == 0) {
            if (dfs(i, gr, used, path, cycle, IsCycle)) {
                break;
            }
        }
    }
    if (IsCycle) {
        std::cout << "YES" << "\n";
        for (int i = 0; i < cycle.size() - 1; ++i) {
            std::cout << cycle[i] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "NO";
    }
    return 0;
}
