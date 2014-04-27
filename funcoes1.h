#ifndef FUNCOES1_H
#define FUNCOES1_H

#define Tamanho_Inicial_Cobra 1
#define x_janeja 1220
#define y_janela 660
#define Largura_inicial 16
#define Altura_inicial 10
/*
 * funcoes1.h
 * 
 * Criado por Ciano Saraiva <saraiva.ufc@gmail.com>
 * 
 */

#define Largura 105
#define Altura  60

#define fori(a,b) for(int a=0 ; a<b ; a++)

typedef struct Cobra_
{
	int x, y;
	int x_a,y_a;
	char forma;
	struct Cobra_ *prox;
}Cobra;

typedef struct Comida_
{
	int x,y;
	int tipo;
}Comida;

typedef struct Projetil_{
	int x,y;
	int x_a, y_a;
	char forma;
	int existe;
}Projetil;

int cobra_bateu_cobra(Cobra *naja);

Comida *cobra_comeu(Cobra *cobra, Comida **comida);

int colidiu_parede(Cobra *naja);

Comida * cria_comida(Comida *aux ,Cobra *naja);

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

#endif
