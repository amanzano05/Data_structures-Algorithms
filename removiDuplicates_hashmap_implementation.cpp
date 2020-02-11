#include <iostream>
#include <vector>
#include <map>
using  namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //using maps
        map<int, int> myMap;//map value-index
        //map all the elements by their value
        for (int i=0; i<nums.size();i++){
            myMap[nums[i]];
        }
        //empty the vector
        nums.clear();
        //fill the vector with the map
        /*for (int i =0 ; i<myMap.size(); i++){
            nums.push_back(myMap[i]);
        }*/
        for (auto element: myMap){
            nums.push_back(element.first);
        }
        return myMap.size();

        /*int size=nums.size();
        int i=0;
        if (size<=0) return size;
        for (int j=0; j < size; j++ ){
            if (nums[i]!= nums[j]){
                nums[i+1]=nums[j];
                i++;
            }
        }
        nums.resize(i+1);
        return i+1;*/
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
