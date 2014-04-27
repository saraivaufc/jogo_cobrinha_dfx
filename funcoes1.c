/*
 * funcoes1.c
 * 
 * Criado por Ciano Saraiva <saraiva.ufc@gmail.com>
 * 
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "dfx.h"
#include "desenhos.h"
#include "funcoes2.h"
#include "funcoes1.h"

extern char * des_comida;
extern char * des_comida_2;
extern char * nodo_horizontal;
extern char * nodo_vertical;
extern char * nodo_cabeca_baixo;
extern char * nodo_cabeca_cima;
extern char * nodo_cabeca_direita;
extern char * nodo_cabeca_esquerda;
extern char * nodo_rabo_baixo;
extern char * nodo_rabo_cima;
extern char * nodo_rabo_direita;
extern char * nodo_rabo_esquerda;
extern char * parede_horizontal;
extern char * parede_vertical;
extern char * vazio;
extern char * bloco;

extern int speed;
extern int tempo;
extern int sair;
extern int venceu;

char c;
char forma_cobra;
Cobra *naja;
Comida **comida;
Projetil *bala;

//prototipos das Funcoes
int cobra_bateu_cobra(Cobra *naja);
Comida *cobra_comeu(Cobra *cobra, Comida **comida);
int colidiu_parede(Cobra *naja);
Comida * cria_comida(Comida *aux , Cobra *naja);
void cria_parede();
Cobra *insere_no_fim(Cobra *atual);
void desenha_cobra(Cobra *cobra);
void desenha_comida(Comida ** comida);
void fim_do_jogo(void);
void inicializa_jogo();
Cobra *insere_na_frente(Cobra *atual,char c);
Cobra *insere_no_fim(Cobra *atual);
char recebe_comando(char x);
Cobra * remove_no_fim(Cobra * atual);


Cobra *insere_na_frente(Cobra *atual,char c)
{
	Cobra *novo=(Cobra *) malloc (sizeof(Cobra));
	novo->x = atual->x; novo->y = atual->y;
	novo->x_a = atual->x_a; novo->y_a = atual->y_a;
	if(c == TECLA_UP)
	{
		novo->y--;
		novo->forma='A';
	}
	if(c == TECLA_DOWN)
	{
		novo->y++;
		novo->forma='V';
	}
	if(c == TECLA_RIGHT)
	{
		novo->x++;
		novo->forma='>';
	}
	if(c == TECLA_LEFT)
	{
		novo->x--;
		novo->forma='<';
	}
	novo->prox=atual;
	return novo;
}

int colidiu_parede(Cobra *naja)
{
	if(naja->x == Largura_inicial || naja->y == Altura_inicial || naja->x== Largura || naja->y == Altura)
	{
		return 1;
	}else return 0;
}

Cobra *insere_no_fim(Cobra *atual)
{
	Cobra *novo=(Cobra *) malloc(sizeof (Cobra));
	Cobra *aux=atual;
	while(aux->prox != NULL)
	{
		aux=aux->prox;
	}
	novo->x=aux->x_a;
	novo->y=aux->y_a;
	novo->x_a=aux->x_a;
	novo->y_a=aux->y_a;
	aux->prox=novo;
	novo->prox=NULL;
	return atual;
}

void desenha_cobra(Cobra *cobra)
{
	//Desenho a cabeca
	movexy(cobra->x, cobra->y);
	if(c == TECLA_DOWN)
		dpixel(nodo_cabeca_baixo);
	if(c == TECLA_UP)
		dpixel(nodo_cabeca_cima);
	if(c == TECLA_RIGHT)
		dpixel(nodo_cabeca_direita);
	if(c == TECLA_LEFT)
		dpixel(nodo_cabeca_esquerda);

	if(cobra->prox == NULL) //caso a cobra tenha apenas a cabeca
		return;

	Cobra *aux=cobra;
	aux=aux->prox;
	for( ; aux != NULL ; aux = aux->prox) //desenha corpo
	{
		movexy(aux->x,aux->y);
		if(c == TECLA_DOWN || c == TECLA_UP)
			dpixel(nodo_vertical);
		if(c == TECLA_LEFT || c == TECLA_RIGHT)
			dpixel(nodo_horizontal);
	}
}

void inicializa_jogo()
{
	criar_janela(x_janeja,y_janela , "Cobrinha");
	set_fundo('W');
	limpar_tela();
	repintar();
	naja=(Cobra *) malloc (sizeof (Cobra));
	naja->x=Largura_inicial+1;
	naja->y=Altura_inicial+1;
	naja->x_a=Largura_inicial+1;
	naja->y_a=Altura_inicial+1;
	naja->prox=NULL;
	bala=(Projetil *) malloc (sizeof (Projetil));
	comida=(Comida **) malloc (2* sizeof (Comida*));
	fori(i,2)
	{
		comida[i]=(Comida *) malloc (sizeof(Comida));
	}
	bala->existe=0;
	c=TECLA_DOWN;
	for(int i=0 ; i< Tamanho_Inicial_Cobra ; i++)
	{
		naja=insere_na_frente(naja,c);
	}
	fori(i,2)
	{
		comida[i]=cria_comida(comida[i], naja);
	}
}

char recebe_comando(char x)
{
	char c;
	while(tecla_pressionada())
	{
		c=get_tecla();
	}

	if(c == TECLA_DOWN || c == TECLA_UP || c == TECLA_LEFT || c == TECLA_RIGHT )
	{
		if( (x == TECLA_DOWN && c == TECLA_UP) || (c == TECLA_DOWN && x == TECLA_UP))
			c=x;
		if((x == TECLA_LEFT && c == TECLA_RIGHT) || (c == TECLA_LEFT && x == TECLA_RIGHT))
			c=x;
		return c;
	}else
		if(c == TECLA_SHIFT_L || c == TECLA_CONTROL)
			atualiza_speed(&speed,c);
		else
			if((int) c == 32)  //tecla espaço
			{
				tempo=tempo-5;
				bala=mata_bala(bala);
				bala=cria_bala(bala,naja);
				forma_cobra=naja->forma;
			}else
				if((int) c == 27) //tecla ESCAPE
					sair=1;
	return x;

}

Cobra * remove_no_fim(Cobra * atual)
{
	Cobra *anterior;
	Cobra *proxima=atual;
	while(proxima->prox != NULL)
	{
		anterior=proxima;
		proxima=proxima->prox;
	}
	movexy(proxima->x, proxima->y);
	dpixel(vazio);

	free(proxima);
	
	anterior->prox=NULL;
	return atual;
}

void cria_parede()
{
	for(int i=Largura_inicial; i<=Largura ; i++)
	{
		for(int k=Altura_inicial ; k<=Altura ; k++)
		{
			if(i == Largura_inicial || i == Largura)
			{
				movexy(i,k);
				dpixel(parede_vertical);
			}
			if(k==Altura_inicial || k== Altura)
			{
				movexy(i,k);
				dpixel(parede_horizontal);
			}
		}
	}
}

Comida * cria_comida(Comida *aux, Cobra * naja)
{
		do
		{
			aux->x=(int) (rand() % (Largura-Largura_inicial)-1) + Largura_inicial+1;
			aux->y=(int) (rand() % (Altura-Altura_inicial  )-1) + Altura_inicial+1;
			aux->tipo=(int) rand() % 2;
		}while(comida_bateu_cobra(naja,aux) || comida_bateu_parede(aux) );
	return aux;
}

void desenha_comida(Comida ** comida)
{
	fori(i,2)
	{
		movexy(comida[i]->x, comida[i]->y);
		if(comida[i]->tipo == 0)
			dpixel(des_comida);
		else
			dpixel(des_comida_2);
	}
}

Comida *cobra_comeu(Cobra *cobra, Comida **comida)
{
	fori(i,2)
	{
		if(cobra->x == comida[i]->x && cobra->y == comida[i]->y)
		{
			return comida[i];
		}
	}
	return NULL;
}

void fim_do_jogo(void)
{
	for(int i=0 ; i<5 ; i++)
	{
		system("aplay Sons/Bateu.wav&");
		usleep(100000);
	}
	limpar_tela();
	repintar();
	int x_meio=(x_janeja/10)/2;
	int y_meio=(y_janela/10)/2;
	set_cor('c');
	animacao_final(0 , 0 , x_janeja/10-1 , y_janela/10-1,x_meio,y_meio);
	movexy(30,30);
	set_cor('r');
	ampliar(2,2);
	dtexto("          Perdeu!!!\n  Pressione ENTER para Sair...");
	repintar();
	char aux;
	do
	{
		aux=get_tecla();
	}while(aux != TECLA_ENTER);
	printf("%c",aux);
	sair=1;
	venceu=0;
}

int cobra_bateu_cobra(Cobra *naja)
{
		int x,y;
		x=naja->x;
		y=naja->y;
		Cobra *aux=naja;
		do
		{
			aux=aux->prox;
			if(x == aux->x && y == aux->y)
			{
				return 1;
			}
		}while(aux->prox != NULL);
	return 0;
}
