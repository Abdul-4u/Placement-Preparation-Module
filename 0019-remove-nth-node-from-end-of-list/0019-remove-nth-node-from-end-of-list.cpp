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
ListNode* removeNthFromEnd(ListNode* head, int n) {

    ListNode origin = ListNode(0,head); 
    
    ListNode * leftn = &origin;        
    while(n>0 ){
        leftn=leftn->next;
        n--;
    }
    ListNode * rightn = &origin;
    while(leftn->next){
        leftn = leftn->next;
        rightn = rightn->next;
    }
    rightn->next = rightn->next->next;
    
    return origin.next;
}
};