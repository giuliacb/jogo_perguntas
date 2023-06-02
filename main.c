#include <stdio.h>
#include <stdlib.h>
#include "json-c/json-c/json.h"

//const int jogadores_max = 6;
//int pontuacao[jogadores_max];

typedef struct jogador{
int pontos;
char nome [50];
}t_jogador;

t_jogador *criar_jogador(int pontos, int nome, int i) {
  t_jogador *jogador;
  jogador = malloc(sizeof(t_jogador));
  if(jogador != NULL) {
    jogador->pontos = pontos;
    jogador->nome[i] = nome;
  }
  return jogador;
}

typedef struct pergunta{
char questao[500];
char item_a[500];
char item_b[500];
char item_c[500];
char item_d[500];
char gabarito;
int tentativas;
char categoria[100];
} t_pergunta;

typedef struct no{
t_pergunta pergunta;
struct no *prox;
}t_no_pergunta;

void novo_jogo() {
  printf("Bem vindos ao jogo Quest!\n");
  printf("Escolha uma das seguintes categorias:\n\n");
  int op;
  
    printf("1- HISTÓRIA\n");
    printf("2- GEOGRAFIA\n");
    printf("3- CIÊNCIAS\n");
    printf("4- ARTES\n");
    printf("5- CINEMA\n");
    printf("6- GERAL\n");
    printf("OPÇÃO: ");
    scanf("%d%*c",&op);
}

void exibir_creditos() {
  printf("Nome do projeto: QUEST\n");
  printf("Integrantes:\n Integrante 1: Bruno Carvalho \n Integrante 2: Giulia Campelo Bezerra \n Integrante 3: João Pedro \n Integrante 4: João  ");
  printf("Professor: Daniel Souza\n");
}

void placar() {
  printf("Quest - placar!\n");
  //?????
}

void inicio() {
  int opcao;
  do {
    printf("1 - NOVO JOGO\n");
    printf("2 - EXIBIR CRÉDITOS\n");
    printf("3 - PLACAR\n");
    printf("4 - SAIR\n");
    printf("OPÇÃO: ");
    scanf("%d%*c", &opcao);

    switch(opcao) {
      default:
        printf("Opção inválida!\n");
        break;
      case 1:
        novo_jogo();
        break;
      case 2:
        exibir_creditos();
      case 3:
        placar();
      case 4: break;
    }
    getchar();
  } while(opcao != 4);
}

int main() {
    FILE *fp;
    char buffer[2048];

    struct json_object *parsed_json;
    struct json_object *id;
    struct json_object *pergunta;
    struct json_object *item_a;
    struct json_object *item_b;
    struct json_object *item_c;
    struct json_object *item_d;
    struct json_object *gabarito;
    struct json_object *categoria;

    size_t n_perguntas;
    size_t i;

    fp = fopen("../data.json", "r");
    fread(buffer, 2048, 120, fp);
    fclose(fp);

    parsed_json = json_tokener_parse(buffer);

    json_object_object_get_ex(parsed_json, "id", &id);
    json_object_object_get_ex(parsed_json, "pergunta", &pergunta);
    json_object_object_get_ex(parsed_json, "item_a", &item_a);
    json_object_object_get_ex(parsed_json, "item_b", &item_b);
    json_object_object_get_ex(parsed_json, "item_c", &item_c);
    json_object_object_get_ex(parsed_json, "item_d", &item_d);
    json_object_object_get_ex(parsed_json, "gabarito", &gabarito);
    json_object_object_get_ex(parsed_json, "categoria", &categoria);

    int tst_id;
    //int id;
    printf("insira o id da pergunta:\n");
    scanf("%d", &tst_id);
    //json_object_get_int(id);
    printf("Pergunta: %s\n\n, \
    Item A: %s\n, Item B: %s\n, Item C: %s\n, Item D: %s\n, \
    Gabarito: %s\n, Categoria:%s\n", \
    json_object_get_string(pergunta),  \
    json_object_get_string(item_a), json_object_get_string(item_b), \
    json_object_get_string(item_c), json_object_get_string(item_d), \
    json_object_get_string(gabarito), json_object_get_string(categoria));

    return 0;
}