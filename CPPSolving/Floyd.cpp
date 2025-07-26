#include<iostream>
#include<vector>
#include<set>
#include<functional>

int main() {
    int n = 0;
    std::cin >> n;
    std::vector<std::vector<int> > dp(n, std::vector<int>(n));
    int inf = 10000000;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> dp[i][j];
            if (dp[i][j] == 0) {
                dp[i][j] = inf; 
        }}
        if (dp[i][i] >= 0) {
            dp[i][i] = 0;
        }}
    for(int k = 0; k < n; ++k) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(dp[i][k] != inf && dp[k][j] != inf) {
                    dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j]);
                }}}}
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            std::cout << dp[i][j] << '\t';
        }
        std::cout << '\n';
    }

    return 0;
}
