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
		};
		~AnalisadorLexico();

		/*-----------------FUNÇÃO PARA ABRIR ARQUIVO COM AS EXPRESSÕES----------------------*/
		void abrindoArquivoExpressao(){
           	int cont = 0;
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
           	int cont = 0;
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

		void verificandoEntrada(string entrada){
			int contador = 0, cont = 0;
			vector<string> tokensFinais;
			string simbolo, palavra, teste, dados, tokenAtual = " ", novaPalavra;
			for(int x = 0; x < entrada.length(); x++){
				if(entrada[x] != ' '){
					simbolo = entrada[x];
					cout << "---------------------------------------------------" << endl;
					cout << "SIMBOLO: " << simbolo << endl;
					for(int y = 0; y < token.getTamanhoExpressao(); y++){
						dados = token.getExpressoes(y);
						regex pattern(dados);
						cout << "---------------------------------------------------" << endl;
                		cout << "TOKEN: " << token.getExpressoes(y) << endl;
                		
						if(regex_match(simbolo, pattern)){
							palavra +=  simbolo;
							cout << "---------------------------------------------------" << endl;
							cout << "PALAVRA: " << palavra << endl;
							cout << "---------------------------------------------------" << endl;
							cout << "TOKENOFICIAL: " << token.getTokens(y) << endl;
							cout << "Y: " << y  << endl;
							if(tokenAtual == " "){
								tokenAtual = token.getTokens(y);
								cout << "OI" << endl;
							}
							else{
								if(tokenAtual != token.getTokens(y)){
									for(int z = 0; z < palavra.length()-1; z++)
										novaPalavra += palavra[z];
									//teste = token.getExpressoes(y);
									cout << "---------------------------------------------------" << endl;
									cout << "NOVAPALVARA: " << novaPalavra << endl;
									cout << "---------------------------------------------------" << endl;
									for(int o = 0; o <  token.getTamanhoExpressao(); o++){
										regex intiger(token.getExpressoes(o));
										if(regex_match(novaPalavra, intiger)){
											cout << "TOKEN ENCONTRADO" << endl;
											tokensFinais.push_back(token.getTokens(o));
											novaPalavra.clear();
											cout << "X: " << x << endl;
											cout << "SIMBOLO: " << simbolo << endl;
											//x--;
											break;
										}
									}
									palavra.clear();
								}
								else
									tokenAtual = token.getTokens(y);
							}
							cont = 1;
							cout << "---------------------------------------------------" << endl;
							cout << "TOKENATUAL: " << tokenAtual << endl;
							break;
						}
						else
							contador++;
					}
					if(contador == token.getTamanhoExpressao())
						tokensFinais.push_back("ERRO");
					contador = 0;
				}
			}
			imprimindoTokens(tokensFinais);
		};


		// void verificandoEntrada(string entrada){
  //           int cont;
  //           vector<string> tokensFinais;
  //           string simbolo, dados, tokenAtual, tokenFinal, palavra;
		// 	for (int x = 0; x < entrada.length(); x++){
		// 		if(entrada[x] != ' '){
  //                   simbolo += entrada[x];
  //                   for (int y = 0; y < token.getTamanhoExpressao(); y++){
  //                       dados = token.getExpressoes(y);
  //                       regex pattern(dados);
  //                       if(regex_match(simbolo, pattern)){
  //                           if(y == 0){
  //                               tokenAtual = token.getTokens(y);
  //                           }
  //                           else{
  //                               if(simbolo == " "){
  //                                   tokensFinais.push_back(token.getTokens(y));
  //                               }
  //                               else{
  //                                   if(tokenAtual != token.getTokens(y)){
  //                                       tokensFinais.push_back(tokenAtual);
  //                                       y--;
  //                                   }
  //                                   else
  //                                       tokenAtual = token.getTokens(y);
  //                               }
  //                           }
  //                           cont = 1;
  //                           break;
  //                       }
  //                       else{
  //                           cont = 0;
  //                       }
  //                   }
  //                   if(cont == 0){
  //                       simbolo.clear();
  //                   }
  //                       //tokensFinais.push_back("ERRO");
		// 		}
		// 		else
  //                   armazena = 0;
		// 	}
		// 	imprimindoTokens(tokensFinais);
		// }

		// void verificandoEntrada(string entrada){
		// 	vector<string> tokenEncontrado;
		// 	int cont;
		// 	string simbolo, dados, palavra;
		// 	for(int x = 0; x < entrada.length(); x++){
  //               simbolo += entrada[x];
  //               cout << "simbolo: " << simbolo << endl;
  //               if(simbolo !=  " "){
  //               	for(int y = 0; y < token.getTamanhoExpressao(); y++){
	 //                    dados = token.getExpressoes(y);
	 //                    regex pattern(dados);
	 //                    if(regex_match(simbolo, pattern)){
	 //                    	palavra = simbolo;
	 //                    	tokenEncontrado.push_back(token.getTokens(y));
	 //                       	cont = 1;
	 //                       	break;
	 //                    }
	 //                    else{
	 //                        cont = 0;
	 //                    }
	 //                    if(cont == 1){
	 //                    	simbolo = palavra;
	 //                    }
	 //                    else
	 //                    	simbolo.clear();
	 //                }
	 //                for(int a = 0; a < tokenEncontrado.size(); a++){
	 //                	cout << "TOKEN: " << tokenEncontrado[a] << endl;
	 //                }
  //               }
		// 	}
		// };

		// void verificandoEntrada(string entrada){
		// 	int cont = 0, controle = 0;
		// 	string palavra, tokenAtual, tokenAnterior, dados, recebe, dado2;
		// 	vector<string> tokensFinal;
		// 	for(int y = 0; y < entrada.length(); y++){
		// 		recebe = entrada[y];
		// 		//cout << recebe << endl;
		// 		for(int x = 0; x < token.getTamanhoExpressao(); x++){
		// 			dados = token.getExpressoes(x);
		// 			//cout << dados << endl;
		// 			regex pattern(dados);
	 //               	if(regex_match(recebe, pattern)){
		// 				palavra += entrada[y];
		// 				if(x == 0)
		// 					tokenAnterior = token.getTokens(x);
		// 				else
		// 					tokenAnterior = token.getTokens(x-1);
		// 				tokenAtual = token.getTokens(x);
		// 				cont = 1;
		// 				// cout << palavra << endl;
		// 				// cout << tokenAnterior << endl;
		// 				// cout << tokenAtual << endl;
		// 				break;
		// 			}
		// 			else{
		// 				cout << "AQI" << endl;
		// 				controle = 1;
		// 			}
		// 			dados.clear();
		// 			recebe.clear();
		// 		}
		// 		if(controle == 1 && cont == 0)
		// 			tokensFinal.push_back("ERRO");

		// 		if(tokenAnterior != tokenAtual){
		// 			y--;
		// 			string verifica;
		// 			for(int x = 0; x < token.getTamanhoExpressao(); x++){
		// 				verifica = token.getTokens(x);
		// 				regex intiger(verifica);
		// 				if(regex_match(palavra, intiger)){
		// 					tokensFinal.push_back(token.getTokens(x));
		// 					//cout << "OI" << endl;
		// 				}
		// 			}
		// 			palavra.clear();
		// 			tokenAtual.clear();
		// 			tokenAnterior.clear();
		// 			cont = 0;
		// 			controle = 0;
		// 		}
		// 		recebe.clear();
		// 	}
		// 	imprimindoTokens(tokensFinal);
		// };

		// /*------------------FUNÇÃO FAZER O TRATAMENTO DA ENTRADA--------------------------*/
		// void tratandoString(string entrada){
		// 	vector<string> stringDividida;
		// 	string recebe;
		// 	for(int x = 0; x < entrada.length(); x++){
		// 		if(entrada[x] != ' ')
		// 			recebe += entrada[x];
		// 		if(entrada[x] == ' '){
		// 			stringDividida.push_back(recebe);
		// 			recebe.clear();
		// 		}
		// 		if(x == entrada.length()-1)
		// 			stringDividida.push_back(recebe);
		// 	}
		// 	verificandoEntrada(stringDividida);
		// };

		// /*------------------FUNÇÃO VERIFICAR SE A ENTRADA É VÁLIDA--------------------------*/
		// void verificandoEntrada(vector<string> recebe){
		// 	vector<string> tokensFinal;
  //           string dados;
  //           int cont = 0;

  //           for(int y = 0; y < recebe.size(); y++){
  //           	for(int x = 0; x < token.getTamanhoExpressao(); x++){
	 //                dados = token.getExpressoes(x);
	 //                regex pattern(dados);
	 //                if(regex_match(recebe[y], pattern)){
	 //                    tokensFinal.push_back(token.getTokens(x));
	 //                    break;
	 //                }
	 //                else{
	 //                	cont++;
	 //                }
	 //   			}
	 //   			if(cont == token.getTamanhoExpressao()){
	 //   				tokensFinal.push_back("ERRO");
	 //   			}
  //               cont = 0;
  //           }
  //           imprimindoTokens(tokensFinal);
		// }


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
#endif // ANALISADORLEXICO_H
