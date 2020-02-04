#include<bits/stdc++.h>

using namespace std;
//Implement the class Box
class Box{
    //l,b,h are integers representing the dimensions of the box
private:
    int l, b, h ;
public:
    // The class should have the following functions :
    // Constructors:
    // Box();
    Box(){
        l=0;
        b=0;
        h=0;
    }
    // Box(int,int,int);
    Box(int x, int y, int z){
        l=x;
        b=y;
        h=z;
    }
    // Box(Box);
    Box(const Box &B){
        l=B.l;
        b=B.b;
        h=B.h;
    }

    // int getLength(); // Return box's length
    int getLength(){return l;}
    // int getBreadth (); // Return box's breadth
    int getBreadth(){return b;}
    // int getHeight ();  //Return box's height
    int getHeight(){return h;}

    // long long CalculateVolume();
    // Return the volume of the box
    long long CalculateVolume(){return (long long )l*b*h;}


//Overload operator < as specified
//bool operator<(Box& b)
bool operator<(Box &boxObject){
        return (l<boxObject.l) || (b<boxObject.b && l==boxObject.l) || (h<boxObject.h && b==boxObject.b && l==boxObject.l) ;
    }

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)
//since an ostream does not have acces to the private variables of Box,
//we need to make it friend.
friend ostream & operator << (ostream& out, const Box &b){
        out<<b.l<<" "<<b.b<<" "<<b.h;
        return out;
    }
};

void check2()
{

    int n;
    cin>>n;
    Box temp;
    for(int i=0;i<n;i++)
    {
        int type;
        cin>>type;
        if(type ==1)
        {
            cout<<temp<<endl;
        }
        if(type == 2)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            temp=NewBox;
            cout<<temp<<endl;
        }
        if(type==3)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            if(NewBox<temp)
            {
                cout<<"Lesser\n";
            }
            else
            {
                cout<<"Greater\n";
            }
        }
        if(type==4)
        {
            cout<<temp.CalculateVolume()<<endl;
        }
        if(type==5)
        {
            Box NewBox(temp);
            cout<<NewBox<<endl;
        }

    }
}

int main()
{
    //input:
    //5
    //2 3 4 5
    //4
    //5
    //4
    //2 4 6 7

    //output:
    //3 4 5
    //60
    //3 4 5
    //60
    //4 6 7
    check2();
}
