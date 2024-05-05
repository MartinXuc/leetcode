// https://leetcode.cn/problems/sqrtx/description/

class Solution
{
public:
    int mySqrt(int x)
    {
        // 使用二分查找的思想，对结果进行筛选
        // 首先确定边界
        int left = 0, right = x;
        int middle;
        while (left <= right)
        {
            middle = (left + right) / 2;
            int middle_2 = middle * middle;
            if (middle_2 == x)
            {
                return middle;
            }
            else if (middle_2 < x)
            {
                left = middle + 1;
            }
            else
            {
                right = middle - 1;
            }
        }
        if (middle * middle > x)
        {
            return middle - 1;
        }
        else
        {
            return middle;
        }
    }
};