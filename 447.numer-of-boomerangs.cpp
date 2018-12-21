int distance(pair<int, int>& a, pair<int, int>& b) {
	return pow(a.first-b.first, 2) + pow(a.second - b.second, 2);
}

int cn2(int& num) {
	return num * (num -1);
}

class Solution {
public:
	int numberOfBoomerangs(vector<pair<int, int>>& points) {
		int num = 0;
		map<int, int> m;
		for(int i = 0; i < points.size(); i++) {
			m.clear();
			for(int j = 0; j < points.size(); j ++) {
				int dis = distance(points[i], points[j]);
				if(m.find(dis) != m.end()) {
					m[dis] ++;
				} else {
					m[dis] = 1;
				}
			}
			for(auto& x: m){
				if(x.second >=2 ) {
					num += cn2(x.second);
				}
			}
			
		}
		return num;
	}
};