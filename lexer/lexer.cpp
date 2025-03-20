#include<iostream>
#include<string>
#include "token.hpp"
using namespace std;
    class Lexer {
        private:
            int position;
            char ch;
            string input;
            
            
            //helper functions
            string IdentHelper() {
                int pos = position;
                do {
                    readChar();
                }while(isalpha(ch) );
                return (input.substr(pos,position-pos));
                
                
            }
            char peekNext() {
                if(readPosition>input.size()){
                    return EOF;
                }
                else {
                    return input[readPosition];
                }
            }
            string digitHelper() {
                int pos = position;
                while(  isdigit(ch)  ) {
                    readChar();
                }
                return input.substr(pos,position-pos);
            }
            void helperSkipEmpty(){
                if(ch==' '){
                    readChar();
                }
                
            }
            void readChar() {
                if(readPosition>=input.size()){
                    ch = EOF;
                }
                else {

                position=readPosition;
                ch = input[readPosition];
                }
                readPosition++;
                // cout << "position: " << position << ", readPosition: " << readPosition << ", ch: '" << ch << "'" << endl;
                
            }
        public:
            int readPosition;
            void load(string hello) {
                input = hello;
                readPosition = 0;
            }
            Token nextToken() {

                readChar();
                helperSkipEmpty();
                Token output;
                switch(ch){
                    case '=':
                        if(peekNext()=='='){
                            char local = ch;
                            readChar();
                            output.type = "EQUALITY";
                            output.value = "==";
                        }
                        else {output.value = ch;
                        output.type = singleTokenTypes[ch];
                        }
                        break;
                    case '!':
                        if(peekNext()=='='){
                            char local = ch;
                            readChar();
                            output.type = "INEQUALITY";
                            output.value = "!=";
                        }else {
                            output.type = singleTokenTypes[ch];
                            output.value = ch;
                        }
                        break;
                    case '+':
                    case '*':
                    case '/':
                    case ')':
                    case '(':
                        output.value = ch;
                        output.type = singleTokenTypes[ch];
                        break;          
                    default:
                        if(isalpha(ch)){
                            output.value = IdentHelper();
                            if(keywords.find(output.value)!=keywords.end()){
                                output.type = keywords[output.value];
                            }     
                            else {
                            output.type = "IDENTIFIER";

                            }
                            position--;
                            readPosition--;
                        }
                        else if(isdigit(ch)) {
                            output.value = digitHelper();
                            output.type = INTEGER;
                            position--;
                            readPosition--;
                        }
                        else {
                            output.value = ch;
                            output.type = ILLEGAL;
                        }
                        
                    
                }
                cout << output.value << ',' << output.type << '\n';
                
                return output;

            }
            
            
    };

int main(){

    string hello="";
    Lexer bello;
    cout << "Welcome to krunkey language please input your commands" << '\n';
    bello.load("vgdhcbjnsdv!=!!++");
    Token output;
    
    do
    {
        getline (cin , hello);
        bello.load(hello);
        do{
        output = bello.nextToken();
        cout  << output.value << ',' << output.type << '\n';
    } while (bello.readPosition-1 < hello.size());
    }while (hello != "quit" || hello != "QUIT");
    return 0;
}