// 3_Longest_Substring_Without_Repeating_Characters.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include <set>
#include <queue>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {

        if (s.empty())
        {
            return 0;
        }

        auto iterBegin = s.cbegin();

        std::set<char> charSets;
        auto iterEnd = iterBegin;

        auto isDuplicateCharFound = [](const std::string& s, std::string::const_iterator begin, std::string::const_iterator end)
        {
            std::set<char> charSets;
            
            auto iter = begin;

            while (iter != end && charSets.find(*iter) == charSets.cend())
            {
                charSets.insert(*iter);
                iter++;
            }

            if (iter == end)
            {
                return false;
            }
            return true;
        };

        while (iterEnd != s.cend())
        {
            if (isDuplicateCharFound(s, iterBegin, iterEnd + 1))
            {
                iterBegin++;
                iterEnd++;
            }
            else
            {
                iterEnd++;
            }
        }

        return iterEnd - iterBegin;
    }
};

int main()
{
    int i;
    Solution s;
    i = s.lengthOfLongestSubstring("abcabcbb");
    i = s.lengthOfLongestSubstring("bbbbb");
    i = s.lengthOfLongestSubstring("pwwkew");
    i = s.lengthOfLongestSubstring("dvdf");
    return 0;
}

