#include <iostream>
#include <algorithm>
#include <vector>

int getMinSteps ( int n ) {
    std::vector<int> dp(n+1);
    dp[1] = 0; // trivial base case

    for(int i = 2 ; i <= n ; i++ )
    {
        dp[i] = 1 + dp[i-1];
        if(i%2==0) dp[i] = std::min( dp[i] , 1+ dp[i/2] );
        if(i%3==0) dp[i] = std::min( dp[i] , 1+ dp[i/3] );
    }
    return dp[n];
}

int main() {
    int n = 10;
    std::cout << "Minimum steps for n = " << n <<": " << getMinSteps(n) << std:: endl;
}