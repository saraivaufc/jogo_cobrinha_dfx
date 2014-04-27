/*
 * Cobrinha.c
 *
 * Criado por Ciano Saraiva <saraiva.ufc@gmail.com>
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "dfx.h"
#include "funcoes1.h"
#include "funcoes2.h"
#include "desenhos.h"

extern char c;
extern Cobra *naja;
extern Comida **comida;
extern Projetil *bala;
extern char forma_cobra;

FILE *record;

int speed;
int sair=0;
int pontos=0;
int pontos_alterou=1;

int pontuacao_atual;
int venceu=0;

struct tm *DataAtual;
time_t segundos;
int tempo=60;
int tempo_real=0;
int tempo_atual=0;
int tempo_anterior=0;
int tempo_musical=0;

int obtem_segundo(time_t segundos)
{
	time(&segundos);
	DataAtual = localtime(&segundos);
	return(DataAtual->tm_sec);
}

int main()
{
	record=fopen("Record.txt","r");
	fscanf(record,"%d",&pontuacao_atual);
	fclose(record);
	record=fopen("Record.txt","w+");

	srand(time(NULL));
	inicializa_jogo();
	instrucoes();
	cria_parede();
	speed=100000;

	Comida * buffer;
	while(1)
	{
		tempo_anterior=tempo_atual;
		tempo_atual=obtem_segundo(segundos);
		if(tempo_atual  != tempo_anterior)
		{
			tempo_real++;
			tempo_musical++;
			tempo--;
			desenha_tempo(tempo);
			if(tempo <= 0)
			{
				fim_do_jogo();
				break;
			}
		}
		if(tempo_musical == 23){
			system("aplay Sons/Rock.wav&");
			tempo_musical=0;
		}
		if(pontos >= 10)
		{
			ganhou_jogo();
			break;
		}
		if(tecla_pressionada())
		{
			c=recebe_comando(c);
		}
		if(sair)
		{
			break;
		}
		if(colidiu_parede(naja))
		{
			fim_do_jogo();
			break;
		}
		if(cobra_bateu_cobra(naja))
		{
			fim_do_jogo();
			break;
		}

		buffer=cobra_comeu(naja,comida);
		if(buffer != NULL) //se Cobra comeu Comida
		{
			pontos_alterou=1;
			usleep(100000);
			if(comida_ruim(buffer))
			{
				pontos--;
				system("aplay Sons/Bateu.wav&");
				if(possui_um_nodo(naja))
				{
					fim_do_jogo();
					break;
				}else
					naja=remove_no_fim(naja);
			}else
			{
				pontos++;
				tempo=tempo+5;
				system("aplay Sons/Comeu.wav&");
				naja=insere_no_fim(naja);
			}
			buffer=cria_comida(buffer,naja);
		}
		buffer=bala_atinge_comida(bala,comida);
		if(bala->existe)
		{
			if(buffer != NULL)  // Bala atingiu Comida
			{
				system("aplay Sons/Comeu.wav&");
				buffer=cria_comida(buffer,naja);
				bala=mata_bala(bala);
			}else
			{
				if(bala_bateu_parede(bala))
				{
					bala=mata_bala(bala);
				}else
				{
					bala=atualiza_bala(bala,forma_cobra);
					desenha_bala(bala);
				}
			}
		}

		naja=insere_na_frente(naja,c);
		if(pontos_alterou)
		{
			desenha_pontos(pontos);
			pontos_alterou=0;
		}
		desenha_cobra(naja);
		naja=remove_no_fim(naja);
		desenha_comida(comida);
		usleep(speed);
	}
	if(venceu)
	{
		if(pontuacao_atual > tempo_real)
			fprintf(record,"%d",pontuacao_atual);
		else
			fprintf(record,"%d",tempo_real);
	}else
		fprintf(record,"%d",pontuacao_atual);
	fclose(record);
	return 0;
}









