#include <iostream>
#include <vector>

struct Tree {
   public:
    Tree(int n) : n(n) {
        tree.resize(n * 4, 0);
        lazyTree.resize(n * 4, -1);
    }

    void setValueRange(int l, int r, long long x) {
        leftValue = l;
        rightValue = r;
        newValue = x;
        SetValueRange(0, 0, n);
    }

    long long sumRange(int l, int r) {
        leftValue = l;
        rightValue = r;
        return SumRange(0, 0, n);
    }

   private:
    int n;
    std::vector<long long> tree;
    std::vector<long long> lazyTree;

    int leftValue;
    int rightValue;
    long long newValue;

    long long SetValueRange(int v, int left, int right) {
        if (left >= rightValue || right <= leftValue) {
            return tree[v];
        }
        if (left >= leftValue && right <= rightValue) {
            tree[v] = newValue * ((right - left) < 1 ? 1 : right - left);
            lazyTree[v] = newValue;
            return tree[v];
        }
        LazyPush(v, left, right);
        int mid = (left + right) / 2;
        tree[v] = SetValueRange(v * 2 + 1, left, mid) + SetValueRange(v * 2 + 2, mid, right);
        return tree[v];
    }

    long long SumRange(long long v, int left, int right) {
        if (left >= rightValue || right <= leftValue) {
            return 0;
        }
        if (left >= leftValue && right <= rightValue) {
            return tree[v];
        }
        LazyPush(v, left, right);
        int mid = (left + right) / 2;
        return SumRange(v * 2 + 1, left, mid) + SumRange(v * 2 + 2, mid, right);
    }

    void LazyPush(long long v, int left, int right) {
        if (lazyTree[v] == -1) {
            return;
        }
        if (left + 1 < right) {
            int mid = (left + right) / 2;
            tree[v * 2 + 1] = lazyTree[v] * (mid - left);
            lazyTree[v * 2 + 1] = lazyTree[v];
            tree[v * 2 + 2] = lazyTree[v] * (right - mid);
            lazyTree[v * 2 + 2] = lazyTree[v];
        }
        lazyTree[v] = -1;
    }
};

int main() {
    int n = 0;
    int k = 0;
    std::cin >> n >> k;
    Tree tree(n);
    while (k--) {
        char c;
        std::cin >> c;
        if (c == 'A') {
            int l = 0;
            int r = 0;
            long long v = 0;
            std::cin >> l >> r >> v;
            tree.setValueRange(l - 1, r, v);
        } else if (c == 'Q') {
            int l = 0;
            int r = 0;
            std::cin >> l >> r;
            std::cout << tree.sumRange(l - 1, r) << "\n";
        }
    }
}