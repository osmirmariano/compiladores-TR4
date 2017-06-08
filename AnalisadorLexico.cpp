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
			//Cria um for para percorrer cada elemento da entrada que o usuário informar
			for(x = 0; x < entrada.length(); x++){
				//Essa condição do if é para verificar se o elemento na posição x é diferente de espaço, porque se for 
				//espaço eu vou desconsidera
				if(entrada[x] != ' '){
					//Crei uma variável do tipo string para receber o elemento da entrada na posição X
					simbolo = entrada[x];
					//Esse for é para percorrer todos os elementos do vetor expressão, que está armazenando as 
					//expressões carregadas pelo o arquivo
					for(y = 0; y < token.getTamanhoExpressao(); y++){
						//Nesse if verifico que para cada expressão, passando o simbolo se o simbolo pertence
						//A alguma expressão
						if(regexVerifica(token.getExpressoes(y), simbolo) == true){//Verificar com regex
							//Criei uma variável para armazenar cada elemento da entrada
							palavra +=  simbolo;
							//Esse tpken oficial ele recebe o token correspondente a sua expressão regular
							tokenOficial = token.getTokens(y);
							//Essa condição entra somente no primeiro caso e quando encontro um token
                            				if(tokenAtual == " "){;
								tokenAtual = token.getTokens(y);
								if(x == entrada.length()-1){
									tokensFinais.push_back(tokenAtual);
								}
							}
							else{
								//Verificando se o token atual é diferente do anterior
								//Pq se for encontrei um token. Pq pode ter caso de ter uma 
								//sequência de mesmo tokens ai eu tenho que mostrar somente um token.
								//Exemplo: abc os tokens dele é IDT IDT IDT, só que mostro somente IDT (um)
								if(tokenAtual != token.getTokens(y)){
									for(z = 0; z < palavra.length()-1; z++)
										novaPalavra += palavra[z];
									//Aqui tenho que passar todos os conjuntos dos simbolos para verificar 
									//se esse conjunto existe alguma expressão regular para ele.
									for(o = 0; o < token.getTamanhoExpressao(); o++){
										if(regexVerifica(token.getExpressoes(o), novaPalavra) == true){
											tokensFinais.push_back(token.getTokens(o));
											//Eu decremento o x, pq tenho que voltar uma casa para 
											//verificar o item anterior, tipo a+. no percurso
											//a percorro depois + ai identifico que é diferente, porém 
											//Ai encontro que a é IDT, mas ai preciso voltar para verificar
											//O + se não voltar uma casa ele já iria para o próximo e não o +
											x--;
											//Para encerrar o laço, evitar processamento desnecessário
											o = token.getTamanhoExpressao();
										}
 									}
									//Limpo tudo, depois que encontrei
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
					//Esse if é para verificação de ERRO, onde caso o contador seja igual ao total geral
					//entende que não existe nenhum token válido
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
					//Caso do final da expressão
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
