
#include <iostream>
#include <vector>
#include "Polynomial.h"
using namespace std;

/*!< Main à titre d'exemple */

int main() {
	vector <double> salut;
	salut.push_back(1);
	salut.push_back(2);
	salut.push_back(3);
	Polynomial p1(salut);
	Polynomial p0;
	cout << p0;//juste
	cout << p1;//juste
	vector <double> hello;
	hello.push_back(1);
	hello.push_back(2);
	Polynomial p2(hello);
	cout << p2;

	Polynomial p;
	p = p0 + p1;//juste
	cout << p;
	p = p1 + p2;//juste
	cout << p;
	p = p0*p1;//juste
	cout << p;
	p = p1*p2;
	cout << p;

	return 0;
}
