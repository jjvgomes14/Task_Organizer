#define RB "\e(0\x6a\e(B" // 188 Right Bottom corner
#define RT "\e(0\x6b\e(B" // 187 Right Top corner
#define LT "\e(0\x6c\e(B" // 201 Left Top cornet
#define LB "\e(0\x6d\e(B" // 200 Left Bottom corner
#define MC "\e(0\x6e\e(B" // 206 Midle Cross
#define HL "\e(0\x71\e(B" // 205 Horizontal Line
#define LC "\e(0\x74\e(B" // 204 Left Cross
#define RC "\e(0\x75\e(B" // 185 Right Cross
#define BC "\e(0\x76\e(B" // 202 Bottom Cross
#define TC "\e(0\x77\e(B" // 203 Top Cross
#define VL "\e(0\x78\e(B" // 186 Vertical Line
#define SP " " 		  // space string

//Function to print a new line (\n)
void new_line() {
    printf("\n");
}

//Function to draw a horizontal line with a given length
void draw_horizontal_line(int length){
    for(int i = 0; i < length; i++){
        printf("%s", HL);
    }
}

//Function to draw a vertical line with a given length
void draw_vertical_line(int length){
    for(int i = 0; i < length-1; i++){
        printf("%s\n", VL);
    }
    printf("%s", VL);
}

//Function to draw the top line with a given length (left and right corners with horizontal line in the middle)
void draw_top_line(int length){
    printf("%s", LT);
    draw_horizontal_line(length);
    printf("%s", RT);
    new_line();
}

//Function to draw the bottom menu with a given length (left and right corners with horizontal line in the middle)
void draw_bottom_line(int length){
    printf("%s", LB);
    draw_horizontal_line(length);
    printf("%s", RB);
    new_line();
}

void draw_line_cross(int length){
    printf("%s", LC);
    draw_horizontal_line(length);
    printf("%s", RC);
    new_line();
}
//Function to draw a blank line with a given length
void draw_blank_line(int length){
    draw_vertical_line(1);
    for(int i = 0; i < length; i++){
        printf("%s", SP);
    }
    draw_vertical_line(1);
    new_line();
}

//Function to draw spaces (" ") with a given length
void draw_space_line(int length){
    for(int i = 0; i < length; i++){
        printf("%s", SP);
    }
}

//Function to center text inside the menu
void center_text(int length, char* text){;
    int text_length = strlen(text);
    int space_length = (length - text_length)/2;

    draw_vertical_line(1);

    //Add spaces before the text
    for(int i=0; i<space_length; i++){
        printf("%s", SP);
    }
    printf("%s", text);

    //If the text is odd, we need to add one more space after the text
    if(text_length%2 != 0){
        for(int i=0; i<space_length+1; i++){
            printf("%s", SP);
        }
    }
    else{
        for(int i=0; i<space_length; i++){
            printf("%s", SP);
        }
    }

    draw_vertical_line(1);
    new_line();
}


void draw_menu_header(int size, char* title, char* subtitle){
    draw_top_line(size);
    center_text(size, title);
    draw_line_cross(size);
    center_text(size, subtitle);
    draw_line_cross(size);
    draw_blank_line(size);
}

void draw_visualizar_tarefa(int size, char* title, char* subtitle){
    draw_top_line(size);
    center_text(size, title);
    draw_line_cross(size);
    center_text(size, subtitle);
    draw_line_cross(size);
    draw_blank_line(size);
}
