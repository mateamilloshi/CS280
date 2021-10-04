#include <iostream>
#include <fstream>
#include <sstream>       
#include <cstdlib>  // exit prototype
#include <sstream>
#include <ctype.h>
#include <string>

using namespace std;

int main(int argc, char *argv []){
    ifstream file;
    int Lcount=0, Wcount=0, MaxWordLen = 0, countNC=0;
    string str = "", word, integer, filename; 
    string WordMaxLen, LineMaxLen;
    int WLength, LineLength, MaxLineLen = 0; 
            
    // if a filename is provided, open file
    cout << "Enter the name of a file to read from: " << endl;
    cin >> filename;
    
    file.open(filename.c_str());
    if( !file)
    {
        cerr << endl;
        cerr << "File cannot be opened" << " " << filename << endl;
        exit (1);
    }
    
    getline(file, str);
    
    while ( !file.eof()) {
        Lcount++; //total no. of lines
        if(str[0] == '#' || (str[0] == '/' && str[1] == '/') ){
            countNC++; //count commentted lines starting with "#" or "//" 
            
            getline(file, str);
            continue; //skipping commentted lines
        }  
    
        LineLength = str.length();
        if(LineLength > MaxLineLen) {
            MaxLineLen = LineLength;
            LineMaxLen = str;
        }	 
            
        istringstream mystring(str);
        mystring >> word;
                    
        while(mystring.good()){
            Wcount++;
            WLength = word.length();
            if(WLength > MaxWordLen){
                MaxWordLen = WLength;
                WordMaxLen = word;
            }
            
            mystring >> word;
        }

            getline(file, str);    	 
    } // end while
    
    //Printing out the results
    cout << endl;
    cout << "Total Number of Lines: " << Lcount << endl;
    cout << "Number of non-commented lines: " << (Lcount - countNC) << endl;
    cout << "Line of Maximum Length: " << "\"" << LineMaxLen << "\"" << endl;
    cout << "Number of Words: " << Wcount << endl;
    cout << "Word of Maximum Length: " << "\"" << WordMaxLen << "\"" << endl;
                    
    return 0;  // ofstream destructor closes file

} // end main
