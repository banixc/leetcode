class Solution
{
  public:
    string decodeString(string s)
    {
        stack<int> repeat;
        stack<string> prefix;
        int now_num = 0;
        string now_str = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '[')
            {
                repeat.push(now_num);
                now_num = 0;
            }
            else if (s[i] == ']')
            {
                int repeat_times = repeat.top();
                repeat.pop();
                string r = "";
                while (repeat_times--)
                {
                    r += now_str;
                };
                now_str = prefix.top() + r;
                prefix.pop();
            }
            else if (s[i] >= '0' && s[i] <= '9')
            {
                if (now_num == 0)
                {
                    prefix.push(now_str);
                    now_str = "";
                }
                now_num = now_num * 10 + s[i] - '0';
            }
            else
                now_str += string(1, s[i]);
        }
        return now_str;
    }
};