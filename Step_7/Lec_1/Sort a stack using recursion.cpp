/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */

void merge(vector<int> &arr, int s, int m, int e) {

	int i = s;
	int j = m + 1;
	int k = s;

	int crr[100];

	while (i <= m and j <= e) {

		if (arr[i] < arr[j]) {
			crr[k] = arr[i];
			i++;
			k++;
		} else {
			crr[k] = arr[j];
			j++;
			k++;
		}

	}

	while (i <= m) {
		crr[k] = arr[i];
		i++;
		k++;
	}

	while (j <= e) {
		crr[k] = arr[j];
		j++;
		k++;
	}

	for (int l = s; l <= e; l++) {
		arr[l] = crr[l];
	}

}

void mergeSort(vector<int> &arr, int s, int e) {
    
	if (s == e) {
		return;
	}

	int m = s + (e - s) / 2;

	mergeSort(arr, s, m);
	mergeSort(arr, m + 1, e);

	merge(arr, s, m, e);

}

void SortedStack :: sort()
{
   //Your code here
   vector<int> v;
   while(!s.empty()){
       v.push_back(s.top());
       s.pop();
   }
   
   mergeSort(v,0,v.size()-1);
   
   for(int i=0;i<v.size();i++){
       s.push(v[i]);
   }
}