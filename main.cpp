#include <iostream>
#include "regex.h"
#include "Regex"

using namespace std;

int main(int argc, char const *argv[]){
    int op;

    
    do{
        cout << "---------------------------------------------------" << endl;
        cout << "\t MENU DE OPÇÃO" << endl;
        cout << "---------------------------------------------------" << endl;
        cout << " 1 -- INSERIR EXPRESSÃO REGULAR" << endl;
        cout << " 2 -- INSERIR TOKENS " << endl;
        cout << " 3 -- ENTRADA CÓDIGO FONTE" << endl;
        cout << " 0 -- SAIR" << endl;
        cout << "---------------------------------------------------" << endl;
        cout << " OPÇÃO: ";
        cin >> op;
        cout << "---------------------------------------------------" << endl;

        switch(op){
            case 1:
                cout << "---------------------------------------------------" << endl;
                cout << "\t INSERÇÃO DA EXPRESSÃO REGULAR" << endl;
                cout << "---------------------------------------------------" << endl;
                cout << " EXPRESSÃO: ";
                break;

            case 2:
                cout << "---------------------------------------------------" << endl;
                cout << "\t INSERÇÃO DE TOKENS" << endl;
                cout << "---------------------------------------------------" << endl;
                break;

            case 3: 
                cout << "---------------------------------------------------" << endl;
                cout << "\t ENTRADA CÓDIGO FONTE" << endl;
                cout << "---------------------------------------------------" << endl;
                break;
                
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