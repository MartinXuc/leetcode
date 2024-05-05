// https://leetcode.cn/problems/search-insert-position/description/

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        // 使用二分查找进行查询
        // 若找到，直接返回
        int left = 0, right = nums.size() - 1;
        int middle;
        while (left <= right)
        {
            middle = (left + right) / 2;
            if (target == nums[middle])
            {
                return middle;
            }
            else if (target < nums[middle])
            {
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }
        // 若未找到，返回将被插入的位置
        return left;
    }
};