// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
using namespace std;
class A{
public:
    
	virtual void M1() { cout << "A.M1()" << endl; }
	void M2(){ cout << "A.M2()" << endl; }
    A(){cout<<"A constructor"<<endl;}
    ~A(){cout<<"A Destructor"<<endl;}

};
class B:public A {
public :

		 void M1() override final  { cout << "B.M1()" << endl; }
		 void M2() { cout << "B.M2()" << endl; }
		 virtual void M3(){ cout << "B.M3()" << endl; }
		 void M4() { cout << "B.M4" << endl; }
             B(){cout<<"B constructor"<<endl;}
    ~B(){cout<<"B Destructor"<<endl;}
};
class C:public B {
public:

	//void M1()  { cout << "C.M1()" << endl; }
	void M3() override { cout << "C.M3()" << endl; }
	void M4()  { cout << "C.M4()" << endl; }
        C(){cout<<"C constructor"<<endl;}
    ~C(){cout<<"C Destructor"<<endl;}
};
int main() {
   /* A aObj;
    A* aPtr = &aObj;
    aPtr->M1();  // Virtual call-> because it is override (A.M1)
    aPtr->M2();  // Non-virtual call

    B bObj;
    B* bPtr = &bObj;
    bPtr->M1();  // Virtual call (B.M1)
    bPtr->M2();  // Non-virtual call
    bPtr->M3();  // Virtual call (B.M3)
    bPtr->M4();  // Non-virtual call

    aPtr = &bObj;
    aPtr->M1();  // Virtual call (B.M1)
    aPtr->M2();  // Non-virtual call

    C cObj;
    cObj.M1();   // Non-virtual call
    cObj.M2();   // Non-virtual call
    cObj.M3();   // Virtual call
    cObj.M4();   // Non-virtual call

    aPtr = &cObj;
    aPtr->M1();  // Non-virtual call
    aPtr->M2();  // Non-virtual call

    bPtr = &cObj;
    bPtr->M1();  // Non-virtual call
    bPtr->M2();  // Non-virtual call
    bPtr->M3();  // Virtual call 
    bPtr->M4();  // Non-virtual call
*/
    C objc;

    A* zPtr=&objc;
}
