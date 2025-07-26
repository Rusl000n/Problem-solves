#include <iostream>
#include <vector>

void DFS(int v, std::vector<std::vector<int> >& gr, std::vector<int>& used, int check, std::vector<int>& answer) {
    answer[v] += check;
    used[v] = 1;
    for (const auto& to : gr[v]) {
        if (used[to] == 0) {
            DFS(to, gr, used, check, answer);
        }
    }

}

int main() {
    int n = 0;
    int m = 0;
    std::cin >> n >> m;
    std::vector<std::vector<int> > gr(n + 1);
    for (int i = 0; i < m; ++i) {
        int a = 0;
        int b = 0;
        std::cin >> a >> b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    std::vector<int> used(n + 1, 0);
    std::vector<int> answer(n + 1, 0);
    int check = 0;
    int i = 1;
    while(i != n + 1) {
        if (used[i] == 0) {
            DFS(i, gr, used, ++check, answer);
        }
        ++i;
    }
    std::cout << check << "\n";
    for (int i = 1; i < n + 1; ++i) {
        std::cout << answer[i] << " ";
    }
} 
