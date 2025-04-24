class Solution
{
public:

    Node * removeDuplicates(struct Node *head)
    {
        // Your code here
        Node* cur = head;
        
        while(cur != NULL && cur->next != NULL){
            if(cur->data == cur->next->data){
                Node* temp = cur->next;
                cur->next = temp->next;
                if(temp->next)
                    temp->next->prev = cur; // updating prev pointer (very imp step) ...
                delete(temp);
            }else{
                cur = cur->next;
            }
        }
        
        return head;
    }
};