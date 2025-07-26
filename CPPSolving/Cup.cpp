#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int inf = INT_MAX;
int timemax = 1440;
int cup = 100;

struct trio {
    int to;
    int t;
    int w;

    trio(int to, int t, int w) : to(to), t(t), w(w) {};
};

bool can_deliver(int weight, int n, std::vector<std::vector<trio> >& gr) {
    int totw = 3000000 + weight * cup;
    std::vector<int> dist(n + 1, inf);
    dist[1] = 0;
    std::vector<bool> parent(n + 1, false);
    for (int i = 1; i < n + 1; ++i) {
        int u = -1;
        for (int v = 1; v < n + 1; ++v) {
            if (!parent[v] && (u == -1 || dist[v] < dist[u])) {
                u = v;
            }
        }
        if (u == -1) {
            break;
        }
        parent[u] = true;
        for (auto& [v, t, w] : gr[u]) {
            if (totw <= w && dist[u] != inf && dist[u] + t < dist[v]) {
                dist[v] = dist[u] + t;
            }
        }
    }
    return dist[n] <= timemax;
}

int main() {
    int n = 0;
    int m = 0;
    std::cin >> n >> m;
    std::vector<std::vector<trio> > gr(n + 1);

    for (int i = 0; i < m; ++i) {
        int u = 0;
        int v = 0;
        int t = 0;
        int w = 0;
        std::cin >> u >> v >> t >> w;
        trio rio(v, t, w);
        trio oir(u, t, w);
        gr[u].push_back(rio);
        gr[v].push_back(oir);
    }
    int l = 0, r = 10000000, ans = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (can_deliver(mid, n, gr)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    std::cout << ans << "\n";
    return 0;
}