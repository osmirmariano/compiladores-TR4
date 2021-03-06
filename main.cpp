#include <iostream>
#include <regex>
#include "AnalisadorLexico.cpp"

using namespace std;

int main(int argc, char const *argv[]){
    int op, op2;
    string entrada;
    AnalisadorLexico *lexico = new AnalisadorLexico();

    do{
        cout << "---------------------------------------------------" << endl;
        cout << "\t MENU DE OPÇÃO" << endl;
        cout << "---------------------------------------------------" << endl;
        cout << " 1 -- CARREGAR ARQUIVO" << endl;
        cout << " 2 -- ENTRADA CÓDIGO FONTE" << endl;
        cout << " 0 -- SAIR" << endl;
        cout << "---------------------------------------------------" << endl;
        cout << " OPÇÃO: ";
        cin >> op;
        cout << "---------------------------------------------------" << endl;

        switch(op){
            case 1:
                cout << "---------------------------------------------------" << endl;
                cout << "\t ARQUIVO CARREGADO" << endl;
                cout << "---------------------------------------------------" << endl;
                lexico->abrindoArquivoExpressao();
                lexico->abrindoArquivoTokens();
                lexico->mostrar();
                break;

            case 2:
                cout << "---------------------------------------------------" << endl;
                cout << "\t ENTRADA CÓDIGO FONTE" << endl;
                cout << "---------------------------------------------------" << endl;
                cout << " ENTRADA: ";
                cin.ignore();
                getline (cin, entrada);
                cout << "---------------------------------------------------" << endl;
                lexico->verificandoEntrada(entrada);
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
