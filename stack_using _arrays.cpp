//Alfonso Manzano Gonzalez
//Stack Data structure implementation using arrays
#include <iostream>

using namespace std;

//size of the stack
#define SIZE 5

template <class myStackType>
class Stack{
    //variable used for the top of the stack
    int top;   
    myStackType myStack[SIZE];

    public:
    //array used

    //constructor
    Stack(){top=-1;}

    //functions
    //pushes an element into the stack
    void push(myStackType x){
        if (top>=SIZE-1){
            cout<<"Stack Overflow \n";
        }else{
            myStack[++top]= x;//increment top before assign it to x
            cout<<x<<" inserted! \n";
        }
    }
    //pops an element from the stack
    myStackType pop(){
        if (top<0){
            cout<<"Stack is Underflow \n";
            return 0;
        }else{
            cout<<myStack[top]<<" popped! \n";
            return myStack[top--];//decrement top after the return
        }
    }
     void displayStack(){
        cout<<"Stack:[ ";
        for (int i=top; i>=0; i--){
            cout<<myStack[i]<<" ";
        }
        cout<<"]\n";
    }

    //checks if the stack is empty
    bool isEmpty(){return top<0;}
};

/*
//the function can be placed outside of the class as follows:
template <class myStackType>
void Stack<myStackType>::push(myStackType x){
    if (top>=SIZE){
        cout<<"Stack Overflow \n";
    }else{
        myStack[top]= x;
        x++;
        cout<<"Element Inserted \n";
    }
}
*/





//driver

int main() {
    //example with integers
    Stack<int> stack;
    bool empty= stack.isEmpty();
    cout<<"the stack is empty? "<<empty<<endl;
    stack.pop();
    int i=1;
    while (i<5){
        cout<<"pushing "<<i<<endl;
        stack.push(i++);
    }
    stack.displayStack();

    for(int i=1; i<5; i++){
      cout<<  stack.pop()<<endl;
    }

    //example with chars
    Stack<char> charStack;
    charStack.push('A');
    charStack.push('M');
    charStack.push('G');
    charStack.displayStack();
    return 0;
}
