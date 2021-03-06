// 84_Largest_Rectangle_in_Histogram.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <algorithm>
#include <set>
#include <vector>
#include <queue>

std::vector<int> FindAvailableWidthValue(const std::vector<int>& heights, int desiredHeight)
{
    std::vector<int> widthValues;
    int widthValue = 0;
    for (size_t i = 0; i < heights.size(); i++)
    {
        if (heights[i] >= desiredHeight)
        {
            widthValue++;
        }
        else
        {
            if (widthValue)
            {
                widthValues.push_back(widthValue);
                widthValue = 0;
            }
        }
    }

    if (widthValue)
    {
        widthValues.push_back(widthValue);
    }

    return widthValues;
}

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        if (heights.empty())
        {
            return 0;
        }
        std::set<int> heightValues;
        for (int h : heights)
        {
            heightValues.insert(h);
        }

        int minHeight = *heightValues.cbegin();
        int maxHeight = *(heightValues.crbegin());

        std::priority_queue<int> areaValues;

        for (int h : heightValues)
        {
            auto widthValues = FindAvailableWidthValue(heights, h);
            for (int w : widthValues)
            {
                areaValues.push(w * h);
            }
        }

        
        return areaValues.top();
    }
};

int main()
{
    Solution s;
    std::vector<int> v1{ 2, 1, 5, 6, 2, 3 };
    int a1 = s.largestRectangleArea(v1);
    return 0;
}

