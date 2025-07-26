#include<iostream>
#include<vector>

int GCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    if (a == 0) {
        return b;
    }
    return GCD(b, a % b);
}

class SegmentTree {
    struct Node {
        int64_t value_ = 0;
        int begin = 0;
        int end = 0;
        Node* left = nullptr;
        Node* right = nullptr;

        Node(int begin, int end) : begin(begin), end(end) {}

        void push() {
            if (begin + 1 != end && left == nullptr) {
                int mid = (begin + end) / 2;
                left = new Node(begin, mid);
                right = new Node(mid, end);
            }
        }

        void set(int index, int value) {
            push();
            if (begin + 1 == end) {
                value_ = value;
            } else if (index < (begin + end) / 2) {
                left->set(index, value);
                value_ = GCD(left->value_, right->value_);
            } else {
                right->set(index, value);
                value_ = GCD(left->value_, right->value_);
            }
        }

        int64_t get(int q_begin, int q_end) {
            if (q_begin <= begin && end <= q_end) {
                return value_;
            }
            if (q_end <= begin || end <= q_begin) {
                return 0;
            }
            push();
            return GCD(left->get(q_begin, q_end), right->get(q_begin, q_end));
        }

        ~Node() {
            delete left;
            delete right;
        }

    } *root = nullptr;

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
    SegmentTree st(1, n + 1);
    for (int i = 1; i <= n; ++i) {
        int64_t v = 0;
        std::cin >> v;
        st.set(i, v);
    }
    int q = 0;
    std::cin >> q;
    for (int i = 0; i < q; ++i) {
        char ch = 0;
        int a = 0, b = 0;
        std::cin >> ch >> a >> b;
        if (ch == 's') {
            std::cout << st.get(a, b + 1) << ' ';
        } else {
            st.set(a, b);
        }
    }
    return 0;
}