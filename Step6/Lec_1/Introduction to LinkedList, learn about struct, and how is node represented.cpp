class Solution {
    public:
      Node* constructLL(vector<int>& arr) {
          // code here
          Node* head = new Node(arr[0]);
          Node* cur = head;
          for(int i=1;i<arr.size();i++){
              Node* temp = new Node(arr[i]);
              cur->next = temp;
              cur = cur->next;
          }
          
          return head;
      }
  };