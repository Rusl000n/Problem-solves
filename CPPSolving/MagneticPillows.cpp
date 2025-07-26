#include <algorithm>
#include <iostream>
#include <vector>

const int MAX = 10000000;
int tim = 1;

void dfs(int v, int p, std::vector<std::vector<int> >& graph, std::vector<int>& used, std::vector<int>& d,
         std::vector<int>& up, std::vector<int>& arr) {
    used[v] = 1;
    d[v] = tim;
    up[v] = tim;
    ++tim;
    int cnt = 0;
    for (int to : graph[v]) {
        if (to == p) {
            continue;
        }
        if (used[to]) {
            up[v] = std::min(up[v], d[to]);
        } else {
            dfs(to, v, graph, used, d, up, arr);
            up[v] = std::min(up[v], up[to]);
            if ((up[to] >= d[v]) && (p != -1)) {
                arr[v] = 1;
            }
            cnt++;
        }
    }
    if ((p == -1) && (cnt > 1)) {
        arr[v] = 1;
    }
}

int main() {
    int n = 0;
    int m = 0;
    std::cin >> n >> m;
    std::vector<std::vector<int> > graph(n + m + 1);
    std::vector<int> used(n + m + 1, 0);
    std::vector<int> d(n + m + 1, 0);
    std::vector<int> up(n + m + 1, 0);
    std::vector<int> arr(n + m + 1, 0);
    for (int i = 1; i <= m; ++i) {
        int a = 0;
        int b = 0;
        int c = 0;
        std::cin >> a >> b >> c;
        graph[n + i].push_back(a);
        graph[a].push_back(n + i);
        graph[n + i].push_back(b);
        graph[b].push_back(n + i);
        graph[n + i].push_back(c);
        graph[c].push_back(n + i);
    }
    for (int i = 1; i <= n + m; ++i) {
        if (used[i] == 0) {
            dfs(i, -1, graph, used, d, up, arr);
        }
    }
    int ans = 0;
    for (int i = n + 1; i <= n + m; ++i) {
        if (arr[i]) {
            ans++;
        }
    }
    std::cout << ans << "\n";
    if (ans > 0) {
        for (int i = n + 1; i <= n + m; ++i) {
            if (arr[i]) {
                std::cout << i - n << " ";
            }
        }
        std::cout << "\n";
    }
    return 0;
}