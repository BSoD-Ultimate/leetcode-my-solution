// 85_Maximal_Rectangle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <algorithm>
#include <cassert>
#include <vector>
#include <unordered_map>

// time limit exceeded :(
// I tried storing previous results for judging if a region is rectangle unfortunately the code still exceeds time limit :(
struct MyPoint
{
    int x; int y;
    MyPoint() : x(0), y(0) {}
    MyPoint(int x, int y) : x(x), y(y) {}
};
bool operator==(const MyPoint& left, const MyPoint& right)
{
    return left.x == right.x && left.y == right.y;
}
struct Rect
{
    MyPoint lt;
    MyPoint rb;

    Rect(){}
    Rect(MyPoint lt, MyPoint rb) : lt(lt), rb(rb)
    {
    }
    int areaValue() const
    {
        return (rb.x - lt.x) * (rb.y - lt.y);
    }
};
bool operator==(const Rect& left, const Rect& right)
{
    return left.lt == right.lt && left.rb == right.rb;
}

namespace std
{
    template<> struct hash<MyPoint>
    {
        size_t operator()(const MyPoint& value) const
        {
            return std::hash<int>{}(value.x) ^ (std::hash<int>{}(value.y) << 1);
        }
    };
    template<> struct hash<Rect>
    {
        size_t operator()(const Rect& value) const
        {
            return std::hash<int>{}(value.lt.x) ^ ( std::hash<int>{}(value.lt.y) ^
                ((std::hash<int>{}(value.rb.x) ^ (std::hash<int>{}(value.rb.y) << 1)) << 1) << 1);
        }
    };
}

bool IsRectangle(const std::vector<std::vector<char>>& matrix, const MyPoint& lt, const MyPoint& rb, std::unordered_map<MyPoint, bool>& visitedResult)
{
    assert(lt.x >= 0 && lt.x <= matrix[0].size());
    assert(lt.y >= 0 && lt.y <= matrix.size());
    assert(rb.x >= 0 && rb.x <= matrix[0].size());
    assert(rb.y >= 0 && rb.y <= matrix.size());

    assert(rb.x > lt.x && rb.y > lt.y);

    MyPoint prevPointX(rb.x - 1, rb.y);
    MyPoint prevPointY(rb.x, rb.y - 1);

    if (!(visitedResult.find(prevPointX) != visitedResult.cend() || visitedResult.find(prevPointY) != visitedResult.cend()))
    {
        int sumValue = 0;
        for (size_t y = lt.y; y < rb.y; y++)
        {
            for (size_t x = lt.x; x < rb.x; x++)
            {
                if (matrix[y][x] == '1')
                {
                    sumValue++;
                }
            }
        }

        return sumValue == (rb.x - lt.x) * (rb.y - lt.y);
    }
    else if (visitedResult.find(prevPointX) != visitedResult.cend())
    {
        if (visitedResult[prevPointX])
        {
            int sumValue = 0;
            for (size_t y = lt.y; y < rb.y; y++)
            {
                if (matrix[y][rb.x - 1] == '1')
                {
                    sumValue++;
                }
            }
            return (sumValue == (rb.y - lt.y));
        }
        else
        {
            return false;
        }
    }
    else /*if (visitedResult.find(prevPointY) != visitedResult.cend())*/
    {
        if (visitedResult[prevPointY])
        {
            int sumValue = 0;
            for (size_t x = lt.x; x < rb.x; x++)
            {
                if (matrix[rb.y - 1][x] == '1')
                {
                    sumValue++;
                }
            }

            return sumValue == (rb.x - lt.x);
        }
        else
        {
            return false;
        }

    }

}

void DoFindMaxRectangleArea(const std::vector<std::vector<char>>& matrix, const MyPoint& startPoint, const MyPoint& endPoint, std::unordered_map<MyPoint, bool>& visitedResult, int& result)
{
    if (endPoint.y > matrix.size() || endPoint.x > matrix[0].size())
    {
        return;
    }
    if (matrix[startPoint.y][startPoint.x] != '1' || matrix[endPoint.y - 1][endPoint.x - 1] != '1')
    {
        return;
    }

    bool isRectangle = false;

    if (visitedResult.find(endPoint) != visitedResult.cend())
    {
        isRectangle = visitedResult[endPoint];
    }
    else
    {
        isRectangle = visitedResult[endPoint] = IsRectangle(matrix, startPoint, endPoint, visitedResult);
    }

    if (!isRectangle)
    {
        return;
    }
    else
    {
        int areaValue = (endPoint.x - startPoint.x) * (endPoint.y - startPoint.y);

        if (areaValue > result)
        {
            result = areaValue;
        }

        DoFindMaxRectangleArea(matrix, startPoint, MyPoint(endPoint.x + 1, endPoint.y), visitedResult, result);
        DoFindMaxRectangleArea(matrix, startPoint, MyPoint(endPoint.x, endPoint.y + 1), visitedResult, result);
    }

}
void FindRectangle(const std::vector<std::vector<char>>& matrix, const MyPoint& startPoint, int& result)
{
    std::unordered_map<MyPoint, bool> visitedSet;
    DoFindMaxRectangleArea(matrix, startPoint, MyPoint(startPoint.x + 1, startPoint.y + 1), visitedSet, result);
}


class Solution {
public:
    int maximalRectangle(std::vector<std::vector<char>>& matrix) {

        if (matrix.empty() || matrix[0].empty())
        {
            return 0;
        }

        int maxRectArea = 0;

        for (size_t y = 0; y < matrix.size(); y++)
        {
            for (size_t x = 0; x < matrix[0].size(); x++)
            {
                int areaValue = 0;
                if (matrix[y][x] == '1')
                {
                    FindRectangle(matrix, MyPoint(x, y), areaValue);
                }
                if (areaValue > maxRectArea)
                {
                    maxRectArea = areaValue;
                }
            }
        }

        return maxRectArea;
    }
};

int main()
{
    std::vector<std::vector<char>> m
    {
        {'1','0','1','0','0' },
        {'1','0','1','1','1' },
        {'1','1','1','1','1' },
        {'1','0','0','1','0' }
    };

    Solution s;
    int a1 = s.maximalRectangle(m);

    return 0;
}

