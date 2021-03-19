#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define ROXO "\x1B[35m"
#define AZUL "\x1B[34m"
#define RESET "\x1B[0m"

void peao_preto(int tabuleiro[8][8], int tabuleiro_temporario[8][8], int linha, int coluna)
{
	if ((linha - 1) >= 0 && tabuleiro[linha - 1][coluna] == 0)
	{
		tabuleiro_temporario[linha - 1][coluna] += 20;
	}
	if ((linha - 1) >= 0 && (coluna - 1) >= 0 && tabuleiro[linha - 1][coluna - 1] > 0)
	{
		tabuleiro_temporario[linha - 1][coluna - 1] += 50;
	}
	if ((linha - 1) >= 0 && (coluna + 1) < 8 && tabuleiro[linha - 1][coluna + 1] > 0)
	{
		tabuleiro_temporario[linha - 1][coluna + 1] += 50;
	}
	if ((linha == 6) && tabuleiro[linha - 2][coluna] == 0)
	{
		tabuleiro_temporario[linha - 2][coluna] += 20;
	}
}

void cavalo_preto(int tabuleiro[8][8], int tabuleiro_temporario[8][8], int linha, int coluna)
{
	if ((linha + 2) < 8 && (coluna + 1) < 8 && tabuleiro[linha + 2][coluna + 1] == 0)
	{
		tabuleiro_temporario[linha + 2][coluna + 1] += 20;
	}
	if ((linha + 2) < 8 && (coluna + 1) < 8 && tabuleiro[linha + 2][coluna + 1] > 0)
	{
		tabuleiro_temporario[linha + 2][coluna + 1] += 50;
	}
	if ((linha + 1) < 8 && (coluna + 2) < 8 && tabuleiro[linha + 1][coluna + 2] == 0)
	{
		tabuleiro_temporario[linha + 1][coluna + 2] += 20;
	}
	if ((linha + 1) < 8 && (coluna + 2) < 8 && tabuleiro[linha + 1][coluna + 2] > 0)
	{
		tabuleiro_temporario[linha + 1][coluna + 2] += 50;
	}
	if ((linha - 1) >= 0 && (coluna + 2) < 8 && tabuleiro[linha - 1][coluna + 2] == 0)
	{
		tabuleiro_temporario[linha - 1][coluna + 2] += 20;
	}
	if ((linha - 1) >= 0 && (coluna + 2) < 8 && tabuleiro[linha - 1][coluna + 2] > 0)
	{
		tabuleiro_temporario[linha - 1][coluna + 2] += 50;
	}
	if ((linha + 2) < 8 && (coluna - 1) >= 0 && tabuleiro[linha + 2][coluna - 1] == 0)
	{
		tabuleiro_temporario[linha + 2][coluna - 1] += 20;
	}
	if ((linha + 2) < 8 && (coluna - 1) >= 0 && tabuleiro[linha + 2][coluna - 1] > 0)
	{
		tabuleiro_temporario[linha + 2][coluna - 1] += 50;
	}
	if ((linha - 2) >= 0 && (coluna + 1) < 8 && tabuleiro[linha - 2][coluna + 1] == 0)
	{
		tabuleiro_temporario[linha - 2][coluna + 1] += 20;
	}
	if ((linha - 2) >= 0 && (coluna + 1) < 8 && tabuleiro[linha - 2][coluna + 1] > 0)
	{
		tabuleiro_temporario[linha - 2][coluna + 1] += 50;
	}
	if ((linha - 1) >= 0 && (coluna - 2) >= 0 && tabuleiro[linha - 1][coluna - 2] == 0)
	{
		tabuleiro_temporario[linha - 1][coluna - 2] += 20;
	}
	if ((linha - 1) >= 0 && (coluna - 2) >= 0 && tabuleiro[linha - 1][coluna - 2] > 0)
	{
		tabuleiro_temporario[linha - 1][coluna - 2] += 50;
	}
	if ((linha + 1) < 8 && (coluna - 2) >= 0 && tabuleiro[linha + 1][coluna - 2] == 0)
	{
		tabuleiro_temporario[linha + 1][coluna - 2] += 20;
	}
	if ((linha + 1) < 8 && (coluna - 2) >= 0 && tabuleiro[linha + 1][coluna - 2] > 0)
	{
		tabuleiro_temporario[linha + 1][coluna - 2] += 50;
	}
	if ((linha - 2) >= 0 && (coluna - 1) >= 0 && tabuleiro[linha - 2][coluna - 1] == 0)
	{
		tabuleiro_temporario[linha - 2][coluna - 1] += 20;
	}
	if ((linha - 2) >= 0 && (coluna - 1) >= 0 && tabuleiro[linha - 2][coluna - 1] > 0)
	{
		tabuleiro_temporario[linha - 2][coluna - 1] += 50;
	}
}

void bispo_preto(int tabuleiro[8][8], int tabuleiro_temporario[8][8], int linha, int coluna)
{
	int k = 1;
	while ((linha + k) < 8 && (coluna + k) < 8 && tabuleiro[linha + k][coluna + k] == 0)
	{
		tabuleiro_temporario[linha + k][coluna + k] += 20;
		k++;
	}
	if ((linha + k) < 8 && (coluna + k) < 8 && tabuleiro[linha + k][coluna + k] > 0)
	{
		tabuleiro_temporario[linha + k][coluna + k] += 50;
	}
	k = 1;
	while ((linha - k) >= 0 && (coluna + k) < 8 && tabuleiro[linha - k][coluna + k] == 0)
	{
		tabuleiro_temporario[linha - k][coluna + k] += 20;
		k++;
	}
	if ((linha - k) >= 0 && (coluna + k) < 8 && tabuleiro[linha - k][coluna + k] > 0)
	{
		tabuleiro_temporario[linha - k][coluna + k] += 50;
	}
	k = 1;
	while ((linha - k) >= 0 && (coluna - k) >= 0 && tabuleiro[linha - k][coluna - k] == 0)
	{
		tabuleiro_temporario[linha - k][coluna - k] += 20;
		k++;
	}
	if ((linha - k) >= 0 && (coluna - k) >= 0 && tabuleiro[linha - k][coluna - k] > 0)
	{
		tabuleiro_temporario[linha - k][coluna - k] += 50;
	}
	k = 1;
	while ((linha + k) < 8 && (coluna - k) >= 0 && tabuleiro[linha + k][coluna - k] == 0)
	{
		tabuleiro_temporario[linha + k][coluna - k] += 20;
		k++;
	}
	if ((linha + k) < 8 && (coluna - k) >= 0 && tabuleiro[linha + k][coluna - k] > 0)
	{
		tabuleiro_temporario[linha + k][coluna - k] += 50;
	}
}

void torre_preta(int tabuleiro[8][8], int tabuleiro_temporario[8][8], int linha, int coluna)
{
	int k = 1;
	while ((linha + k) < 8 && tabuleiro[linha + k][coluna] == 0)
	{
		tabuleiro_temporario[linha + k][coluna] += 20;
		k++;
	}
	if ((linha + k) < 8 && tabuleiro[linha + k][coluna] > 0)
	{
		tabuleiro_temporario[linha + k][coluna] += 50;
	}
	k = 1;
	while ((linha - k) >= 0 && tabuleiro[linha - k][coluna] == 0)
	{
		tabuleiro_temporario[linha - k][coluna] += 20;
		k++;
	}
	if ((linha - k) >= 0 && tabuleiro[linha - k][coluna] > 0)
	{
		tabuleiro_temporario[linha - k][coluna] += 50;
	}
	k = 1;
	while ((coluna - k) >= 0 && tabuleiro[linha][coluna - k] == 0)
	{
		tabuleiro_temporario[linha][coluna - k] += 20;
		k++;
	}
	if ((coluna - k) >= 0 && tabuleiro[linha][coluna - k] > 0)
	{
		tabuleiro_temporario[linha][coluna - k] += 50;
	}
	k = 1;
	while ((coluna + k) < 8 && tabuleiro[linha][coluna + k] == 0)
	{
		tabuleiro_temporario[linha][coluna + k] += 20;
		k++;
	}
	if ((coluna + k) < 8 && tabuleiro[linha][coluna + k] > 0)
	{
		tabuleiro_temporario[linha][coluna + k] += 50;
	}
}

void rainha_preta(int tabuleiro[8][8], int tabuleiro_temporario[8][8], int linha, int coluna)
{
	bispo_preto(tabuleiro, tabuleiro_temporario, linha, coluna);
	torre_preta(tabuleiro, tabuleiro_temporario, linha, coluna);
}

void rei_preto(int tabuleiro[8][8], int tabuleiro_temporario[8][8], int linha, int coluna)
{
	if ((linha + 1) < 8 && tabuleiro[linha + 1][coluna] == 0)
	{
		tabuleiro_temporario[linha + 1][coluna] += 20;
	}
	if ((linha + 1) < 8 && tabuleiro[linha + 1][coluna] > 0)
	{
		tabuleiro_temporario[linha + 1][coluna] += 50;
	}
	if ((linha + 1) < 8 && (coluna + 1) < 8 && tabuleiro[linha + 1][coluna + 1] == 0)
	{
		tabuleiro_temporario[linha + 1][coluna + 1] += 20;
	}
	if ((linha + 1) < 8 && (coluna + 1) < 8 && tabuleiro[linha + 1][coluna + 1] > 0)
	{
		tabuleiro_temporario[linha + 1][coluna + 1] += 50;
	}
	if ((coluna + 1) < 8 && tabuleiro[linha][coluna + 1] == 0)
	{
		tabuleiro_temporario[linha][coluna + 1] += 20;
	}
	if ((coluna + 1) < 8 && tabuleiro[linha][coluna + 1] > 0)
	{
		tabuleiro_temporario[linha][coluna + 1] += 50;
	}
	if ((coluna + 1) < 8 && (linha - 1) >= 0 && tabuleiro[linha - 1][coluna + 1] == 0)
	{
		tabuleiro_temporario[linha - 1][coluna + 1] += 20;
	}
	if ((coluna + 1) < 8 && (linha - 1) >= 0 && tabuleiro[linha - 1][coluna + 1] > 0)
	{
		tabuleiro_temporario[linha - 1][coluna + 1] += 50;
	}
	if ((linha - 1) >= 0 && tabuleiro[linha - 1][coluna] == 0)
	{
		tabuleiro_temporario[linha - 1][coluna] += 20;
	}
	if ((linha - 1) >= 0 && tabuleiro[linha - 1][coluna] > 0)
	{
		tabuleiro_temporario[linha - 1][coluna] += 50;
	}
	if ((linha - 1) >= 0 && (coluna - 1) >= 0 && tabuleiro[linha - 1][coluna - 1] == 0)
	{
		tabuleiro_temporario[linha - 1][coluna - 1] += 20;
	}
	if ((linha - 1) >= 0 && (coluna - 1) >= 0 && tabuleiro[linha - 1][coluna - 1] > 0)
	{
		tabuleiro_temporario[linha - 1][coluna - 1] += 50;
	}
	if ((coluna - 1) >= 0 && tabuleiro[linha][coluna - 1] == 0)
	{
		tabuleiro_temporario[linha][coluna - 1] += 20;
	}
	if ((coluna - 1) >= 0 && tabuleiro[linha][coluna - 1] > 0)
	{
		tabuleiro_temporario[linha][coluna - 1] += 50;
	}
	if ((coluna - 1) >= 0 && (linha + 1) < 8 && tabuleiro[linha + 1][coluna - 1] == 0)
	{
		tabuleiro_temporario[linha + 1][coluna - 1] += 20;
	}
	if ((coluna - 1) >= 0 && (linha + 1) < 8 && tabuleiro[linha + 1][coluna - 1] > 0)
	{
		tabuleiro_temporario[linha + 1][coluna - 1] += 50;
	}
}

void peao_branco(int tabuleiro[8][8], int tabuleiro_temporario[8][8], int linha, int coluna)
{
	if ((linha + 1) < 8 && tabuleiro[linha + 1][coluna] == 0)
	{
		tabuleiro_temporario[linha + 1][coluna] += 20;
	}
	if ((linha + 1) < 8 && (coluna + 1) < 8 && tabuleiro[linha + 1][coluna + 1] < 0)
	{
		tabuleiro_temporario[linha + 1][coluna + 1] += 50;
	}
	if ((linha + 1) < 8 && (coluna - 1) < 8 && tabuleiro[linha + 1][coluna - 1] < 0)
	{
		tabuleiro_temporario[linha + 1][coluna - 1] += 50;
	}
	if ((linha == 1) && tabuleiro[linha + 2][coluna] == 0)
	{
		tabuleiro_temporario[linha + 2][coluna] += 20;
	}
}

void cavalo_branco(int tabuleiro[8][8], int tabuleiro_temporario[8][8], int linha, int coluna)
{
	if ((linha + 2) < 8 && (coluna + 1) < 8 && tabuleiro[linha + 2][coluna + 1] == 0)
	{
		tabuleiro_temporario[linha + 2][coluna + 1] += 20;
	}
	if ((linha + 2) < 8 && (coluna + 1) < 8 && tabuleiro[linha + 2][coluna + 1] < 0)
	{
		tabuleiro_temporario[linha + 2][coluna + 1] += 50;
	}
	if ((linha + 1) < 8 && (coluna + 2) < 8 && tabuleiro[linha + 1][coluna + 2] == 0)
	{
		tabuleiro_temporario[linha + 1][coluna + 2] = +20;
	}
	if ((linha + 1) < 8 && (coluna + 2) < 8 && tabuleiro[linha + 1][coluna + 2] < 0)
	{
		tabuleiro_temporario[linha + 1][coluna + 2] += 50;
	}
	if ((linha - 1) >= 0 && (coluna + 2) < 8 && tabuleiro[linha - 1][coluna + 2] == 0)
	{
		tabuleiro_temporario[linha - 1][coluna + 2] += 20;
	}
	if ((linha - 1) >= 0 && (coluna + 2) < 8 && tabuleiro[linha - 1][coluna + 2] < 0)
	{
		tabuleiro_temporario[linha - 1][coluna + 2] += 50;
	}
	if ((linha + 2) < 8 && (coluna - 1) >= 0 && tabuleiro[linha + 2][coluna - 1] == 0)
	{
		tabuleiro_temporario[linha + 2][coluna - 1] += 20;
	}
	if ((linha + 2) < 8 && (coluna - 1) >= 0 && tabuleiro[linha + 2][coluna - 1] < 0)
	{
		tabuleiro_temporario[linha + 2][coluna - 1] += 50;
	}
	if ((linha - 2) >= 0 && (coluna + 1) < 8 && tabuleiro[linha - 2][coluna + 1] == 0)
	{
		tabuleiro_temporario[linha - 2][coluna + 1] += 20;
	}
	if ((linha - 2) >= 0 && (coluna + 1) < 8 && tabuleiro[linha - 2][coluna + 1] < 0)
	{
		tabuleiro_temporario[linha - 2][coluna + 1] += 50;
	}
	if ((linha - 1) >= 0 && (coluna - 2) >= 0 && tabuleiro[linha - 1][coluna - 2] == 0)
	{
		tabuleiro_temporario[linha - 1][coluna - 2] += 20;
	}
	if ((linha - 1) >= 0 && (coluna - 2) >= 0 && tabuleiro[linha - 1][coluna - 2] < 0)
	{
		tabuleiro_temporario[linha - 1][coluna - 2] += 50;
	}
	if ((linha + 1) < 8 && (coluna - 2) >= 0 && tabuleiro[linha + 1][coluna - 2] == 0)
	{
		tabuleiro_temporario[linha + 1][coluna - 2] += 20;
	}
	if ((linha + 1) < 8 && (coluna - 2) >= 0 && tabuleiro[linha + 1][coluna - 2] < 0)
	{
		tabuleiro_temporario[linha + 1][coluna - 2] += 50;
	}
	if ((linha - 2) >= 0 && (coluna - 1) >= 0 && tabuleiro[linha - 2][coluna - 1] == 0)
	{
		tabuleiro_temporario[linha - 2][coluna - 1] += 20;
	}
	if ((linha - 2) >= 0 && (coluna - 1) >= 0 && tabuleiro[linha - 2][coluna - 1] < 0)
	{
		tabuleiro_temporario[linha - 2][coluna - 1] += 50;
	}
}

void bispo_branco(int tabuleiro[8][8], int tabuleiro_temporario[8][8], int linha, int coluna)
{
	int k = 1;
	while ((linha + k) < 8 && (coluna + k) < 8 && tabuleiro[linha + k][coluna + k] == 0)
	{
		tabuleiro_temporario[linha + k][coluna + k] += 20;
		k++;
	}
	if ((linha + k) < 8 && (coluna + k) < 8 && tabuleiro[linha + k][coluna + k] < 0)
	{
		tabuleiro_temporario[linha + k][coluna + k] += 50;
	}
	k = 1;
	while ((linha - k) >= 0 && (coluna + k) < 8 && tabuleiro[linha - k][coluna + k] == 0)
	{
		tabuleiro_temporario[linha - k][coluna + k] += 20;
		k++;
	}
	if ((linha - k) >= 0 && (coluna + k) < 8 && tabuleiro[linha - k][coluna + k] < 0)
	{
		tabuleiro_temporario[linha - k][coluna + k] += 50;
	}
	k = 1;
	while ((linha - k) >= 0 && (coluna - k) >= 0 && tabuleiro[linha - k][coluna - k] == 0)
	{
		tabuleiro_temporario[linha - k][coluna - k] += 20;
		k++;
	}
	if ((linha - k) >= 0 && (coluna - k) >= 0 && tabuleiro[linha - k][coluna - k] < 0)
	{
		tabuleiro_temporario[linha - k][coluna - k] += 50;
	}
	k = 1;
	while ((linha + k) < 8 && (coluna - k) >= 0 && tabuleiro[linha + k][coluna - k] == 0)
	{
		tabuleiro_temporario[linha + k][coluna - k] += 20;
		k++;
	}
	if ((linha + k) < 8 && (coluna - k) >= 0 && tabuleiro[linha + k][coluna - k] < 0)
	{
		tabuleiro_temporario[linha + k][coluna - k] += 50;
	}
}

void torre_branca(int tabuleiro[8][8], int tabuleiro_temporario[8][8], int linha, int coluna)
{
	int k = 1;
	while ((linha + k) < 8 && tabuleiro[linha + k][coluna] == 0)
	{
		tabuleiro_temporario[linha + k][coluna] += 20;
		k++;
	}
	if ((linha + k) < 8 && tabuleiro[linha + k][coluna] < 0)
	{
		tabuleiro_temporario[linha + k][coluna] += 50;
	}
	k = 1;
	while ((linha - k) >= 0 && tabuleiro[linha - k][coluna] == 0)
	{
		tabuleiro_temporario[linha - k][coluna] += 20;
		k++;
	}
	if ((linha - k) >= 0 && tabuleiro[linha - k][coluna] < 0)
	{
		tabuleiro_temporario[linha - k][coluna] += 50;
	}
	k = 1;
	while ((coluna - k) >= 0 && tabuleiro[linha][coluna - k] == 0)
	{
		tabuleiro_temporario[linha][coluna - k] += 20;
		k++;
	}
	if ((coluna - k) >= 0 && tabuleiro[linha][coluna - k] < 0)
	{
		tabuleiro_temporario[linha][coluna - k] += 50;
	}
	k = 1;
	while ((coluna + k) < 8 && tabuleiro[linha][coluna + k] == 0)
	{
		tabuleiro_temporario[linha][coluna + k] += 20;
		k++;
	}
	if ((coluna + k) < 8 && tabuleiro[linha][coluna + k] < 0)
	{
		tabuleiro_temporario[linha][coluna + k] += 50;
	}
}

void rainha_branca(int tabuleiro[8][8], int tabuleiro_temporario[8][8], int linha, int coluna)
{
	torre_branca(tabuleiro, tabuleiro_temporario, linha, coluna);
	bispo_branco(tabuleiro, tabuleiro_temporario, linha, coluna);
}

void rei_branco(int tabuleiro[8][8], int tabuleiro_temporario[8][8], int linha, int coluna)
{
	if ((linha + 1) < 8 && tabuleiro[linha + 1][coluna] == 0)
	{
		tabuleiro_temporario[linha + 1][coluna] += 20;
	}
	if ((linha + 1) < 8 && tabuleiro[linha + 1][coluna] < 0)
	{
		tabuleiro_temporario[linha + 1][coluna] += 50;
	}
	if ((linha + 1) < 8 && (coluna + 1) < 8 && tabuleiro[linha + 1][coluna + 1] == 0)
	{
		tabuleiro_temporario[linha + 1][coluna + 1] += 20;
	}
	if ((linha + 1) < 8 && (coluna + 1) < 8 && tabuleiro[linha + 1][coluna + 1] < 0)
	{
		tabuleiro_temporario[linha + 1][coluna + 1] += 50;
	}
	if ((coluna + 1) < 8 && tabuleiro[linha][coluna + 1] == 0)
	{
		tabuleiro_temporario[linha][coluna + 1] += 20;
	}
	if ((coluna + 1) < 8 && tabuleiro[linha][coluna + 1] < 0)
	{
		tabuleiro_temporario[linha][coluna + 1] += 50;
	}
	if ((coluna + 1) < 8 && (linha - 1) >= 0 && tabuleiro[linha - 1][coluna + 1] == 0)
	{
		tabuleiro_temporario[linha - 1][coluna + 1] += 20;
	}
	if ((coluna + 1) < 8 && (linha - 1) >= 0 && tabuleiro[linha - 1][coluna + 1] < 0)
	{
		tabuleiro_temporario[linha - 1][coluna + 1] += 50;
	}
	if ((linha - 1) >= 0 && tabuleiro[linha - 1][coluna] == 0)
	{
		tabuleiro_temporario[linha - 1][coluna] += 20;
	}
	if ((linha - 1) >= 0 && tabuleiro[linha - 1][coluna] < 0)
	{
		tabuleiro_temporario[linha - 1][coluna] += 50;
	}
	if ((linha - 1) >= 0 && (coluna - 1) >= 0 && tabuleiro[linha - 1][coluna - 1] == 0)
	{
		tabuleiro_temporario[linha - 1][coluna - 1] += 20;
	}
	if ((linha - 1) >= 0 && (coluna - 1) >= 0 && tabuleiro[linha - 1][coluna - 1] < 0)
	{
		tabuleiro_temporario[linha - 1][coluna - 1] += 50;
	}
	if ((coluna - 1) >= 0 && tabuleiro[linha][coluna - 1] == 0)
	{
		tabuleiro_temporario[linha][coluna - 1] += 20;
	}
	if ((coluna - 1) >= 0 && tabuleiro[linha][coluna - 1] < 0)
	{
		tabuleiro_temporario[linha][coluna - 1] += 50;
	}
	if ((coluna - 1) >= 0 && (linha + 1) < 8 && tabuleiro[linha + 1][coluna - 1] == 0)
	{
		tabuleiro_temporario[linha + 1][coluna - 1] += 20;
	}
	if ((coluna - 1) >= 0 && (linha + 1) < 8 && tabuleiro[linha + 1][coluna - 1] < 0)
	{
		tabuleiro_temporario[linha + 1][coluna - 1] += 50;
	}
}

void IniciaTabuleiro(int tabuleiro[8][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			tabuleiro[i][j] = 0;
		}
	}
	tabuleiro[7][0] = -4;
	tabuleiro[7][1] = -2;
	tabuleiro[7][2] = -3;
	tabuleiro[7][3] = -5;
	tabuleiro[7][4] = -6;
	tabuleiro[7][5] = -3;
	tabuleiro[7][6] = -2;
	tabuleiro[7][7] = -4;
	tabuleiro[6][0] = -1;
	tabuleiro[6][1] = -1;
	tabuleiro[6][2] = -1;
	tabuleiro[6][3] = -1;
	tabuleiro[6][4] = -1;
	tabuleiro[6][5] = -1;
	tabuleiro[6][6] = -1;
	tabuleiro[6][7] = -1;
	tabuleiro[1][0] = 1;
	tabuleiro[1][1] = 1;
	tabuleiro[1][2] = 1;
	tabuleiro[1][3] = 1;
	tabuleiro[1][4] = 1;
	tabuleiro[1][5] = 1;
	tabuleiro[1][6] = 1;
	tabuleiro[1][7] = 1;
	tabuleiro[0][0] = 4;
	tabuleiro[0][1] = 2;
	tabuleiro[0][2] = 3;
	tabuleiro[0][3] = 5;
	tabuleiro[0][4] = 6;
	tabuleiro[0][5] = 3;
	tabuleiro[0][6] = 2;
	tabuleiro[0][7] = 4;
}

void mostra_jogo(int tabuleiro[8][8])
{
	printf("\n\n\n\n\n");
	for (int i = 7; i > -1; i--)
	{
		printf("\t\t\t\t\t\t%d ", i);
		for (int j = 0; j < 8; j++)
		{
			if (tabuleiro[i][j] == 0)
			{
				printf("|  ");
			}
			else if (tabuleiro[i][j] < 0 && tabuleiro[i][j])
			{
				printf("|%d", tabuleiro[i][j]);
			}
			else if (tabuleiro[i][j] > 0 && tabuleiro[i][j] < 10)
			{
				printf("| %d", tabuleiro[i][j]);
			}
			else if (tabuleiro[i][j] > 15 && tabuleiro[i][j] < 30)
			{
				printf("|");
				printf(AZUL " O" RESET);
			}
			else if (tabuleiro[i][j] > 40 && (tabuleiro[i][j] - 50) < 0)
			{
				printf("|");
				printf(ROXO "%d" RESET, (tabuleiro[i][j] - 50));
			}
			else if (tabuleiro[i][j] > 40 && (tabuleiro[i][j] - 50) > 0)
			{
				printf("|");
				printf(ROXO " %d" RESET, (tabuleiro[i][j] - 50));
			}
		}
		printf("|\n\t\t\t\t\t\t  -------------------------\n");
	}
	printf("\t\t\t\t\t\t    0  1  2  3  4  5  6  7\n");
}

int possibilidades(int linha, int coluna, int elemento, int tabuleiro[8][8], int tabuleiro_temporario[8][8])
{

	switch (elemento)
	{
	case 1:
		peao_branco(tabuleiro, tabuleiro_temporario, linha, coluna);
		break;
	case 2:
		cavalo_branco(tabuleiro, tabuleiro_temporario, linha, coluna);
		break;
	case 3:
		bispo_branco(tabuleiro, tabuleiro_temporario, linha, coluna);
		break;
	case 4:
		torre_branca(tabuleiro, tabuleiro_temporario, linha, coluna);
		break;
	case 5:
		rainha_branca(tabuleiro, tabuleiro_temporario, linha, coluna);
		break;
	case 6:
		rei_branco(tabuleiro, tabuleiro_temporario, linha, coluna);
		break;
	case -1:
		peao_preto(tabuleiro, tabuleiro_temporario, linha, coluna);
		break;
	case -2:
		cavalo_preto(tabuleiro, tabuleiro_temporario, linha, coluna);
		break;
	case -3:
		bispo_preto(tabuleiro, tabuleiro_temporario, linha, coluna);
		break;
	case -4:
		torre_preta(tabuleiro, tabuleiro_temporario, linha, coluna);
		break;
	case -5:
		rainha_preta(tabuleiro, tabuleiro_temporario, linha, coluna);
		break;
	case -6:
		rei_preto(tabuleiro, tabuleiro_temporario, linha, coluna);
		break;
	}

	int verifica = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (tabuleiro_temporario[i][j] > 6)
			{
				verifica = 1;
				break;
			}
		}
	}
	system("cls");
	mostra_jogo(tabuleiro_temporario);

	return verifica;
}

int mover(int linhaDe, int colunaDe, int linhaPara, int colunaPara, int tabuleiro[8][8])
{
	int fim = 0;
	if (tabuleiro[linhaPara][colunaPara] == 6)
	{
		fim = -1;
	}
	else if (tabuleiro[linhaPara][colunaPara] == -6)
	{
		fim = 1;
	}
	tabuleiro[linhaPara][colunaPara] = tabuleiro[linhaDe][colunaDe];
	tabuleiro[linhaDe][colunaDe] = 0;
	return fim;
}

void jogo(int tabuleiro[8][8])
{
	int tabuleiro_temporario[8][8];
	setlocale(LC_ALL, "Portuguese");
	typedef struct
	{
		int linhaDe, colunaDe, linhaPara, colunaPara;
	} jogada;
	mostra_jogo(tabuleiro);
	jogada player1;
	printf("\nQual peça você quer mover?(Informe a linha e em seguida a  coluna):\n");
	scanf("%d", &player1.linhaDe);
	fflush(stdin);
	scanf("%d", &player1.colunaDe);
	while ((player1.linhaDe < 0 || player1.linhaDe > 7 ||
					player1.colunaDe < 0 || player1.colunaDe > 7) ||
				 tabuleiro[player1.linhaDe][player1.colunaDe] == 0)
	{
		printf("Digite outra posição:\n");
		fflush(stdin);
		scanf("%d", &player1.linhaDe);
		scanf("%d", &player1.colunaDe);
	};
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			tabuleiro_temporario[i][j] = tabuleiro[i][j];
		}
	}
	int resposta = possibilidades(player1.linhaDe, player1.colunaDe, tabuleiro[player1.linhaDe][player1.colunaDe], tabuleiro, tabuleiro_temporario);
	if (resposta == 1)
	{
		printf("Suas possibilidades estão marcadas no tabuleiro, escolha uma delas(Informe a linha e em seguida a  coluna):\n");

		scanf("%d", &player1.linhaPara);

		fflush(stdin);
		scanf("%d", &player1.colunaPara);

		while (
				(player1.linhaPara < 0 || player1.linhaPara > 7 ||
				 player1.colunaPara < 0 || player1.colunaPara > 7) ||
				tabuleiro_temporario[player1.linhaPara][player1.colunaPara] < 7)
		{
			printf("Faça um movimento válido.\n");

			fflush(stdin);
			scanf("%d", &player1.linhaPara);
			scanf("%d", &player1.colunaPara);
		}
		system("cls");
		int fim = mover(player1.linhaDe, player1.colunaDe, player1.linhaPara, player1.colunaPara, tabuleiro);
		if (fim == 0)
		{
			jogo(tabuleiro);
		}
		else if (fim == -1)
		{
			mostra_jogo(tabuleiro);
			printf("\nFim de Jogo\nVencedor:Player2");
		}
		else if (fim == 1)
		{
			mostra_jogo(tabuleiro);
			printf("\nFim de Jogo\nVencedor:Player1");
		}
	}
	else if (resposta == 0)
	{
		system("cls");
		printf("Não há jogadas possíveis para esta peça.\n");
		jogo(tabuleiro);
	}
}

int main()
{
	int tabuleiro[8][8];
	IniciaTabuleiro(tabuleiro);
	jogo(tabuleiro);
	return 0;
}
