class Solution {
    public:
      // Function to reverse a doubly linked list
      DLLNode* reverseDLL(DLLNode* head) {
          // Your code here
          
          if(!head) return nullptr;
          
          DLLNode* cur = head;
          DLLNode* newHead = cur;
          
          while(cur != NULL){
              DLLNode* temp = cur->prev;
              cur->prev = cur->next;
              cur->next = temp;
              newHead = cur;
              cur = cur->prev;
          }
          
          return newHead;
      }
  };