// 85_Maximal_Rectangle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <algorithm>
#include <cassert>
#include <vector>
#include <unordered_set>

// time limit exceeded :(
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
    template<> struct hash<Rect>
    {
        size_t operator()(const Rect& value) const
        {
            return std::hash<int>{}(value.lt.x) ^ ( std::hash<int>{}(value.lt.y) ^
                ((std::hash<int>{}(value.rb.x) ^ (std::hash<int>{}(value.rb.y) << 1)) << 1) << 1);
        }
    };
}

bool IsRectangle(const std::vector<std::vector<char>>& matrix, const MyPoint& lt, const MyPoint& rb)
{
    assert(lt.x >= 0 && lt.x <= matrix[0].size());
    assert(lt.y >= 0 && lt.y <= matrix.size());
    assert(rb.x >= 0 && rb.x <= matrix[0].size());
    assert(rb.y >= 0 && rb.y <= matrix.size());

    assert(rb.x > lt.x && rb.y > lt.y);

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

void DoFindRectangle(const std::vector<std::vector<char>>& matrix, const MyPoint& startPoint, const MyPoint& endPoint, std::unordered_set<Rect>& result)
{
    if (endPoint.y > matrix.size() || endPoint.x > matrix[0].size())
    {
        return;
    }
    if (matrix[startPoint.y][startPoint.x] != '1' || matrix[endPoint.y - 1][endPoint.x - 1] != '1')
    {
        return;
    }
    
    if (result.find(Rect(startPoint, endPoint)) != result.cend())
    {
        return;
    }

    if (!IsRectangle(matrix, startPoint, endPoint))
    {
        return;
    }

    {
        result.emplace(startPoint, endPoint);

        DoFindRectangle(matrix, startPoint, MyPoint(endPoint.x + 1, endPoint.y), result);
        DoFindRectangle(matrix, startPoint, MyPoint(endPoint.x, endPoint.y + 1), result);
    }

}
void FindRectangle(const std::vector<std::vector<char>>& matrix, const MyPoint& startPoint, std::unordered_set<Rect>& result)
{
    DoFindRectangle(matrix, startPoint, MyPoint(startPoint.x + 1, startPoint.y + 1), result);
}


class Solution {
public:
    int maximalRectangle(std::vector<std::vector<char>>& matrix) {

        if (matrix.empty() || matrix[0].empty())
        {
            return 0;
        }

        std::unordered_set<Rect> results;

        for (size_t y = 0; y < matrix.size(); y++)
        {
            for (size_t x = 0; x < matrix[0].size(); x++)
            {
                if (matrix[y][x] == '1')
                {
                    FindRectangle(matrix, MyPoint(x, y), results);
                }
            }
        }

        if (results.empty())
        {
            return 0;
        }

        int areaValue = 0;
        for (const Rect& rc : results)
        {
            int area = rc.areaValue();
            if (area > areaValue)
            {
                areaValue = area;
            }
        }

        return areaValue;
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

