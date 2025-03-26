class Solution {
    public:
      // Function to count nodes of a linked list.
      int getCount(struct Node* head) {
  
          // Code here
          Node* cur = head;
          int cnt = 0;
          
          while(cur != NULL){
              cur = cur->next;
              cnt++;
          }
          
          return cnt;
      }
  };