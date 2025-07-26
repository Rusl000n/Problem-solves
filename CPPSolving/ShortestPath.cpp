#include <iostream>
#include <vector>
#include <set>
#include <functional>

struct trio {
    int from = 0;
    int to = 0;
    int64_t weight = 0;
};

int main() {
    int n = 0;
    int m = 0;
    int s = 0;
    std::cin >> n >> m >> s;
    ++n;

    std::vector<trio> edges(m);
    for (auto& [f, t, w] : edges) {
        std::cin >> f >> t >> w;
    }

    const int64_t inf = 1000000000000000000;
    std::vector<int64_t> dist(n, inf);
    dist[s] = 0;
    std::set<int> be_negative;

    for (int k = 1; k <= n; ++k) {
        for (const auto& [f, t, w] : edges) {
            if (dist[f] == inf) { continue;
}
            if (dist[t] > dist[f] + w) {
                dist[t] = dist[f] + w;
                if (k == n) {
                    be_negative.insert(t);
                }
            }
        }
    }

    std::vector<std::vector<int> > gr(n);
    for (const auto& [f, t, w] : edges) {
        gr[f].push_back(t);
    }

    std::vector<int> used(n, false);
    std::function<void(int)> dfs = [&](int v) {
        used[v] = true;
        for (auto to : gr[v]) {
            if (!used[to]) {
                dfs(to);
            }
        }
    };

    for (int v : be_negative) {
        if (!used[v]) {
            dfs(v);
        }
    }

    for (int i = 1; i < n; ++i) {
        if (dist[i] == inf) {
            std::cout << "*\n";
        } else if (used[i]) {
            std::cout << "-\n";
        } else {
            std::cout << dist[i] << '\n';
        }
    }

    return 0;
}