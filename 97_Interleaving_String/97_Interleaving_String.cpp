// 97_Interleaving_String.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <string>
// incomplete
class Solution {
public:
    bool isInterleave(std::string s1, std::string s2, std::string s3) {

    }
};

int main()
{
    Solution s;
    
    bool b1 = s.isInterleave("aabcc", "dbbca", "aadbbcbcac");
    bool b2 = s.isInterleave("aabcc", "dbbca", "aadbbbaccc");

    return 0;
}

