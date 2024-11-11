/**
 * Definition for singly-linked list->
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        
        if (list1==nullptr){
            return list2;
        }
        else if (list2==nullptr){
            return list1;
        }
        else if (list1==nullptr and list2==nullptr){
            return nullptr;
        }

        ListNode* head;
        ListNode* n1;
        ListNode* n2;
        ListNode* prev;

        if (list1->val<list2->val){
            head=list1;
            prev=list1;
            n1=list1->next;
            n2=list2;
        }
        else{
            head=list2;
            prev=list2;
            n1=list2->next;
            n2=list1;
        }


        //[1,   2,   4]
        //     ^
        //    p,n2

        //[1,   3,  4]
        //^     ^
        //h    n1

        //[1,2,4]

        //[1,1, 2, ]

        while (n1 and n2){
            if (n1->val<=n2->val){
                prev->next=n1;
                prev=n1;
                n1=n1->next;
            }
            else{
                prev->next=n2;
                prev=n2;
                n2=n2->next;
            }
        }

        if (n1){
            prev->next=n1;
        }
        else{
            prev->next=n2;
        }

        return head;
    }
};

//The ListNode class shows you how the linked list is defined for your chosen language. Take Python3 as an example. 
//To define a linked list [1, 2, 4], you write "l1 = ListNode(1,ListNode(2, ListNode(3, None)))". Hence, 
//to get the first value (the head) of l1, we do "l1.val"; to get second value, we do "l1.next.val"; and to 
//get the third value, we do "l1.next.next.val"

