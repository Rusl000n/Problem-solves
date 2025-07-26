#include <iostream>
#include <queue>
#include <vector>

int main() {
    int n = 0;
    int s = 0;
    int e = 0;
    std::cin >> n >> s >> e;
    std::vector<std::vector<std::pair<int, int> > > gr(n + 1);
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            int w = 0;
            std::cin >> w;
            if (w != -1 && i != j) {
                gr[i].push_back(std::make_pair(j, w));
            }
        }
    }
    std::priority_queue<int> q;
    std::vector<int> dist(n + 1, n * n * n);
    dist[s] = 0;
    std::vector<int> parents(n + 1, 1);
    q.push(s);

    while (!q.empty()) {
        int x = q.top();
        q.pop();
        for (const auto to : gr[x]) {
            int w = to.second;
            if (dist[to.first] > dist[x] + w) {
                dist[to.first] = dist[x] + w;
                parents[to.first] = x;
                q.push(to.first);
            }
        }
    }
    if (dist[e] == n * n * n) {
        std::cout << -1;
    } else {
        std::vector<int> answer;
        int i = e;
        answer.push_back(i);
        while (i != s) {
            i = parents[i];
            answer.push_back(i);
        }
        for (int j = answer.size() - 1; j >= 0; --j) {
            std::cout << answer[j] << " ";
        }
    }
}
