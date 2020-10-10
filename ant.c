#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#define ESQUERDA  0
#define CIMA      1
#define DIREITA   2
#define BAIXO     3


typedef struct
{
	int x;
	int y;
	int dir;
} ANT;

int **aloca_matriz(int lin, int col);
void proximo_passo(ANT *f, int **tabuleiro);
void move_formiga(ANT *f, int **tabuleiro, int lin, int col);
void imprime_tabuleiro(int **tabuleiro, int lin, int col);

int
main(int argc, char **argv)
{
	initscr();   /* Inicia a tela    */
	curs_set(0); /* Desliga o cursor */
	
	int lin, col, **tabuleiro, steps = 0;
	ANT fumiga;

	/* Obtem o tamanho da tela */
	getmaxyx(stdscr, lin, col);

	tabuleiro = aloca_matriz(lin, col);

	for (int i = 0; i < lin; i++)
		for (int j = 0; j < col; j++)
			tabuleiro[i][j] = 0;
	

	fumiga.x   = lin/2;
	fumiga.y   = col/2;
	fumiga.dir = ESQUERDA;

	while(1)
	{
		proximo_passo(&fumiga,tabuleiro);
		move_formiga(&fumiga, tabuleiro, lin, col);
		imprime_tabuleiro(tabuleiro, lin, col);
		mvprintw(lin-2, col/2 - 3, "%d", steps++);
		refresh();
		usleep(3333);


	}
	
	/* Encerra a janela do ncurses*/
	endwin();
	return 0;
}



/* 
Aloca o espaço para uma matriz,
não checa os mallocs porque a vida é muito curta pra isso, mas não para escrever esse comentário
desculpa maziero
*/
int**
aloca_matriz(int lin, int col)
{
	int **matriz;
	matriz = malloc(sizeof(int*) * lin);
	for (int i = 0; i < lin; i++)
		matriz[i] = malloc(sizeof(int) * col);
	return matriz;
}

void 
proximo_passo(ANT *f, int **tabuleiro)
{
	if (tabuleiro[f->x][f->y])
	{
		f->dir = (f->dir + 5) % 4;
	} else 
	{
		f->dir = (f->dir + 3) % 4;
	}
}

void 
move_formiga(ANT *f, int **tabuleiro, int lin, int col)
{
	tabuleiro[f->x][f->y] = (tabuleiro[f->x][f->y] + 1) % 2;
	switch(f->dir)
	{
		case ESQUERDA:
			f->x = (f->x + lin - 1) % lin;
		break;
		case DIREITA:
			//f->x += 1;
			f->x = (f->x + lin + 1) % lin;
		break;
		case CIMA:
			//f->y -= 1;
			f->y = (f->y + col - 1) % col;
		break;
		case BAIXO:
			//f->y += 1;
			f->y = (f->y + col + 1) % col;
		break;
	
	}

}


void 
imprime_tabuleiro(int **tabuleiro, int lin, int col)
{
	for (int i = 0; i < lin; i++)
		for (int j = 0; j < col; j++)
			tabuleiro[i][j] ? mvaddch(i,j,' ') : mvaddch(i,j,'#');
}

