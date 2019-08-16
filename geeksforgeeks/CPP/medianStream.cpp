#include <bits/stdc++.h>
using namespace std;
class Median{
    public:
    priority_queue<int> max_heap;
    priority_queue<int,vector<int>,greater<int>>min_heap;
    void insert(int i){
        if(max_heap.empty() || max_heap.top()>i){
         max_heap.push(i);   
        }
        else{
            min_heap.push(i);
        }
        if(max_heap.size()>min_heap.size()+1){
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        else if(max_heap.size()+1 < min_heap.size()){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    double findMedian(){
        if(max_heap.size()==min_heap.size()){
            return max_heap.empty()?0: ((max_heap.top()+min_heap.top())/2.0);
        }
        else
        return max_heap.size()>min_heap.size()? max_heap.top():min_heap.top();
    }
};
int main() {
	cin>>n;
	Median m;
	while(n--){
	   cin>>x;
	   m.insert(x);
	   cout<<(int)m.findMedian()<<" ";
	    	cout<<endl;
	}
	return 0;
}