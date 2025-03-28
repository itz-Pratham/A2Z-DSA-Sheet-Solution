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
        bool isPalindrome(ListNode* head) {
            ListNode* cur = head;
    
            if(cur->next == NULL) return true;
    
            ListNode* slow = head;
            ListNode* fast = head;
    
            while(fast != NULL && fast->next != NULL){
                slow = slow->next;
                fast = fast->next->next;
            }
    
            cur = slow;
            ListNode* prev = nullptr;
    
            while(cur != NULL){
                ListNode* temp = cur->next;
                cur->next = prev;
                prev = cur;
                cur = temp;
            }
    
            while(prev != NULL){
                if(prev->val == head->val){
                    prev = prev->next;
                    head = head->next;
                }
                else{
                    return false;
                }
            }
    
            return true;
        }
    };