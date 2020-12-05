#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#include "Ponto.h"
#include "Percurso.h"
#include "Segmento.h"
using namespace std;

void        fase1(const string);
void        fase2(const string);

int main(void)
{
    Percurso percurso("quadrado.txt");
    vector<int> idx;
    for (unsigned i = 0; i < percurso.pontos.size(); i += 1)
        idx.push_back(i);

    cout << percurso.pontos;
    cout << "\n\
[inicio] Total do percurso: " 
    << percurso.comprimento(idx) << "\n\n";

    // classificando os pontos por distancia da origem
    sort(percurso.pontos.begin(), percurso.pontos.end(),
        [](Ponto a, Ponto b) { return a.distanciaDaOrigem() < b.distanciaDaOrigem(); });
    cout << percurso.pontos;
    cout << "\n\
[classificado por distancia da origem] Total do percurso: "
    << percurso.comprimento(idx) << "\n\n";

    // salva o maior e o menor
    percurso.menor_percurso = 10e20f;
    float este_percurso = 0.f;
    
    // computa as distancias para todos os possiveis percursos
    int testes = 0;
    do
    {
        testes += 1;
        este_percurso = percurso.comprimento(idx);
        if (este_percurso < percurso.menor_percurso)
        {   
            percurso.menor_percurso = este_percurso;
            percurso.melhor_sequencia.clear();
            for_each( idx.begin(), idx.end(),
                [&](int ix) { percurso.melhor_sequencia.push_back(percurso.pontos[ix]); }
            );  // for_each()
        };  // if()

    } while (std::next_permutation(idx.begin(), idx.end()));

    cout << "\n\n==> Percurso com deslocamento MINIMO: " 
        << percurso.menor_percurso << "mm\n\n";
    cout << percurso.melhor_sequencia;

    return 0;
};  // main()


void        fase1(const string msg)
{
    vector<Ponto> ponto
    {
        { 0.0, 0.0 }, { 1.0, 1.0 },
        { 1.0, 2.0 }, { 2.0, 1.0 },
        { 2.0, 2.0 }
    };
    cout << "\n\n==> " << msg << "\n\n";
    cout << Segmento(ponto[0], ponto[1]) << endl;
    cout << Segmento(ponto[0], ponto[4]) << endl;
    return;
};  // fase1()


void        fase2(const string msg)
{
    Ponto A = { 0.,0. };
    Ponto B = { 1.,4. };
    cout << "\n\n==> " << msg << "\n\n";
    cout << "Usando variaveis: " << Segmento(A, B) << endl;

    cout << "Usando constantes:\n";
    cout << Segmento(Ponto{ 0.,0. }, Ponto{ 2.,3. }) << endl;
    cout << Segmento(Ponto{ 0.,0. }, Ponto{ 1.,2. }) << endl;
    return;
};  // fase2()

