#include <ctime>
#include <iostream>
#include <random>
#include <vector>

std::mt19937_64 rd(time(0));

class CartesianSet {
   private:
    struct Node {
        long long value;
        int priority = rd() % 1000;
        Node* left = nullptr;
        Node* right = nullptr;
        long long sumValue;

        Node(long long value) : value(value), sumValue(value) {
        }
    };

   public:
    void insert(long long value) {
        if (!Find(root, value)) {
            auto [less, more] = Split(root, value);
            root = Merge(Merge(less, new Node(value)), more);
        }
    }

    long long sumValueRange(long long left, long long right) {
        auto [L, R] = Split(root, right);
        auto [T, M] = Split(L, left - 1);
        long long ans = M ? M->sumValue : 0;
        root = Merge(Merge(T, M), R);
        return ans;
    }

   private:
    Node* root = nullptr;

    void reSum(Node* A) {
        if (A == nullptr) {
            return;
        }
        A->sumValue = A->value;
        A->sumValue += (A->left != nullptr ? A->left->sumValue : 0);
        A->sumValue += (A->right != nullptr ? A->right->sumValue : 0);
    }

    std::pair<Node*, Node*> Split(Node* A, long long key) {
        if (!A) {
            return std::make_pair(nullptr, nullptr);
        }
        if (A->value > key) {
            auto [less, more] = Split(A->left, key);
            A->left = more;
            reSum(A);
            return std::make_pair(less, A);
        } else {
            auto [less, more] = Split(A->right, key);
            A->right = less;
            reSum(A);
            return std::make_pair(A, more);
        }
    }

    Node* Merge(Node* A, Node* B) {
        if (A == nullptr) {
            return B;
        }
        if (B == nullptr) {
            return A;
        }
        if (A->priority > B->priority) {
            A->right = Merge(A->right, B);
            reSum(A);
            return A;
        } else {
            B->left = Merge(A, B->left);
            reSum(B);
            return B;
        }
    }

    bool Find(Node* A, long long key) {
        if (A == nullptr) {
            return false;
        }
        if (A->value == key) {
            return true;
        }
        return (key < A->value) ? Find(A->left, key) : Find(A->right, key);
    }
};

int main() {
    int n = 0;
    std::cin >> n;
    CartesianSet tree;
    long long flag = 0;
    while (n--) {
        char com;
        std::cin >> com;
        if (com == '+') {
            long long v = 0;
            std::cin >> v;
            if (flag != 0) {
                tree.insert(((v + flag) % 1000000000));
            } else {
                tree.insert(v);
            }
            flag = 0;
        } else if (com == '?') {
            long long l = 0;
            long long r = 0;
            std::cin >> l >> r;
            long long ans = tree.sumValueRange(l, r);
            std::cout << ans << "\n";
            flag = ans;
        }
    }
}