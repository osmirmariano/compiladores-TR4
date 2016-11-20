#include <iostream>
#include <vector>
#include "regex.h"

using namespace std;

class AnalisadorLexico{
    public:
        vector<Token> tokens;
	public:
		AnalisadorLexico();
		~AnalisadorLexico();

        void AnalisadorLexico(vector<Token> tokens){
            this.tokens = tokens;
        };

        void adicionarToken(vector<Token> token){
            tokens.push_back(token);
        };

        void adicionarToken(string nome, string reg){

        };
};
