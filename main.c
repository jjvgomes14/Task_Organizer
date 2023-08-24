#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Inclui bibliotecas criadas no programa
#include "lib/utilidades.h"
#include "lib/menu.h"
#include "lib/funcoes.h"

//Limpa a tela de execução
#define clrscr() printf("\e[1;1H\e[2J")
//Define o numero maximo de tarefas
#define MAX_TAREFAS 100
//Define o tamanho pras tabelas
#define window_size 100

//Roda o programa
int main( ){
    //Limpa a tela de execução
    clrscr();
    //Declara estruturas, arquivos, e constantes
    Tarefa tarefas[MAX_TAREFAS];
    int num_tarefas=0, opcao, id;
    const char *arquivo_tarefa = "tarefas.txt";
    Tarefa novaTarefa;
    //Inicia o loop do programa
    do{
        //Desenha um menu personalizado da biblioteca "menu"
        menu(window_size);
        scanf("%d", &opcao);
        //Seleciona a opção do menu a ser realizado
        switch(opcao){
            case 1:
                clrscr();
                //Chama funções especificas da biblioteca "Funcoes.h"
                nova_tarefa(novaTarefa, tarefas, &num_tarefas);
                break;
            case 2:
                clrscr();
                if (num_tarefas == 0){
                    printf("Nenhuma tarefa encontrada\n");
                    break;
                } else {
                    //Chama funções especificas da biblioteca "Funcoes.h"
                    mostrar_tarefa(tarefas, num_tarefas);
                    break;
                }
            case 3:
                clrscr();
                //Verifica se ja tem tarefa criada
                if (num_tarefas == 0){
                    printf("Nenhuma tarefa para editar\n");
                    break;
                } else {
                    printf("Digite o ID da tarefa que deseja alterar: ");
                    scanf("%d", &id);
                    //Chama funções especificas da biblioteca "Funcoes.h"
                    editar_tarefa(id, tarefas, num_tarefas);
                    break;
                }
            case 4:
                clrscr();
                //Verifica se ja tem tarefa criada
                if (num_tarefas == 0){
                    printf("Nenhuma tarefa para concluir\n");
                    break;
                } else {
                    printf("Digite o ID da tarefa concluida: ");
                    scanf("%d", &id);
                    //Chama funções especificas da biblioteca "Funcoes.h"
                    tarefa_concluida(id, tarefas, num_tarefas);
                    break;
                }
            case 5:
                clrscr();
                //Verifica se ja tem tarefa criada
                if (num_tarefas == 0){
                    printf("Nenhuma tarefa para excluir\n");
                    break;
                } else {
                    printf("Digite o ID da tarefa a ser excluido: ");
                    scanf("%d", &id);
                    //Chama funções especificas da biblioteca "Funcoes.h"
                    excluir_tarefa(id, tarefas, &num_tarefas);
                    break;
                }
            case 6:
                clrscr();
                //Desenha um menu de creditos personalizado
                creditos(window_size);
                getchar();
                clrscr();
                break;
            case 0:
                clrscr();
                //Chama funções especificas da biblioteca "Funcoes.h"
                salvar_tarefa(arquivo_tarefa, tarefas, num_tarefas);
                printf("Programa encerrado.\n");
                break;
            default:
                printf("Opcao invalida\n");
                break;
        }
    } while (opcao !=0);
    return 0;
}

