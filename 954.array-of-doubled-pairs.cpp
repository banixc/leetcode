// too slow, to be optimized!
class Solution {
public:
    static bool compare(const int& a, const int& b)
    {
        if(a < 0 && b < 0) {
            return a > b;
        } 
        return a < b;
    }

    bool canReorderDoubled(vector<int>& A) {
        sort(A.begin(), A.end(), compare);
                
        map<int, int> nums;
        for(auto x: A) {
            // cout << x << endl;
            if(nums.count(x)>0) {
                nums[x]+=1;
            } else {
                nums[x]=1;
            }
        }
        int count = A.size();
        for(auto x: A) {
            if(nums[x]!=0) {
                // continue;
                if(nums.count(x*2)>0 && nums[x*2] > 0) {
                    nums[x]--;
                    nums[x*2]--;
                    count -=2;
                }
            }
        }
        return count == 0;
    }
};