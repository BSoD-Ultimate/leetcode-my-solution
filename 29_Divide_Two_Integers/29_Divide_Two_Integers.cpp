// 29_Divide_Two_Integers.cpp : Defines the entry point for the console application.
//

/*
 * unaccepted answer. goddamn it
*/
#include "stdafx.h"

#include <stdint.h>
#include <cstdlib>

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool operand = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0);

        int absDividend = abs(dividend);
        if (dividend == 0x80000000)
        {
            absDividend = 0x7fffffff;
        }
        int absDivisor = abs(divisor);

        int ret = 0;

        int mul = 0;
        
        while (mul - absDividend <= 0)
        {
            mul += absDivisor;
            ret++;
        }

        if (ret < 0)
        {
            ret = 0x7fffffff;
        }
        else
        {
            ret--;
        }


        return operand ? ret : -ret;
    }
};

int main()
{
    Solution s;

    int ddd = 0x80000000;

    //int d1 = ddd / -1;
    //int dd1 = s.divide(0x80000000, -1);
    int d2 = 0x7fffffff / 1;
    int dd2 = s.divide(0x7fffffff, 1);
    int d3 = -10 / 3;
    int dd3 = s.divide(-10, 3);
    int d4 = -10 / -3;
    int dd4 = s.divide(-10, -3);
    return 0;
}

