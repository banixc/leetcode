class Solution
{
  public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<bool> dp(s.size(), false);
        map<string, int> word_set;
        int max_word_size = 0;
        for (int i = 0; i < wordDict.size(); i++)
        {
            word_set[wordDict[i]] = i;
            max_word_size = max(max_word_size, int(wordDict[i].size()));
        }
        int min_start = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (i > 0 && !dp[i - 1])
                continue;
            bool flag = false;
            for (int j = 0; j < max_word_size && i + j < s.size(); j++)
            {
                if (word_set.count(string(s.begin() + i, s.begin() + i + j + 1)) > 0)
                {
                    dp[i + j] = true;
                    flag = true;
                    if (i + j == s.size() - 1)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};