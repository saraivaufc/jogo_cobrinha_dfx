/*
 * desenhos.c
 * 
 * Criado por Ciano Saraiva <saraiva.ufc@gmail.com>
 * 
 */


char *nodo_horizontal="\
 KrK KrK  \n\
rKKKrKKKrK\n\
rKKKrKKKrr\n\
rrrrrrrrrr\n\
rrrrrrrrrr\n\
rrrrrrrrrr\n\
rrrrrrrrrr\n\
rKKKrKKKrr\n\
rKKKrKKKrK\n\
 KrK KrK  ";

char *nodo_vertical="\
 KrrrrrrK \n\
 rrrrrrrr \n\
KKKrrrrKKK\n\
rKKrrrrKKr\n\
KKKrrrrKKK\n\
rrrrrrrrrr\n\
KKKrrrrKKK\n\
rKKrrrrKKr\n\
KKKrrrrKKK\n\
 rrrrrrrr ";

char *nodo_cabeca_direita="\
WWrrrr    \n\
WWrrrrr   \n\
KKKKyyrr  \n\
KKKKyyrKr \n\
rrrrrrrrrr\n\
rrrrrrrrrr\n\
KKKKyyrKr \n\
KKKKyyrr  \n\
WWrrrrr   \n\
WWrrrr    ";
char *nodo_cabeca_esquerda="\
    rrrrWW\n\
   rrrrrWW\n\
  rryyKKKK\n\
 rKryyKKKK\n\
rrrrrrrrrr\n\
rrrrrrrrrr\n\
 rKryyKKKK\n\
  rryyKKKK\n\
   rrrrrWW\n\
    rrrrWW";
char *nodo_cabeca_cima="\
    rr    \n\
   rrrr   \n\
  rKrrKr  \n\
 rrrrrrrr \n\
rryyrryyrr\n\
rryyrryyrr\n\
rrKKrrKKrr\n\
rrKKrrKKrr\n\
WWKKrrKKWW\n\
WWKKrrKKWW";
char *nodo_cabeca_baixo="\
WWKKrrKKWW\n\
WWKKrrKKWW\n\
rrKKrrKKrr\n\
rrKKrrKKrr\n\
rryyrryyrr\n\
rryyrryyrr\n\
 rrrrrrrr \n\
  rKrrKr  \n\
   rrrr   \n\
    rr    ";
char *nodo_rabo_direita="\
WWWWWWWrrr\n\
WWWWWWrrKK\n\
WWWWrrKKKK\n\
WWrrrKKKKK\n\
rrKKrrrrrr\n\
rrKKrrrrrr\n\
WWrrrKKKKK\n\
WWWWrrKKKK\n\
WWWWWWrrKK\n\
WWWWWWWrrr";
char *nodo_rabo_esquerda="\
rrrWWWWWWW\n\
KKKrWWWWWW\n\
KKKKrrWWWW\n\
KKKKKrrrWW\n\
rrrrrrKKrr\n\
rrrrrrKKrr\n\
KKKKKrrrWW\n\
KKKKrrWWWW\n\
KKrrWWWWWW\n\
rrrWWWWWWW";
char *nodo_rabo_cima="\
rKKKrrKKKr\n\
rKKKrrKKKr\n\
rrKKrrKKrr\n\
WrKKrrKKrW\n\
WWrKrrKrWW\n\
WWrrrrrrWW\n\
WWWrKKrWWW\n\
WWWrKKrWWW\n\
WWWWrrWWWW\n\
WWWWrrWWWW";
char *nodo_rabo_baixo="\
WWWWrrWWWW\n\
WWWWrrWWWW\n\
WWWrKKrWWW\n\
WWWrKKrWWW\n\
WWrrrrrrWW\n\
WWrKrrKrWW\n\
WrrKrrKrrW\n\
rrKKrrKKrr\n\
rKKKrrKKKr\n\
rKKKrrKKKr";


char *vazio="\
WWWWWWWWWW\n\
WWWWWWWWWW\n\
WWWWWWWWWW\n\
WWWWWWWWWW\n\
WWWWWWWWWW\n\
WWWWWWWWWW\n\
WWWWWWWWWW\n\
WWWWWWWWWW\n\
WWWWWWWWWW\n\
WWWWWWWWWW";
char *des_comida="\
     rrr  \n\
    rr    \n\
  gggggg  \n\
 gggggggg \n\
ggggggWWgg\n\
ggggggWWgg\n\
gggggggWgg\n\
gggggggggg\n\
 gggggggg \n\
  gggggg  ";

char *des_comida_2="\
     ggg  \n\
    gg    \n\
  rrrrrr  \n\
 rrrrrrrr \n\
rrrrrrWWrr\n\
rrrrrrWWrr\n\
rrrrrrrWrr\n\
rrrrrrrrrr\n\
 rrrrrrrr \n\
  rrrrrr  ";



   
char *parede_horizontal="\
rrrWWrrrrW\n\
rrrrWWrrrW\n\
rrrrrWWWWW\n\
WWWWrWWrrr\n\
rrrrrWrrrr\n\
rrWrrWWWWW\n\
WrWWWWWrWW\n\
WrrrWrrrWr\n\
WrrrWrrrWr\n\
WrrrWWWWWr";



char *parede_vertical="\
rrrWrrWrrr\n\
rrrWrrWWrr\n\
rrWWWrWrrr\n\
rWWrWWWrWW\n\
WWrrrrWWWr\n\
WrWrrrrWrr\n\
rrrWWrrrrr\n\
rrrWWWWWrr\n\
rrrWrrrrWW\n\
WWWWrrrWWr";

char *bloco="\
###########\n\
###########\n\
###########\n\
###########\n\
###########\n\
###########\n\
###########\n\
###########\n\
###########\n\
###########";


char *bala_direita="\
           \n\
           \n\
           \n\
 B     B   \n\
 B     BB  \n\
 BBBBBBBBB \n\
 B     BB  \n\
 B     B   \n\
           \n\
           \n\
           ";


char *bala_esquerda="\
           \n\
           \n\
           \n\
   B     B \n\
  BB     B \n\
 BBBBBBBBB \n\
  BB     B \n\
   B     B \n\
           \n\
           \n\
           ";


char *bala_cima="\
           \n\
     B     \n\
    BBB    \n\
   BBBBB   \n\
     B     \n\
     B     \n\
     B     \n\
     B     \n\
     B     \n\
   BBBBB   \n\
           ";


char *bala_baixo="\
           \n\
   BBBBB   \n\
     B     \n\
     B     \n\
     B     \n\
     B     \n\
     B     \n\
   BBBBB   \n\
    BBB    \n\
     B     \n\
           ";

