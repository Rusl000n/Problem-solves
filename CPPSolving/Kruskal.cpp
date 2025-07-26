#include <iostream>
#include <vector>
#include <algorithm>

struct trio {
   public:
    int u;
    int v;
    long long w;
    trio(int u = 0, int v = 0, int w = 0) : u(u), v(v), w(w) {};
};

class Krascal {
   private:
    std::vector<int> parent;
    std::vector<int> r;
   public:
    Krascal(int n) {
        parent.resize(n);
        r.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }
    void unite(int u, int v) {
        int a = find(u);
        int b = find(v);
        if (a != b) {
            if (r[a] > r[b]) {
                parent[b] = a;
            } else if (r[a] < r[b]) {
                parent[a] = b;
            } else {
                parent[b] = a;
                ++r[a];
            }
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n = 0;
    int m = 0;
    std::cin >> n >> m;
    if (m < n - 1) {
        std::cout << "NON-CONNECTED";
        return 0;
    }
    std::vector<trio> gr(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> gr[i].u >> gr[i].v >> gr[i].w;
    }
   
    std::sort(gr.begin(), gr.end(), [](const trio& a, const trio& b) {
        return a.w < b.w;
    });
    Krascal d(n);
    long long ans = 0;
    int cnt = 0;
    for (auto [u, v, w] : gr) {
        if (d.find(u) != d.find(v)) {
            d.unite(u, v);
            ans += w;
            cnt++;
            if (cnt == n - 1) {
                break;
            }
        }
    }
    if (cnt == n - 1) {
        std::cout << ans;
    } else {
        std::cout << "NON-CONNECTED";
    }
}
