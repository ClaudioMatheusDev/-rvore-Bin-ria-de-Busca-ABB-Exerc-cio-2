#include "TABB.h"
#include <iostream>

// CLASSE ÁRVORE BINÁRIA - BINARY TREE ---------------------------------------------

//----------------------------------------------------------------------------------
void TABB::Init()
{
	Raiz = NULL;	
	
} // void TABB::Init()

//----------------------------------------------------------------------------------
bool TABB::IsEmpty()
{
	return Raiz == NULL;	
	
} // void TABB::IsEmpty()

//----------------------------------------------------------------------------------

TABB::TNo* TABB::GetRaiz()
{
	return Raiz;
	
} // TNo TABB::GetRaiz()


//--- CONSTRUTOR -------------------------------------------------------------------------------
TABB::TABB()
{
	Init();
	
} // TABB()

//--- DESTRUTOR --------------------------------------------------------------------------------

TABB::~TABB()
{
	if( !IsEmpty() )
	{		
		//ExcluirNo(Raiz->dado);
	}	
	
} // ~TABB()

//----------------------------------------------------------------------------------
void TABB::print_caminhamento_em_pre_ordem(TNo *no)
{
	if( no != NULL )
	{
		printf("%d ", no->dado);
		print_caminhamento_em_pre_ordem(no->esq);
		print_caminhamento_em_pre_ordem(no->dir);
	}	
	
} // print_caminhamento_em_pre_ordem

//----------------------------------------------------------------------------------
void TABB::print_caminhamento_em_in_ordem(TNo *no)
{
	if( no != NULL )
	{
		print_caminhamento_em_in_ordem(no->esq);
		printf("%d ", no->dado);
		print_caminhamento_em_in_ordem(no->dir);
	}	
	
} // print_caminhamento_em_in_ordem

//----------------------------------------------------------------------------------
void TABB::print_caminhamento_em_pos_ordem(TNo *no)
{
	if( no != NULL )
	{
		print_caminhamento_em_pos_ordem(no->esq);
		print_caminhamento_em_pos_ordem(no->dir);
		printf("%d ", no->dado);
	}	
	
} // print_caminhamento_em_pos_ordem



//----------------------------------------------------------------------------------
void TABB::InserirNo(TNo *&No, TInfo valor)
{
	if( No != NULL )
	{
		if( valor < No->dado )
		{
			InserirNo( No->esq, valor);
		}
		else
		{
			InserirNo( No->dir, valor);
		}
	}
	else
	{
		No = new TNo;
		No->dado = valor;
		No->esq = NULL;
		No->dir = NULL;
	}
		
} // InserirNo(TNo *No, TInfo valor)

//----------------------------------------------------------------------------------
TABB::TNo* TABB::LocalizarNo(TNo *No, TInfo valor)
{
	if( No != NULL )
	{
		if( valor == No->dado )
		{
			return No;
		}		
		else
		if( valor < No->dado )
		{
			return LocalizarNo( No->esq, valor);
		}
		else
		{
			return LocalizarNo( No->dir, valor);
		}
	}
	else
	{
		return NULL;
	}
		
} // TABB::TNo* TABB::LocalizarNo(TNo *No, TInfo valor)

//----------------------------------------------------------------------------------

int TABB::TotalNos(TNo *no){
	if(no == NULL) 
	return 0;
	
	return TotalNos(no->esq) + TotalNos(no->dir) + 1;
}// FUNÇÃO PARA RETORNAR A QUANTIDADE DE NÓS QUE TEM NA ARVORE.

//----------------------------------------------------------------------------------

int TABB::Altura(TNo *no)
{
	int i, j, retorno;
	
	if(no == NULL)
	{
		return -1;
	}
	
	i = Altura(no->esq);
	j = Altura(no->dir);
	
	
	if(i > j)
	{
		retorno = i+1;
	}else{
		retorno = j+1;
	}
	
	return retorno;
	
}//FUNÇÃO PARA RETORNAR QUAL É A ALTURA QUE ESTÁ 

//----------------------------------------------------------------------------------

TABB::TNo* TABB::Pai(TNo *no, TInfo Elemento)
{
	TNo* aux;
	
	if(IsEmpty()) return NULL;
	
	if(no == NULL) return NULL;
	
	if(Raiz -> dado == Elemento) return Raiz;
	
	if(Elemento > no -> dado)
	{
		if(no -> dir != NULL)
		{
			return no;
		}else{
			return Pai(no->dir, Elemento);
		}
		
	}
	else
	{
		if(no -> esq != NULL)
		{
			if(no -> esq -> dado == Elemento){
				return no;
			}else{
				return Pai(no->esq, Elemento);
			}
		}
	}
	
	return NULL;
}//FUNÇÃO PARA ENCONTRAR QUAL É O PAI DE UM DETERMINADO ELEMENTO INCLUIDO NA ARVORE

//----------------------------------------------------------------------------------

int TABB::Nivel(TInfo Elemento){
	TNo *n = LocalizarNo(GetRaiz(), Elemento);

 	int nivel;
 	
 	if(n != NULL){
 		nivel = 0;
 		while(n != GetRaiz()){
 			n = Pai(GetRaiz(), n->dado);
 			nivel++;
		 }
		 return nivel;
	 }else{
	 	return -1;
	 }
} //FUNÇÃO PARA ENCONTRAR O NÍVEL DE UM DETERMINDADO ELEMENTO 


//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

