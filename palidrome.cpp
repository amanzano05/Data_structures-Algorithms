#include <iostream>
#include <ctype.h>
using namespace std;


class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;
        int j=s.length()-1;
        while(j>i){
            if (isalnum(s[i]) && isalnum(s[j])){
                if (tolower(s[i])!=tolower(s[j])) {
                    return false;
                }else{
                    i++;
                    j--;
                }

            }
            if (!isalnum(s[i])) i++;
            if (!isalnum(s[j])) j--;
        }
        return true;
    }
};

int main() {
    Solution mySolution;
    string s="A man, a plan, a canal: Panama";
    bool r=mySolution.isPalindrome(s);
    cout<<r<<endl;
    return 0;
}
