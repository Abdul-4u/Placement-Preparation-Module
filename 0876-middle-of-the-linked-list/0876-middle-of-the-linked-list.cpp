/**
 * Definition for singly-linked list.
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
    ListNode* middleNode(ListNode* head) {
        
       /*Take two pointers, that moves two node and other moves
        one node at a time*/

        ListNode* fast=head->next;
        ListNode* slow=head;

        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }

       /* Now find numbers of node present in the linked list as we 
         have to return mid+1 node for even numbered linked lists*/
       
        ListNode* temp=head;
        int count=0;

        while(temp!=NULL){
            temp=temp->next;
            count++;
        }

        if(count%2==0){
            return slow->next;
        }
        else{
            return slow;
        }
    }
};