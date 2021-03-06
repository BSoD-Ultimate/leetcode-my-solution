// 382_Linked_List_Random_Node.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <map>
#include <cstdlib>
#include <ctime>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /** @param head The linked list's head.
    Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) 
        : nodeCount(0)
        , _lHead(head)
    {
        int count = 0;
        ListNode* h = head;
        while (h)
        {
            count++;
            h = h->next;
        }
        nodeCount = count;
    }

    /** Returns a random node's value. */
    int getRandom() {
        return getIndex(rand() % nodeCount);
    }

    int getIndex(int index)
    {
        ListNode* node = _lHead;
        size_t startIndex = 0;

        //auto nearestIter = FindNearest(index);
        //if (nearestIter != _listNodePtrs.cend())
        //{
        //    node = nearestIter->second;
        //    startIndex = nearestIter->first;
        //}
        //else
        //{
        //    node = _lHead;
        //}


        for (size_t i = startIndex; i < index && node->next; i++)
        {
            node = node->next;
        }
        
        //_listNodePtrs[index] = node;

        return node->val;
    }

    //std::map<int, ListNode*>::const_iterator FindNearest(int index)
    //{
    //    if (_listNodePtrs.empty())
    //    {
    //        return _listNodePtrs.cend();
    //    }

    //    auto iterFind = _listNodePtrs.find(index);
    //    if (iterFind != _listNodePtrs.cend())
    //    {
    //        return iterFind;
    //    }
    //    
    //    auto nearestIter = _listNodePtrs.cbegin();
    //    auto prevIter = nearestIter;
    //    while (nearestIter != _listNodePtrs.cend())
    //    {
    //        if (nearestIter->first - index > 0)
    //        {
    //            return prevIter;
    //        }

    //        prevIter = nearestIter;
    //        nearestIter++;
    //    }

    //    return prevIter;
    //}
private:
    int nodeCount;
    ListNode* _lHead;
    //std::map<int, ListNode*> _listNodePtrs;

};

/**
* Your Solution object will be instantiated and called as such:
* Solution obj = new Solution(head);
* int param_1 = obj.getRandom();
*/

static ListNode* getRandomLinkedList(int listCount) 
{
    ListNode* lHead = NULL;

    for (size_t i = 0; i < listCount; i++)
    {
        ListNode* newNode = new ListNode(rand());
        newNode->next = lHead;
        lHead = newNode;
    }

    return lHead;
}

int main()
{
    srand(unsigned(time(NULL)));

    ListNode* l = getRandomLinkedList(900);

    Solution s(l);

    int i = 0;
    i = s.getRandom();
    i = s.getRandom();
    i = s.getRandom();
    i = s.getRandom();
    i = s.getRandom();
    i = s.getRandom();
    return 0;
}

