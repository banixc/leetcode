// Time complexity: O(nlgn)
// Space complexity: O(n)
// rank: Middle


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(), nums.end()); 
        int max_num = 0;
        map<int, int> m;
        for(auto x: nums) {
            if(m.find(x)!=m.end()) continue; 
            if(m.find(x-1)!=m.end()) {
                m[x] = m[x-1] + 1;
                m.erase(x-1);
            } else {
                m[x] = 1;
            }
            max_num = max(max_num, m[x]);
        }
        return max_num;
    }
};
