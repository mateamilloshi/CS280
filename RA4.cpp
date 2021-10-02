#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <sstream>
using namespace std; 

int main( int argc, char* argv[] ) {
  string line,word;
  string fileName;
  ifstream myfile;
    //bool empty = true;
    
    if( argc < 2 )
    {
        cout << "No file is found\n";
       
        return 0;
    }
    
    fileName=argv[1];
    myfile.open(fileName);
    
    	if(myfile.fail())
	{
		//cout<<endl;
		cerr<<"File cannot be opened: "<<fileName<<endl;
		exit(1);
		
	}
    
  map<string, int> PrepCount = {{"in", 0},{"on", 0},{"to", 0},{"at", 0},{"after", 0},{"with", 0},{"over", 0},{"by", 0},{"between", 0},{"into", 0},};
    
    int count_words=0;
    while(myfile>>word) { // while there is more words to read
    count_words++;
    for(int i=0;i<word.length();i++) {
    word[i] = tolower(word[i]);
    }
      if(PrepCount.find(word)!=PrepCount.end()) {
      PrepCount[word]++; // if it is a preposition then increment its count
      }
    }
            if(count_words==0) { // if file is empty
    cout<<"File is empty.\n";
    exit(1);
    }
        if(count_words!=0){
    cout<<"List of Prepositions seen in the file and their number of occurrences:"<<endl;
      cout<<endl;
      int max_freq = 0;
    string max_freq_word="after"; // max freq of any preposition
    for(auto itr = PrepCount.begin();itr!=PrepCount.end();itr++)
    {
    if(itr->second > max_freq || itr->second == max_freq){
      //max_freq_word = itr->first;//maxword
      //max_freq=itr->second;//maxfreq
      if(itr->second!= max_freq)
      {
        max_freq_word = itr->first;//maxword
        max_freq=itr->second;
      }


    }
    cout << itr->first <<": " << itr->second << endl;
    }
        cout<<"The preposition with maximum occurrences is \""<<max_freq_word<<"\" found "<<max_freq<<" times.\n";
       
    }
        

  
}