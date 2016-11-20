#include <iostream>
#include "regex.h"

using namespace std;

class Token{
    private:
    	string nomeToken;
    	Pattern expressao;

	public:
		Token(){
			void setNomeToken(string nomeToken)
			string getNomeToken();
			void seExpressao();
			string getExpressao();
		};
		~Token();

		void setNomeToken(string nomeToken){
			this.nomeToken = nomeToken;
		};

		void seExpressao(){
			this.expressao = expressao;
		};

		string getNomeToken(){
            return nomeToken;
		};


		string getExpressao(){
			return expressao;
		}

		bool verificar(string entrada){
            match_results m = expressao.matcher(entrada);
		};
};
