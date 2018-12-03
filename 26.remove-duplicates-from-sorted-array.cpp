class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size();
        } 
        int p_size = 1;
        int last_num = nums[0];
        for(int i = 1; i < nums.size() ;i ++) {
            if (last_num != nums[i]) {
                nums[p_size] = nums[i];
                p_size ++;
                last_num = nums[i];
            }
        }
        return p_size;
    }
};
