// 70_Climbing_Stairs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>

int DoClimbStairs(int stairCount, int curStep, std::vector<int>& solutions)
{
    if (curStep > stairCount)
    {
        return 0;
    }
    if (curStep == stairCount)
    {
        return 1;
    }

    if (solutions[curStep] > 0)
    {
        return solutions[curStep];
    }

    solutions[curStep] = DoClimbStairs(stairCount, curStep + 1, solutions) + DoClimbStairs(stairCount, curStep + 2, solutions);
    return solutions[curStep];
}

class Solution {
public:
    int climbStairs(int n) {
        std::vector<int> solutionArray(n + 1, 0);
        int ret =  DoClimbStairs(n, 0, solutionArray);
        int i = 1;
        return ret;
    }
};

int main()
{
    Solution s;
    //s.climbStairs(1);
    //s.climbStairs(2);
    //s.climbStairs(3);
    s.climbStairs(35);
    return 0;
}

