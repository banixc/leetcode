int get(map<int, int>& m, int k) {
	if(m.find(k) == m.end()) {
		return 0;
	}
	return m[k];
}

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> p;
		int zero = 0;
		map<int, int> nav;
		map<int, int> pos;
		for(int i = 0; i < nums.size(); i ++)  {
			int num = nums[i]; 
			if(num>0) {
				pos[num] = get(pos, num) + 1;
			} else if(num<0) {
				nav[num] = get(nav, num) + 1; 
			} else {
				zero ++;
			}
		}
		if(zero >= 3) {
			vector<int> temp(3, 0);
			p.push_back(temp);
		}
		
		if(zero > 0) {
			for(auto nav_it: nav) {
				if(get(pos, -nav_it.first) > 0 ) {
					vector<int> temp;
					temp.push_back(0);
					temp.push_back(nav_it.first);
					temp.push_back(-nav_it.first);
					p.push_back(temp);
				}
			}
		}
		
//         cout << "0" << "=>" << zero << endl;
		
//         for(auto x: nav) 
//             cout << x.first << "=>" << x.second << endl;
		
//         for(auto x: pos)
//             cout << x.first << "=>" << x.second << endl;
		
		for(auto nav_it: nav) {
			int half = - nav_it.first / 2;
			for(auto pos_it: pos) {
				if(pos_it.second >= 2 && pos_it.first * 2 == -nav_it.first) {
					vector<int> temp(2, pos_it.first);
					temp.push_back(nav_it.first);
					p.push_back(temp);
				}
				if(pos_it.first <= half) continue;
				int third = -nav_it.first-pos_it.first;
				if(get(pos, third)>0) {
					vector<int> temp;
					temp.push_back(nav_it.first);
					temp.push_back(pos_it.first);
					temp.push_back(third);
					p.push_back(temp);
				} 
			}
		}

		
		for(auto nav_it: pos) {
			int half = - nav_it.first / 2;
			for(auto pos_it: nav) {
				if(pos_it.second >= 2 && pos_it.first * 2 == -nav_it.first) {
					vector<int> temp(2, pos_it.first);
					temp.push_back(nav_it.first);
					p.push_back(temp);
				}
				if(pos_it.first >= half) continue;
				int third = -nav_it.first-pos_it.first;
				if(get(nav, third)>0) {
					vector<int> temp;
					temp.push_back(nav_it.first);
					temp.push_back(pos_it.first);
					temp.push_back(third);
					p.push_back(temp);
				} 
			}
		}
		return p;
	}
};