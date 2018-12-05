// 二维dp
// Runtime: 16 ms, faster than 50.27% of C++ online submissions for Maximal Square.
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int x = matrix.size();
        if(x == 0) {
            return 0;
        }
        int y = matrix[0].size();
        if(y == 0) {
            return 0;
        }
        int max_num = 0;
        vector<vector<int>> dp(x, vector<int>(y, 0));
        for(int i=0; i<x; i++)
            for(int j=0; j<y; j++) {
                if(i==0||j==0) {
                    dp[i][j] = matrix[i][j] == '1' ? 1:0;
                    max_num = max(max_num, dp[i][j]);
                } else if(matrix[i][j] == '1') {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
                    max_num = max(max_num, dp[i][j]);
                }
            }
        return max_num * max_num;
    }
};
