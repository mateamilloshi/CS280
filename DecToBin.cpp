#include <iostream>
#include <string>
using namespace std;

string DecToBin(int num){
    
     if (num ==1){
       return "1";
     }
       
    
   else
       return DecToBin(num / 2) + to_string(num % 2)  ;
    
    
    
}