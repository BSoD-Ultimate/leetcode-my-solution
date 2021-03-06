// 76_Minimum_Window_Substring.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <string>
#include <queue>
#include <map>
#include <unordered_map>

std::map<char, int> GetCharSet(const std::string& s)
{
    std::map<char, int> charSet;
    for (char c : s)
    {
        if (charSet.find(c) != charSet.cend())
        {
            charSet[c]++;
        }
        else
        {
            charSet[c] = 1;
        }
    }

    return charSet;
}

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if (s.empty() || s.length() < t.length())
        {
            return "";
        }
        auto charSet = GetCharSet(t);

        int matchRemain = charSet.size();

        auto iterStart = s.cbegin(), iterEnd = s.cend();
        auto tmpStart = s.cbegin(), tmpEnd = tmpStart;

        bool matchFound = false;

        while (tmpStart != s.cend())
        {
            while (tmpEnd != s.cend() && matchRemain > 0)
            {
                std::string substr(tmpStart, tmpEnd);
                if (charSet.find(*tmpEnd) == charSet.end())
                {
                    tmpEnd++;
                    continue;
                }

                charSet[*tmpEnd]--;
                if (charSet[*tmpEnd] == 0)
                {
                    matchRemain--;
                }
                tmpEnd++;
            }
            if (matchRemain > 0)
            {
                break;
            }
            if (matchRemain == 0)
            {
                matchFound = true;
            }
            while (tmpStart < s.cend() && charSet.find(*tmpStart) == charSet.end())
            {
                tmpStart++;
            }
            if (tmpEnd - tmpStart < iterEnd - iterStart)
            {
                iterStart = tmpStart;
                iterEnd = tmpEnd;
            }
            
            if (tmpStart < s.cend())
            {
                if (charSet[*tmpStart]== 0)
                {
                    matchRemain++;
                }
                charSet[*tmpStart]++;
                tmpStart++;
            }
        }

        if (!matchFound)
        {
            return std::string();
        }
        return std::string(iterStart, iterEnd);
    }
};

int main()
{
    Solution s;
    //std::string s1 = s.minWindow("ADOBECODEBANC", "ABC");
    //std::string s2 = s.minWindow("ADOBECODEBANC", "ABCDA");
    //std::string s3 = s.minWindow("a", "aa");
    //std::string s4 = s.minWindow("aaaaaaaaaaaabbbbbcdd", "abcdd");
    std::string s5 = s.minWindow("a", "b");
    std::string s6 = s.minWindow("a", "a");

    return 0;
}

