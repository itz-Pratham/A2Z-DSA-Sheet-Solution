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
        ListNode* sortList(ListNode* head) {
            vector<int> v;
            ListNode* cur = head;
            ListNode* newList = head;
            ListNode* newCur = newList;
    
            if(!(head && head->next)) return head;
    
            while(cur != NULL){
                v.push_back(cur->val);
                cur = cur->next;
            }
    
            sort(v.begin(),v.end());
    
            for(int i=0;i<v.size();i++){
                ListNode* temp = new ListNode(v[i]);
                newCur->next = temp;
                newCur = newCur->next;
            }
    
            return newList->next;
        }
    };