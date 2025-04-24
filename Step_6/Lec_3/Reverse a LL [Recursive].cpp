class Solution {
    public:
        void recursize(ListNode* &cur, ListNode* &prev){
            if(cur == NULL){
                return;
            }
    
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
    
            recursize(cur,prev);
    
            return;
        }
    
        ListNode* reverseList(ListNode* head) {
            ListNode* cur = head;
            ListNode* prev = nullptr;
    
            recursize(cur,prev);
    
            return prev;
        }
    };