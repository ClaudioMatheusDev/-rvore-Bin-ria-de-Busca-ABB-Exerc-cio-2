#include <iostream>
#include "TABB.h"

using namespace std;

//---------------------------------------------------------------------------------
int main(int argc, char** argv) {
	
	TABB arvore;
	TABB::TNo* no;
	TABB::TInfo n;
	
	arvore.InserirNo( arvore.Raiz, 8 );
	arvore.InserirNo( arvore.Raiz, 3 );
	arvore.InserirNo( arvore.Raiz, 1 );
	arvore.InserirNo( arvore.Raiz, 5 );
	arvore.InserirNo( arvore.Raiz, 11);
	arvore.InserirNo( arvore.Raiz, 9 );
	arvore.InserirNo( arvore.Raiz, 14);
	arvore.InserirNo( arvore.Raiz, 10);
	
	arvore.print_caminhamento_em_pre_ordem( arvore.GetRaiz() );
	
	cout << "\n\n";	
	
	int total = arvore.TotalNos(arvore.GetRaiz()); //Imprimindo o total de nos da arvore
	cout << "Total de nos na Arvore: " << total << " ";
	
	cout << "\n\n";	
	
	int altura = arvore.Altura(arvore.GetRaiz());//Imprimindo a altura de nos da arvore
	cout << "Altura da arvore: " << altura << " "; 

	cout << "\n\n";	
	
	TABB::TNo* pai = arvore.Pai(arvore.GetRaiz(), 9); //Imprimindo o qual é o pai do número inserido nos nó
	if (pai != NULL) 
	{
    cout << "Pai de 9: " << pai->dado << " ";
	} //IF PAI
	else 
	{
    cout << "9 não estah na arvore ou eh a raiz." << " "; 
	}//ELSE PAI
	
 	cout << "\n\n";	
 	
 	int nivel = arvore.Nivel(14);
	if (nivel != -1) 
	{
    cout << "Nivel de 14: " << nivel << " ";
	} // IF NIVEL
	else 
	{
    cout << "14 não está na arvore." << " ";
	}//ELSE NIVEL
	
 	
 	
	cout << "\n\n";	

	return 0;

} // main()
