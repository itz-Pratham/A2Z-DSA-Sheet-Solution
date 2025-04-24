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
        ListNode* reverse(ListNode* head){
            ListNode* cur1 = head;
            ListNode* prev1 = NULL;
    
            while(cur1 != NULL){
                ListNode* temp = cur1->next;
                cur1->next = prev1;
                prev1 = cur1;
                cur1 = temp;
            }
    
            return prev1;
        }
        ListNode* reverseKGroup(ListNode* head, int k) {
            
            ListNode* cur = head;
            int n = 1;
            ListNode* listEnd = head;
            ListNode* previous = NULL;
    
            while(listEnd != NULL && cur != NULL){
                if(n != k){
                    listEnd = listEnd->next;
                    n++;
                }
                else{
                    ListNode* nextNode = listEnd->next;
                    listEnd->next = NULL;
                    ListNode* newHead = reverse(cur);
                    if(cur == head){
                        head = newHead;
                    }
                    else{
                        if(previous) previous->next = newHead;
                    }
                    previous = cur;
                    cur->next = nextNode;
                    cur = cur->next;
                    listEnd = nextNode;
                    n = 1;
                }
            }
    
            return head;
        }
    };