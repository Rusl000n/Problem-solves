#include <iostream>
#include <vector>

std::vector<int> ans;
int key = 0;

void DFS(int v, std::vector<std::vector<int> >& gr, std::vector<int>& used) {
    used[v] = 1;
    ans.push_back(v);
    for (const auto& to : gr[v]) {
        if (used[to] == 1 && v == key) {
            return;
        }
        if (used[to] == 0) {
            DFS(to, gr, used);
            ans.push_back(v);

        }
    }
}

int main() {
    int n = 0;
    int m = 0;
    int v = 0;
    std::cin >> n >> m >> key;
    v = key;
    std::vector<std::vector<int> > gr(n + 1);
    for (int i = 0; i < m; ++i) {
        int a = 0;
        int b = 0;
        std::cin >> a >> b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    std::vector<int> used(n + 1, 0);
    DFS(v, gr, used);
    std::cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++i) {
        std::cout << ans[i] << " ";
    }
}
