// https://leetcode.cn/problems/remove-duplicates-from-sorted-array/

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        // 使用一个简单的双指针即可完成
        int slow_index = 0;
        for (int fast_index = 0; fast_index < nums.size(); fast_index++)
        {
            if (fast_index == 0 || nums[fast_index] != nums[fast_index - 1])
            {
                nums[slow_index] = nums[fast_index];
                slow_index++;
            }
        }
        return slow_index;
    }
};