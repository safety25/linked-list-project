#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct team_player {
	int number;
    int age;
    char name[20];
    char position[20]; 

	struct team_player *next;
    struct team_player *prev;
};

typedef struct team_player player;

// oyuncu eklemek için gerekli fonksiyon
player *add_player (int new_number, int new_age, char new_name[], char new_position[]){
    
    player *new_player = (player*)malloc(sizeof(player));
    new_player->number = new_number;
    new_player->age = new_age;
    strcpy(new_player->name, new_name);
    strcpy(new_player->position, new_position);
    new_player->next = NULL;
    new_player->prev = NULL;

    return new_player;
}

//oyuncu çıkarmak için gerekli fonksiyon
player *extract_player(player*tail){
    if (tail == NULL)
    {
        printf("Takimda oyuncu yok!\n");
    }

    else
    {
        int number;
        printf("Takimdan ayrilacak kisinin numarasi: ");
        scanf("%d",&number);

        if (tail->next == NULL && tail->number == number)
        {
            player *tmp = tail;
            free(tmp);
            printf("Takimda oyuncu kalmadi!\n");
            exit(1);
        }
        
        else if (tail->next != NULL && tail->next->number == number)
        {
            player *tmp = tail->next;
            tail->next = tmp->next;
            free(tmp);
            printf("%d numarali oyuncu takimdan cikarildi!\n", number);
            return tail;
        }

        else{
            player *tmp = tail->next;
            player *tmp2 = tail->next;

            while (tmp->next != tail->next)
            {
                if (tmp->number == number){
                    tmp2->next = tmp->next;
                    tmp->next->prev = tmp2;
                    free(tmp);
                    printf("%d numarali oyuncu takimdan cikarildi!\n", number);
                    return tail;
                }

                tmp2 = tmp;
                tmp = tmp->next; 

                if (tmp == tail && tmp->number == number)
                {
                    tmp->next->prev = tmp2;
                    tmp2->next = tmp->next;
                    free(tmp);
                    printf("%d numarali oyuncu takimdan cikarildi!\n", number);
                    return tail;
                }  


            }
            

        }
        

    }
    
    return tail;
  
}

player *find_player(player *tail){
    char name[20];
    printf("Bulmak istediginiz oyuncunun adini yazin: ");
    scanf("%s",name);
    
    player *find = tail;
    int i = 0;
    while (true)
    {
        if(find == tail->next)
        {
            i++;
            if(i == 2)
            {  
                {break;}
            }
        }

        if(strcmp(find->name,name) == 0){
            printf("%s %d yasindadir, %d numarali formayi giymektedir ve onun pozisyonu %s dir! \n",name,find->age,find->number,find->position);
            return find;
        }

        find = find->next;      
    }

    printf("Boyle bir oyuncu bulunamadi!\n");
    return NULL;
}


player *insert_player(player *tail){
    int number;
    int age;
    char name[20] ;
    char position[20];
    printf("Oyuncu adi: ");
    scanf("%s",name);              
    printf("Oyuncu numarasi: ");
    scanf("%d", &number);
    printf("Oyuncu yasi: ");
    scanf("%d",&age);
    printf("Oyuncu pozisyonu: ");
    scanf("%s",position);

    player* new_player = add_player(number,age,name,position);
    
    if (tail == NULL){
        tail = new_player;
        printf("Oyuncu takima eklendi!\n");
        return tail;
    }

    else if (tail->next == NULL && tail->prev == NULL)
    {
        tail->next = new_player;
        tail->prev = new_player;
        new_player->next = tail;
        new_player->prev = tail;
        printf("Oyuncu takima eklendi!\n");
        return tail;
    }
    
    else {
        new_player->next = tail->next;
        tail->next->prev = new_player;
        tail->next = new_player;
        new_player->prev = tail;
        printf("Oyuncu takima eklendi!\n");
        return tail;
    }


    
}

void print_players(player *tail){
    player *tmp = tail->next;
    if (tail == NULL)
    {
        printf("Takimda henuz oyuncu yok!\n");
    }
    if(tmp == NULL)
    {
        printf("Adi: %s Yasi: %d Numarasi: %d Pozisyonu: %s \n                  |\n                  |",tail->name, tail->age, tail->number, tail->position);
        printf("\n");
        return;
    }
    
    int i = 0;
    while (true){

        if(tmp == tail->next)
        {
            i++;
            if(i == 2)
            {
                return;
            }
        }

        printf("Adi: %s Yasi: %d Numarasi: %d Pozisyonu: %s \n                  |\n                  |",tmp->name, tmp->age, tmp->number, tmp->position);
        tmp = tmp->next;
        printf("\n");

    }

}

int menu(){
    int selection;

    printf("*******************************\n");
    printf("Oyuncu eklemek icin 1 e basin \n");
    printf("Oyuncu cikartmak icin 2 ye basin \n");
    printf("Oyunculari ekrana yazdirmak icin 3 e basin \n");
    printf("İstediginiz oyuncuyu bulmak icin 4 e basin \n");
    printf("Cikmak icin 0 a basin\n");
    printf("Seciminiz: "); scanf("%d", &selection);
    return selection;

}


