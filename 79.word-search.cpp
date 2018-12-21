class Solution {
public:
	vector<vector<bool>> visit;
	
	bool exist(vector<vector<char>>& board, string word) {
		if(board.size()==0||board[0].size()==0) return false;
		visit = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));
		for(int i = 0; i < board.size(); i ++)
			for(int j =0; j < board[0].size(); j++) {
				if (DFS(board, word, 0, i, j)) {
					// cout << true << endl;
					return true;
				}
			}
		// cout << false << endl;
		return false;
	}
	
	bool DFS(vector<vector<char>>& board, string& word, int start, int x, int y) {
		// cout << "x " << x << " y " << y <<" " << start << endl;
		if(x<0||y<0||x>board.size()-1||y>board[0].size()-1) return false;
		if(visit[x][y]) return false;
		if(word[start]==board[x][y]) {
			if (start == word.size()-1) {
				return true;
			} else {
				visit[x][y] = true;
				bool result = DFS(board, word, start+1, x, y+1) || DFS(board, word, start+1, x+1, y)
					||DFS(board, word, start+1, x-1, y) || DFS(board, word, start+1, x, y-1);
				if (result) return true;
				visit[x][y] = false;
				return false;
			}
		} else {
			return false;
		}
	}
};
};