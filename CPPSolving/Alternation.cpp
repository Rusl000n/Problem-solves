#include <iostream>
#include <vector>

class SegmentTree {
   private:
    struct Node {
        int64_t value = 0;
        int begin = 0;
        int end = 0;
        Node* left = nullptr;
        Node* right = nullptr;
        Node(int begin, int end) : begin(begin), end(end) {
        }
        void push() {
            if (begin + 1 != end && left == nullptr) {
                int mid = (begin + end) / 2;
                left = new Node(begin, mid);
                right = new Node(mid, end);
            }
        }
        void set(int index, int64_t val) {
            push();
            if (begin + 1 == end) {
                value = val;
            } else {
                if (index < left->end) {
                    left->set(index, val);
                } else {
                    right->set(index, val);
                }
                value = left->value + right->value;
            }
        }
        int64_t get(int q_begin, int q_end) {
            if (q_begin >= q_end)
                return 0;
            if (q_begin <= begin && end <= q_end) {
                return value;
            }
            if (q_end <= begin || end <= q_begin) {
                return 0;
            }
            push();
            return left->get(q_begin, q_end) + right->get(q_begin, q_end);
        }
        ~Node() {
            delete left;
            delete right;
        }
    }* root = nullptr;
   public:
    SegmentTree(int begin, int end) {
        root = new Node(begin, end);
    }
    void set(int index, int64_t value) {
        root->set(index, value);
    }
    int64_t get(int q_begin, int q_end) {
        return root->get(q_begin, q_end);
    }
    ~SegmentTree() {
        delete root;
    }
};

int main() {
    int n = 0;
    std::cin >> n;
    SegmentTree treeone(1, n + 1);
    SegmentTree treetwo(1, n + 1);
    for (int i = 1; i <= n; ++i) {
        int a = 0;
        std::cin >> a;
        if (i % 2 == 1) {
            treetwo.set(i, a);
        } else {
            treeone.set(i, a);
        }
    }
    int m = 0;
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        int type = 0;
        int a = 0;
        int b = 0;
        std::cin >> type >> a >> b;
        if (type == 1) {
            int len = b - a + 1;
            int64_t odd_sum = treetwo.get(a, b + 1);
            int64_t even_sum = treeone.get(a, b + 1);
            int64_t res = odd_sum - even_sum;
            if (a % 2 == 0) {
                res = -res;
            }
            std::cout << res << '\n';
        } else {
            if (a % 2 == 1) {
                treetwo.set(a, b);
            } else {
                treeone.set(a, b);
            }
        }
    }
}