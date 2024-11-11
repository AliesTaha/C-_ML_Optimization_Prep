
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {       
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev;
        ListNode* next;
        ListNode* curr;

        if (head == nullptr || head->next == nullptr){
            return head;
        }

        prev=head;  
        curr=head;
        next=head->next;
        prev->next=nullptr;

        while (next){
            curr=next;
            next=curr->next;
            curr->next=prev;
            prev=curr;
        }
        return prev;
    }
}; 

