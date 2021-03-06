// 93_Restore_IP_Addresses.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>
#include <sstream>

// WTF?? 0ms??
void DoRestore(const std::string& ipAddr, int curSplitIndex,
    std::vector<std::string>& curSplitResult, std::vector<std::vector<std::string>>& splitResults)
{
    // split fails
    if ((ipAddr.length() - curSplitIndex) > 0 && curSplitResult.size() == 4)
    {
        return;
    }
    // split ok
    if (curSplitResult.size() == 4 && curSplitIndex == ipAddr.length())
    {
        splitResults.push_back(curSplitResult);
        return;
    }

    int nextSplitIndex = curSplitIndex + 3;
    if (nextSplitIndex > ipAddr.length())
    {
        nextSplitIndex = ipAddr.length();
    }
    while (nextSplitIndex > curSplitIndex)
    {
        std::string splitStr(ipAddr.cbegin() + curSplitIndex, ipAddr.cbegin() + nextSplitIndex);
        int value = atoi(splitStr.c_str());
        if (splitStr.length() == std::to_string(value).length() && value >= 0 && value <= 255)
        {
            curSplitResult.push_back(splitStr);

            DoRestore(ipAddr, nextSplitIndex, curSplitResult, splitResults);
            curSplitResult.pop_back();
        }
        nextSplitIndex--;
    }
}

class Solution {
public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
        if (s.length() < 4 || s.length() > 12)
        {
            return std::vector<std::string>();
        }

        std::vector<std::vector<std::string>> splitResults;
        std::vector<std::string> splitResult;
        DoRestore(s, 0, splitResult, splitResults);
        
        std::vector<std::string> ipResults;

        for (const auto& ip : splitResults)
        {
            std::ostringstream oss;
            oss << ip[0] << '.' << ip[1] << '.' << ip[2] << '.' << ip[3];
            ipResults.push_back(oss.str());
        }

        return ipResults;
    }
};

int main()
{
    Solution s;
    //s.restoreIpAddresses("25525511135");
    s.restoreIpAddresses("010010");
    return 0;
}

