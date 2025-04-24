class Solution {
    public:
      Node* addOne(Node* head) {
          // Your Code here
          // return head of list after adding one
          
          string s = "";
          
          Node* cur = head;
          
          while(cur != NULL){
              s += to_string(cur->data);
              cur = cur->next;
          }
          
          int last_idx = s.size()-1;
          
          while(last_idx >= 0 && s[last_idx] == '9'){
              s[last_idx] = '0';
              last_idx--;
          }
          
          if(last_idx == -1){
              s = "1" + s;
          }
          else
              s[last_idx]++;
          
          Node* newHead = new Node(-1);
          Node* newCur = newHead;
          
          for(int i=0;i<s.size();i++){
              newCur->next = new Node(s[i]-'0');
              newCur = newCur->next;
          }
          
          return newHead->next;
      }
  };