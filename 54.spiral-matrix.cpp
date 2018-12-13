class Solution
{
  public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> r;
        if (matrix.size() == 0)
            return r;
        int x_start = -1;
        int y_start = -1;
        int x_end = matrix.size();
        int y_end = matrix[0].size();
        int x = 0, y = 0, d = 0;
        do
        {
            r.push_back(matrix[x][y]);
            switch (d)
            {

            case 0:
                if (y < y_end - 1)
                {
                    y++;
                }
                else
                {
                    x++;
                    x_start++;
                    d = 1;
                }
                break;
            case 1:
                if (x < x_end - 1)
                {
                    x++;
                }
                else
                {
                    y--;
                    y_end--;
                    d = 2;
                }
                break;

            case 2:
                if (y > y_start + 1)
                {
                    y--;
                }
                else
                {
                    x--;
                    x_end--;
                    d = 3;
                }
                break;

            case 3:
                if (x > x_start + 1)
                {
                    x--;
                }
                else
                {
                    y++;
                    y_start++;
                    d = 0;
                }
                break;
            }
        } while (x_start + 1 < x_end && y_start + 1 < y_end);

        return r;
    }
};