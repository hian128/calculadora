#include <iostream>
using namespace std;

// Struct genérica para operações
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
        cout << "Resposta invalida. Por favor, digite 's' para sim ou 'n' para nao." << endl;
        return usar_novamente();  // recursão
    }
}

int main() {
    int opcao;
    bool continuar = true;

    while (continuar) {
        cout << "================================" << endl;
        cout << "CALCULADORA" << endl;
        cout << "=================================" << endl;
        cout << "Selecione uma opcao:" << endl;
        cout << "1. Adicao" << endl;
        cout << "2. Subtracao" << endl;
        cout << "3. Multiplicacao" << endl;
        cout << "4. Divisao" << endl;
        cout << "5. Sair" << endl;

        cin >> opcao;

        while (opcao < 1 || opcao > 5) {
            cout << "Opcao invalida. Digite novamente: ";
            cin >> opcao;
        }

        if (opcao == 5) {
            cout << "Obrigado por usar a calculadora!" << endl;
            break;
        }

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

        continuar = usar_novamente();  // pergunta se quer continuar
    }

    return 0;
}
