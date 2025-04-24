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
        ListNode* rotateRight(ListNode* head, int k) {
            ListNode* prev = head;
            ListNode* cur = head;
            ListNode* k_start = head;
            int sz = 0;
            
            while(cur != NULL){
                prev = cur;
                cur = cur->next;
                sz++;
            }
    
            if(sz == 0 || sz == 1 || k%sz == 0) return head;
    
            int cnt = 1;
    
            while(sz-cnt != (k%sz)){
                k_start = k_start->next;
                cnt++;
            }
    
            ListNode* temp = k_start->next;
            k_start->next = NULL;
            prev->next = head;
    
            return temp;
        }
    };