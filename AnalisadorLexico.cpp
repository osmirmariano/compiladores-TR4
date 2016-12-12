#ifndef ANALISADORLEXICO_H
#define ANALISADORLEXICO_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Token.cpp"
using namespace std;

class AnalisadorLexico{
	public:
		Token token;
	public:
		AnalisadorLexico(){
            void abrindoArquivoExpressao();
            void abrindoArquivoTokens();
            void mostrar();
            void verificandoEntrada(vector<string> recebe);
            void tratandoString(string entrada);
            void imprimindoTokens(vector<string> tokensFinal);
            bool regexVerifica(string dados, string simbolo);
		};
		~AnalisadorLexico();

		/*-----------------FUNÇÃO PARA ABRIR ARQUIVO COM AS EXPRESSÕES----------------------*/
		void abrindoArquivoExpressao(){
            ifstream txtFile;
            string linha;
            //Abrindo o arquivo
            txtFile.open("regexExpressao.txt");

            while(!txtFile.eof()){
                //Ler o conteúdo de uma linha e atribuíndo para a expressao
                getline(txtFile, linha);
                token.setExpressao(linha);
            }
            //Fechando o arquivo
            txtFile.close();
		};

		/*------------------FUNÇÃO PARA ABRIR ARQUIVO COM OS TOKENS--------------------------*/
		void abrindoArquivoTokens(){
            ifstream txtFile;
            string linha;
            //Abrindo o arquivo
            txtFile.open("regexTokens.txt");

            while(!txtFile.eof()){
                //Ler o conteúdo de uma linha e atribuindo o mesmo para o token
                getline(txtFile, linha);
                token.setNomeToken(linha);
            }
            //Fechando o arquivo
            txtFile.close();
		};

		/*------------------FUNÇÃO MOSTRAR AS EXPRESSÕES E TOKENS--------------------------*/
		void mostrar(){
			cout << "---------------------------------------------------" << endl;
			cout << "\t EXPRESSÕES" << endl;
			cout << "---------------------------------------------------" << endl;
			for(int x = 0; x <  token.getTamanhoExpressao(); x++){
            	cout << " " << token.getExpressoes(x) << endl;
            }
            cout << "---------------------------------------------------" << endl;
            cout << "\t TOKENS" << endl;
            cout << "---------------------------------------------------" << endl;
            for(int x = 0; x <  token.getTamanhoToken(); x++){
            	cout << " " << token.getTokens(x) << endl;
            }
            cout << "---------------------------------------------------" << endl;
		};


		/*------------------FUNÇÃO PARA REALIZAR A VERIFICAÇÃO REGEX-------------------------*/
		bool regexVerifica(string dados, string simbolo){
			regex pattern(dados);
			if(regex_match(simbolo, pattern)){
				return true;
			}
			else
				return false;
		};

		/*------------------FUNÇÃO VERIFICAR SE A ENTRADA É VÁLIDA-------------------------*/
		void verificandoEntrada(string entrada){
			int x, y, z, o;
			int contador = 0, ccont = 0, retira = 0;
			vector<string> tokensFinais;
			vector<string> tokenErro;
			string simbolo, palavra, tokenAtual = " ", novaPalavra = "", tokenOficial, algo, recebe;

			for(x = 0; x < entrada.length(); x++){
				if(entrada[x] != ' '){
					simbolo = entrada[x];
					for(y = 0; y < token.getTamanhoExpressao(); y++){
						if(regexVerifica(token.getExpressoes(y), simbolo) == true){//Verificar com regex
							palavra +=  simbolo;
							tokenOficial = token.getTokens(y);
                            if(tokenAtual == " "){;
								tokenAtual = token.getTokens(y);
								if(x == entrada.length()-1){
									tokensFinais.push_back(tokenAtual);
								}
							}
							else{
								//Verificando se o token atual é diferente do anterior
								if(tokenAtual != token.getTokens(y)){
									for(z = 0; z < palavra.length()-1; z++)
										novaPalavra += palavra[z];

									for(o = 0; o < token.getTamanhoExpressao(); o++){
										if(regexVerifica(token.getExpressoes(o), novaPalavra) == true){
											tokensFinais.push_back(token.getTokens(o));
											x--;
											o = token.getTamanhoExpressao();
										}
 									}

									novaPalavra.clear();
									palavra.clear();
									tokenAtual = " ";
								}
								else
									tokenAtual = token.getTokens(y);
								if(x == entrada.length()-1/* && tokenOficial != ""*/){
									for(int a = 0; a < token.getTamanhoExpressao(); a++){
										if(regexVerifica(token.getExpressoes(a), palavra) == true){
											tokensFinais.push_back(token.getTokens(a));
											break;
										}
									}
								}
							}
							y = token.getTamanhoExpressao();
						}
						else
							contador++;
					}
					if(contador == token.getTamanhoExpressao()){
						recebe = entrada[x];
						algo += entrada[x];
						if(algo.length() == 2){
							for(int i = 0; i < token.getTamanhoExpressao(); i++){
								if(regexVerifica(token.getExpressoes(i), algo)) {
									tokensFinais.push_back(token.getTokens(i));
									algo.clear();
								}
								else
									ccont++;
							}
							if(ccont == token.getTamanhoExpressao())
								tokensFinais.push_back("ERRO");
						}
						else{
							if(palavra == " "){
								for(int b = 0; b < token.getTamanhoExpressao(); b++){
									if(regexVerifica(token.getExpressoes(b), palavra)){
										tokensFinais.push_back(token.getTokens(b));
									}
								}
							}else{
								tokensFinais.push_back(tokenAtual);
							}
							novaPalavra.clear();
							palavra.clear();
							tokenAtual = " ";
							tokenOficial.clear();
							tokensFinais.push_back("ERRO");
							tokenErro.push_back(recebe);		
						}
					}
				}
				else{
					//É aqui que está acontecendo o problema de aparecer IDT
					if(palavra.length() != 0){
						for(int c = 0; c < token.getTamanhoExpressao(); c++){
							if(regexVerifica(token.getExpressoes(c), palavra)){
								tokensFinais.push_back(token.getTokens(c));
							}
						}
					}
					palavra.clear();
					tokenAtual = " ";
					tokenOficial = " ";
				}
				contador = 0;
			}
			imprimindoTokens(tokensFinais);
			if(tokenErro.size() > 0)
				imprimindoErros(tokenErro);
		};


		/*---------------------FUNÇÃO IMPRIMIR O RESULTADO-----------------------------*/
		void imprimindoTokens(vector<string> tokensFinal){
			vector<string> novoTokenFinal;
			novoTokenFinal = teste(tokensFinal);
			cout << "---------------------------------------------------" << endl;
			cout << "\t           SAÍDA:" << endl;
			cout << "---------------------------------------------------" << endl;
			for(int x = 0; x < novoTokenFinal.size(); x++){
				cout << " <" << novoTokenFinal[x] << ">";
			}
			cout << endl;
		};

		/*---------------------FUNÇÃO IMPRIMIR O RESULTADO-----------------------------*/
		vector<string> teste(vector<string> tokensFinal){
			vector<string> novoTokenFinal;
			string recebeDados;
			for(int x = 0; x < tokensFinal.size(); x++){
				if(tokensFinal[x] != " "){
					recebeDados = tokensFinal[x];
					novoTokenFinal.push_back(recebeDados);
				}
			}
			return novoTokenFinal;
		};

		/*-----------------------FUNÇÃO IMPRIMIR OS ERROS------------------------------*/
		void imprimindoErros(vector<string> tokenErro){
			cout << "---------------------------------------------------" << endl;
			cout << "\t           ERRO LÉXICO:" << endl;
			cout << "---------------------------------------------------" << endl;
			for(int x = 0; x < tokenErro.size(); x++){
				cout << " ERRO LÉXICO = " << tokenErro[x] << endl;
			}
		};

};
#endif // ANALISADORLEXICO_H
