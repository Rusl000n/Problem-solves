#include<iostream>
#include<vector>
#include<iomanip>
#include<cmath>
#include<tuple>


struct Point {
    double x = 0;
    double y = 0;
    explicit Point () = default;
    Point (double x, double y) : x (x), y(y) {}
    Point operator+ (const Point& other) const {
        return Point(x + other.x, y + other.y);
    }
    Point operator-(const Point& other) const {
        return Point (x - other.x, y - other. y);
    }
    double operator^ (const Point& other) const {
        return x * other.y - y * other.x;
    }
    bool operator==(const Point& other) const {
        return std::tie(x, y) == std::tie(other.x, other.y);
    }
};
double dist(const Point& p1, const Point& p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return std::sqrt(dx * dx + dy * dy);
}
std::istream& operator>>(std::istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
}
std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << p.x << ' ' << p.y;
    return os;
}
int main() {
    int n = 0;
    std::cin >> n;
    std::vector<Point> points(n);
    for (auto &p: points) {
        std::cin >> p;
    }
    Point p0 = points[0];
    for (auto &p: points) {
        if (p0.y > p.y) {
            p0 = p;
        } else if (p0.y == p.y && p0.x > p.x) {
            p0 = p;
        }
    }
    std::vector<Point> hull;
    hull.push_back(p0);
    while (true) {
        Point tmp = points[0];
        if (tmp == p0) tmp = points[1];
        for (auto &p: points) {
            if (((tmp - p0) ^ (p - p0)) > 0) {
                tmp = p;
            }
        }
        hull.push_back(tmp);
        if (hull.front() == hull.back()) break;
        p0 = tmp;
    }
    double perimeter = 0;
    double square = 0;
    for (size_t i = 0; i + 1 < hull.size(); ++i) {
        square += hull[i] ^ hull[i + 1];
        perimeter += dist(hull[i], hull[i + 1]);
    }
        if (square < 0) square = -square;
        square = square / 2;
        std::cout << std::fixed << std::setprecision(5) <<  perimeter << std::endl;
        std::cout << std::fixed << std::setprecision(5) << square;


        return 0;
}