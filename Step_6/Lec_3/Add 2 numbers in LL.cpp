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
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* cur1 = l1;
            ListNode* cur2 = l2;
            ListNode* newHead = new ListNode(-1);
            ListNode* newCur = newHead;
    
            int carry = 0;
    
            while(cur1 != NULL || cur2 != NULL){
                int sum = 0;
    
                if(cur1 && cur2)
                    sum = cur1->val + cur2->val;
                else if(cur1)
                    sum = cur1->val;
                else
                    sum = cur2->val;
    
                ListNode* temp = new ListNode((sum%10 + carry)%10);
                carry = (sum + carry)/10;
                newCur->next = temp;
                newCur = newCur->next;
    
                cur1 = (cur1 != NULL) ? cur1->next : NULL;
                cur2 = (cur2 != NULL) ? cur2->next : NULL;
            }
    
            if(carry > 0){
                ListNode* temp = new ListNode(carry);
                newCur->next = temp;
                newCur = newCur->next;
            }
    
            return newHead->next;
        }
    };