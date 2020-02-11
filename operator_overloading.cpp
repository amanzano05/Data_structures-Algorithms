#include <iostream>
#include <string>
using namespace std;
class FamilyMember{
public:
    string  name, lastname1, lastname2;
    FamilyMember(string a, string b, string c){name=a; lastname1=b, lastname2=c;}



    friend FamilyMember operator + (FamilyMember const &dad, FamilyMember const &mom){
        string nm;
        cout<<"Name: "<<endl;
        cin>>nm;
        FamilyMember child(nm,dad.lastname1,mom.lastname1);
        return child;
    }
};
int main() {
    FamilyMember father("alfonso","manzano", "gonzalez");
    FamilyMember mother("Rosy","Reyes","Loera");

    FamilyMember son=father+mother;

    cout<<son.name<<" "<<son.lastname1<<" "<<son.lastname2<<endl;


    return 0;
}
