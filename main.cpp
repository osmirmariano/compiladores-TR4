#include <iostream>
#include "regex.h"
//#include "AnalisadorLexico.cpp"
#include "Token.cpp"

using namespace std;

int main(int argc, char const *argv[]){
    int op, op2;
    string expressao, tokens;
    Token *token = new Token();

    do{
        cout << "---------------------------------------------------" << endl;
        cout << "\t MENU DE OPÇÃO" << endl;
        cout << "---------------------------------------------------" << endl;
        cout << " 1 -- INSERIR EXPRESSÃO REGULAR E TOKENS" << endl;
        cout << " 2 -- ENTRADA CÓDIGO FONTE" << endl;
        cout << " 3 -- MOSTRAR" << endl;
        cout << " 0 -- SAIR" << endl;
        cout << "---------------------------------------------------" << endl;
        cout << " OPÇÃO: ";
        cin >> op;
        cout << "---------------------------------------------------" << endl;

        switch(op){
            case 1:
                do{
                    cout << "---------------------------------------------------" << endl;
                    cout << "\t INSERÇÃO DA EXPRESSÃO REGULAR" << endl;
                    cout << "---------------------------------------------------" << endl;
                    cout << " EXPRESSÃO: ";
                    cin >> expressao;
                    cout << "---------------------------------------------------" << endl;
                    token->setExpressao(expressao);
                    //Chamar Inserir Expressão
                    cout << "---------------------------------------------------" << endl;
                    cout << "\t INSERÇÃO DE TOKENS" << endl;
                    cout << "---------------------------------------------------" << endl;
                    cout << " TOKENS: ";
                    cin >> tokens;
                    cout << "---------------------------------------------------" << endl;
                    token->setNomeToken(tokens);
                    //Chamar Inserir Tokens
                    cout << endl;
                    cout << " 1 -- INSERIR MAIS" << endl;
                    cout << " 0 -- ENCERRAR INSERÇÃO" << endl;
                    cout << "---------------------------------------------------" << endl;
                    cout << " OPÇÃO: ";
                    cin >> op2;
                    cout << "---------------------------------------------------" << endl;
                    if(op2 != 1){
                        cout << "OPÇÃO INVÁLIDA!" << endl;
                        op2 = 0;
                    }
                }while(op2 != 0);
                break;

            case 2:
                cout << "---------------------------------------------------" << endl;
                cout << "\t ENTRADA CÓDIGO FONTE" << endl;
                cout << "---------------------------------------------------" << endl;
                break;
            case 3:
                cout << "---------------------------------------------------" << endl;
                cout << "\t MOSTRAR" << endl;
                cout << "---------------------------------------------------" << endl;
                for(int x = 0; x <  token->getTamanhoExpressao(); x++){
                    cout << " " << token->getExpressoes(x);
                }
                cout << endl;
                for(int x = 0; x <  token->getTamanhoToken(); x++){
                    cout << " " << token->getTokens(x);
                }

            case 0:
                cout << "\tAPLICAÇÃO ENCERRADA COM SUCESSO!" << endl << endl;
                break;

            default:
                cout << "\tOPÇÃO INVÁLIDA, POR FAVOR ESCOLHA UMA VÁLIDA" << endl;
        }
        cout << endl << "  PARA VOLTAR AO MENU PRESSIONE ENTER" << endl;
        cin.ignore().get();//Comando para Pausa no terminal
        cout << "\e[H\e[2J";//Comando para limpar a tela
    }while(op != 0);
};
