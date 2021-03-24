#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>
#include <stdbool.h>
#define ROXO "\x1B[35m"
#define AZUL "\x1B[34m"
#define RESET "\x1B[0m"
struct Peca
{
    int codigo;
    int linha, coluna;
    int ataques;
    struct Peca *prox, *ant;
};

struct Posicao
{
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

struct Peca* LiberaListaPeca(struct Peca* lista){
    struct Peca* aux = lista;
    lista->ant->prox = NULL;
    while(aux != NULL){
        lista= lista->prox;
        free(aux);
        aux = lista;
    }
    return NULL;
};

struct Jogada* LiberaListaJogada(struct Jogada* lista)
{
    struct Jogada* aux = lista;
    lista->ant->prox = NULL;
    while(aux != NULL){
        lista= lista->prox;
        free(aux);
        aux = lista;
    }
    return NULL;
};

struct Peca* CriaListaPeca()
{
    struct Peca* sentinela = (struct Peca*) malloc(sizeof(struct Peca));
    sentinela->prox = sentinela;
    sentinela->ant = sentinela;
    sentinela->codigo = 0;
    return sentinela;
};

struct Jogada* CriaListaJogada()
{
    struct Jogada* sentinela = (struct Jogada*) malloc(sizeof(struct Jogada*));
    sentinela->prox = sentinela;
    sentinela->ant = sentinela;
    sentinela->linhaDe = -1;
    sentinela->colunaDe = -1;
    return sentinela;
};

struct Peca* InsereInicioPeca(struct Peca* sentinela, int codigo, int linha, int coluna, int ataques)
{
    struct Peca* novo= (struct Peca*)malloc(sizeof(struct Peca));
    novo->linha=linha;
    novo->coluna=coluna;
    novo->codigo=codigo;
    novo->ataques=ataques;
    /*
    if(sentinela==NULL)
    {
        sentinela = (struct Peca*) malloc(sizeof(struct Peca));
        sentinela->codigo = 0;
        sentinela->prox = novo;
        sentinela->ant = novo;
        novo->prox=sentinela;
        novo->ant=sentinela;
        return novo;
    }
    */
    novo->prox=sentinela->prox;
    novo->ant=sentinela;
    sentinela->prox->ant=novo;
    sentinela->prox=novo;
    return novo;
}

struct Jogada* InsereInicioJogada(struct Jogada* sentinela, int linhaDe, int colunaDe, int linhaPara, int colunaPara)
{
    struct Jogada* novo = (struct Jogada*)malloc(sizeof(struct Jogada));
    novo->linhaDe=linhaDe;
    novo->colunaDe=colunaDe;
    novo->linhaPara=linhaPara;
    novo->colunaPara=colunaPara;
    /*
    if(sentinela==NULL)
    {
        sentinela = (struct Jogada*) malloc(sizeof(struct Jogada));
        sentinela->colunaDe = -1;
        sentinela->linhaDe = -1;
        sentinela->prox = novo;
        sentinela->ant = novo;
        novo->prox=sentinela;
        novo->ant=sentinela;
        return novo;
    }
    */
    novo->prox=sentinela->prox;
    novo->ant=sentinela;
    sentinela->prox->ant=novo;
    sentinela->prox=novo;
    return sentinela;
}

void RemovePeca(struct Peca* lista, int linha, int coluna){
    struct Peca* aux = lista->prox;
    while(aux != lista && aux->linha != linha && aux->coluna != coluna){
        aux = aux->prox;
    }
    if(aux != NULL){
        aux->prox->ant = aux->ant;
        aux->ant->prox = aux->prox;
        free(aux);
        printf("deletando peca");
    }
}

struct Posicao IniciaTabuleiro()
{
    int i, j;

    struct Posicao tabuleiro;
    tabuleiro.jogVez = 1;
    tabuleiro.brancas=tabuleiro.pretas=NULL;
    for(i=0; i<8; i++)
    {
        for(j=0; j<8; j++)
        {
            tabuleiro.tab[i][j]=NULL;
        }
    }
    tabuleiro.qtdPretas=16;
    tabuleiro.qtdBrancas=16;
    tabuleiro.brancas = CriaListaPeca();
    tabuleiro.pretas = CriaListaPeca();
    for(i=0; i<8; i++)
    {
        tabuleiro.tab[1][i]=InsereInicioPeca(tabuleiro.brancas, 1, 1, i, 0);
        tabuleiro.tab[6][i]=InsereInicioPeca(tabuleiro.pretas, -1, 6, i, 0);
    }

    tabuleiro.tab[0][0]=InsereInicioPeca(tabuleiro.brancas, 4, 0, 0, 0);
    tabuleiro.tab[0][7]=InsereInicioPeca(tabuleiro.brancas, 4, 0, 7, 0);
    tabuleiro.tab[0][1]=InsereInicioPeca(tabuleiro.brancas, 2, 0, 1, 0);
    tabuleiro.tab[0][6]=InsereInicioPeca(tabuleiro.brancas, 2, 0, 6, 0);
    tabuleiro.tab[0][2]=InsereInicioPeca(tabuleiro.brancas, 3, 0, 2, 0);
    tabuleiro.tab[0][5]=InsereInicioPeca(tabuleiro.brancas, 3, 0, 5, 0);
    tabuleiro.tab[0][4]=InsereInicioPeca(tabuleiro.brancas, 6, 0, 4, 0);
    tabuleiro.tab[0][3]=InsereInicioPeca(tabuleiro.brancas, 5, 0, 3, 0);

    tabuleiro.tab[7][0]=InsereInicioPeca(tabuleiro.pretas, -4, 7, 0, 0);
    tabuleiro.tab[7][7]=InsereInicioPeca(tabuleiro.pretas, -4, 7, 7, 0);
    tabuleiro.tab[7][1]=InsereInicioPeca(tabuleiro.pretas, -2, 7, 1, 0);
    tabuleiro.tab[7][6]=InsereInicioPeca(tabuleiro.pretas, -2, 7, 6, 0);
    tabuleiro.tab[7][2]=InsereInicioPeca(tabuleiro.pretas, -3, 7, 2, 0);
    tabuleiro.tab[7][5]=InsereInicioPeca(tabuleiro.pretas, -3, 7, 5, 0);
    tabuleiro.tab[7][4]=InsereInicioPeca(tabuleiro.pretas, -6, 7, 4, 0);
    tabuleiro.tab[7][3]=InsereInicioPeca(tabuleiro.pretas, -5, 7, 3, 0);

    return tabuleiro;

}

//Inicio das funções de jogadas de peças
struct Jogada* peao(struct Jogada* movimentos, struct Peca* p, struct Peca* tabuleiro[8][8])
{
    if((p->linha+p->codigo)>=0 && (p->linha+p->codigo)<=7)
    {
        if(tabuleiro[p->linha+p->codigo][p->coluna]==NULL)
        {
            movimentos=InsereInicioJogada(movimentos, p->linha, p->coluna, (p->linha+p->codigo), p->coluna);
        }
        if(tabuleiro[p->linha+p->codigo][p->coluna-1]!=NULL && p->coluna>0 && (tabuleiro[p->linha+p->codigo][p->coluna-1]->codigo*p->codigo)<0)
        {
            movimentos=InsereInicioJogada(movimentos, p->linha, p->coluna, (p->linha+p->codigo), (p->coluna-1));
            tabuleiro[p->linha+p->codigo][p->coluna-1]->ataques++;
        }
        if(tabuleiro[p->linha+p->codigo][p->coluna+1]!=NULL && p->coluna<7 && (tabuleiro[p->linha+p->codigo][p->coluna+1]->codigo*p->codigo)<0)
        {
            movimentos=InsereInicioJogada(movimentos, p->linha, p->coluna, (p->linha+p->codigo), (p->coluna+1));
            tabuleiro[p->linha+p->codigo][p->coluna+1]->ataques++;
        }
    }
    return movimentos;
}

struct Jogada* cavalo(struct Jogada* movimentos, struct Peca* p, struct Peca* tabuleiro[8][8])
{
    if(p->linha<6)
    {
        if(p->coluna<7)
        {
            if(tabuleiro[p->linha+2][p->coluna+1]!=NULL && tabuleiro[p->linha+2][p->coluna+1]->codigo*p->codigo<0)
            {
                tabuleiro[p->linha+2][p->coluna+1]->ataques++;
                movimentos=InsereInicioJogada(movimentos, p->linha, p->coluna, p->linha+2, p->coluna+1);
            }
            else if(tabuleiro[p->linha+2][p->coluna+1]==NULL)
            {
                movimentos=InsereInicioJogada(movimentos, p->linha, p->coluna, p->linha+2, p->coluna+1);
            }
        }
        if(p->coluna>0)
        {
            if(tabuleiro[p->linha+2][p->coluna-1]!=NULL && tabuleiro[p->linha+2][p->coluna-1]->codigo*p->codigo<0)
            {
                tabuleiro[p->linha+2][p->coluna+1]->ataques++;
                movimentos=InsereInicioJogada(movimentos, p->linha, p->coluna, p->linha+2, p->coluna-1);
            }
            else if(tabuleiro[p->linha+2][p->coluna-1]==NULL)
            {
                movimentos=InsereInicioJogada(movimentos, p->linha, p->coluna, p->linha+2, p->coluna-1);
            }
        }
    }
    if(p->linha<7)
    {
        if(p->coluna<6)
        {
            if(tabuleiro[p->linha+1][p->coluna+2]!=NULL && tabuleiro[p->linha+1][p->coluna+2]->codigo*p->codigo<0)
            {
                tabuleiro[p->linha+1][p->coluna+2]->ataques++;
                movimentos=InsereInicioJogada(movimentos, p->linha, p->coluna, p->linha+1, p->coluna+2);
            }
            else if(tabuleiro[p->linha+1][p->coluna+2]==NULL)
            {
                movimentos=InsereInicioJogada(movimentos, p->linha, p->coluna, p->linha+1, p->coluna+2);
            }
        }
        if(p->coluna>1)
        {
            if(tabuleiro[p->linha+1][p->coluna-2]!=NULL && tabuleiro[p->linha+1][p->coluna-2]->codigo*p->codigo<0)
            {
                tabuleiro[p->linha+1][p->coluna-2]->ataques++;
                movimentos=InsereInicioJogada(movimentos, p->linha, p->coluna, p->linha+1, p->coluna-2);
            }
            else if(tabuleiro[p->linha+1][p->coluna-2]==NULL)
            {
                movimentos=InsereInicioJogada(movimentos, p->linha, p->coluna, p->linha+1, p->coluna-2);
            }
        }
    }
    if(p->linha>1)
    {
        if(p->coluna<7)
        {
            if(tabuleiro[p->linha-2][p->coluna+1]!=NULL && tabuleiro[p->linha-2][p->coluna+1]->codigo*p->codigo<0)
            {
                tabuleiro[p->linha-2][p->coluna+1]->ataques++;
                movimentos=InsereInicioJogada(movimentos, p->linha, p->coluna, p->linha-2, p->coluna+1);
            }
            else if(tabuleiro[p->linha-2][p->coluna+1]==NULL)
            {
                movimentos=InsereInicioJogada(movimentos, p->linha, p->coluna, p->linha-2, p->coluna+1);
            }
        }
        if(p->coluna>0)
        {
            if(tabuleiro[p->linha-2][p->coluna-1]!=NULL && tabuleiro[p->linha-2][p->coluna-1]->codigo*p->codigo<0)
            {
                tabuleiro[p->linha-2][p->coluna-1]->ataques++;
                movimentos=InsereInicioJogada(movimentos, p->linha, p->coluna, p->linha-2, p->coluna-1);
            }
            else if(tabuleiro[p->linha-2][p->coluna-1]==NULL)
            {
                movimentos=InsereInicioJogada(movimentos, p->linha, p->coluna, p->linha-2, p->coluna-1);
            }
        }
    }
    if(p->linha>0)
    {
        if(p->coluna<6)
        {
            if(tabuleiro[p->linha-1][p->coluna+2]!=NULL && tabuleiro[p->linha-1][p->coluna+2]->codigo*p->codigo<0)
            {
                tabuleiro[p->linha-1][p->coluna+2]->ataques++;
                movimentos=InsereInicioJogada(movimentos, p->linha, p->coluna, p->linha-1, p->coluna+2);
            }
            else if(tabuleiro[p->linha-2][p->coluna-1]==NULL)
            {
                movimentos=InsereInicioJogada(movimentos, p->linha, p->coluna, p->linha-1, p->coluna+2);
            }
        }
        if(p->coluna>1)
        {
            if(tabuleiro[p->linha-1][p->coluna-2]!=NULL && tabuleiro[p->linha-1][p->coluna-2]->codigo*p->codigo<0)
            {
                tabuleiro[p->linha-1][p->coluna-2]->ataques++;
                movimentos=InsereInicioJogada(movimentos, p->linha, p->coluna, p->linha-1, p->coluna-2);
            }
            else if(tabuleiro[p->linha-1][p->coluna-2]==NULL)
            {
                movimentos=InsereInicioJogada(movimentos, p->linha, p->coluna, p->linha-1, p->coluna-2);
            }
        }
    }
    return movimentos;
}

struct Jogada* bispo(struct Jogada* movimentos, struct Peca* p, struct Peca* tabuleiro[8][8])
{
    /*
    a funçao recebe como parametro a lista de jogadas, o ponteiro da peça e o tabuleiro que é um ponteiro para todas as peças que ainda estao no jogo.
    */
    int k=0;
    do
    {
        k++;
        if(p->linha+k<8 && p->coluna-k>=0)
        {
            if(tabuleiro[p->linha+k][p->coluna-k]!=NULL && tabuleiro[p->linha+k][p->coluna-k]->codigo*p->codigo<0)
            {
                /*
                se a linha e a coluna da peça nao ultrapassarem 0 e 8 depois de somados com o contador, precisamos verificar se o ponteiro do tabuleiro na posicao linha+k coluna-k
                        aponta para uma peça ou para nulo, caso aponte para uma peça, temos que verificar se a multiplicaçao da negativo pois isto significa que as duas peças sao de sinais diferentes,
                        entao podemos realizar a captura
                */
                tabuleiro[p->linha+k][p->coluna-k]->ataques++;/*
        se a açao for de captura temos que sinalizar que a peça adversaria esta sofrendo 1 ataque*/
                movimentos=InsereInicioJogada(movimentos,p->linha,p->coluna,p->linha+k,p->coluna-k);
            }
            else if(tabuleiro[p->linha+k][p->coluna-k]==NULL)
            {
                movimentos=InsereInicioJogada(movimentos,p->linha, p->coluna,p->linha+k,p->coluna-k);/*
        Se o tabuleiro na posicao linha+k coluna-k estiver apontando para null significa que a casa esta livre entao nao eh uma jogada de captura, nao sinalizamos ataque para
                nenhuma peça, mas nos 2 casos temos que colocar as jogadas na lista de movimentos possiveis*/
            }
        }
    }
    while(p->linha+k<8 && p->linha-k>=0 && p->coluna+k<8 && p->coluna-k>=0 && tabuleiro[p->linha+k][p->coluna-k]==NULL);
    /*ja fiz a diagonal superior esquerda, o resto eh a mesma estrutura, a torre é bem semelhante ao bispo*/

    //Diagonal superior direita
    k=0;
    do
    {
        k++;
        if(p->linha+k<8 && p->coluna+k<8)
        {
            if(tabuleiro[p->linha+k][p->coluna+k]!=NULL && tabuleiro[p->linha+k][p->coluna+k]->codigo*p->codigo<0)
            {
                tabuleiro[p->linha+k][p->coluna+k]->ataques++;
                movimentos=InsereInicioJogada(movimentos,p->linha,p->coluna,p->linha+k,p->coluna+k);
            }
            else if(tabuleiro[p->linha+k][p->coluna+k]==NULL)
            {
                movimentos=InsereInicioJogada(movimentos,p->linha, p->coluna,p->linha+k,p->coluna+k);
            }
        }
    }
    while(p->linha+k<8 && p->linha-k>=0 && p->coluna+k<8 && p->coluna-k>=0 && tabuleiro[p->linha+k][p->coluna+k]==NULL);

    //Diagonal inferior esquerda
    k=0;
    do
    {
        k++;
        if(p->linha-k>=0 && p->coluna-k>=0)
        {
            if(tabuleiro[p->linha-k][p->coluna-k]!=NULL && tabuleiro[p->linha-k][p->coluna-k]->codigo*p->codigo<0)
            {
                tabuleiro[p->linha-k][p->coluna-k]->ataques++;
                movimentos=InsereInicioJogada(movimentos,p->linha,p->coluna,p->linha-k,p->coluna-k);
            }
            else if(tabuleiro[p->linha-k][p->coluna-k]==NULL)
            {
                movimentos=InsereInicioJogada(movimentos,p->linha, p->coluna,p->linha-k,p->coluna-k);
            }
        }
    }
    while(p->linha+k<8 && p->linha-k>=0 && p->coluna+k<8 && p->coluna-k>=0 && tabuleiro[p->linha-k][p->coluna-k]==NULL);

    //Diagonal inferior direita
    k=0;
    do
    {
        k++;
        if(p->linha-k>=0 && p->coluna+k<8)
        {
            if(tabuleiro[p->linha-k][p->coluna+k]!=NULL && tabuleiro[p->linha-k][p->coluna+k]->codigo*p->codigo<0)
            {
                tabuleiro[p->linha-k][p->coluna+k]->ataques++;
                movimentos=InsereInicioJogada(movimentos,p->linha,p->coluna,p->linha-k,p->coluna+k);
            }
            else if(tabuleiro[p->linha-k][p->coluna+k]==NULL)
            {
                movimentos=InsereInicioJogada(movimentos,p->linha, p->coluna,p->linha-k,p->coluna+k);
            }
        }
    }
    while(p->linha+k<8 && p->linha-k>=0 && p->coluna+k<8 && p->coluna-k>=0 && tabuleiro[p->linha-k][p->coluna+k]==NULL);

    return movimentos;
}

//Torre
struct Jogada* torre(struct Jogada* movimentos, struct Peca* p, struct Peca* tabuleiro[8][8])
{
    int k = 0;
    do //Cima
    {
        k++;
        if(p->coluna+k<8)
        {
            if(tabuleiro[p->linha][p->coluna+k]!=NULL && tabuleiro[p->linha][p->coluna+k]->codigo*p->codigo<0)
            {
                tabuleiro[p->linha][p->coluna+k]->ataques++;
                movimentos=InsereInicioJogada(movimentos,p->linha,p->coluna,p->linha,p->coluna+k);
            }
            else if(tabuleiro[p->linha][p->coluna+k]==NULL)
            {
                movimentos=InsereInicioJogada(movimentos,p->linha, p->coluna,p->linha,p->coluna+k);
            }
        }
    }
    while(p->linha+k<8 && p->linha-k>=0 && p->coluna+k<8 && p->coluna-k>=0 && tabuleiro[p->linha][p->coluna+k]==NULL);

    k = 0;
    do //Direita
    {
        k++;
        if(p->linha+k<8)
        {
            if(tabuleiro[p->linha+k][p->coluna]!=NULL && tabuleiro[p->linha+k][p->coluna]->codigo*p->codigo<0)
            {
                tabuleiro[p->linha+k][p->coluna]->ataques++;
                movimentos=InsereInicioJogada(movimentos,p->linha,p->coluna,p->linha+k,p->coluna);
            }
            else if(tabuleiro[p->linha+k][p->coluna]==NULL)
            {
                movimentos=InsereInicioJogada(movimentos,p->linha, p->coluna,p->linha+k,p->coluna);
            }
        }
    }
    while(p->linha+k<8 && p->linha-k>=0 && p->coluna+k<8 && p->coluna-k>=0 && tabuleiro[p->linha+k][p->coluna]==NULL);

    k = 0;
    do //Baixo
    {
        k++;
        if(p->coluna-k>=0)
        {
            if(tabuleiro[p->linha][p->coluna-k]!=NULL && tabuleiro[p->linha][p->coluna-k]->codigo*p->codigo<0)
            {
                tabuleiro[p->linha][p->coluna-k]->ataques++;
                movimentos=InsereInicioJogada(movimentos,p->linha,p->coluna,p->linha,p->coluna-k);
            }
            else if(tabuleiro[p->linha][p->coluna-k]==NULL)
            {
                movimentos=InsereInicioJogada(movimentos,p->linha, p->coluna,p->linha,p->coluna-k);
            }
        }
    }
    while(p->linha+k<8 && p->linha-k>=0 && p->coluna+k<8 && p->coluna-k>=0 && tabuleiro[p->linha][p->coluna-k]==NULL);

    k = 0;
    do //Esquerda
    {
        k++;
        if(p->linha-k>=0)
        {
            if(tabuleiro[p->linha-k][p->coluna]!=NULL && tabuleiro[p->linha-k][p->coluna]->codigo*p->codigo<0)
            {
                tabuleiro[p->linha-k][p->coluna]->ataques++;
                movimentos=InsereInicioJogada(movimentos,p->linha,p->coluna,p->linha-k,p->coluna);
            }
            else if(tabuleiro[p->linha-k][p->coluna]==NULL)
            {
                movimentos=InsereInicioJogada(movimentos,p->linha, p->coluna,p->linha-k,p->coluna);
            }
        }
    }
    while(p->linha+k<8 && p->linha-k>=0 && p->coluna+k<8 && p->coluna-k>=0 && tabuleiro[p->linha-k][p->coluna]==NULL);

    return movimentos;
}

struct Jogada* rei(struct Jogada* movimentos, struct Peca* p, struct Peca* tabuleiro[8][8])
{
    int k = 0;
    if(p->coluna < 7){
        do
        {
            k++;
            if(p->coluna+1<8)
            {
                if(tabuleiro[p->linha][p->coluna+1]!=NULL && tabuleiro[p->linha][p->coluna+1]->codigo*p->codigo<0)
                {
                    tabuleiro[p->linha][p->coluna+1]->ataques++;
                    movimentos=InsereInicioJogada(movimentos,p->linha,p->coluna,p->linha,p->coluna+1);
                }
                else if(tabuleiro[p->linha][p->coluna+1]==NULL)
                {
                    movimentos=InsereInicioJogada(movimentos,p->linha, p->coluna,p->linha,p->coluna+1);
                }
            }
        }
        while(p->linha+k<8 && p->linha-k>=0 && p->coluna+k<8 && p->coluna-k>=0 && tabuleiro[p->linha][p->coluna+1]==NULL);
    }

    if(p->coluna < 7 && p->linha < 7){
        k = 0;
        do
        {
            k++;
            if(p->linha+1<8 && p->coluna+1<8)
            {
                if(tabuleiro[p->linha+1][p->coluna+1]!=NULL && tabuleiro[p->linha+1][p->coluna+1]->codigo*p->codigo<0)
                {
                    tabuleiro[p->linha+1][p->coluna+1]->ataques++;
                    movimentos=InsereInicioJogada(movimentos,p->linha,p->coluna,p->linha+1,p->coluna+1);
                }
                else if(tabuleiro[p->linha+1][p->coluna+1]==NULL)
                {
                    movimentos=InsereInicioJogada(movimentos,p->linha, p->coluna,p->linha+1,p->coluna+1);
                }
            }
        }
        while(p->linha+k<8 && p->linha-k>=0 && p->coluna+k<8 && p->coluna-k>=0 && tabuleiro[p->linha+1][p->coluna+1]==NULL);
    }

    if(p->linha < 7){
        k = 0;
        do
        {
            k++;
            if(p->linha+1<8)
            {
                if(tabuleiro[p->linha+1][p->coluna]!=NULL && tabuleiro[p->linha+1][p->coluna]->codigo*p->codigo<0)
                {
                    tabuleiro[p->linha+1][p->coluna]->ataques++;
                    movimentos=InsereInicioJogada(movimentos,p->linha,p->coluna,p->linha+1,p->coluna);
                }
                else if(tabuleiro[p->linha+1][p->coluna]==NULL)
                {
                    movimentos=InsereInicioJogada(movimentos,p->linha, p->coluna,p->linha+1,p->coluna);
                }
            }
        }
        while(p->linha+k<8 && p->linha-k>=0 && p->coluna+k<8 && p->coluna-k>=0 && tabuleiro[p->linha+1][p->coluna]==NULL);
    }

    if(p->coluna > 0 && p->linha < 7){
        k = 0;
        do
        {
            k++;
            if(p->linha+1<8 && p->coluna-1>=0)
            {
                if(tabuleiro[p->linha+1][p->coluna-1]!=NULL && tabuleiro[p->linha+1][p->coluna-1]->codigo*p->codigo<0)
                {
                    tabuleiro[p->linha+1][p->coluna-1]->ataques++;
                    movimentos=InsereInicioJogada(movimentos,p->linha,p->coluna,p->linha+1,p->coluna-1);
                }
                else if(tabuleiro[p->linha+1][p->coluna-1]==NULL)
                {
                    movimentos=InsereInicioJogada(movimentos,p->linha, p->coluna,p->linha+1,p->coluna-1);
                }
            }
        }
        while(p->linha+k<8 && p->linha-k>=0 && p->coluna+k<8 && p->coluna-k>=0 && tabuleiro[p->linha+1][p->coluna-1]==NULL);
    }

    if(p->coluna > 0){
        k = 0;
        do
        {
            k++;
            if(p->coluna-1>=0)
            {
                if(tabuleiro[p->linha][p->coluna-1]!=NULL && tabuleiro[p->linha][p->coluna-1]->codigo*p->codigo<0)
                {
                    tabuleiro[p->linha][p->coluna-1]->ataques++;
                    movimentos=InsereInicioJogada(movimentos,p->linha,p->coluna,p->linha,p->coluna-1);
                }
                else if(tabuleiro[p->linha][p->coluna-1]==NULL)
                {
                    movimentos=InsereInicioJogada(movimentos,p->linha, p->coluna,p->linha,p->coluna-1);
                }
            }
        }
        while(p->linha+k<8 && p->linha-k>=0 && p->coluna+k<8 && p->coluna-k>=0 && tabuleiro[p->linha][p->coluna-1]==NULL);
    }

    if(p->coluna > 0 && p->linha > 0){
        k = 0;
        do
        {
            k++;
            if(p->linha-1<8 && p->coluna-1>=0)
            {
                if(tabuleiro[p->linha-1][p->coluna-1]!=NULL && tabuleiro[p->linha-1][p->coluna-1]->codigo*p->codigo<0)
                {
                    tabuleiro[p->linha-1][p->coluna-1]->ataques++;
                    movimentos=InsereInicioJogada(movimentos,p->linha,p->coluna,p->linha-1,p->coluna-1);
                }
                else if(tabuleiro[p->linha-1][p->coluna-1]==NULL)
                {
                    movimentos=InsereInicioJogada(movimentos,p->linha, p->coluna,p->linha-1,p->coluna-1);
                }
            }
        }
        while(p->linha+k<8 && p->linha-k>=0 && p->coluna+k<8 && p->coluna-k>=0 && tabuleiro[p->linha-1][p->coluna-1]==NULL);
    }

    if(p->linha > 0){
        k = 0;
        do
        {
            k++;
            if(p->linha-1<8)
            {
                if(tabuleiro[p->linha-1][p->coluna]!=NULL && tabuleiro[p->linha-1][p->coluna]->codigo*p->codigo<0)
                {
                    tabuleiro[p->linha-1][p->coluna]->ataques++;
                    movimentos=InsereInicioJogada(movimentos,p->linha,p->coluna,p->linha-1,p->coluna);
                }
                else if(tabuleiro[p->linha-1][p->coluna]==NULL)
                {
                    movimentos=InsereInicioJogada(movimentos,p->linha, p->coluna,p->linha-1,p->coluna);
                }
            }
        }
        while(p->linha+k<8 && p->linha-k>=0 && p->coluna+k<8 && p->coluna-k>=0 && tabuleiro[p->linha-1][p->coluna]==NULL);
    }

    if(p->coluna > 0){
        k = 0;
        do
        {
            k++;
            if(p->linha+1<8 && p->coluna-1>=0)
            {
                if(tabuleiro[p->linha+1][p->coluna-1]!=NULL && tabuleiro[p->linha+1][p->coluna-1]->codigo*p->codigo<0)
                {
                    tabuleiro[p->linha+1][p->coluna-1]->ataques++;
                    movimentos=InsereInicioJogada(movimentos,p->linha,p->coluna,p->linha+1,p->coluna-1);
                }
                else if(tabuleiro[p->linha+1][p->coluna-1]==NULL)
                {
                    movimentos=InsereInicioJogada(movimentos,p->linha, p->coluna,p->linha+1,p->coluna-1);
                }
            }
        }
        while(p->linha+k<8 && p->linha-k>=0 && p->coluna+k<8 && p->coluna-k>=0 && tabuleiro[p->linha+1][p->coluna-1]==NULL);
    }

    return movimentos;
}
//Fim das funções de jogada de peças

void AjustaCor(int peca)
{
    switch(abs(peca))
    {
    case 1:
        printf("\033[0;36m");
        break;
    case 2:
        printf("\033[1;33m");
        break;
    case 3:
        printf("\033[0;35m");
        break;
    case 4:
        printf("\033[0;32m");
        break;
    case 5:
        printf("\033[0;34m");
        break;
    case 6:
        printf("\033[1;31m");
        break;
    }
}

void ResetCor()
{
    printf("\033[0m");
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
            }
            else
            {
                if (PosAtual.tab[i][j]!=NULL && PosAtual.tab[i][j]->codigo < 0)
                {
                    printf("|");
                }
                else if (PosAtual.tab[i][j]!=NULL && PosAtual.tab[i][j]->codigo > 0)
                {
                    printf("| ");
                }
                //AjustaCor(PosAtual.tab[i][j]->codigo);
                printf("%d", PosAtual.tab[i][j]->codigo);
                //ResetCor();
            }
        }
        printf("|\n\t\t\t\t\t\t  -------------------------\n");
    }
    printf("\t\t\t\t\t\t    0  1  2  3  4  5  6  7\n");
}

struct Jogada *CalculaMovimentosPossiveis(struct Posicao PosAtual)
{
    struct Peca* aux=PosAtual.brancas;
    do
    {
        aux->ataques=0;
        aux=aux->prox;
    }
    while(aux!=PosAtual.brancas);

    aux=PosAtual.pretas;
    do
    {
        aux->ataques=0;
        aux=aux->prox;
    }
    while(aux!=PosAtual.pretas);

    //1 é branco
    if(PosAtual.jogVez==1)
    {
        aux=PosAtual.brancas;
    }
    else
    {//-1 é preto
        aux=PosAtual.pretas;
    }

    struct Jogada* movimentos = CriaListaJogada();
    do
    {
        switch (abs(aux->codigo))
        {
        case 1: case -1:
            movimentos=peao(movimentos, aux, PosAtual.tab);
            break;
        case 2: case -2:
            movimentos=cavalo(movimentos, aux, PosAtual.tab);
            break;
        case 3: case -3:
            movimentos=bispo(movimentos, aux, PosAtual.tab);
            break;
        case 4: case -4:
            movimentos=torre(movimentos, aux, PosAtual.tab);
            break;
        case 5: case -5:
            movimentos=torre(movimentos, aux, PosAtual.tab);
            movimentos=bispo(movimentos, aux, PosAtual.tab);
            break;
        case 6: case -6:
            movimentos=rei(movimentos, aux, PosAtual.tab);
            break;

        }
        aux=aux->prox;

    }
    while(aux->codigo != 0);

    return movimentos;
}

// 1 é branco
// -1 é preto
int ExecutaJogada(struct Posicao *posAtual, struct Jogada* jogada){

    if (posAtual->tab[jogada->linhaPara][jogada->colunaPara] != NULL){
        if(posAtual->tab[jogada->linhaPara][jogada->colunaPara]->codigo == 6) {
            return 1;
        }

        if(posAtual->jogVez == 1) {
            RemovePeca(posAtual->pretas, jogada->linhaPara, jogada->colunaPara);
            posAtual->pretas--;
        }
        else{
            RemovePeca(posAtual->brancas, jogada->linhaPara, jogada->colunaPara);
            posAtual->brancas--;
        }

    }

    posAtual->tab[jogada->linhaPara][jogada->colunaPara] = posAtual->tab[jogada->linhaDe][jogada->colunaDe];
    posAtual->tab[jogada->linhaPara][jogada->colunaPara]->linha = jogada->linhaPara;
    posAtual->tab[jogada->linhaPara][jogada->colunaPara]->coluna = jogada->colunaPara;
    posAtual->tab[jogada->linhaDe][jogada->colunaDe] = NULL;

    return 0;
}

bool VerificaJogada(struct Jogada* jogada, struct Jogada* jogadasPossiveis){
    struct Jogada *aux = jogadasPossiveis->prox;
    while(aux->linhaDe != -1) {
        if(aux->linhaDe == jogada->linhaDe && aux->colunaDe == jogada->colunaDe &&
           aux->linhaPara == jogada->linhaPara && aux->colunaPara == jogada->colunaPara ) {
            return true;
       }
        aux = aux->prox;
    }

    printf("\nJogada Invalida\nOpcoes para esta peca: \n");
    aux = jogadasPossiveis->prox;
    while(aux->linhaDe != -1) {
        if(aux->linhaDe == jogada->linhaDe && aux->colunaDe == jogada->colunaDe) {
            printf("L:%d C:%d -> L:%d C:%d\n", aux->linhaDe, aux->colunaDe, aux->linhaPara, aux->colunaPara);
        }
        aux = aux->prox;
    }

    return false;
}

void PegaEscolha(int *linha, int* coluna) {
    //Funcao para garatir que a escolha está dentro do tabuleiro
    printf("Linha: ");
    scanf("%d", linha);
    fflush(stdin);
    printf("Coluna: ");
    scanf("%d", coluna);
    while (*linha < 0 || *linha > 8 || *coluna < 0|| *coluna > 8)
    {
        printf("Digite outra posição:\n");
        fflush(stdin);
        printf("Linha: ");
        scanf("%d", linha);
        fflush(stdin);
        printf("Coluna: ");
        scanf("%d", coluna);
    };
}

void Jogo(struct Posicao posAtual)
{
    setlocale(LC_ALL, "Portuguese");

    struct Jogada *jogadasPossiveis;
    struct Jogada *jogada = (struct Jogada*) malloc(sizeof(struct Jogada));

    do {
        jogadasPossiveis = CalculaMovimentosPossiveis(posAtual);
        Desenha(posAtual);


        printf("Jogador da vez: %s(%d)\n", posAtual.jogVez == 1 ? "branco" : "preto", posAtual.jogVez);
        printf("\nQual peça você quer mover?\n");
        PegaEscolha(&jogada->linhaDe, &jogada->colunaDe);
        while(posAtual.tab[jogada->linhaDe][jogada->colunaDe] == NULL ||
              ((posAtual.tab[jogada->linhaDe][jogada->colunaDe]->codigo > 0 && posAtual.jogVez < 0) ||
               (posAtual.tab[jogada->linhaDe][jogada->colunaDe]->codigo < 0 && posAtual.jogVez > 0))) {
            printf("Digite outra posição:\n");
            PegaEscolha(&jogada->linhaDe, &jogada->colunaDe);
        }

        printf("\nPara qual posicao você quer mover?\n");
        PegaEscolha(&jogada->linhaPara, &jogada->colunaPara);
        while(!VerificaJogada(jogada, jogadasPossiveis)){
            printf("\nDigite outra posição:\n");
            PegaEscolha(&jogada->linhaPara, &jogada->colunaPara);
        }
        system("cls");
        posAtual.jogVez = -1 * posAtual.jogVez;

        jogadasPossiveis = LiberaListaJogada(jogadasPossiveis);
    }
    while(ExecutaJogada(&posAtual, jogada) == 0);
    posAtual.jogVez = -1 * posAtual.jogVez; //Desinverte a vez
    printf("\nVitoria do jogador %s!", posAtual.jogVez == 1 ? "branco" : "preto", posAtual.jogVez);
    fflush(stdin);
    getchar();
}

int main()
{
    struct Posicao posAtual=IniciaTabuleiro();
    Jogo(posAtual);

    return 0;
}
