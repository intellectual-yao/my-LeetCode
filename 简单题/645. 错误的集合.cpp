// Source : https://leetcode-cn.com/problems/set-mismatch/
// Date : 2021-10-18

/******************************************************************************************
集合 s 包含从 1 到 n 的整数。不幸的是，因为数据错误，导致集合里面某一个数字复制了成了集合里面的另外一个数字的值，
导致集合 丢失了一个数字 并且有一个数字重复 。给定一个数组 nums 代表了集合 S 发生错误后的结果。
请你找出重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。

示例 1：

输入：nums = [1,2,2,4]
输出：[2,3]
示例 2：

输入：nums = [1,1]
输出：[1,2]

提示：

2 <= nums.length <= 104
1 <= nums[i] <= 104
******************************************************************************************/

/*******************************************************************************************************
题目分析：将所有的元素放入哈希表中，记录每个元素放入的次数，如果放入两次，那么这个元素就是多余的元素，相反，如果没有出现过的元素就是缺失的元素。
********************************************************************************************************/
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> errorNums(2);
        int n = nums.size();
        unordered_map<int, int> mp;
        //将元素对应的次数存入哈希表
        //下面是关键步骤
        for (auto& num : nums) {
            mp[num]++;
        }
        //哈希表中查询元素的次数，出现两次的就是多余的
        for (int i = 1; i <= n; i++) {
            int count = mp[i];
            if (count == 2) {
                errorNums[0] = i;
            }
            //出现次数为0 的就是缺少的
            else if (count == 0) {
                errorNums[1] = i;
            }
        }
        return errorNums;
    }
};

        // vector<int> a;
        // vector<int> b;
        // int count = 1;
        // sort(nums.begin(), nums.end());
        // //排序以后相邻的两个元素如果相同则将其放入数组第一个位置
        // for(int i = 0;i < nums.size() - 1; ++i)
        // {
        //     //当找到该重元素的时候，需要将后面的元素全部前移以方便查找缺失值
        //     if(nums[i] == nums[i + 1])
        //     {
        //         a.push_back(nums[i]);
        //         nums[i + 1] = 0;
        //     }
        // }
        // if(nums[nums.size() - 1] != nums.size())
        //     a.push_back(nums.size());
        // else
        // {
        //     for(int k = 0;k < nums.size();++k)
        //     {
        //         if(nums[k] != count)
        //         {
        //             a.push_back(count);
        //             break;

        //         }
        //         else
        //             ++count;
        //     }
        // }    
        // return a;
//     }
// };
