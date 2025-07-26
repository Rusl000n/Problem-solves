#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct DisjointSets {

    std::vector<int> s;
    std::vector<int> p;

    int Find(int a) {
        int r = a;
        while (p[r] != -1) {
            r = p[r];
        }
        while (p[a] != -1) {
            int t = p[a];
            p[a] = r;
            a = t;
        }
        return r;
    }

   public:
    void Reset(int n) {
        s.clear();
        p.clear();
        s.resize(n);
        p.resize(n, -1);
        for (int i = 0; i < n; ++i) {
            s[i] = i;
        }
        std::cout << "RESET DONE\n";
    }

    void Join(int j, int k) {
        if (Find(j) == Find(k)) {
            std::cout << "ALREADY" << " " << j << " " << k << "\n";
        } else {
            p[Find(j)] = Find(k);
        }
    }

    bool Check(int j, int k) {
        if (Find(j) == Find(k)) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    std::string a;
    std::vector<std::string> words;
    DisjointSets work;
    while (std::getline(std::cin, a)) {
        if (!a.empty()) {
            std::stringstream s(a);
            std::string word;
            s >> word;
            if (word == "RESET") {
                int c;
                s >> c;
                work.Reset(c);
            } else {
                int c;
                int d;
                s >> c;
                s >> d;
                if (word == "JOIN") {
                    work.Join(c, d);
                } else {
                    if (work.Check(c, d)) {
                        std::cout << "YES\n";
                    } else {
                        std::cout << "NO\n";
                    }
                }
            }
        } else {
            break;
        }
    }
}