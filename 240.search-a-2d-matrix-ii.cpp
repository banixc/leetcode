class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) return false;
        if(matrix[0].size()==0) return false;
        if(matrix[0][0]>target) return false; 
        int start_x=0, start_y=0, end_x=matrix.size(), end_y=matrix[0].size();
        while(!(start_x >= end_x && start_y >= end_y)) {
            for(int i = start_x; i < end_x; i ++) {
                if(matrix[i][end_y-1] == target) return true;
                if(matrix[i][end_y-1] < target) start_x++;
                else {
                    end_y--;
                    if(end_y==0)return false;
                    break;
                }
            }
            for(int i = start_y; i < end_y; i ++) {
                if(matrix[end_x-1][i] == target) return true;
                if(matrix[end_x-1][i] < target) start_y++;
                else {
                    end_x--;
                    if(end_x==0) return false;
                    break;
                }
            }
        }
        return false;
    }
    
    
    // for(int i=0; i < matrix.size();)
    //         for(int j=0; j< matrix.size();) {
    //             // cout <<i << " " << j << endl;
    //             if(matrix[i][j]==target) return true;
    //             if(matrix[i][j]>target) return false;
    //             bool flag = false;
    //             if(j<matrix[0].size()-1) {
    //                 if(matrix[i][j+1]==target) return true;
    //                 if(matrix[i][j+1]<target) {
    //                     j++;
    //                     flag = true;  
    //                 }
    //             }
    //             if(i<matrix.size()-1) {
    //                 if(matrix[i+1][j]==target) return true;
    //                 if(matrix[i+1][j]<target) {
    //                     i++;
    //                     flag = true;  
    //                 }
    //             }
    //             if(!flag) return false;
    //         }
    //     return false;
};