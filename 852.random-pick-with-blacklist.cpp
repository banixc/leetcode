//slow
class Solution {
public:
    map<int, int> blacklist_map;
    int size = 0;
    Solution(int N, vector<int> blacklist) {
        sort(blacklist.begin(), blacklist.end());
        for(int i = 0; i<blacklist.size(); i++) {
            blacklist_map[blacklist[i]-i] = i+1;
        }
        size = N-blacklist.size();
        
    }
        int floor_r(const int& key){
            if(blacklist_map.begin()->first > key) {
                return -1;
            }
            if(blacklist_map.rbegin()->first <= key) {
                return blacklist_map.rbegin()->second;
            }

            if(blacklist_map.count(key) > 0) {
                return blacklist_map[key];
            }
            return (--blacklist_map.upper_bound(key) ) -> second;
    }

    
    int pick() {
        int r = rand() % size;
        if(blacklist_map.size()==0) return r;
        int p = floor_r(r);
        if(p == -1) return r;
        return p + r;

    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(N, blacklist);
 * int param_1 = obj.pick();
 */