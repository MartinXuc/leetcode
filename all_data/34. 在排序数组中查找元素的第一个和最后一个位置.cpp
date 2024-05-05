// https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        // 首先使用简单的二分查找来进行粗略定位
        bool found = false;
        int left = 0, right = nums.size() - 1;
        int middle;
        vector<int> ans;
        while (left <= right)
        {
            middle = (left + right) / 2;
            if (nums[middle] == target)
            {
                found = true;
                break;
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
        // 若根本不存在
        if (found == false)
        {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        // 存在，此时middle一定是target
        // 向左寻找边界
        int temp = middle;
        while (nums[temp] == target)
        {
            temp--;
        }
        ans.push_back(temp + 1);
        // 向右寻找边界
        temp = middle;
        while (nums[temp] == target)
        {
            temp++;
        }
        ans.push_back(temp - 1);
        return ans;
    }
};