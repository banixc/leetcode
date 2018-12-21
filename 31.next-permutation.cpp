class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		if(nums.size()<=1){
			return ;
		}
		int check = nums[nums.size()-1];
		int i;
		int min_index = -1;
		int min_nums = check;
		for(i = nums.size()-2; i >= 0;  i--)  {
			if(check > nums[i]){
				break;
			} else {
				check = nums[i];
			}
		}
		// cout << i << " " << check << endl;
		if (i != -1) {
			int start = i;
			int swap = -1;
			int min = nums[i];
			for(i++;i<nums.size();i++) {
				if(nums[i]<=nums[start]) {
					break;
				}
			}
			int temp = nums[start];
			nums[start] = nums[i-1];
			nums[i-1] = temp;
			sort(nums.begin()+start+1, nums.end());
		} else {
			sort(nums.begin(), nums.end());
		}
	}
};
