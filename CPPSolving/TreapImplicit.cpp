#include <ctime>
#include <iostream>
#include <random>
#include <string>

std::mt19937_64 rd(time(0));

struct Node {
    Node* left = nullptr;
    Node* right = nullptr;
    int64_t value = 0;
    int sz = 1;
    uint64_t pr = rd();
    Node(int64_t val) : value(val) {
    }
};

class Tree {
   private:
    Node* root = nullptr;


    int size(Node* tree) {
        return tree != nullptr ? tree->sz : 0;
    }

    void update(Node* tree) {
        if (tree == nullptr)
            return;
        tree->sz = size(tree->left) + size(tree->right) + 1;
    }

    std::pair<Node*, Node*> split(Node* tree, int64_t count) {
        if (tree == nullptr) {
            return std::make_pair(nullptr, nullptr);
        }
        if (size(tree->left) >= count) {
            auto [less, more] = split(tree->left, count);
            tree->left = more;
            update(tree);
            return std::make_pair(less, tree);
        }
        auto [less, more] = split(tree->right, count - size(tree->left) - 1);
        tree->right = less;
        update(tree);
        return std::make_pair(tree, more);
    }

    Node* merge(Node* less, Node* more) {
        if (less == nullptr) {
            return more;
        }
        if (more == nullptr) {
            return less;
        }
        if (less->pr < more->pr) {
            more->left = merge(less, more->left);
            update(more);
            return more;
        }
        less->right = merge(less->right, more);
        update(less);
        return less;
    }

    void print(Node* tree) {
        if (tree == nullptr) {
            return;
        }
        print(tree->left);
        std::cout << tree->value << ' ';
        print(tree->right);
    }


   public:
    void insert(int index, int64_t value) {
        auto [less, more] = split(root, index);
        root = merge(merge(less, new Node(value)), more);
    }

    int getSize() {
        return size(root);
    }

    void erase(int index) {
        auto [less, m] = split(root, index);
        auto [l, more] = split(m, 1);
        delete l;
        root = merge(less, more);

    }
    
    void print() {
        print(root);
    }
};

int main() {
    int n = 0;
    int k = 0;
    std::cin >> n >> k;
    Tree t;
    for (int i = 0; i < n; ++i) {
        int a = 0;
        std::cin >> a;
        t.insert(i, a);
    }
    while (k--) {
        std::string com;
        std::cin >> com;
        if (com == "del") {
            long long a = 0;
            std::cin >> a;
            t.erase(a - 1);
        } else if (com == "add") {
            int x = 0;
            int i = 0;
            std::cin >> i >> x;
            t.insert(i, x);
        }
    }
    std::cout << t.getSize() << '\n';
    t.print();
    return 0;
}