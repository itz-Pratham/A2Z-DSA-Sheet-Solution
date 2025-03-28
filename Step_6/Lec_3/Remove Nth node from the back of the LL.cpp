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
            ListNode* cur = head;
            ListNode* start = head;
            ListNode* prev = start;
            int sz = 0;
            int finale = sz;
    
            while(cur != NULL){
                cur = cur->next;
                sz++;
            }
    
            finale = sz-n;
            sz = 0;
    
            if(finale == 0) return head->next;
    
            while(sz != finale){
                prev = start;
                start = start->next;
                sz++;
            }
    
            prev->next = start->next;
    
            return head;
    
        }
    };