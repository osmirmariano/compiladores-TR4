#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Token.cpp"

using namespace std;
//Classe Arquivo
class Arquivo{
	public:
		Token token;
	public:
		Arquivo(){
            void abrindoArquivoExpressao();
            void abrindoArquivoTokens();
            void mostrar();
            void verificandoEntrada(vector<string> recebe);
            void tratandoString(string entrada);
            void imprimindoTokens(vector<string> tokensFinal);
		};
		~Arquivo();

		/*-----------------FUNÇÃO PARA ABRIR ARQUIVO COM AS EXPRESSÕES----------------------*/
		void abrindoArquivoExpressao(){
           	int cont = 0;
            ifstream txtFile;
            string linha;
            //Abrindo o arquivo
            txtFile.open("regexExpressao.txt");

            while(!txtFile.eof()){
                //Ler o conteúdo de uma linha e armazenar no vector
                getline(txtFile, linha);
                token.setExpressao(linha);
            }
            //Fechando o arquivo
            txtFile.close();
		}

		/*------------------FUNÇÃO PARA ABRIR ARQUIVO COM OS TOKENS--------------------------*/
		void abrindoArquivoTokens(){
           	int cont = 0;
            ifstream txtFile;
            string linha;
            //Abrindo o arquivo
            txtFile.open("regexTokens.txt");

            while(!txtFile.eof()){
                //Ler o conteúdo de uma linha
                getline(txtFile, linha);
                token.setNomeToken(linha);
            }
            //Fechando o arquivo
            txtFile.close();
		}

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
		}

		/*Verificando a entrada. No caso vou pegar cada simbolo da string e verificar se entrada 
		é válida até encontrar um espaco*/
		// void verificandoEntrada(string entrada){
		// 	int cont = 0;
		// 	string palavra, tokenAtual, dados;

		// 	for(int x = 0; x < entrada.length(); x++){				
		// 		for(int y = 0; y < token.getTamanhoExpressao(); y++){
		// 			dados = token.getExpressoes(y);
		// 			regex pattern(dados);
	 //               	if(regex_match(entrada[x], pattern)){
		// 				palavra += entrada[x];
		// 				tokenAtual = token.getTokens(y);
		// 				cont = 1;
		// 			}
		// 			else{
		// 				cont = 0;
		// 			}
		// 			//tokensFinal.push_back(token.getTokens(x));
		// 		}
		// 	}
		// };

		/*------------------FUNÇÃO FAZER O TRATAMENTO DA ENTRADA--------------------------*/
		void tratandoString(string entrada){
			vector<string> stringDividida;
			string recebe;
			for(int x = 0; x < entrada.length(); x++){
				if(entrada[x] != ' ')
					recebe += entrada[x];
				if(entrada[x] == ' '){
					stringDividida.push_back(recebe);
					recebe.clear();
				}
				if(x == entrada.length()-1)
					stringDividida.push_back(recebe);
			}
			verificandoEntrada(stringDividida);
		};

		/*------------------FUNÇÃO VERIFICAR SE A ENTRADA É VÁLIDA--------------------------*/
		void verificandoEntrada1(vector<string> recebe){
			vector<string> tokensFinal;
            string dados;
            int cont = 0;
            
            for(int y = 0; y < recebe.size(); y++){
            	for(int x = 0; x < token.getTamanhoExpressao(); x++){
	                dados = token.getExpressoes(x);
	                regex pattern(dados);
	                if(regex_match(recebe[y], pattern)){
	                    tokensFinal.push_back(token.getTokens(x));
	                    break;
	                }
	                else{
	                	cont++;
	                }
	   			}
	   			if(cont == token.getTamanhoExpressao()){
	   				tokensFinal.push_back("ERRO");
	   			}
                cont = 0;
            }
            imprimindoTokens(tokensFinal);
		}

		
		/*---------------------FUNÇÃO IMPRIMIR O RESULTADO-----------------------------*/
		void imprimindoTokens(vector<string> tokensFinal){
			cout << "\t           SAÍDA:" << endl;
			cout << "---------------------------------------------------" << endl;
			for(int x = 0; x < tokensFinal.size(); x++){
				cout << " <" << tokensFinal[x] << ">";
			}
			cout << endl;
		}
};
#endif // ARQUIVO_H
