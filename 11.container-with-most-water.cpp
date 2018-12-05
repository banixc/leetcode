// Brute Force

inline int get_area(int start_point, int start_height, int end_point, int end_height)
{
    return (start_point - end_point) * (start_height < end_height ? start_height : end_height);
}

class Solution
{
  public:
    int maxArea(vector<int> &height)
    {
        int l_size = height.size();
        int max_area = 0;
        for (int i = 0; i < l_size; i++)
            for (int j = 0; j < i; j++)
            {
                int area = get_area(i, height[i], j, height[j]);
                max_area = max_area > area ? max_area : area;
            }
        return max_area;
    }
};
