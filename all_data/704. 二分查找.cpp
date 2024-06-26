// https://leetcode.cn/problems/binary-search/

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        // 搜索过程中，使用左闭右闭区间
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int middle = (left + right) / 2;
            if (nums[middle] == target)
            {
                return middle;
            }
            else if (nums[middle] > target)
            {
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }
        return -1;
    }
};