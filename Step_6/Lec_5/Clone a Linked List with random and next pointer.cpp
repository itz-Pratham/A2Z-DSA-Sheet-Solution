/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    public:
        Node* copyRandomList(Node* head) {
            Node* cur = head;
    
            if(!head) return nullptr;
    
            // making new nodes in between
            while(cur != NULL){
                Node* temp = new Node(cur->val);
                temp->next = cur->next;
                cur->next = temp;
                cur = temp->next;
            }
    
            // connecting random pointers
            cur = head;
    
            while(cur != NULL){
                Node* copyNode = cur->next;
                if(cur->random) copyNode->random = cur->random->next;
                else copyNode->random = NULL;
                cur = cur->next->next;
            }
    
            // connecting next pointers
            Node* newHead = new Node(-1);
            Node* newCur = newHead;
            cur = head;
    
            while(cur != NULL){
                newCur->next = cur->next;
                cur->next = cur->next->next;
                newCur = newCur->next;
                cur = cur->next;
            }
    
            return newHead->next;
        }
    };