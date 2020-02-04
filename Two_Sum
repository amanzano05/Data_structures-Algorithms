/*Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//prints the array
void printArr(vector<int> & arr){
    //print vector;
    cout<<"{ ";
    for (int i =0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<"}\n";
}

//comparator used for sorting from greater to lower
bool MyComp(int i, int j){return i<j;}


//===============two sum bigO(n^2)===================//
// Return the indices, not the values
vector <int> twoSum(vector<int> arr, int target){
    for (int i=0; i<arr.size();i++){
        for(int j=0; j<arr.size();j++){
            if (arr[i]+arr[j]==target && i!=j){
                return {i, j};
            }
        }
    }
    return {};
}

//======================two sum bigO(n log n)===============================//
//steps:
//sort the array and save original indexes. two options using structure or pair
//get the first element and the last; i, j
//while i<j
//if i+j>target: j--
//if i+j<target: i++
//if i+j=target: return i and j

//------------using structure
struct myPairs{
    int first, second;
};

//comparator needed
bool comparator(myPairs a, myPairs b){
    return a.first<b.first;
}

vector<int>twoSumBetter(vector<int> arr, int target ){
    //creates a vector of pairs
    vector<myPairs> pair;
    //fills the vector with the value and corresponding index
    for (int i=0; i<arr.size(); i++){
        pair.push_back(myPairs());
        pair[i].first=arr[i];
        pair[i].second=i;
    }
    sort(pair.begin(), pair.end(), comparator);
    int i=0;
    int j=arr.size()-1;
    while(i<j){
       if (pair[i].first+pair[j].first>target){j--;}
       if (pair[i].first+pair[j].first<target){i++;}
       if (pair[i].first+pair[j].first==target){return {pair[i].second, pair[j].second};}
    }

    return {};
}


//------------------using pair data structure
vector<int>twoSumBetterPairs(vector<int> arr, int target ){
    //creates a vector of pairs
    vector< pair<int, int> > myPairs;
    //fills the vector with the value and corresponding index
    for (int i=0; i<arr.size(); i++){
        pair <int, int> temp (arr[i], i);
        myPairs.push_back(temp);
    }
    sort(myPairs.begin(), myPairs.end());
    int i=0;
    int j=arr.size()-1;
    while(i<j){
        if (myPairs[i].first+myPairs[j].first>target){j--;}
        if (myPairs[i].first+myPairs[j].first<target){i++;}
        if (myPairs[i].first+myPairs[j].first==target){return {myPairs[i].second,myPairs[j].second};}
    }

    return {};
}

int main() {
    vector<int> myArr{1,7, 8, 2, 15};

    vector<int> copyArr=myArr;

    cout<<"original array:\n";
    printArr(myArr);

    //print sorted vector low to high
    cout<<"Sorted array(low to high):\n";
    sort(myArr.begin(),myArr.end());
    printArr(myArr);

    //print array high to low
    cout<<"Sorted array(high to low):\n";
    sort(myArr.begin(), myArr.end(), MyComp);
    printArr(myArr);


    //get the original array
    myArr=copyArr;

    cout<<"original array:\n";
    printArr(myArr);

    //target sum is 16 with bigO(n^2)
    int tar=16;
    vector<int> sum=twoSum(myArr,tar);
    cout<<"indices from array to sum: "<<tar<<endl;
    cout<<"BigO(n^2):\n";
    printArr(sum);

    //target sum is with bigO(n^2)
    sum=twoSumBetter(myArr,tar);
    cout<<"BigO(n log n) using structure:\n";
    printArr(sum);

    //target sum is with bigO(n^2)
    sum=twoSumBetterPairs(myArr,tar);
    cout<<"BigO(n log n) using pairs:\n";
    printArr(sum);

    return 0;
}
