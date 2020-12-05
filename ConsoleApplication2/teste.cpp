#pragma once

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#include "Ponto.h"
#include "Percurso.h"
#include "Segmento.h"
using namespace std;

template <typename T, typename... Args>
float caminho(T t, Args... pontos)
{
    return  (t >> ... >> pontos);
};


int main(void)
{
    vector<Ponto> ponto
    {
        { 0.0, 0.0 }, { 1.0, 1.0 },
        { 1.0, 2.0 }, { 2.0, 1.0 },
        { 2.0, 2.0 }
    };

    cout << Segmento(ponto[0], ponto[1]) << endl;
    cout << Segmento(ponto[0], ponto[4]) << endl;

    Ponto A = { 0.,0. };
    Ponto B = { 1.,4. };
    cout << "Usando variaveis: " << Segmento(A, B) << endl;

    cout << "Usando constantes:\n";
    cout << Segmento(Ponto{ 0.,0. }, Ponto{ 2.,3. }) << endl;
    cout << Segmento(Ponto{ 0.,0. }, Ponto{ 1.,2. }) << endl;

    //Percurso percurso("entrada.txt");
    Percurso percurso("quadrado.txt");
    cout << percurso;

    //cout << "Total do percurso: " << percurso.comprimento() << "\n";
    // classificado
    sort(percurso.pontos.begin(), percurso.pontos.end(),
        [](Ponto a, Ponto b) { return a.distanciaDaOrigem() < b.distanciaDaOrigem(); });
    cout << percurso;

    // cria um vetor de indices
    vector<int> idx;
    for (unsigned i = 0; i < percurso.pontos.size(); i += 1)
        idx.push_back(i);
    int testes = 1;

    // computa as distancias para todos os possiveis percursos
    do
    {
        cout << "Permutacao: " << testes << endl;;
        for (auto&& i : idx)
            cout << i << " ";
        cout << endl;
        testes += 1;
    } while (std::next_permutation(idx.begin(), idx.end()));
    return 0;
}
