// Ativ02.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    int numeroSecreto = rand() % 100 + 1;
    int tentativas = 0;
    int hipotese;

    cout << "\tBem vindo ao advinhe meu número\n\n";
    do {
        cout << "Insira uma tentativa: ";
        cin >> hipotese;
        ++tentativas;

        if (hipotese > numeroSecreto)
        {
            cout << "Muito alto!\n\n";
        }
        else if (hipotese < numeroSecreto)
        {
            cout << "Muito baixo!\n\n";
        }
        else
        {
            cout << "\nÉ isso! Você acertou em " << tentativas << " tentativas!\n";

        }
    } while (hipotese != numeroSecreto);
    return 0;
}
