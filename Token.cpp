#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include <vector>
#include <regex>

using namespace std;

class Token{
    private:
    	vector<string> nomeToken;
    	vector<string> expressao;
	
	public:
		Token(){
			void setNomeToken(string nomeTokens);
			void setExpressao(string expressoes);
			string getNomeToken();
			string getExpressao();
			int getTamanhoToken();
			int getTamanhoExpressao();
		};
		~Token();

		void setNomeToken(string nomeTokens){
			nomeToken.push_back(nomeTokens);
		};

		void setExpressao(string expressoes){
			expressao.push_back(expressoes);
		};

		vector<string> getNomeToken(){
            return nomeToken;
		};

		vector<string> getExpressao(){
			return expressao;
		};

		int getTamanhoToken(){
			return nomeToken.size();
		};

		int getTamanhoExpressao(){
			return expressao.size();
		};

		string getExpressoes(int indice) {
			return expressao[indice];
		};

		string getTokens(int indice) {
			return nomeToken[indice];
		};
};
#endif // TOKEN_H