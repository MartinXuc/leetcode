// https://leetcode.cn/problems/move-zeroes/

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        // 使用双指针，先将所有非零元素放在前面，然后将后面的位置填0
        int slow_index = -1;
        for (int fast_index = 0; fast_index < nums.size(); fast_index++)
        {
            if (nums[fast_index] != 0)
            {
                slow_index++;
                nums[slow_index] = nums[fast_index];
            }
        }
        for (slow_index++; slow_index < nums.size(); slow_index++)
        {
            nums[slow_index] = 0;
        }
    }
};