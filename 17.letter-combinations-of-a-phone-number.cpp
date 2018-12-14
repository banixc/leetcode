static const string arr[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> r1;
        vector<string> r2;
        for(auto x: digits){
            string s = arr[x-'2'];
            if(r1.empty()) {
                for(auto c: s) 
                    r2.push_back(string(1, c));
            } else {
                for(auto old_str: r1) 
                for(auto c: s) {
                    r2.push_back(old_str+string(1,c));
                }
            }

            r1 = r2;
            r2.clear();
        }
        return r1;
    }
         
};
