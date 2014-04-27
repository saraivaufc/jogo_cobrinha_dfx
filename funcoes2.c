/*
 * funcoes2.c
 * 
 * Criado por Ciano Saraiva <saraiva.ufc@gmail.com>
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "funcoes1.h"
#include "dfx.h"
#include "desenhos.h"

extern char * bloco;
extern char *bloco_grande;
extern char *parede_horizontal;
extern char *parede_vertical;
extern char * bala_baixo;
extern char * bala_cima;
extern char * bala_esquerda;
extern char * bala_direita;
extern char *vazio;
extern Cobra *naja;
extern Projetil *bala;
extern int pontos;
extern int venceu;

extern FILE * record;
extern int pontuacao_atual;
extern int tempo_real;

//Prototipo das Funcoes
int comida_bateu_cobra(Cobra *naja, Comida *maca);
int comida_bateu_parede(Comida *maca);
void animacao_final(int x_inicial, int y_inicial, int x_final, int y_final, int ponto_x, int ponto_y);
void atualiza_speed(int *speed , char c);
void instrucoes(void);
int comida_ruim(Comida *comida);
int possui_um_nodo(Cobra *naja);
Projetil * cria_bala(Projetil *bala, Cobra * naja);
void desenha_bala(Projetil * bala);
Comida * bala_atinge_comida(Projetil * bala ,Comida ** comida);
Projetil *mata_bala(Projetil *bala);
Projetil *atualiza_bala(Projetil * bala,char c);
int bala_bateu_parede(Projetil * bala);

int comida_bateu_cobra(Cobra *naja, Comida *maca)
{
	for(Cobra * aux=naja ; aux->prox != NULL ; aux=aux->prox)
	{
		if(maca->x == aux->x && maca->y == aux->y)
			return 1;
	}
	return 0;
}


int comida_bateu_parede(Comida *maca)
{
	if(maca->x == Largura || maca->x == Largura_inicial || maca->y == Altura || maca->y == Altura_inicial)
		return 1;
	else
		return 0;
}

void animacao_final(int x_inicial, int y_inicial, int x_final, int y_final, int ponto_x, int ponto_y)
{
	for(int i=y_final ; i>y_inicial ; i--)
	{
		movexy(x_inicial,i);
		dpixel(bloco);
	}
	for(int i= x_inicial ; i< x_final ; i++)
	{
		movexy(i,y_inicial);
		dpixel(bloco);
	}
	for(int i=y_inicial ; i<y_final ; i++)
	{
		movexy(x_final,i);
		dpixel(bloco);
	}
	for(int i= x_final ; i>x_inicial ; i--)
	{
		movexy(i,y_final);
		dpixel(bloco);
	}
	usleep(100000);
	if(x_inicial == ponto_x || y_inicial == ponto_y)
		return ;
	animacao_final(x_inicial+1,y_inicial+1,x_final-1,y_final-1,ponto_x,ponto_y);
}

void atualiza_speed(int *speed ,char c)
{
	if(c == TECLA_SHIFT_L)
		*speed=10000;
	if(c == TECLA_CONTROL)
		*speed=100000;
}

void instrucoes()
{
	set_fundo('W');
	limpar_tela();
	repintar();
	movexy(1,1);
	ampliar(3,3);
	set_cor('r');
	dtexto("Instrucoes:");
	ampliar(2,2);
	movexy(1,3);
	ampliar(2,2);
	dtexto("\n\n-Use as Setas para movimentar a Cobra! \n\n-As teclas Shift_E e Ctrl_E use para aumentar ou \n diminuir a velocidade da Cobra!\n\n-Pressione ESPACE para atirar!\n\n-Voce ganha 5 seg para cada fruta verde comida!\n\n-Voce perde 5 seg para cada tiro efetuado!\n\n-Voce ganha 1 Ponto para cada Fruta verde comida!\n\n-Voce Perde 1 Ponto para cada Fruta vermelha comida!\n\n-Objetivo: Atingir 10 pontos antes que o tempo acabe!\n\n-Voce Perde caso a Cobra bata na Parede,nela mesma,\n comendo uma fruta vermelha tendo apenas uma parte\n ou o tempo termine!\n\nPressione Qualquer Tecla pra Comercar...");
	char aux=get_tecla();
	printf("%c",aux);
	system("aplay Sons/Rock.wav&");
	limpar_tela();
	ampliar(1,1);
	set_fundo('W');
	limpar_tela();
	repintar();
}

int comida_ruim(Comida *comida)
{
	if(comida->tipo)
		return 1;
	else
		return 0;
}

int possui_um_nodo(Cobra *naja)
{
	int cont=0;
	for(Cobra *aux=naja ; aux != NULL ; aux=aux->prox)
	{
		cont++;
	}
	if(cont == 2)
		return 1;
	else
		return 0;
}


int bala_existe(Projetil *bala)
{
	if(bala->existe)
		return 1;
	else
		return 0;
}

Projetil * cria_bala(Projetil * bala, Cobra * naja)
{
	bala->forma=naja->forma;
	bala->x=naja->x; bala->y=naja->y;
	bala->existe=1;
	return bala;
}

void desenha_bala(Projetil * bala)
{
	movexy(bala->x_a, bala->y_a);
	dpixel(vazio);
	movexy(bala->x, bala->y);
	if(bala->forma == '>') dpixel(bala_direita);
	if(bala->forma == '<') dpixel(bala_esquerda);
	if(bala->forma == 'A') dpixel(bala_cima);
	if(bala->forma == 'V') dpixel(bala_baixo);
	
}

Comida * bala_atinge_comida(Projetil * bala ,Comida ** comida)
{
	fori(i,2)
	{
		if(bala->x == comida[i]->x && bala->y == comida[i]->y)
			return comida[i];
	}
	return NULL;
}

Projetil *mata_bala(Projetil *bala)
{
	movexy(bala->x, bala->y);
	if(bala_bateu_parede(bala))
	{
		if(bala->x == Largura || bala->x == Largura_inicial)
		{
			dpixel(parede_horizontal);
		}else
			dpixel(parede_vertical);
	}
	else
		dpixel(vazio);
	movexy(bala->x_a, bala->y_a);
	dpixel(vazio);
	bala->existe=0;
	return bala;
}

Projetil *atualiza_bala(Projetil * bala,char c)
{
	bala->x_a=bala->x;
	bala->y_a=bala->y;
	if(c == '>') bala->x++;
	if(c == '<') bala->x--;
	if(c == 'A') bala->y--;
	if(c == 'V') bala->y++;
	return bala;
}


int bala_bateu_parede(Projetil * bala)
{
	if(bala->x == Largura_inicial || bala->x == Largura || bala->y == Altura_inicial || bala->y == Altura)
		return 1;
	else
		return 0;
}

void desenha_pontos(int pontos)
{
	for(int i=28 ; i <= 32 ; i++ )
	{
		movexy(i,3);
		set_cor('W');
		ampliar(3,3);
		dpixel(bloco);
		ampliar(1,1);
	}
	movexy(1,3);
	set_cor('r');
	ampliar(3,3);
	dtexto("Pontos = %d",pontos);
	ampliar(1,1);
}

void desenha_tempo(int tempo)
{
	for(int i=108 ; i <= 118 ; i++ )
	{
		movexy(i,3);
		ampliar(3,3);
		set_cor('W');
		dpixel(bloco);
		ampliar(1,1);
	}
	movexy(90,3);
	set_cor('r');
	ampliar(3,3);
	dtexto("Tempo:%d", tempo);
	ampliar(1,1);
}

void ganhou_jogo(void)
{
	venceu=1;
	limpar_tela();
	repintar();
	int x_meio=(x_janeja/10)/2;
	int y_meio=(y_janela/10)/2;
	set_cor('c');
	animacao_final(0 , 0 , x_janeja/10-1 , y_janela/10-1,x_meio,y_meio);
	movexy(30,30);
	set_cor('g');
	ampliar(2,2);
	dtexto("      Parabens, Voce Venceu!\n      Sua Pontuacao:%d\n      Recorde Anterior:%d\n		Pressione ENTER para Sair...",tempo_real,pontuacao_atual);
	repintar();
	char aux;
	do
	{
		aux=get_tecla();
	}while(aux != TECLA_ENTER);
	printf("%c",aux);
}
