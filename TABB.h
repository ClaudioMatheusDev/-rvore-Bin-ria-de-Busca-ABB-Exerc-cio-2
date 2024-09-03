#ifndef TABB_H
#define TABB_H

// CLASSE ÁRVORE BINÁRIA DE BUSCA - BINARY TREE ---------------------------------------------

class TABB
{
	//-----------------------------------------------
	public:
		
		typedef int TInfo;
		
		struct TNo {	
			TInfo dado;	
			TNo *esq, *dir;
		};

		TNo *Raiz;

		bool IsEmpty();
		
		TNo* GetRaiz();		
			
		void print_caminhamento_em_pre_ordem(TNo *no);
		void print_caminhamento_em_in_ordem(TNo *no);
		void print_caminhamento_em_pos_ordem(TNo *no);
									
		TABB();  // construtor
		~TABB(); // destrutor
				
		void InserirNo(TNo *&No, TInfo valor);
		TNo* LocalizarNo(TNo *No, TInfo valor);
		
		//Inserindo os novos metodos
		int TotalNos(TNo *no);
		int Altura(TNo *no);
		TNo* Pai(TNo *no, TInfo Elemento);
		int Nivel (TInfo Elemento);


		
	//-----------------------------------------------
	protected:
		
		void Init();

		

	//-----------------------------------------------
	private:
		
		
}; // TABB

#endif
