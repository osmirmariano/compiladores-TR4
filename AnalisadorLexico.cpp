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



		bool regexVerifica(string dados, string simbolo){
			regex pattern(dados);
			if(regex_match(simbolo, pattern)){
				return true;
			}
			else
				return false;
		};

		void verificandoEntrada(string entrada){
			int x = 0, y, z, o;
			int contador = 0, cont = 0, tratamento, logico = 0;
			vector<string> tokensFinais;
			vector<string> tokenErro;
			string simbolo, palavra, teste, dados, tokenAtual = " ", novaPalavra="", tokenOficial, word, algo;

			for(x = 0; x < entrada.length(); x++){
				if(entrada[x] != ' '){
					simbolo = entrada[x];
					cout << "---------------------------------------------------" << endl;
					cout << "SIMBOLO: " << simbolo << endl;
					for(y = 0; y < token.getTamanhoExpressao(); y++){
						if(regexVerifica(token.getExpressoes(y), simbolo) == true){//Verificar com regex
							palavra +=  simbolo;
							cout << "PALAVRA: " << palavra << endl;
							cout << "---------------------------------------------------" << endl;
							cout << "TOKENATUAL: " << token.getTokens(y) << endl;
							tokenOficial = token.getTokens(y);
                            word += palavra;
                            if(tokenAtual == " "){;
								tokenAtual = token.getTokens(y);
								if(x == entrada.length()-1){
									cout << "VAI INSERIR NO VETOR: " << tokenAtual << endl; 
									tokensFinais.push_back(tokenAtual);
								}
							}

							else{

								if(tokenAtual != token.getTokens(y)){
									for(z = 0; z < palavra.length()-1; z++)
										novaPalavra += palavra[z];

									cout << "---------------------------------------------------" << endl;
									cout << "NOVAPALAVRA: " << novaPalavra << endl;
									cout << "---------------------------------------------------" << endl;
									for(o = 0; o < token.getTamanhoExpressao(); o++){
										if(regexVerifica(token.getExpressoes(o), novaPalavra) == true){
											cout << "ENCONTRADO VAI PARA TOKENFINAL: " << token.getTokens(o) << endl;
											tokensFinais.push_back(token.getTokens(o));
											x--;
											o = token.getTamanhoExpressao();
										}
 									}

									novaPalavra.clear();
									palavra.clear();
									tokenAtual = " ";
									cont = 1;
								}
								else
									tokenAtual = token.getTokens(y);
								if(x == entrada.length()-1/* && tokenOficial != ""*/){
									for(int a = 0; a < token.getTamanhoExpressao(); a++){
										if(regexVerifica(token.getExpressoes(a), palavra) == true){
											cout << "2 VAI INSERIR NO VETOR: " << token.getTokens(a) << endl; 
											tokensFinais.push_back(token.getTokens(a));
											break;
										}
									}
								}
							}

							cout << "---------------------------------------------------" << endl;
							cout << "TOKENANTERIOR: " << tokenAtual << endl;
							y = token.getTamanhoExpressao();
						}
						else
							contador++;
					}
					cout << "TOKENATUAL: " << tokenOficial << endl;
					cout << "CONTADOR: " << contador << endl;
					string testes;
					/*if(contador == token.getTamanhoExpressao()){
						cout << "Entrou" << endl;
						string recebe;
						recebe = entrada[x];
						testes += simbolo[x];
						//É aqui que está acontecendo o problema de aparecer IDTz
						if(palavra != " "){
							for(int b = 0; b < token.getTamanhoExpressao(); b++){
								if(regexVerifica(token.getExpressoes(b), palavra)){
									cout << "3 VAI INSERIR NO VETOR: " << token.getTokens(b) << endl; 
									tokensFinais.push_back(token.getTokens(b));
								}
							}
						}
						else
							tokensFinais.push_back(tokenAtual);
						novaPalavra.clear();
						palavra.clear();
						tokenAtual = " ";
						tokenOficial.clear();
						tokensFinais.push_back("ERRO");
						tokenErro.push_back(recebe);
					}*/
					if(contador == token.getTamanhoExpressao()){
						cout << "Entrou" << endl;
						string recebe;
						recebe = entrada[x];
						algo += entrada[x];
						int ccont = 0, retira=0, z=0;
						if(algo.length() == 2){
							cout << "verificar " << endl;
							for(int i = 0; i < token.getTamanhoExpressao(); i++){
								if(regexVerifica(token.getExpressoes(i), algo)) {
									cout << "EXPRE: " << token.getExpressoes(i) << endl;
									cout << "to: " << token.getTokens(i) << endl;
									
									// retira = tokensFinais.size();
									// cout << "retira 1: " << retira << endl;
									// //del(tokensFinais[retira]);
									// //tokensFinais[retira] = "";
									// retira = tokensFinais.size();
									// cout << "retira 2: " << retira << endl;

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
										cout << "3 VAI INSERIR NO VETOR: " << token.getTokens(b) << endl; 
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
					cout << "PALA: " << palavra.length() << endl;
					if(palavra.length() != 0){
						for(int c = 0; c < token.getTamanhoExpressao(); c++){
							if(regexVerifica(token.getExpressoes(c), palavra)){
								cout << "4 VAI INSERIR NO VETOR: " << token.getTokens(c) << endl; 
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
