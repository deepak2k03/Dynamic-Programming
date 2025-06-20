#include <bits/stdc++.h>
using namespace std;

int fibo(int n) {
    if (n <= 1) return n;

    vector<int> dp(n + 1); // Create dp table from 0 to n
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)  dp[i] = dp[i - 1] + dp[i - 2]; // Fill dp[i] using previous two values
    return dp[n]; // Final answer
  
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Fibonacci(" << n << ") = " << fibo(n) << endl;

    return 0;
}
