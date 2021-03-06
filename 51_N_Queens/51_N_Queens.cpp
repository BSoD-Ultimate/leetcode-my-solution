// 51_N_Queens.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>
#include <string>
#include <set>

typedef std::vector<int> NQueenSolution;

// check diagonal
bool TryPlaceQueen(NQueenSolution& solution, int curColumn, int placeRow)
{
    int fieldSize = solution.size();

    // left-top
    {
        int colIndex = curColumn;
        int rowIndex = placeRow;

        while (rowIndex < fieldSize && colIndex >= 0)
        {
            if (solution[colIndex] == rowIndex)
            {
                return false;
            }
            colIndex--;
            rowIndex++;
        }
    }
    // left-bottom
    {
        int colIndex = curColumn;
        int rowIndex = placeRow;

        while (rowIndex >= 0 && colIndex >= 0)
        {
            if (solution[colIndex] == rowIndex)
            {
                return false;
            }
            colIndex--;
            rowIndex--;
        }
    }

    solution[curColumn] = placeRow;

    return true;
}

void DoSolveNQueens(int n, NQueenSolution solution, int curColumn, std::vector<NQueenSolution>& solutions)
{
    std::set<int> availableRowIndexes;
    for (size_t i = 0; i < n; i++)
    {
        availableRowIndexes.insert(i);
    }

    for (size_t i = 0; i < curColumn; i++)
    {
        availableRowIndexes.erase(solution[i]);
    }

    // last queen
    if (availableRowIndexes.size() == 1 || curColumn == n - 1)
    {
        if (TryPlaceQueen(solution, curColumn, *availableRowIndexes.begin()))
        {
            solutions.push_back(solution);
        }
        return;
    }

    for (auto iter = availableRowIndexes.cbegin(); iter != availableRowIndexes.cend(); iter++)
    {
        if (TryPlaceQueen(solution, curColumn, *iter))
        {
            DoSolveNQueens(n, solution, curColumn + 1, solutions);
        }
    }
}

class Solution {
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<NQueenSolution> solutions;
        DoSolveNQueens(n, NQueenSolution(n, -1), 0, solutions);

        std::vector<std::vector<std::string>> encodedSolutions;

        for (const NQueenSolution& solution : solutions)
        {
            std::string row(n, '.');
            std::vector<std::string> encodedSolution(n, row);

            for (size_t i = 0; i < solution.size(); i++)
            {
                encodedSolution[solution[i]][i] = 'Q';
            }

            encodedSolutions.push_back(encodedSolution);
        }

        return encodedSolutions;
    }
};

int main()
{
    Solution s;
    auto solutions1 = s.solveNQueens(4);
    auto solutions2 = s.solveNQueens(8);
    return 0;
}

