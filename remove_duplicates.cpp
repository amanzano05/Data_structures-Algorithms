/*Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

It doesn't matter what you leave beyond the returned length.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //using maps
        if (nums.size()<2) return nums.size();
        map<int, int> myMap;//map value-index
        //map all the elements by their value
        for (int i=0; i<nums.size();i++) myMap[nums[i]];
        //empty the vector
        nums.clear();
        //fill the vector with the map
        for (auto element: myMap) nums.push_back(element.first);
        return myMap.size();
    }
};



int main() {
    vector<int> myVec{1,1,2,3,3,5,6};
    Solution sol;
    int res=sol.removeDuplicates(myVec);
    cout<<res<<endl;
    for(int i=0 ; i<myVec.size(); i++){
        cout<<myVec[i]<<" ";
    }
    return 0;
}
