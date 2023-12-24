#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool valid = true;

char space[3][3]={{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};

void title(){
    printf("  _______ _____ _____   _______       _____   _______ ____  ______ \n");
    printf(" |__   __|_   _/ ____| |__   __|/\\   / ____| |__   __/ __ \\|  ____|\n");
    printf("    | |    | || |         | |  /  \\ | |         | | | |  | | |__   \n");
    printf("    | |    | || |         | | / /\\ \\| |         | | | |  | |  __|  \n");
    printf("    | |   _| || |____     | |/ ____ \\ |____     | | | |__| | |____ \n");
    printf("    |_|  |_____\\_____|    |_/_/    \\_\\_____|    |_|  \\____/|______|\n");
}

void draw(){
    printf("       |        |      \n"); 
    printf("    %c  |   %c    |   %c  \n ", space[0][0], space[0][1], space[0][2]);
    printf("______|________|_______\n");
    printf("       |        |      \n"); 
    printf("    %c  |   %c    |   %c  \n ", space[1][0], space[1][1], space[1][2]);
    printf("______|________|_______\n");
    printf("       |        |      \n"); 
    printf("    %c  |   %c    |   %c  \n ", space[2][0], space[2][1], space[2][2]);
    printf("______|________|_______\n");
}

void translate(char i, char playerno){
    if (i=='1'){
        if (space[0][0] != '1')    
            valid = false;
        else{
            space[0][0] = playerno;
            valid = true;
        }
    } 
    else if (i=='2'){
        if (space[0][1] != '2')
            valid = false;
        else {
            space[0][1] = playerno;
            valid = true;
        }
    }
    else if (i=='3'){
        if (space[0][2] != '3')
            valid = false;
        else {
            space[0][2] = playerno;
            valid = true;
        }
    }
    else if (i=='4'){
        if (space[1][0] != '4')
            valid = false;
        else {
            space[1][0] = playerno;
            valid = true;
        }
    }
    else if (i=='5'){
        if (space[1][1] != '5')
            valid = false;
        else {
            space[1][1] = playerno;
            valid = true;
        }
    }
    else if (i=='6'){
        if (space[1][2] != '6')
            valid = false;
        else {
            space[1][2] = playerno;
            valid = true;
        }
    }
    else if (i=='7'){
        if (space[2][0] != '7')
            valid = false;
        else {
            space[2][0] = playerno;
            valid = true;
        }
    }
    else if (i=='8'){
        if (space[2][1] != '8')
            valid = false;
        else {
            space[2][1] = playerno;
            valid = true;
        }
    }
    else if (i=='9'){
        if (space[2][2] != '9')
            valid = false;
        else {
            space[2][2] = playerno;
            valid = true;
        }
    }
}

void player1(){
    char i;
    printf("Player 1 (%c): please choose a number: ", 'X');
    scanf(" %c", &i);  // Add a space before %c to consume any whitespace characters
    getchar();
    translate(i,'X');
}

void player2(){
    char i;
    printf("Player 2 (%c): please choose a number: ", 'O');
    scanf(" %c", &i);  // Add a space before %c to consume any whitespace characters
    getchar();
    translate(i,'O');
}

char checkBoard(void)
{
    int i;

    for(i=0; i<3; i++)
        if(space[i][0]==space[i][1] && space[i][0]==space[i][2])
            return space[i][0];

    for(i=0; i<3; i++)
        if(space[0][i]==space[1][i] && space[0][i]==space[2][i])
            return space[0][i];

    if(space[0][0]==space[1][1] && space[1][1]==space[2][2])
        return space[0][0];

    if(space[0][2]==space[1][1] && space[1][1]==space[2][0])
        return space[0][2];

    return ' ';
}

int main(){
    title();
    char win = ' ';
    char n1[50];
    char n2[50];

    printf("Enter the name of the first player: ");
    scanf("%s", n1);
    getchar();
    printf("Enter the name of the second player: ");
    scanf("%s", n2);
    getchar();
    system("cls");

    int choice;
    do {
        printf("Menu:\n");
        printf("1. Start a new game\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Reset the game
                for (int i = 0; i < 3; i++)
                    for (int j = 0; j < 3; j++)
                        space[i][j] = '1' + i * 3 + j;
                win = ' ';
                system("cls");
                
                while(win == ' '){
                    draw();

                    valid = true;
                    do{
                        printf("%s's turn ", n1);
                        player1();
                    } while (valid == false);
                    system("cls");

                    draw();

                    valid = true;
                    do{
                        printf("%s's turn ", n2);
                        player2();
                    } while (valid == false);
                    system("cls");

                    win = checkBoard();
                }

                if(win == 'X'){
                    printf("Congrats %s wins!\n", n1);
                } else if(win == 'O'){
                    printf("Congrats %s wins!\n", n2);
                } else {
                    printf("It's a draw!\n");
                }
                break;
            case 2:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter 1 or 2.\n");
                break;
        }
    } while (choice != 2);

    return 0;
}
