#include <ctime>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

std::mt19937_64 rd(time(0));

struct Node {
    int v;
    int y = rd() % 1000;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(int v) : v(v) {
    }

    ~Node() {
        delete left;
        delete right;
    }
};

class CartesianTree {
   public:
    void insert(int key) {
        if (!Find(root, key)) {
            auto [l, r] = Split(root, key);
            root = Merge(Merge(l, new Node(key)), r);
        }
    }

    void deleteKey(int key) {
        Erase(root, key);
    }

    bool exists(int key) {
        return Find(root, key);
    }

   private:
    Node* root = nullptr;

    Node* Merge(Node* A, Node* B) {
        if (A == nullptr) {
            return B;
        }
        if (B == nullptr) {
            return A;
        }
        if (A->y > B->y) {
            A->right = Merge(A->right, B);
            return A;
        }
        B->left = Merge(A, B->left);
        return B;
    }

    std::pair<Node*, Node*> Split(Node* A, int key) {
        if (A == nullptr) {
            return std::make_pair(nullptr, nullptr);
        }
        if (A->v > key) {
            auto [l, r] = Split(A->left, key);
            A->left = r;
            return std::make_pair(l, A);
        }
        auto [l, r] = Split(A->right, key);
        A->right = l;
        return std::make_pair(A, r);
    }

    void Erase(Node*& A, int key) {
        if (A == nullptr) {
            return;
        }
        if (A->v == key) {
            Node* temp = A;
            A = Merge(A->left, A->right);
            temp->left = temp->right = nullptr;
            delete temp;
        } else {
            Erase((key < A->v ? A->left : A->right), key);
        }
    }

    bool Find(Node* A, int key) {
        if (A == nullptr) {
            return false;
        }
        if (A->v == key) {
            return true;
        }
        if (A->v > key) {
            return Find(A->left, key);
        } else {
            return Find(A->right, key);
        }
    }
};

int main() {
    std::string a;
    CartesianTree tree;
    while (true) {
        if (std::getline(std::cin, a)) {
            std::stringstream ss(a);
            std::string b;
            std::string c;
            ss >> b;
            ss >> c;
            int key = std::stoi(c);
            if (b[0] == 'i') {
                tree.insert(key);
            } else if (b[0] == 'e') {
                std::cout << (tree.exists(key) ? "true\n" : "false\n");
            } else if (b[0] == 'd') {
                tree.deleteKey(key);
            }
        } else {
            break;
        }
    }
}
