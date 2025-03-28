class Solution {
    public:
        ListNode *detectCycle(ListNode *head) {
            ListNode* slow = head;
            ListNode* fast = head;
    
            while(fast != NULL and fast->next != NULL){
                slow = slow->next;
                fast = fast->next->next;
    
                if(slow == fast){
                    break;
                }
            }
            
            if(!(fast && fast->next)) return nullptr;
    
            while(head != slow){
                head = head->next;
                slow = slow->next;
            }
    
            return head;
        }
    };