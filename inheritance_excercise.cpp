#include <iostream>
#include <string>
//inheritance ann polymorphism

using namespace std;
//base abstract class
class Shape{
    /*protected members cannot be accessed or viewed from outside
     * of the class; except for the class, derived classes and friend functions.*/
    protected:
        string  name;

    /*public members are accessible from any where outside
     * of the class but within the program.*/
    public:
        //constructor
        Shape(string s){name=s;}

        //setters and getters
        void setName(string s){name=s;}
        string getName(){return name;}

        //pure virtual or abstract function
        virtual double getArea()=0;


};

//child classes
class Circle : public Shape{
    protected:
        double radius;
    public:
        //constructor
        Circle(string s, double r): Shape(s){radius=r;}
        //setters and getters
        void setRadius(double r){radius=r;}
        double getRadius(){return radius;}
        virtual double getArea(){return radius*radius*3.1416;}
};

class Triangle: public Shape{
    protected:
        double  height, width;

    public:
        Triangle(string s, double w, double h):Shape(s){
            height=h;
            width=w;
        }
        //setters and getters
        void setWidth(double w){width=w;}
        void setHeight(double h){height=h;}
        double getWidth(){return width;}
        double getHeight(){return height;}
        virtual double getArea(){return 0.5*height*width;}

};

 class Rectangle: public Shape{
protected:
    double  height, width;

    public:
        Rectangle(string s, double w, double h):Shape(s){
            height=h;
            width=w;
        }
        //setters and getters
        void setWidth(double w){width=w;}
        void setHeight(double h){height=h;}
        double getWidth(){return width;}
        double getHeight(){return height;}
        virtual double getArea(){return height*width;}
    };

int main() {
    Rectangle R("Rectangle",2,3);
    cout<<R.getArea()<<endl;
    //polymorphism using pointers
    Shape *shape= new Rectangle("rectangle", 4, 5);
    cout<<shape->getArea()<<endl;
    //polymorphism using reference
    shape=&R;
    cout<<shape->getArea()<<endl;
    return 0;
}
