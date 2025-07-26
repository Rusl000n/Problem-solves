#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

std::set<std::pair<int, int> > answer;
int timer = 0;

void DFS(int v, int p, std::vector<std::vector<int> >& gr, std::vector<int>& used, std::vector<int>& tin,
         std::vector<int>& tout) {
    used[v] = 1;
    ++timer;
    tin[v] = timer;
    tout[v] = timer;
    for (const auto& to : gr[v]) {
        if (used[to] == 0) {
            DFS(to, v, gr, used, tin, tout);
            tout[v] = std::min(tout[to], tout[v]);
            if (tin[v] < tout[to]) {
                answer.insert(std::make_pair(v, to));
            }
        } else if (to != p) {
            tout[v] = std::min(tout[v], tin[to]);
        }
    }
}

int main() {
    int n = 0;
    int m = 0;
    std::cin >> n >> m;
    std::vector<std::vector<int> > gr(n + 1);
    std::vector<std::pair<int, int> > inp;
    for (int i = 0; i < m; ++i) {
        int u = 0;
        int v = 0;
        std::cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
        inp.push_back(std::make_pair(u, v));
    }
    std::vector<int> used(n + 1, 0);
    std::vector<int> tin(n + 1, 0);
    std::vector<int> tout(n + 1, 0);
    DFS(1, -1, gr, used, tin, tout);
    std::vector<int> ans;
    for (auto j = answer.begin(); j != answer.end(); ++j) {
        int cnt = 0;
        int is = -1;
        for (const auto& i : inp) {
            ++cnt;
            if ((i.first == (*j).first && i.second == (*j).second) ||
                (i.first == (*j).second && i.second == (*j).first)) {
                if (is == -1) {
                    is = cnt;
                } else if (is != -1) {
                    is = -1;
                    break;
                }
            }
        }
        if (is != -1) {
            ans.push_back(is);
        }
    }
    std::cout << ans.size() << "\n";

    std::sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) {
      std::cout << ans[i] << " ";
    }
}
