#include <stdio.h>
#include "SLL.h"
#include <string.h>


int main(void){
    player *head = NULL;
    head = add_player(25,24,"Alperen","Safety");
    
    int selection = menu();
    
    while (selection != 0)
    {
        if (selection == 1){
            insert_player(&head);
        }

        else if (selection == 2){   
            head = extract_player(head);
            
        }
        
        else if (selection == 3){
            print_players(head);
        }

        else if (selection == 4){
            find_player(head);
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