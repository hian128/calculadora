#include <iostream>
using namespace std;

// Struct para as operações
struct Operacao {
    double num1;
    double num2;
    double resultado;
};

// Função para perguntar se deseja usar novamente
bool usar_novamente() {
    string resposta;
    cout << "Deseja usar a calculadora novamente? (s/n): ";
    cin >> resposta;

    if (resposta == "s" || resposta == "S")
        return true;
    else if (resposta == "n" || resposta == "N") {
        cout << "Obrigado por usar a calculadora!" << endl;
        return false;
    } else {
        cout << "Resposta invalida. Digite 's' para sim ou 'n' para nao." << endl;
        return usar_novamente();  // chama de novo até ser válido
    }
}

int main() {
    int opcao;
    bool continuar = true;

    while (continuar) {
        cout << "\n=============================" << endl;
        cout << "      CALCULADORA SIMPLES    " << endl;
        cout << "=============================" << endl;

        // Menu com validação simples
        while (true) {
            cout << "Escolha uma opcao:" << endl;
            cout << "1. Adicao" << endl;
            cout << "2. Subtracao" << endl;
            cout << "3. Multiplicacao" << endl;
            cout << "4. Divisao" << endl;
            cout << "5. Sair" << endl;
            cout << "Digite a opcao: ";

            cin >> opcao;

            if (cin.fail()) {
                cin.clear(); // limpa o erro
                cin.ignore(1000, '\n'); // descarta o que o usuário digitou
                cout << "Entrada invalida! Por favor, digite um numero de 1 a 5.\n" << endl;
                continue;
            }

            if (opcao >= 1 && opcao <= 5) {
                break; // opção válida
            } else {
                cout << "Opcao invalida! Digite um numero entre 1 e 5.\n" << endl;
            }
        }

        // Opção de sair
        if (opcao == 5) {
            cout << "Obrigado por usar a calculadora!" << endl;
            break;
        }

        // Operação matemática
        Operacao op;
        cout << "Digite o primeiro numero: ";
        cin >> op.num1;
        cout << "Digite o segundo numero: ";
        cin >> op.num2;

        switch (opcao) {
        case 1:
            op.resultado = op.num1 + op.num2;
            cout << "Resultado: " << op.num1 << " + " << op.num2 << " = " << op.resultado << endl;
            break;
        case 2:
            op.resultado = op.num1 - op.num2;
            cout << "Resultado: " << op.num1 << " - " << op.num2 << " = " << op.resultado << endl;
            break;
        case 3:
            op.resultado = op.num1 * op.num2;
            cout << "Resultado: " << op.num1 << " * " << op.num2 << " = " << op.resultado << endl;
            break;
        case 4:
            if (op.num2 == 0) {
                cout << "Erro: Divisao por zero nao e permitida." << endl;
            } else {
                op.resultado = op.num1 / op.num2;
                cout << "Resultado: " << op.num1 << " / " << op.num2 << " = " << op.resultado << endl;
            }
            break;
        }

        // Perguntar se deseja continuar
        continuar = usar_novamente();
    }

    return 0;
}
