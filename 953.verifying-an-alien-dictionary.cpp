class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int i = 0;
        for(auto x: order) {
            order_map[x-'a'] = i++;    
        }
        for(int i =0; i < words.size()-1; i ++) {
            if (!comp(words[i], words[i+1])) {
                return false;
            }
        }        
        return true;
    }
    vector<int> order_map = vector<int>(26, 0);
    int comp(char a, char b) {
        return order_map[a-'a'] - order_map[b-'a'];
    }
    bool comp(string a, string b) {
        for(int i =0;;i++) {
            char a_c, b_c;
            if(i>=a.size()) {
                return true;
            }
            if(i>=b.size()) {
                return false;
            }
            
            int r = comp(a[i], b[i]);
            if(r > 0){
                return false;
            } else if (r == 0) {
                continue;
            } else {
                return true;
            }
        }
    }
};