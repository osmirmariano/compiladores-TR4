#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Token.cpp"

using namespace std;

class Arquivo{
	public:
		Token token;
	public:
		Arquivo(){
            void abrindoArquivoExpressao();
            void abrindoArquivoTokens();
            void mostrar();
		};
		~Arquivo();

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

		void mostrar(){
			cout << "\t EXPRESSÕES" << endl;
			for(int x = 0; x <  token.getTamanhoExpressao(); x++){
            	cout << " " << token.getExpressoes(x) << endl;
            }
            cout << endl;
            cout << "\t TOKENS" << endl;
            for(int x = 0; x <  token.getTamanhoToken(); x++){
            	cout << " " << token.getTokens(x) << endl;
            }
		}

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
			}	
			verificandoEntrada(recebe);
		};

		void verificandoEntrada(vector<string> recebe){
			vector<string> tokensFianl;
            string dados;
            int cont = 0;
            for(int y = 0; y < recebe.size(); y++){
            	for(int x = 0; x < token.getTamanhoExpressao(); x++){
	                dados = token.getExpressoes(x);
	                regex pattern(dados);
	                if(regex_match(entrada, pattern)){
	                	cont++;
	                    tokensFianl.push_back(token.getTokens(x))
	                    break;
	                }
	   			}
            }

   			if(cont == 0)
                cout << "<ERRO>\n";
		}
};
#endif // ARQUIVO_H
