//Define a estrutura "Tarefa" com suas observações
typedef struct{
    char nome[50];
    char descricao[50];
    char criacao[20];
    char entrega[20];
    int concluido;
} Tarefa;
//Função para criar uma nova tarefa
void nova_tarefa(Tarefa novaTarefa, Tarefa tarefas[], int *num_tarefas){
    //Adiciona o nome na estrutura "Tarefa" utilizando o fgets() para ler o q foi digitado no teclado e o strpcspn para subistituir o caracter de nova linha por um caracter nulo indicando o final da string
    printf("Digite o nome da tarefa: ");
    getchar();
    fgets(novaTarefa.nome, sizeof(novaTarefa.nome), stdin);
    novaTarefa.nome[strcspn(novaTarefa.nome, "\n")] = '\0';
    //Adiciona a descrição na estrutura "Tarefa" utilizando o fgets() para ler o q foi digitado no teclado e o strpcspn para subistituir o caracter de nova linha por um caracter nulo indicando o final da string
    printf("Descreva a tarefa: ");
    fgets(novaTarefa.descricao, sizeof(novaTarefa.descricao), stdin);
    novaTarefa.descricao[strcspn(novaTarefa.descricao, "\n")] = '\0';
    //Adiciona a data de criação na estrutura "Tarefa" utilizando o fgets() para ler o q foi digitado no teclado e o strpcspn para subistituir o caracter de nova linha por um caracter nulo indicando o final da string
    printf("Digite a data de criacao da tarefa: ");
    fgets(novaTarefa.criacao, sizeof(novaTarefa.criacao), stdin);
    novaTarefa.criacao[strcspn(novaTarefa.criacao, "\n")] = '\0';
    //Adiciona a data de entrega na estrutura "Tarefa" utilizando o fgets() para ler o q foi digitado no teclado e o strpcspn para subistituir o caracter de nova linha por um caracter nulo indicando o final da string
    printf("Digite a data de entrega da tarefa: ");
    fgets(novaTarefa.entrega, sizeof(novaTarefa.entrega), stdin);
    novaTarefa.entrega[strcspn(novaTarefa.entrega, "\n")] = '\0';
    //Coloca o status de concluido como falso
    novaTarefa.concluido = 0;
    //Faz um contador de tarefas
    tarefas[*num_tarefas] = novaTarefa;
    (*num_tarefas)++;

    printf("Tarefa adicionada\n");
}
//Função para mostrar as tarefas adicionadas
void mostrar_tarefa(Tarefa tarefas[], int numTarefas){
    //Desenha um menu para exibir as tarefas utilizando ferramentas da biblioteca "utilidades.h"
    draw_visualizar_tarefa(100, "Tarefas", "ID    Titulo       Data de criacao        Data de entrega      Concluida        Descricao");
    for (int i = 0; i < numTarefas; i++) {
        printf("      %-4d %-16s %-23s %-17s %-15s %-20s\n", i + 1, tarefas[i].nome, tarefas[i].criacao, tarefas[i].entrega, tarefas[i].concluido ? "Sim" : "Nao", tarefas[i].descricao);
    }
    draw_bottom_line(100);
    printf("Tarefas mostradas\n");
}
//Função para editar a tarefa selecionada
void editar_tarefa(int id, Tarefa tarefas[], int numTarefas){
    //Indentifica se é uma tarefa existente
    if (id<1 || id>numTarefas){
        printf("ID da tarefa invalido\n");
        return;
    }
    //Mostra a tarefa antes das alterações
    Tarefa *tarefa = &tarefas[id-1];
    printf("Tarefa Atual:\n");
    printf("Nome: %s\n", tarefa->nome);
    printf("Descricao: %s\n", tarefa->descricao);
    printf("Data de criacao: %s\n", tarefa->criacao);
    printf("Data de entrega: %s\n", tarefa->entrega);
    //Pega as novas informações da tarefa da mesma forma de que se estivesse adicionando uma nova tarefa
    printf("Digite o novo nome da tarefa: ");
    getchar();
    fgets(tarefa->nome, sizeof(tarefa->nome), stdin);
    tarefa->nome[strcspn(tarefa->nome, "\n")] = '\0';

    printf("Nova descricao: ");
    fgets(tarefa->descricao, sizeof(tarefa->descricao), stdin);
    tarefa->descricao[strcspn(tarefa->descricao, "\n")] = '\0';

    printf("Nova data de criacao:  ");
    fgets(tarefa->criacao, sizeof(tarefa->criacao), stdin);
    tarefa->criacao[strcspn(tarefa->criacao, "\n")] = '\0';

    printf("Nova data de entrega: ");
    fgets(tarefa->entrega, sizeof(tarefa->entrega), stdin);
    tarefa->entrega[strcspn(tarefa->entrega, "\n")] = '\0';

    printf("Tarefa atualizada\n");
}
//Função para marcar tarefa como concluida
void tarefa_concluida(int id, Tarefa tarefas[], int numTarefas){
    //Indentifica se é uma tarefa existente
    if (id<1 || id>numTarefas){
        printf("ID da tarefa invalido\n");
        return;
    }
    //Transforma o status de concluido da tarefa selecionada como true
    tarefas[id-1].concluido = 1;
    printf("Tarefa marcada como concluida\n");
}
//Função para exlcuir tarefa selecionada
void excluir_tarefa(int id, Tarefa tarefas[], int *numTarefas){
    //Indentifica se é uma tarefa existente
    if (id < 1 || id > numTarefas){
        printf("ID invalido\n");
        return;
    }
    for (int i = id-1; i < *numTarefas - 1; i++){
        tarefas[i] = tarefas [i+1];
    }

    (*numTarefas)--;
    printf("Tarefa excluida\n");
}
//Função que salvará as tarefas existentes em um arquivo "Tarefas.txt" ao sair do programa
void salvar_tarefa(const char *nomeArquivo, Tarefa tarefas[], int numTarefas){
    //Abre o arquivo em forma de edição
    FILE *arquivo = fopen(nomeArquivo, "w");
    //Verifica se foi aberto corretamente
    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo\n");
        return;
    }
    //Escreve as tarefas no arquivo
    for (int i = 0; i< numTarefas; i++){
        fprintf(arquivo, "%s, %s, %s, %s, %d\n", tarefas[i].nome, tarefas[i].descricao, tarefas[i].criacao, tarefas[i].entrega, tarefas[i].concluido);
    }
    //Fecha o arquivo
    fclose(arquivo);

    printf("Tarefas salvas\n");
}