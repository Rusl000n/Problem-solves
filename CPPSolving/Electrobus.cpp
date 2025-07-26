#include <iostream>
#include <queue>
#include <vector>

struct arrives {
    int to;
    int out;
    int in;
    arrives(int t_o, int ou_t, int i_n) : to(t_o), out(ou_t), in(i_n) {}
};

void Dijkstra(int& start, std::vector<std::vector<arrives> >& gr, std::vector<int>& dist) {
    std::queue<int> q;
    q.push(start);
    dist[start] = 0;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto i : gr[v]) {
            int to = i.to;
            int out = i.out;
            int in = i.in;
            if (dist[to] >= in && dist[v] <= out) {
                dist[to] = in;
                q.push(to);
            }
        }
    }
}

int main() {
    int n = 0;
    int start = 0;
    int end = 0;
    std::cin >> n >> start >> end;
    std::vector<std::vector<arrives> > gr(n + 1);
    int m = 0;
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        int a = 0;
        int b = 0;
        int o = 0;
        int in = 0;
        std::cin >> a >> o >> b >> in;
        arrives ar(b, o, in);
        gr[a].push_back(ar);
    }
    std::vector<int> times(n + 1, 1000000);
    Dijkstra(start, gr, times);
    std::cout << (times[end] == 1000000 ? -1 : times[end]);
}