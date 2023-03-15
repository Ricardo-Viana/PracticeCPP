// ProjetoC++.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <string>

using namespace std;

short verificaAno(short ano);
short verificaMes(short mes);
short verificaDia(short dia, short mes);
short pegarDoisUltimosDigitos(short ano);
short adicionarCodigoDoMes(short mes);
bool verificaAnoBissexto(short ano);
short codigoPorSeculo(short ano);

int main()
{
    string diasDaSemana[] = {"Sabado", "Domingo", "Segunda", "Terca", "Quarta", "Quinta", "Sexta"};
    short const POSICOES = 3; // Uma data possui tres posições dd mm e aaaa, vai ajudar a inicializar o array de data
    short data[] = {0,0,0};
    // data[2] = ano, data[1] = mes, data[0] = dia
    cout << "Digite o ano que deseja procurar o dia da semana (De 1700 a 2099)" << endl;
    cin >> data[2];
    //ano = verificaAno(ano);
    cout << "Digite o mes que deseja procurar o dia da semana (De 1 a 12)" << endl;
    cin >> data[1];
    //mes = verificaMes(mes);
    cout << "Digite o dia que deseja procurar o dia da semana (De 1 a 31)" << endl;
    cin >> data[0];
    //dia = verificaDia(dia, mes);
    short calculoDia = pegarDoisUltimosDigitos(data[2]);
    calculoDia = calculoDia / 4;
    calculoDia += data[0]; // data[0] dia do mes
    calculoDia += adicionarCodigoDoMes(data[1]);
    // Subtrair um se o ano for bissexto e o mes janeiro ou fevereiro
    if (verificaAnoBissexto(data[2]) == true && data[1] == 1 || data[1] == 2) {
        calculoDia -= 1;
    }
    calculoDia += codigoPorSeculo(data[2]);
    calculoDia += pegarDoisUltimosDigitos(data[2]);
    calculoDia = calculoDia % 7;
    cout << "O dia da semana e: " << diasDaSemana[calculoDia];

}

short codigoPorSeculo(short ano) {
    if (ano >= 2000) {
        return 6;
    }
    else if(ano >= 1900){
        return 0;
    }
    else if (ano >= 1800) {
        return 2;
    }
    else {
        return 4;
    }
}


bool verificaAnoBissexto(short ano) {
    if (ano % 400 == 0 || ano % 4 == 0 && ano % 100 != 0) return true;
    else return false;
}



short adicionarCodigoDoMes(short mes) {
    switch (mes) {
    case 1:
    case 10:
        return 1;
    case 2:
    case 3:
    case 11:
        return 4;
    case 4:
    case 7:
        return 0;
    case 5:
        return 2;
    case 6:
        return 5;
    case 8:
        return 3;  
    case 9:
    case 12:
        return 6;  
    }
    return 0;
}

short pegarDoisUltimosDigitos(short ano) {
    short doisUltDigitos = ano % 100;
    return doisUltDigitos;
}

short verificaAno(short ano) {
    if (ano >= 1700 && ano <= 2099) {
        return ano;
    }
    else {
        do {
            std::cout << "Digite um ano válido (De 1700 a 2099)";
            std::cin >> ano;
        } while (ano < 1700 || ano > 2099);
        return ano;
    }
}

short verificaMes(short mes) {
    if (mes >= 1 && mes <= 12) {
        return mes;
    }
    else {
        do {
            std::cout << "Digite um mês válido (De 1 a 12)";
            std::cin >> mes;
        } while (mes < 1 || mes > 12);
        return mes;
    }
}

short verificaDia(short dia, short mes) {
    return 1;
    //if (mes % 2 == 0 && mes != 8) 
}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
