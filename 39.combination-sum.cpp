// recursive

class Solution {
public:
    vector<int> _candidates;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        _candidates = candidates;
        return combinationSumRev(candidates.size()-1, target);
    }
    vector<vector<int>> combinationSumRev(int end_point, int target) {
        vector<vector<int>> rev_result;
        if(target < _candidates[0]) {return rev_result;}
        for(int i = end_point; i > -1 ; i --) {
            if (target < _candidates[i]) {continue;}
            if (target == _candidates[i]) {rev_result.push_back(vector<int>(1, target));}
            vector<vector<int>> temp_rev_result = combinationSumRev(i, target - _candidates[i]);
            if(!temp_rev_result.empty()) {
                for(auto x: temp_rev_result) {
                    x.push_back(_candidates[i]);
                    rev_result.push_back(x);
                }
            }
        }
        return rev_result;
    
    }
};
