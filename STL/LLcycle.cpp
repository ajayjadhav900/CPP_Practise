#include <iostream>
#include <unordered_map>
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode *head)
{
    std::unordered_map<ListNode *, int> hashMap;
    for (auto *temp = head; temp->next != nullptr; temp = temp->next)
    {
        auto res = hashMap.insert(std::make_pair(head->next, head->val));
        if (res.second == false)
        {
            return true;
        } 
    }

    return false;
}

int main()
{
    // Create a sample linked list with a cycle (for demonstration purposes).
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = head->next; // Creating a cycle

    // Check if the linked list has a cycle
    if (hasCycle(head))
    {
        std::cout << "The linked list has a cycle.\n";
    }
    else
    {
        std::cout << "The linked list does not have a cycle.\n";
    }

    // Clean up the memory (not necessary for the algorithm)
    ListNode *current = head;
    while (current != nullptr)
    {
        ListNode *temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
