#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define ROXO "\x1B[35m"
#define AZUL "\x1B[34m"
#define RESET "\x1B[0m"
struct Peca{
	int codigo;
	int linha, coluna;
	int ataques;
	struct Peca *prox, *ant; 
};

struct Posicao{
	int qtdBrancas;
	struct Peca *brancas;
    int qtdPretas;
    struct Peca *pretas;
    int jogVez;
    struct Peca *tab[8][8];
};
struct  Jogada
{
    int linhaDe, colunaDe, linhaPara, colunaPara;
    struct Jogada *prox, *ant;
};
struct Peca* InsereInicio(struct Peca* sentinela, int codigo, int linha, int coluna, int ataques){
	struct Peca* novo= (struct Peca* )malloc(sizeof(struct Peca));
	novo->linha=linha;
	novo->coluna=coluna;
	novo->codigo=codigo;
	novo->ataques=ataques;
		if(sentinela==NULL){
			novo->prox=novo;
			novo->ant=novo;
			return novo;		
			}
			novo->prox=sentinela;
			novo->ant=sentinela->ant;
			sentinela->ant->prox=novo;
			sentinela->ant=novo;
			sentinela=novo;
			return sentinela;
}
struct Jogada* InsereIniciojogada(struct Jogada* sentinela, int linhaDe, int colunaDe, int linhaPara, int colunaPara){
	struct Jogada* novo= (struct Jogada* )malloc(sizeof(struct Jogada));
	novo->linhaDe=linhaDe;
	novo->colunaDe=colunaDe;
	novo->linhaPara=linhaPara;
	novo->colunaPara=colunaPara;
		if(sentinela==NULL){
			novo->prox=novo;
			novo->ant=novo;
			return novo;		
			}
			novo->prox=sentinela;
			novo->ant=sentinela->ant;
			sentinela->ant->prox=novo;
			sentinela->ant=novo;
			sentinela=novo;
			return sentinela;
}
struct Posicao IniciaTabuleiro(){
	int i, j, jogVez=1;

	struct Posicao tabuleiro;
	tabuleiro.brancas=tabuleiro.pretas=NULL;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			tabuleiro.tab[i][j]=NULL;
		}
	}
	tabuleiro.qtdPretas=16;
	tabuleiro.qtdPretas=16;
	for(i=0;i<8;i++){
		tabuleiro.tab[1][i]=tabuleiro.brancas=InsereInicio(tabuleiro.brancas, 1, 1, i, 0);
		tabuleiro.tab[6][i]=tabuleiro.pretas=InsereInicio(tabuleiro.brancas, -1, 6, i, 0);
	}
	tabuleiro.tab[0][0]=tabuleiro.brancas=InsereInicio(tabuleiro.brancas, 4, 0, 0, 0);
	tabuleiro.tab[0][7]=tabuleiro.brancas=InsereInicio(tabuleiro.brancas, 4, 0, 7, 0);
	tabuleiro.tab[0][1]=tabuleiro.brancas=InsereInicio(tabuleiro.brancas, 2, 0, 1, 0);
	tabuleiro.tab[0][6]=tabuleiro.brancas=InsereInicio(tabuleiro.brancas, 2, 0, 6, 0);
	tabuleiro.tab[0][2]=tabuleiro.brancas=InsereInicio(tabuleiro.brancas, 3, 0, 2, 0);
	tabuleiro.tab[0][5]=tabuleiro.brancas=InsereInicio(tabuleiro.brancas, 3, 0, 5, 0);
	tabuleiro.tab[0][4]=tabuleiro.brancas=InsereInicio(tabuleiro.brancas, 6, 0, 4, 0);
	tabuleiro.tab[0][3]=tabuleiro.brancas=InsereInicio(tabuleiro.brancas, 5, 0, 3, 0);

	tabuleiro.tab[7][0]=tabuleiro.pretas=InsereInicio(tabuleiro.pretas, -4, 7, 0, 0);
	tabuleiro.tab[7][7]=tabuleiro.pretas=InsereInicio(tabuleiro.pretas, -4, 7, 7, 0);
	tabuleiro.tab[7][1]=tabuleiro.pretas=InsereInicio(tabuleiro.pretas, -2, 7, 1, 0);
	tabuleiro.tab[7][6]=tabuleiro.pretas=InsereInicio(tabuleiro.pretas, -2, 7, 6, 0);
	tabuleiro.tab[7][2]=tabuleiro.pretas=InsereInicio(tabuleiro.pretas, -3, 7, 2, 0);
	tabuleiro.tab[7][5]=tabuleiro.pretas=InsereInicio(tabuleiro.pretas, -3, 7, 5, 0);
	tabuleiro.tab[7][4]=tabuleiro.pretas=InsereInicio(tabuleiro.pretas, -6, 7, 4, 0);
	tabuleiro.tab[7][3]=tabuleiro.pretas=InsereInicio(tabuleiro.pretas, -5, 7, 3, 0);
	return tabuleiro;

}
void ResetCor(){
    printf("\033[0m");
}

void AjustaCor(int peca){
    switch(abs(peca)){
    case 1: printf("\033[0;36m");break;
    case 2: printf("\033[1;33m");break;
    case 3: printf("\033[0;35m");break;
    case 4: printf("\033[0;32m");break;
    case 5: printf("\033[0;34m");break;
    case 6: printf("\033[1;31m");break;
    }
}
struct Jogada* peao(struct Jogada* movimentos, struct Peca* p, struct Peca* tabuleiro[8][8]){
	if((p->linha+p->codigo)>=0 && (p->linha+p->codigo)<=7){
		if(tabuleiro[p->linha+p->codigo][p->coluna]==NULL){
			movimentos=InsereIniciojogada(movimentos, p->linha, p->coluna, (p->linha+p->codigo), p->coluna);
		}
		if(tabuleiro[p->linha+p->codigo][p->coluna-1]!=NULL && p->coluna>0 && (tabuleiro[p->linha+p->codigo][p->coluna-1]->codigo*p->codigo)<0){
			movimentos=InsereIniciojogada(movimentos, p->linha, p->coluna, (p->linha+p->codigo), (p->coluna-1));
		}
		if(tabuleiro[p->linha+p->codigo][p->coluna-1]!=NULL && p->coluna<7 && (tabuleiro[p->linha+p->codigo][p->coluna+1]->codigo*p->codigo)<0){
			movimentos=InsereIniciojogada(movimentos, p->linha, p->coluna, (p->linha+p->codigo), (p->coluna+1));
		}
	}
	return movimentos;
}


void Desenha(struct Posicao PosAtual)
{
	printf("\n\n\n\n\n");
	int i, j;
	for (i = 7; i > -1; i--)
	{
		printf("\t\t\t\t\t\t%d ", i);
		for (j = 0; j < 8; j++)
		{
			if (PosAtual.tab[i][j] == NULL)
			{
				printf("|  ");
			} else{
				if (PosAtual.tab[i][j]!=NULL && PosAtual.tab[i][j]->codigo < 0)
			{
				printf("|");
			}
			else if (PosAtual.tab[i][j]!=NULL && PosAtual.tab[i][j]->codigo > 0)
			{
				printf("| ");
			}
				printf("%d", PosAtual.tab[i][j]->codigo);
			}
			 
		}
		printf("|\n\t\t\t\t\t\t  -------------------------\n");
	}
	printf("\t\t\t\t\t\t    0  1  2  3  4  5  6  7\n");
}


struct Jogada *CalculaMovimentosPossiveis(struct Posicao PosAtual){
	struct Peca* aux=PosAtual.brancas;
	do{
		aux->ataques=0;
		aux=aux->prox;
	}while(aux!=PosAtual.brancas);
		aux=PosAtual.pretas;
	do{
		aux->ataques=0;
		aux=aux->prox;
	}while(aux!=PosAtual.pretas);
if(PosAtual.jogVez=1){
	aux=PosAtual.brancas;
} else{
	aux=PosAtual.pretas;
}
struct Jogada* movimentos=NULL;
do{
		switch (abs(aux->codigo)){
			case 1 :
			movimentos=peao(movimentos, aux, PosAtual.tab);
			break;
			/*case: 2 case: -2
			movimentos=cavalo(movimentos, aux, PosAtual.tab);
			break;
			case: 3 case: -3
			movimentos=bispo(movimentos, aux, PosAtual.tab);
			break;
			case: 4 case: -4
			movimentos=torre(movimentos, aux, PosAtual.tab);
			break;
			case: 5 case: -5
			movimentos=torre(movimentos, aux, PosAtual.tab);
			movimentos=bispo(movimentos, aux, PosAtual.tab);
			break;
			case:6 case: -6
			movimentos=rei(movimentos, aux, PosAtual.tab); 
			break;*/
		}
		aux=aux->prox;
	}while(aux->prox!=PosAtual.brancas);
}

int main(){
	struct Posicao tabuleiro=IniciaTabuleiro();
	Desenha(tabuleiro);

return 0;
}

		
	
    
