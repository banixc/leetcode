// too slow, to optimization


uint string_to_int(string& r){
    vector<bool> b(26, 0);
    for(auto c: r)
        b[c-'a'] = 1;
    return accumulate(b.rbegin(), b.rend(), 0, [](int x, int y) { return (x << 1) + y; });
}

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<uint> v_bool;
        for(auto s :words) {
            // cout << string_to_int(s) << " " << s << endl;
            v_bool.push_back(string_to_int(s));           
        }
        
        int max_size = 0;
        for(int i = 1; i < words.size(); i ++)
            for(int j = 0; j < i; j++) {
                if ((v_bool[i] & v_bool[j]) == 0) {
                    max_size = max(max_size, int(words[i].size() * words[j].size()));
                }
            }
        return max_size;
    }
};