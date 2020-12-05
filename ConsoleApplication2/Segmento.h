#pragma once
#include <iomanip>
#include <ostream>
#include "Ponto.h"

class Segmento
{
private:
	Ponto A;
	Ponto B;
public:
	float	comprimento;
	Segmento() : A({ 0.,0. }), B({ 0.0,0.0 }), comprimento(0.) {};
	Segmento(Ponto A, Ponto B) :
		A(A), B(B), comprimento(A>>B) {};

public:
	friend ostream& operator<<(ostream& out, const Segmento& S)
	{
		out << "[ A = (" << 
			S.A.x << "," << S.A.y << "), B = (" <<
			S.B.x << "," << S.B.y << ")" <<
			" ] Distancia = " << fixed << setprecision(2) << (S.A >> S.B) << "mm\n";
		return out;
	}
};

