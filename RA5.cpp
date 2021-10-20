#include <iostream>
#include <cctype>
#include <map>
#include <string>
#include "lex.h"

using namespace std;
using std::map;



static map <Token ,string> tokenPrint = {
  { PROGRAM,  "PROGRAM"},
  { WRITE,    "WRITE"},
  { INT,      "INT"},
  { END,      "END"},
  { IF,       "IF"},
  { FLOAT,    "FLOAT"},
  { STRING,   "STRING"},
  { REPEAT,   "REPEAT"},
  { BEGIN,    "BEGIN"},
  { IDENT,    "IDENT"},
  { ICONST,   "ICONST"},
  { RCONST,   "RCONST"},
  { SCONST,   "SCONST"},
  { PLUS,     "PLUS"},
  { MINUS,    "MINUS"},
  { MULT,     "MULT"},
  { DIV,      "DIV"},
  { REM,      "REM"},
  { ASSOP,    "ASSOP"},
  { LPAREN,   "LPAREN"},
  { RPAREN,   "RPAREN"},
  { COMMA,    "COMMA"},
  { EQUAL,    "EQUAL"},
  { GTHAN,    "GTHAN"},
  { SEMICOL,  "SEMICOL"},
  { ERR,      "ERR"}, 
  { DONE,     "DONE"}
};



ostream& operator<<(ostream& out, const LexItem& tok) {
	Token tt = tok.GetToken();
   
	out << tokenPrint[ tt ];
    
	if( tt == IDENT || tt == SCONST || tt == ICONST || tt == RCONST || tt == ERR ) {
        
		out << " (" << tok.GetLexeme() << ")";
        //cout<<" Line:# ";
        //out<<tok.GetLinenum();
	}
    cout<<" Line #: ";
    out<<tok.GetLinenum();
    cout<<endl;
	return out;
    
}

static map<string, Token> kwmap= {
  { "PROGRAM",  PROGRAM},
  { "WRITE",    WRITE},
  { "INT",      INT},
  { "END",      END},
  { "IF",       IF},
  { "FLOAT",    FLOAT},
  { "STRING",   STRING},
  { "REPEAT",   REPEAT},
  { "BEGIN",    BEGIN},

};


LexItem id_or_kw(const string& lexeme, int linenum)
{
	Token tt = IDENT;
    
	auto kIt = kwmap.find(lexeme);
	if( kIt != kwmap.end() )
		tt = kIt->second;
     
	return LexItem(tt, lexeme, linenum);
}

