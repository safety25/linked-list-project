#include <stdio.h>
#include "DCL.h"
#include <string.h>


int main(void){
    player* tail = NULL;
    tail = add_player(25,24,"Alperen","Safety");

    int selection = menu();
    
    while (selection != 0)
    {
        if (selection == 1){
            tail = insert_player(tail);
        }

        else if (selection == 2){   
            tail = extract_player(tail);
            
        }
        
        else if (selection == 3){
            print_players(tail);
        }

        else if (selection == 4){
            find_player(tail);
        }
        
        else if (selection == 0){
            exit(1);
        }
        
        else {
            printf("Lutfen listedeki rakamlardan birini tuslayin!\n");
        }

        selection = menu();
        
    }

}