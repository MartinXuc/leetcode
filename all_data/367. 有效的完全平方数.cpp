// https://leetcode.cn/problems/valid-perfect-square/description/

class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        // 使用简单的二分查找查询该数的平方根整数解是否存在
        if (num == 1)
            return true;
        int left = 0, right = num;
        int middle;
        while (left <= right)
        {
            middle = (left + right) / 2;
            if (middle * middle == num)
            {
                return true;
            }
            else if (middle * middle > num)
            {
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }
        return false;
    }
};