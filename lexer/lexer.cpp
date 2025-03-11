#include<iostream>
#include<string>
#include "token.hpp"
using namespace std;
    class Lexer {
        public:
            int position;
            int readPosition;
            char ch;
            string input;
        public:
            int load(string hello) {
                input = hello;
                readPosition = 0;
                return 0;
            }
            void readChar() {
                position=readPosition;
                ch = input[position];
                readPosition++;
                // cout << "position: " << position << ", readPosition: " << readPosition << ", ch: '" << ch << "'" << endl;
                
            }
            Token nextToken() {
                readChar();
                Token output;
                switch(ch){
                    case '=':
                        output.value = ch;
                        output.type = singleTokenTypes[ch];
                        break;
                    case '+':
                        output.value = ch;
                        output.type = singleTokenTypes[ch];
                        break;
                    case '*':
                        output.value = ch;
                        output.type = singleTokenTypes[ch];
                        break;
                    case '/':
                        output.value = ch;
                        output.type = singleTokenTypes[ch];
                        break;
                    case ' ':
                        output.value = ch;
                        output.type = singleTokenTypes[ch];
                        break;  
                    case ')':
                        output.value = ch;
                        output.type = singleTokenTypes[ch];
                        break;
                    case '(':
                        output.value = ch;
                        output.type = singleTokenTypes[ch];
                        break;          
                    default:
                        if(isalpha(ch)){
                            output.value = IdentHelper();
                            if(keywords.find(output.value)!=keywords.end()){
                                output.type = "KEYWORD";
                            }     
                            else {
                            output.type = "IDENTIFIER";

                            }
                            position--;
                            readPosition--;
                        }
                        else if(isdigit(ch)) {
                            output.value = digitHelper();
                            output.type = "INTEGER";
                            position--;
                            readPosition--;
                        }
                        else {
                            output.value = ch;
                            output.type = "ILLEGAL";
                        }
                        
                    
                }
                // cout << output.value << ',' << output.type << '\n';
                
                return output;

            }
            string IdentHelper() {
                int pos = position;
                do {
                    readChar();
                }while(isalpha(ch));
                return input.substr(pos,position-pos);
                
                
            }
            string digitHelper() {
                int pos = position;
                do {
                    readChar();
                }while(isdigit(ch));
                return input.substr(pos,position-pos);
            }
            
    };

int main(){
    Lexer bello;
    string hello = "=++/*balls()9999999999999999balls let ";
    bello.load(hello);
    Token output = bello.nextToken();
    while(output.type!="ILLEGAL"){
        cout  << output.value << ',' << output.type << '\n';
        output = bello.nextToken();
    }



    return 0;
}