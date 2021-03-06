// 5_Longest_Palindromic_Substring.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <string>
#include <queue>

bool IsPalidrome(const std::string& s)
{
    if (s.empty())
    {
        return false;
    }


    auto sBegin = s.cbegin();
    auto sEnd = s.cend() - 1;

    while (!(sBegin == sEnd || sEnd < sBegin))
    {
        if (*sBegin != *sEnd)
        {
            return false;
        }
        sBegin++;
        sEnd--;
    }

    return true;
}

class Solution {
public:
    std::string longestPalindrome(std::string s) {

        auto CheckSubstrPalindrome = [&s](size_t substrlength)
        {
            auto iterBegin = s.cbegin();
            auto iterEnd = iterBegin + substrlength;

            while (1)
            {
                std::string substr(iterBegin, iterEnd);

                if (IsPalidrome(substr))
                {
                    return substr;
                }

                if (iterEnd == s.cend())
                {
                    break;
                }

                iterBegin++;
                iterEnd++;
            } 

            return std::string();

        };

        int substrLength = s.length();

        while (substrLength > 0)
        {
            std::string subStr = CheckSubstrPalindrome(substrLength);
            if (!subStr.empty())
            {
                return subStr;
                break;
            }
            substrLength--;
        }


        return "";
    }
};

int main()
{
    std::string res;
    Solution s;

    res = s.longestPalindrome("babad");
    res = s.longestPalindrome("cbbd");
    return 0;
}

