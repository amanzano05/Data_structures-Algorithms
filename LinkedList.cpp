//implementation of a linkedList
#include <iostream>
#include <string>

using namespace std;
//struct for linkedList
struct node {
    int data;
    node* next;
};

class LinkedList{
private:
    node* head;
public:
    //constructor
    LinkedList() { head = NULL; }
    

    //funtion for adding a node in the front
    void addNode(int data) {
        //create the new node
        node* newNode = new node;
        //asign the new data
        newNode->data = data;
        //point next to the head
        newNode->next = head;
        //make the head the new node
        head = newNode;
    }

    //add an element to the back
    void addNodeBack(int data) {
        //create the node
        node *newNode = new node;
        //assign the data
        newNode->data = data;
        //point next to null since it is the last one
        newNode->next = NULL;
        //if list is empty make the node the the head
        if (head == NULL) {
            head= newNode;
        }else {
            //get the first element
            node* current = head;
            //go to the last element
            //while current is not NUll
            //go to the next one
            while (current->next) {
                current = current->next;
            }
            //add the element
            current->next = newNode;
        }
    }

    //get the value for the corresponding index
    int getValue(int index) {
        node* current = head;
        int counter = 0;
        while (current) {
            if (counter == index) { return current->data; }
            current = current->next;
            counter++;
        }
        cout << "Index no found\n";
        return -1;
    }

    //print the list;
    void printList() {
        node *current =head;
        //while current is not null
        //print the data and move to the next one
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    //insert in possition n
    void insert(int data, int position) {
        //create an iterator
        node* current = head;
        //create a counter;
        int counter = 0;
        //create node
        node* newNode = new node;
        //assign the data to the new node
        newNode->data = data;
        //got to the insertion position 
        while (current) {
            //get the last element before insertion
            if (counter == position - 1) break;
            counter++;
            current = current->next;
        }
        //if the position is not null insert the element
        //other wise out of bounds
        if (current != NULL) {
            //point to the next element
            newNode->next = current->next;
            //point the last eleent before insertion to the elemment inserted
            current->next = newNode;
        }
        else { cout << "Error."; }
    }
    int size() {
        //iterator
        node* current = head;
        //counter
        int count = 0;
        //while current is not NULL count and move to the next one
        while (current) {
            count++;
            current = current->next;
        }
        return count++;
    }

    int findVal(int val){
        node* current = head;
        int counter = 0;
        //while current is not null and val is not data 
        //go to the next one
        while (current && val != current->data) {
            counter++;
            current = current->next;
        }
        if (current) {
           // return index
            return counter;
        }
        else { 
            cout << "Value not found\n";
            return -1; }
    }

    void deleteVal(int val) {
        //find the position of the value
        int position = findVal(val);
        //iterator
        node* current = head;
        //if position position no found return
        if (position == -1) {  
            return;
        }
        //go to the element[position-1] 
        //the previous element before the one to be deleted
        for (int i = 0; i < position-1; i++) {
            current = current->next;
        }
        current->next = current->next->next;
    }

    void deleteIndex(int index) {
        //if the linkList is emty return 
        if (size() == 0) {
            cout << "The linkedList is empty...\n";
            return;
        }
        node* current = new node;
        current = head;
        int counter = 0;
        //if the index is the head
        if (index == 0) { head = head->next; }
        //if the index is negative
        if (index < 0) { return; }
        //go to the element before the index 
        while (current->next && (counter < index - 1)) {
            current = current->next;
            counter++;
         }
        //if the next index is valid
        if (current->next!=NULL) {
            //point the elment before the index to the one after the index
            current->next = current->next->next;
        }
        else {
            cout << "Error out of bounds\n";
        }
    }
};



int main()
{
    LinkedList myLs;
    myLs.addNode(1);
    //list:1
    myLs.addNode(2);
    //list:2,1
    myLs.addNodeBack(4);
    //list:2,1,4
    myLs.addNode(5);
    //list:5,2,1,4
    myLs.printList();
    //list:5,2,1,4
    myLs.insert(3, 4);
    //list:5,2,1,4,3
    myLs.printList();
    //list:5,2,1,4,3
    cout << "index 2: " << myLs.getValue(2)<<endl;
    //out:index 2: 1
    cout << myLs.findVal(3) << endl;
    //out:4
    cout << myLs.size() << endl;
    //out:5
    myLs.deleteVal(3);
    //list:5,2,1,4
    myLs.printList();
    //out:5,2,1,4
    myLs.deleteIndex(-1);
    myLs.printList();

    
}

