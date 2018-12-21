class Solution {
public:
vector<vector<int> > dp;
	string s;

	string longestPalindrome(string s) {
		this->s = s;
		if(s.size()<2) return s;
		dp = vector<vector<int> >(s.size(), vector<int>(s.size(), 0));
			int max_len = 0;
	int max_start = 0;
	int max_end = 0;
		for(int i = 0; i < s.size(); i ++) 
			for(int j = i+1; j < s.size(); j ++) {
				int len = dp_find(i, j);
				// cout << len << " " << i << " " << j << endl;
				if(len > max_len) {
					max_len = len;
					max_start = i;
					max_end = j;
				}
			}
		// for(auto x:dp) {
		// 	for(auto y:x) {
		// 		cout << y << " ";
		// 	}cout << endl;
		// }	
		return string(s.begin()+max_start, s.begin()+max_end+1);
	}
	
	int dp_find(int start, int end) {
		if(start<0||start>dp.size()-1||end<0||end>dp.size()-1) return -1;
//		if(start == end) return 1;
//		if(start > end) return -1;
		if(dp[start][end]==0) {
			if(start==end) {
				dp[start][end] = 1;
			} else 
			if(start>end) {
				dp[start][end] = -1;
			} else 
			if(start == end - 1) {
				if(s[start] == s[end]) {
					dp[start][end] = 2;
				} else {
					dp[start][end] = -1;
				}
			} else {
				int last = dp_find(start+1,end-1);
				if(last>0 && s[start]==s[end]) {
					dp[start][end] = last +2;
				} else {
					dp[start][end] = -1;
				}
			}
			
			
		}
		return dp[start][end];
	}
};