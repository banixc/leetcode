class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size()==0) {
            return 0;
        }
        int num = 0;
        for(int i = 0; i < grid.size(); i++) 
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    num ++;
                    find_and_update(grid, i, j);
                } else {
                    grid[i][j] = 'G';
                }
            }
        return num;
    }
    void find_and_update(vector<vector<char>>& grid, int x, int y) {
        if(grid[x][y] == '1') {
            grid[x][y] = 'G';
            if(x>0) 
                find_and_update(grid, x-1, y);
            if(x<grid.size()-1) 
                find_and_update(grid, x+1, y);
            if(y>0)
                find_and_update(grid, x, y-1);
            if(y<grid[0].size()-1)
                find_and_update(grid, x, y+1);
        }
    }
    
};