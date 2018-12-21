class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> p;
		string start = "";
		DFS(p, start, n, n);
		return p;
	}
	
	void DFS(vector<string>& r, string start, int left, int right) {
		if(right<left) return;
		if(right==0 && left==0) {
			r.push_back(start);
			return;
		}
		if(left>0){DFS(r, start+'(',left-1, right);}
		if(right>0){DFS(r, start+')', left, right-1);}
	}
};