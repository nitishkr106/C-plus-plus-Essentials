#include<iostream>
#include<string>
using namespace std;
#define ADD(operandOne, operandTwo) ((operandOne) + (operandTwo))   //Macros

template<typename T>  
T add(T operandOne,T operandTwo){  //Function Template
    return operandOne+operandTwo;
}

int main(){
    cout<<ADD(900,200)<<endl;

    int result=add<int>(100,200);
    cout<<result<<endl;

    string strResult=add<string>("Hi","Hello");
    cout<<strResult<<endl;
}