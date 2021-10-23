#include <iostream>
#include <string>
using namespace std;

string DecToBin(int num);

int main()
{
	int dec ;
	
	cout << "Enter a decimal number: " << endl;
	cin >> dec;
	
	string str = DecToBin(dec);
	cout<< endl ;
	cout << "result of converting the decimal number " << dec << " to Binary is: " << str << endl;
    
    return 0;
}

