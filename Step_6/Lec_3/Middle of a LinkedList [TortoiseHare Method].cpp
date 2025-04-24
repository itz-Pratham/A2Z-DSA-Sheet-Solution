class Solution {
    public:
        ListNode* middleNode(ListNode* head) {
            ListNode* prev = head;
            ListNode* cur = head;
    
            while(cur != NULL){
                if(cur->next) cur = cur->next->next;
                else break;
                if(prev->next) prev = prev->next;
            }
    
            return prev;
        }
    };