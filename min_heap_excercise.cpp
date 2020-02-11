#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int size= nums.size();// size of the vector
        //create a min Heap
        priority_queue<int, vector<int>, greater<int> > minHeap;
        //for all the elements in nums keep
        //only the K greatest elements in the in heap
        for (int i=0 ; i<size; i++){
            //if the size of the heap is less that k
            //then push the element into the heap
            if (minHeap.size()<k){
                minHeap.push(nums[i]);
            }else{
                //otherwise if the top of the heap is smaller than
                //the current elemnt replace the top for the element
                if(minHeap.top()<nums[i]){
                    minHeap.pop();
                    minHeap.push(nums[i]);
                }
            }
        }
        //return the smallest number
        //since we are just keepeing the greatest k elements
        return minHeap.top();
    }
};


int main() {
    int k=2;
    vector <int> vec{3,2,1,5,6,4};
    Solution sol;
    int res=sol.findKthLargest(vec, k);
    cout<<res<<endl;
    return 0;
}
