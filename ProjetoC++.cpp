// ProjetoC++.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <string>

using namespace std;

enum Meses {
    JANEIRO = 1, FEVEREIRO, MARCO, ABRIL, MAIO,
    JUNHO, JULHO, AGOSTO, SETEMBRO, OUTUBRO, NOVEMBRO, DEZEMBRO
};
short verificaAno(short ano);
short verificaMes(short mes);
short verificaDia(short dia, short mes, short ano);
short pegarDoisUltimosDigitos(short ano);
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
    data[2] = verificaAno(data[2]);
    
    cout << "Digite o mes que deseja procurar o dia da semana (De 1 a 12)" << endl;
    cin >> data[1];
    data[1] = verificaMes(data[1]);
   
    data[0] = verificaDia(data[0], data[1], data[2]);
    
    short calculoDia = pegarDoisUltimosDigitos(data[2]);
    calculoDia = calculoDia / 4;
    calculoDia += data[0]; // data[0] dia do mes
    
    // Adicionar código do mês
    switch (data[1]) {
        case JANEIRO:
        case OUTUBRO:
            calculoDia += 1;
            break;
        case FEVEREIRO:
        case MARCO:
        case NOVEMBRO:
            calculoDia += 4;
            break;
        case ABRIL:
        case JULHO:
            calculoDia += 0;
            break;
        case MAIO:
            calculoDia += 2;
            break;
        case JUNHO:
            calculoDia += 5;
            break;
        case AGOSTO:
            calculoDia += 3;
            break;
        case SETEMBRO:
        case DEZEMBRO:
            calculoDia += 6;
            break;
    }

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
            std::cout << "Digite um ano válido (De 1700 a 2099)" << endl;
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
            std::cout << "Digite um mês válido (De 1 a 12)" << endl;
            std::cin >> mes;
        } while (mes < 1 || mes > 12);
        return mes;
    }
}

short verificaDia(short dia, short mes, short ano) {
    switch (mes) {
        // meses com dia 31
        case JANEIRO:
        case MARCO:
        case MAIO:
        case JULHO:
        case AGOSTO:
        case OUTUBRO:
        case DEZEMBRO:
            do {
                std::cout << "Digite um dia que deseja procurar o dia da semana (De 1 a 31)" << endl;
                std::cin >> dia;
            } while (dia < 1 || dia > 31);
            return dia;
        // meses com dia 30
        case ABRIL:
        case JUNHO:
        case SETEMBRO:
        case NOVEMBRO:
            do {
                std::cout << "Digite um dia que deseja procurar o dia da semana (De 1 a 30)" << endl;
                std::cin >> dia;
            } while (dia < 1 || dia > 30);
            return dia;
        case FEVEREIRO:
            if (verificaAnoBissexto(ano)) {
                do {
                    std::cout << "Digite um dia que deseja procurar o dia da semana (De 1 a 29)" << endl;
                    std::cin >> dia;
                } while (dia < 1 || dia > 29);
                return dia;
            }
            else {
                do {
                    std::cout << "Digite um dia que deseja procurar o dia da semana (De 1 a 28)" << endl;
                    std::cin >> dia;
                } while (dia < 1 || dia > 28);
                return dia;
            }
    }

}

