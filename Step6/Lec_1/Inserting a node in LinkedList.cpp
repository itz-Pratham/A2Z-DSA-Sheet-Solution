class Solution {
    public:
      Node *insertAtEnd(Node *head, int x) {
          // Code here
          Node* cur = head;
          
          if(cur == NULL){
              Node* n = new Node(x);
              n->next = head;
              head = n;
              return head;
          }
          
          while(cur->next != NULL)
              cur = cur->next;
              
          cur->next = new Node(x);
          
          return head;
      }
  };