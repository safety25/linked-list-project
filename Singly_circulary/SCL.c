#include <stdlib.h>
#include <stdio.h>
#include <string.h>


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

    return new_player;
}

//oyuncu çıkarmak için gerekli fonksiyon
player *extract_player(player *head,player*tail){
   if (head == NULL)
    {
        printf("Takimda oyuncu yok!\n");
    }
    
    else
    {
        int number;
        printf("Takimdan ayrilacak kisinin numarasi: ");
        scanf("%d",&number);
        
        //bir eleman varsa onu silmek için
        if (head == tail  && head->number == number){ 
            player* tmp = head;
            free(tmp);
            head->next = NULL;
            head->prev = NULL;
            printf("Takimda oyuncu kalmadi!\n");
            exit(1);
        }

       //Baştaki elemanı silmek için
       else if (head->next != NULL && head->number == number){
            player *tmp = head;
            head = tmp->next;
            free(tmp);
            tail->next = head;
            printf("%d numarali oyuncu takimdan çıkarildi!\n",number);
            return head;
        }
                
    
        //aradaki elemanlar ve en sondaki elemanı silmek için
        else{
            player* tmp = head;
            player* tmp2 = head;

            while (tmp->next != head)
            {

                if (tmp->number == number){
                    tmp2->next = tmp->next;
                    free(tmp);
                    printf("%d numarali oyuncu takimdan cikarildi!\n", number);
                    return head;
                }

                tmp2 = tmp;
                tmp = tmp->next;
                
                //tail dan çıkarma
                if (tmp->next == head && tmp->number == number)
                {
                    tmp2->next = tmp->next;
                    tmp->next = NULL;
                    free(tmp);
                    printf("%d numarali oyuncu takimdan cikarildi!\n", number);
                    return head;
                }
                
            }

        }
    }
    return head;
}

player *find_player(player *head, player *tail){
    char name[20];
    printf("Bulmak istediginiz oyuncunun adini yazin: ");
    scanf("%s",name);
    
    player *find = head;
    while (find != tail)
    {
        if(strcmp(find->name,name) == 0){
            printf("%s %d yasindadir, %d numarali formayi giymektedir ve onun pozisyonu %s dir! \n",name,find->age,find->number,find->position);
            return find;
        }

        find = find->next;
        
         
    }

    if (find == tail && strcmp(find->name,name) == 0){
        printf("%s %d yasindadir, %d numarali formayi giymektedir ve onun pozisyonu %s dir! \n",name,find->age,find->number,find->position);
        return find;
    }

    printf("Boyle bir oyuncu bulunamadi!\n");
    return NULL;

}



player *insert_player(player *head, player *tail){
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
    
    if (head == NULL){
        head = new_player;
        tail = new_player;
        printf("Oyuncu takima eklendi!\n");
        return head;

    }
    else {

        new_player->next = head;
        head = new_player;
        tail->next = head;
        printf("Oyuncu takima eklendi!\n");
        return head;
    }
    
}

void print_players(player *head, player *tail){
    player *tmp = head;
    if (head == NULL)
    {
        printf("Takimda henuz oyuncu yok!\n");
    }
    
    
    int c = 0;
    while (1){ 
        if(tmp == head)
        {
            c++;
            if(c == 2)
            {break;}
        }
        
        printf("Adi: %s Yasi: %d Numarasi: %d Pozisyonu: %s \n                  |\n                  |",tmp->name, tmp->age, tmp->number, tmp->position);        
        tmp = tmp->next;
        printf("\n");

        if (head == tail)
        {
            return;
        }
        
        
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


