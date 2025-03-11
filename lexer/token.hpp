#include<string>
#include<map>
#include<set>
using namespace std;
    struct Token{
        string type;
        string value;
    };
    map<char,string> singleTokenTypes {{'=',"ASSIGN"},{'+',"ADDITION"}, {'/',"DIVIDE"},{'*',"MULTIPLY"},{' ',"SPACE"},{'(',"LBRAC"},{')',"RBRAC"}};
    set<string> keywords = {"let", "func","if" ,"else" ,"return","while","for","do","switch","case","break","continue"  };
    
