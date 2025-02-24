#include <iostream>
#include <vector>
using namespace std;

// Function to find the Longest Common Subsequence (LCS) using DP (Bottom-Up)
int lcs(string &s1, string &s2) {
    int m = s1.length();
    int n = s2.length();

    // Create a DP table initialized to 0
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Build the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1]; // Characters match
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // Characters do not match
            }
        }
    }

    return dp[m][n];
}

int main() {
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    int length = lcs(s1, s2);
    cout << "Length of Longest Common Subsequence: " << length << endl;

    return 0;
}
