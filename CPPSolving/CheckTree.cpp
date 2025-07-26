#include <iostream>
#include <set>
#include <vector>

void dfs(int v, std::vector<std::vector<int> >& gr, std::vector<int>& used, bool& IsTree, int p = -1) {
    used[v] = 1;
    for (int to : gr[v]) {
        if (used[to] == 0) {
            dfs(to,gr, used, IsTree, v);
        } else if (to != p) {
            IsTree = false;
        }
    }
}

int main() {
    int n = 0;
    int m = 0;
    std::cin >> n >> m;
    if (m != n - 1) {
        std::cout << "NO";
        return 0;
    }
    std::vector<std::vector<int> > gr(n + 1);
    for (int i = 0; i < m; ++i) {
        int b = 0;
        int c = 0;
        std::cin >> b >> c;
        gr[b].push_back(c);
        gr[c].push_back(b);

    }

    std::vector<int> used(n + 1, 0);
    bool IsTree = true;

    dfs(1, gr, used, IsTree);
    if (!IsTree) {
        std::cout << "NO";
        return 0;
    }

    for (int i = 1; i < n + 1; ++i) {
        if (used[i] == 0) {
            std::cout << "NO";
            return 0;
        }
    }

    std::cout << "YES";
    return 0;
}
