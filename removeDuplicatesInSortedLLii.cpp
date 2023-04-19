#include <bits/stdc++.h>
using namespace std;
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int data)
    {
        val = data;
        next = NULL;
    }
};
ListNode *make_list(vector<int> v)
{
    ListNode *head = new ListNode(v[0]);
    for (int i = 1; i < v.size(); i++)
    {
        ListNode *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new ListNode(v[i]);
    }
    return head;
}
void print_list(ListNode *head)
{
    ListNode *ptr = head;
    cout << "[";
    while (ptr)
    {
        cout << ptr->val << ", ";
        ptr = ptr->next;
    }
    cout << "]" << endl;
}
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *nex = head->next;
        if (nex->val == head->val)
        {
            while (nex && nex->val == head->val)
                nex = nex->next;
            return deleteDuplicates(nex);
        }
        else
        {
            head->next = deleteDuplicates(nex);
            return head;
        }
    }
};
main()
{
    Solution ob;
    vector<int> v = {1,2,3,3,4,4,5};
    ListNode *head = make_list(v);
    print_list(ob.deleteDuplicates(head));
}