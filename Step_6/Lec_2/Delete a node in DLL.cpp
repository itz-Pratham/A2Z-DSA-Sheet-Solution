class Solution {
    public:
      // Function to delete a node at given position.
      Node* deleteNode(Node* head, int pos) {
          // Your code here
          Node* cur = head;
          int pos_rn = 1;
          
          if(pos_rn == pos){
              head = head->next;  
              if (head) head->prev = NULL;  
              delete cur;  
              return head;
          }
          
          while(cur->next != NULL){
              cur = cur->next;
              pos_rn += 1;
              if(pos_rn == pos) break;
          }
          
          Node* temp = cur->next;
          Node* prevNode = cur->prev;
          prevNode->next = temp;
          
          if(temp)
              temp->prev = prevNode;
          
          return head;
      }
  };