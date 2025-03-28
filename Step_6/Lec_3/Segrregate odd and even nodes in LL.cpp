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
        ListNode* oddEvenList(ListNode* head) {
    
            if(!(head && head->next && head->next->next)) return head;
            
            ListNode* odd = head;
            ListNode* even = head->next;
            ListNode* evenStart = even;
            ListNode* cur = head->next->next;
    
            while(cur != NULL){
                odd->next = cur;
                odd = odd->next;
                cur = cur->next;
                if(cur){ 
                    even->next = cur;
                    even = even->next;
                    cur = cur->next;
                }
            }
    
            even->next = NULL;
    
            odd->next = evenStart;
    
            return head;
    
        }
    };