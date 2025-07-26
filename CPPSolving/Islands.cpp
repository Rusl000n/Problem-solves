#include <deque>
#include <iostream>
#include <vector>

int main() {
    int n = 0;
    int m = 0;
    std::cin >> n >> m;
    std::vector<int> inp(n + 1);
    std::vector<std::vector<int> > gr(n + 1);
    for (int i = 1; i < n + 1; ++i) {
        std::cin >> inp[i];
    }
    for (int i = 0; i < m; ++i) {
        int a = 0;
        int b = 0;
        std::cin >> a >> b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    int inf = n * m;
    std::vector<int> steps(n + 1, 0);
    std::vector<int> parent(n + 1, -1);
    std::vector<int> cost(n + 1, inf);
    std::deque<int> q;
    cost[1] = 0;
    steps[1] = 1;
    q.push_back(1);
    bool flag = false;
    while (!q.empty()) {
        int u = q.front();
        q.pop_front();
        if (u == n) {
            flag = true;
            break;
        }
        for (int v : gr[u]) {
            int cc = cost[u];
            if (inp[u] != inp[v]) {
                cc += 1;
            }
            if (cc < cost[v]) {
                steps[v] = steps[u] + 1;
                parent[v] = u;
                cost[v] = cc;
                if (inp[u] == inp[v]) {
                    q.push_front(v);
                } else {
                    q.push_back(v);
                }
            } else if (cc == cost[v] && steps[u] + 1 < steps[v]) {
                steps[v] = steps[u] + 1;
                parent[v] = u;
                if (inp[u] == inp[v]) {
                    q.push_front(v);
                } else {
                    q.push_back(v);
                }
            }
        }
    }
    if (!flag) {
        std::cout << "impossible";
        return 0;
    }
    std::vector<int> answer;
    int node = n;
    while (node != -1) {
        answer.push_back(node);
        node = parent[node];
    }

    std::cout << cost[n] << " " << answer.size() << "\n";
    for (int i = answer.size() - 1; i >= 0; --i) {
        std::cout << answer[i] << " ";
    }
}
