#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>


struct Tree {
   public:
    Tree(std::vector<long long>& arr) : n(1) {
        while (n < arr.size()) {
            n *= 2;
        }
        tree.resize(n * 2, 0);
        lazyTree.resize(n * 2, 0);
        for (int i = 0; i < arr.size(); ++i) {
            tree[n + i] = arr[i];
        }
        for (int i = n - 1; i > 0; --i) {
            tree[i] = std::max(tree[i * 2], tree[i * 2 + 1]);
        }
    }

    void addValueRange(int l, int r, long long x) {
        leftValue = l;
        rightValue = r;
        newValue = x;
        AddValueRange(1, 0, n);
    }

    long long maxValueRange(int l, int r) {
        leftValue = l;
        rightValue = r;
        return MaxValueRange(1, 0, n);
    }

   private:
    int n;
    std::vector<long long> tree;
    std::vector<long long> lazyTree;

    int leftValue;
    int rightValue;
    long long newValue;

    void LazyAdd(int v, int left, int right) {
        if (lazyTree[v] != 0) {
            tree[v] += lazyTree[v];
            if (left + 1 != right) {
                lazyTree[v * 2] += lazyTree[v];
                lazyTree[v * 2 + 1] += lazyTree[v];
            }
            lazyTree[v] = 0;
        }
    }

    void AddValueRange(int v, int left, int right) {
        LazyAdd(v, left, right);
        if (right <= leftValue || rightValue <= left) {
            return;
        }
        if (leftValue <= left && right <= rightValue) {
            lazyTree[v] += newValue;
            LazyAdd(v, left, right);
            return;
        }
        int mid = (left + right) / 2;
        AddValueRange(v * 2, left, mid);
        AddValueRange(v * 2 + 1, mid, right);
        tree[v] = std::max(tree[v * 2], tree[v * 2 + 1]);
    }

    long long MaxValueRange(int v, int left, int right) {
        LazyAdd(v, left, right);
        if (right <= leftValue || rightValue <= left) {
            return LLONG_MIN;
        }
        if (leftValue <= left && right <= rightValue) {
            return tree[v];
        }
        int mid = (left + right) / 2;
        return std::max(MaxValueRange(v * 2, left, mid), MaxValueRange(v * 2 + 1, mid, right));
    }
};

int main() {
    int n = 0;
    std::cin >> n;
    std::vector<long long> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    Tree tree(arr);
    int k = 0;
    std::cin >> k;
    while (k--) {
        char c;
        std::cin >> c;
        if (c == 'm') {
            int l = 0, r = 0;
            std::cin >> l >> r;
            std::cout << tree.maxValueRange(l - 1, r) << " ";
        } else {
            int l = 0, r = 0;
            long long x = 0;
            std::cin >> l >> r >> x;
            tree.addValueRange(l - 1, r, x);
        }
    }
}