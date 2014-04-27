/*
 * funcoes2.h
 * 
 * Criado por Ciano Saraiva <saraiva.ufc@gmail.com>
 * 
 */
 
#include "funcoes1.h"
#ifndef FUNCOES2_H
#define FUNCOES2_H

#define fori(a,b) for(int a=0 ; a<b ; a++)

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

void desenha_pontos(int pontos);

void desenha_tempo(int tempo);

void ganhou_jogo(void); 

#endif










