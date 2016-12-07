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

		void verificandoEntrada1(string entrada){
			int x, y, contador = 0;
			string simbolo;
			vector<string> listaTokens;
			vector<string> tokensFinais;
			cout << "ENTRADA TAMANHO: " << entrada[entrada.length()-1] << endl;
			for(x = 0; x < entrada.length(); x++){
				if(entrada[x] != ' '){
					simbolo += entrada[x];
					for(y = 0; y < token.getTamanhoExpressao(); y++){
						regex pattern(token.getExpressoes(y));
						if(regex_match(simbolo, pattern)){
							listaTokens.push_back(token.getTokens(y));
							y = token.getTamanhoExpressao();
						}
						else
							contador++;
						if(listaTokens.size() > 1){
							if(listaTokens[listaTokens.size()-1] != listaTokens[listaTokens.size()]){
								tokensFinais.push_back(token.getTokens(y));
								simbolo.clear();
								//x--;
							}
						}
					}
					if(contador == token.getTamanhoExpressao())
						tokensFinais.push_back("ERRO");
				}
			}
			imprimindoTokens(tokensFinais);
		};

		void verificandoEntrada(string entrada){
			int x = 0, y, z, o, t=0;
			int contador = 0, cont = 0, tratamento, logico = 0;
			vector<string> tokensFinais;
			vector<string> tokenErro;
			string simbolo, palavra, teste, dados, tokenAtual = " ", novaPalavra="", tokenOficial;
			cout << "TAMANHO: "  << entrada.length() << endl;
			t = entrada.length();
			for(x = 0; x < entrada.length(); x++){
			//while(x != entrada.length()){
				//if(entrada[x] != ' '){
					simbolo = entrada[x];
					cout << "---------------------------------------------------" << endl;
					cout << "SIMBOLO: " << simbolo << endl;
					for(y = 0; y < token.getTamanhoExpressao(); y++){
						cout << "FOR1: " << x << endl;
						dados = token.getExpressoes(y);
						regex pattern(dados);
						cout << "---------------------------------------------------" << endl;
                		cout << "TOKEN: " << token.getExpressoes(y) << endl;
                		
						if(regex_match(simbolo, pattern)){
							cout<<" VÁLIDO"<<endl;
							palavra +=  simbolo;
							cout << "---------------------------------------------------" << endl;
							cout << "PALAVRA: " << palavra << endl;
							cout << "---------------------------------------------------" << endl;
							cout << "TOKENOFICIAL: " << token.getTokens(y) << endl;
							tokenOficial = token.getTokens(y);
                            cout << "ENTRADA TAMANHO: " << entrada[entrada.length()-1] << endl;
                            
                            if(tokenAtual == " "){;
								tokenAtual = token.getTokens(y);
								if(x == entrada.length()-1)
									tokensFinais.push_back(tokenAtual);
							}

							else{
								if(tokenAtual != token.getTokens(y)){
									for(z = 0; z < palavra.length()-1; z++)
										novaPalavra += palavra[z];
									cout << "---------------------------------------------------" << endl;
									cout << "NOVAPALAVRA: " << novaPalavra << endl;
									cout << "---------------------------------------------------" << endl;
									for(o = 0; o < token.getTamanhoExpressao(); o++){
										cout << "FOR2: " << x << endl;
										regex intiger(token.getExpressoes(o));
										if(regex_match(novaPalavra, intiger)){
											cout << "TOKEN ENCONTRADO" << endl;
											cout << "VAI PARA VETOR: " << token.getTokens(o) << endl;
											tokensFinais.push_back(token.getTokens(o));
											x--;
											o = token.getTamanhoExpressao();
										}
 									}
									novaPalavra.clear();
									palavra.clear();
									cont = 1;
								}
								else
									tokenAtual = token.getTokens(y);
								if(x == entrada.length()-1/* && tokenOficial != ""*/){
									cout << "PALAVRA 2: " << palavra << endl;
									for(int a = 0; a < token.getTamanhoExpressao(); a++){
										regex ultimo(token.getExpressoes(a));
										if(regex_match(palavra, ultimo)){
											tokensFinais.push_back(token.getTokens(a));
											break;
										}

									}
									//tokensFinais.push_back(tokenOficial);
								}

							}
							
							cout << "---------------------------------------------------" << endl;
							cout << "TOKENATUAL: " << tokenAtual << endl;
							y = token.getTamanhoExpressao();
						}
						else
							contador++;
					//}
					cout << "TOKENOFICIAL: " << tokenOficial << endl;
					cout << "CONTADOR: " << contador << endl;
					if(contador == token.getTamanhoExpressao()){
						cout << "Entrou" << endl;
						string recebe;
						recebe = entrada[x];

						for(int b = 0; b < token.getTamanhoExpressao(); b++){
							regex value(token.getExpressoes(b));
							if(regex_match(palavra, value)){
								tokensFinais.push_back(token.getTokens(b));
								break;
							}
							
						}
						novaPalavra.clear();
						palavra.clear();
						tokensFinais.push_back("ERRO");
						tokenErro.push_back(recebe);
					}
					
					//cont = 0;
				}
				contador = 0;
				//x++;
				int a = x;
				cout << "1X: " << x << endl;
				cout << "2X: " << a-1 << endl;
				cout << "CONT: " << cont << endl;
				// if(cont == 1){
				// 	x = a-1;
				// }
				/*if(x = entrada.length())
					tokensFinais.push_back(tokenOficial);*/
			}
			imprimindoTokens(tokensFinais);
			if(tokenErro.size() > 0)
				imprimindoErros(tokenErro);
		};

		/*---------------------FUNÇÃO IMPRIMIR O RESULTADO-----------------------------*/
		void imprimindoTokens(vector<string> tokensFinal){
			cout << "---------------------------------------------------" << endl;
			cout << "\t           SAÍDA:" << endl;
			cout << "---------------------------------------------------" << endl;
			for(int x = 0; x < tokensFinal.size(); x++){
				cout << " <" << tokensFinal[x] << ">";
			}
			cout << endl;
		};

		void imprimindoErros(vector<string> tokenErro){
			cout << "---------------------------------------------------" << endl;
			cout << "\t           ERRO LÉXICO:" << endl;
			cout << "---------------------------------------------------" << endl;
			for(int x = 0; x < tokenErro.size(); x++){
				cout << "     " << tokenErro[x] << " NÃO FAZ PARTE" << endl;
			}
		};
		
};
#endif // ANALISADORLEXICO_H
