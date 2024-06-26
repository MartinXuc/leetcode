// https://leetcode.cn/problems/backspace-string-compare/description/

class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        f(s);
        f(t);
        return (s == t);
    }
    // 将含退格的字符串转换成最终结果
    void f(string &s)
    {
        // 使用双指针法将st进行改写
        int slow_index = -1;
        for (int fast_index = 0; fast_index < s.size(); fast_index++)
        {
            if (s[fast_index] != '#')
            {
                slow_index++;
                s[slow_index] = s[fast_index];
            }
            else
            {
                slow_index--;
            }
        }
        s.resize(slow_index + 1);
    }
};