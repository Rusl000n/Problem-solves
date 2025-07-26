#include<iostream>
#include<vector>

int lgn = 20;
std::vector<std::vector<int> > gr;
std::vector<std::vector<int> > dp;
std::vector<int> h;

void dfs(int v, int par) {
    h[v] = h[par] + 1;
    dp[v][0] = par; // прыгаем на 2 в степени ноль
    for (auto to : gr[v]) {
        if (to != par) {
            dfs(to, v);
        }
    }
}

int lca(int u, int v) {
    if (h[u] > h[v]) {
        std::swap(u, v);
    }
    for (int k = lgn; k >= 0; --k) {
        int to = dp[v][k];
        if (h[to] >= h[u]) {
            v = to;
        }
    }
    if (u == v) return u;
    for (int k = lgn; k >= 0; --k) {
        if (dp[u][k] != dp[v][k]) {
            u = dp[u][k];
            v = dp[v][k];
        }
    }
    return dp[u][0]; // dp[v][0]
}

int main() {
    int n = 0, m = 0;
    std::cin >> n >> m;
    gr.resize(n);
    h.resize(n);
    dp.resize(n, std::vector<int>(lgn + 1));
    for (int u = 1; u < n; ++u) {
        int v = 0;
        std::cin >> v;
        gr[v].push_back(u);
        gr[u].push_back(v);
    }
    dfs(0, 0);
    for(int k = 1; k < lgn; ++k) {
        for (int v = 0; v < n; ++v) {
            dp[v][k] = dp[dp[v][k - 1]][k - 1];
        }
    }
    long long a1 = 0, a2 = 0, x = 0, y = 0, z = 0;
    std::cin >> a1 >> a2 >> x >> y >> z;
    int cur_v = 0;
    long long summ = 0;
    for (int i = 0; i < m; ++i) {
        cur_v = lca((a1 + cur_v) % n, a2);
        summ += cur_v;
        a1 = (x * a1 + y * a2 + z) % n;
        a2 = (x * a2 + y * a1 + z) % n;
    }
    std::cout << summ;
    return 0;
}