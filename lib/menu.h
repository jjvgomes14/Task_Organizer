//Funcao responsável para criar um menu personalizado, usando ferramentas da biblioteca "utilidades.h"
void menu(int menu_size){
    draw_menu_header(menu_size, "Minhas Tarefas", "Joao Victor Gomes Prado");
    center_text(menu_size, "1. Adicionar tarefa");
    center_text(menu_size, "2. Visualizar tarefa");
    center_text(menu_size, "3. Editar tarefa");
    center_text(menu_size, "4. Marcar tarefa como concluida");
    center_text(menu_size, "5. Excluir tarefa");
    center_text(menu_size, "6. Creditos");
    center_text(menu_size, "0. Sair");
    draw_blank_line(menu_size);
    draw_line_cross(menu_size);
    center_text(menu_size, "Escolha uma opcao");
    draw_space_line((menu_size/2));
}
//Funcao responsável para criar um menu de creditos personalizado, usando ferramentas da biblioteca "utilidades.h"
void creditos(int menu_size){
    draw_menu_header(menu_size, "Desenvolvimento de algoritimos", "Projeto final");
    center_text(menu_size, "Projeto criado por:");
    center_text(menu_size, "Joao Victor Gomes Prado : github.com/jjvgomes14");
    center_text(menu_size, "Obrigado pela atencao!");
    draw_blank_line(menu_size);
    draw_bottom_line(menu_size);
    center_text(menu_size, "Pressione 'enter' para voltar ao menu");
    draw_space_line((menu_size));
    draw_bottom_line(menu_size);
    //Pressione enter para retornar ao menu
    getchar();
}