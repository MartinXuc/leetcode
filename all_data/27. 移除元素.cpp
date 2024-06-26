// https://leetcode.cn/problems/remove-element/

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        // 不使用vector自带的方法，而是单纯对数组进行操作，可以使用双指针法。
        int fast_index, slow_index;
        for (fast_index = 0, slow_index = 0; fast_index < nums.size();)
        {
            // 检查快指针上的数值是否待删除
            if (nums[fast_index] == val)
            {
                fast_index++;
                continue;
            }
            // 将快指针上的数值覆盖给慢指针当前位置
            if (fast_index != slow_index)
            {
                nums[slow_index] = nums[fast_index];
            }
            // 正常的指针更新
            fast_index++;
            slow_index++;
        }
        // 删除多余元素
        for (int i = 0; i < fast_index - slow_index; i++)
        {
            nums.pop_back();
        }
        // 返回长度
        return nums.size();
    }
};

// 实际上快指针就相当于一个寻找和val不同值的先锋，慢指针就相当于一个新的数组
// 每次快指针找到一个符合要求的值，就打个电话告诉后方的慢指针，让慢指针更新一下新数组
// 这样到最后快指针就将原数组遍历了一遍，慢指针就对应了一个符合要求的数组