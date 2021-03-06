// 1_Two_Sum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>
#include <unordered_map>
#include <cassert>


int GetSum(const std::vector<int>& nums, size_t index1, size_t index2)
{
    assert(index1 < nums.size());
    assert(index2 < nums.size());

    return nums[index1] + nums[index2];
}

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (GetSum(nums, i, j) == target)
                {
                    return std::vector<int>{i, j};
                }
            }
        }
        return std::vector<int>();
    }
};

class Solution2 {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> numMap;
        for (int i = 0; i < nums.size(); i++)
        {
            numMap[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            auto iter = numMap.find(target - nums[i]);
            if (iter != numMap.cend() && iter->second != i)
            {
                return std::vector<int>{i, iter->second};
            }
        }
        return std::vector<int>();
    }
};


int main()
{
    std::vector<int> v{ 3,2,4 };

    Solution2 s;
    auto ret = s.twoSum(v, 9);

    return 0;
}

