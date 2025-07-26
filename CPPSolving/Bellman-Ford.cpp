#include <iostream>
#include <queue>
#include <vector>

int main() {
    int n = 0;
    int m = 0;
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<int, int> > > gr(n + 1);
    for (int i = 0; i < m; ++i) {
        int a = 0;
        int b = 0;
        int w = 0;
        std::cin >> a >> b >> w;
        gr[a].push_back(std::make_pair(b, w));
    }
    std::queue<int> q;
    std::vector<int> dist(n + 1, 30000);
    dist[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto& [to, w] : gr[v]) {
            if (dist[to] > dist[v] + w) {
                dist[to] = dist[v] + w;
                q.push(to);
            }
        }
    }
    for (int i = 1; i < n + 1; ++i) {
        std::cout << dist[i] << " ";
    }
}