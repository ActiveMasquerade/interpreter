#include<string>
#include<map>
#include<set>
using namespace std;
    const string 
        //single tokens 
        ASSIGN = "ASSIGN",
        ADDITION = "ADDITION",
        DIVIDE = "DIVIDE",
        MULTIPLY = "MULTIPLY",
        SPACE = "SPACE",
        LBRAC = "LBRAC",
        RBRAC = "RBRAC",
        NOT = "NOT",
        // multiple char tokens
        LET = "LET",
        FUNCTION = "func",
        IF = "IF",
        ELSE="ELSE",
        RETURN="RETURN",
        WHILE="WHILE",
        FOR="FOR",
        DO="DO",
        SWITCH="SWITCH",
        CASE="CASE",
        BREAK="BREAK",
        CONTINUE="CONTINUE",
        INEQUALITY = "INEQUALITY",
        EQUALITY = "EQUALITY",
        INTEGER = "INTEGER",
        ILLEGAL = "ILLEGAL"
        ;

    struct Token{
        string type;
        string value;
    };
    map<char,string> singleTokenTypes {{'=',ASSIGN},
                                    {'+',ADDITION},
                                    {'/',DIVIDE},
                                    {'*',MULTIPLY},
                                    {' ',SPACE},
                                    {'(',LBRAC},
                                    {')',RBRAC},
                                    {'!',NOT}};
    map<string,string> keywords = {{"let",LET},
                                    {"func",FUNCTION},
                                    {"if",IF},
                                    {"else",ELSE},
                                    {"return",RETURN},
                                    {"while",WHILE},
                                    {"for",FOR},
                                    {"do",DO},
                                    {"switch",SWITCH},
                                    {"case",CASE},
                                    {"break",BREAK},
                                    {"continue",CONTINUE},
                                    {"!=",INEQUALITY},
                                    {"==",EQUALITY}
                                    };
    
