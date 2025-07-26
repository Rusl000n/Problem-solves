#include <cmath>
#include <iostream>
#include <vector>

struct trio {
    int x;
    int y;
    int w;

    trio(int x = 1, int y = 1, int w = 0) : x(x), y(y), w(w) {}
};

class LCA {
   public:
    LCA(std::vector<trio>& gr) : n(gr.size() + 1), LOGN(std::log2(n) + 1) {
        parents.resize(n, std::vector<int>(LOGN));
        vals.resize(n, std::vector<int>(LOGN, 10000000));
        deep.resize(n);
        for (auto [x, y, w] : gr) {
            if (x > y) {
                std::swap(x, y);
            }
            parents[y][0] = x;
            vals[y][0] = w;
        }
        parents[0][0] = 0;
        vals[0][0] = 10000000;
        for (int i = 1; i < n; ++i) {
            deep[i] = deep[parents[i][0]] + 1;
        }
        for (int j = 1; j < LOGN; ++j) {
            for (int i = 0; i < n; ++i) {
                parents[i][j] = parents[parents[i][j - 1]][j - 1];
                vals[i][j] = std::min(vals[parents[i][j - 1]][j - 1], vals[i][j - 1]);
            }
        }
    }

    int genMin(int x, int y) {
        int res = 10000000;
        if (deep[x] < deep[y]) {
            std::swap(x, y);
        }
        for (int i = LOGN - 1; i >= 0; --i) {
            if (deep[x] - (1 << i) >= deep[y]) {
                res = std::min(res, vals[x][i]);
                x = parents[x][i];
            }
        }
        if (x == y) {
            return res;
        }
        for (int i = LOGN - 1; i >= 0; --i) {
            if (parents[x][i] != parents[y][i]) {
                res = std::min(res, std::min(vals[x][i], vals[y][i]));
                x = parents[x][i];
                y = parents[y][i];
            }
        }
        res = std::min(res, std::min(vals[x][0], vals[y][0]));
        return res;
    }

   private:
    int n;
    int LOGN;
    std::vector<std::vector<int> > parents;
    std::vector<std::vector<int> > vals;
    std::vector<int> deep;
};

int main() {
    int n = 0;
    std::cin >> n;
    std::vector<trio> gr(n - 1);
    for (int i = 1; i < n; ++i) {
        std::cin >> gr[i - 1].x >> gr[i - 1].w;
        --gr[i - 1].x;
        gr[i - 1].y = i;
    }
    LCA tree(gr);
    int k = 0;
    std::cin >> k;
    while (k--) {
        int a = 0;
        int b = 0;
        std::cin >> a >> b;
        std::cout << tree.genMin(--a, --b) << "\n";
    }
}