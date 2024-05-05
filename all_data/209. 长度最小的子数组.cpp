// https://leetcode.cn/problems/minimum-size-subarray-sum/

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        // 寻找边界条件
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        if (sum < target)
            return 0;
        else if (sum == target)
            return nums.size();
        // 正式寻找
        for (int window_size = 1; window_size < nums.size() - 1; window_size++)
        {
            // 定义窗口中数字之和
            int window_sum = 0;
            // 初始化窗口中数字之和
            for (int i = 0; i < window_size; i++)
            {
                window_sum += nums[i];
            }
            // 先判断，再更新
            int window_address = 0;
            while (window_sum < target)
            {
                // window向右滑动一格
                window_sum -= nums[window_address];
                window_sum += nums[window_address + window_size];
                window_address++;
                if (window_address + window_size == nums.size())
                {
                    break;
                }
            }
            if (window_sum >= target)
            {
                return window_size;
            }
        }
        return -1;
    }
};