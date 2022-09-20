class Solution {
public:
	int findLength(vector<int>& A, vector<int>& B) {
		int m = size(A), n = size(B), ans = 0, dp[m+1][n+1]; 
		memset(dp, -1, sizeof dp);
		for(int i = 0; i < m; i++) {
			for(int j = 0, len = 0; j < n; j++) {
				if(dp[i][j] == -1) {
					while(i + len < m and j + len < n and A[i+len] == B[j+len]) len++;
					while(len) dp[i + len][j + len] = len--;  // store the result for states (i, j) : 
															  // we know results for all states from (i, j) - (i+len, j+len)
				}
				ans = max(ans, dp[i][j]);
			}
		}
		return ans;
	}
};