class Solution {
    public:
      void deleteAllOccurOfX(struct Node** head, int x) {
          // Write your code here
          Node* temp = *head;
          
          while(temp != NULL){
              if(temp->data == x){
                  if(temp == *head){
                      *head = temp->next;
                  }
                  Node* newNode = temp->next;
                  Node* prevNode = temp->prev;
                  if(prevNode) prevNode->next = newNode;
                  if(newNode) newNode->prev = prevNode;
                  delete(temp);
                  temp = newNode;
              }
              else
                  temp = temp->next;
          }
      }
  };