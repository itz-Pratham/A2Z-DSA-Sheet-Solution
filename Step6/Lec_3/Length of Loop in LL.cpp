class Solution {
    public:
      // Function to find the length of a loop in the linked list.
      int countNodesinLoop(Node *head) {
          // Code here
          Node* cur = head;
          Node* prev = head;
          
          while(cur != nullptr && cur->next != nullptr){
              prev = prev->next;
              cur = cur->next->next;
              
              if(prev == cur){
                  break;
              }
          }
          
          if(!(cur && cur->next)) return 0;
          
          while(head != prev){
              head = head->next;
              prev = prev->next;
          }
          
          Node* h = head;
          int number = 1;
          head = head->next;
          
          while(head != h){
              head = head->next;
              number++;
          }
          
          return number;
      }
  };