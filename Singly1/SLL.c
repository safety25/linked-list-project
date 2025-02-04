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

//oyuncu eklemek için gerekli fonksiyon
player *add_player (int new_number, int new_age, char new_name[], char new_position[]){
    
    player *new_player = (player*)malloc(sizeof(player));
    new_player->number = new_number;
    new_player->age = new_age;
    strcpy(new_player->name, new_name);
    strcpy(new_player->position, new_position);
    new_player->next = NULL;

    return new_player;
}


player *extract_player(player *head){
    //takımda hiç oyuncu yoksa bu fonksiyon çalışır.
    if (head == NULL)
    {
        printf("Takimda oyuncu yok!\n");
    }
    
    else
    {
        int number;
        printf("Takimdan ayrilacak kisinin numarasi: ");
        scanf("%d",&number);
        
        //takımda 1 tane oyuncu varsa o oyuncuyu çıkartır.
        if (head->next == NULL && head->number == number){    
            player *tmp = head;
            free(tmp);
            head = NULL;
            printf("Takimda oyuncu kalmadi!\n");
            
        }

        //çıkartılacak oyuncu en baştaysa onu çıkartmak için yapılan if fonksiyonu
        else if (head->next != NULL && head->number == number){
            player *tmp = head->next;
            free(head);
            head = tmp;
            printf("%d numarali oyuncu takimdan çıkarildi!\n",number);
        }

        //en baştaki oyuncular dışındaki bütün oyuncuları sırayla arayarak bulup çıkartan fonksiyon
        else{
            player* tmp = head;
            player* tmp2 = head;

            while (tmp->next!=NULL)
            {   
                if (tmp->number == number){
                    tmp2->next = tmp->next;
                    free(tmp);
                    printf("%d numarali oyuncu takimdan cikarildi!\n", number);
                }

                tmp2 = tmp;
                tmp = tmp->next;
            }

            if (tmp->number == number)
            {
                tmp2->next = tmp->next;
                free(tmp);
                printf("%d numarali oyuncu takimdan cikarildi!\n",number);
            }
        }
    }
    return head;
}


player *find_player(player *head){
    char name[20];
    printf("Bulmak istediginiz oyuncunun adini yazin: ");
    scanf("%s",name);
    
    player *find = head;
    while (find != NULL)
    {
        if(strcmp(find->name,name) == 0){
            printf("%s %d yasindadir, %d numarali formayi giymektedir ve onun pozisyonu %s dir! \n",name,find->age,find->number,find->position);
            return find;
        }

        find = find->next;

        if (strcmp(find->name, name) != 0)
        {
            printf("Boyle bir oyuncu bulunamadi\n");
            return find;
        }
        
         
    }
   return NULL;

}

void insert_player(player **head){
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
    
    //Eğer takımda oyuncu yoksa ilk oyuncuyu başa ekler
    if (*head == NULL){
        *head = new_player;
        printf("Oyuncu takima eklendi!\n");
    }

    //takımda oyuncu varsa ilk baştaki oyuncunun üstüne ekleyerek devam eder
    else {
        new_player->next = *head; 
        *head = new_player;
        printf("Oyuncu takima eklendi!\n");
    }
    
}

void print_players(player *head){
    player *tmp = head;
    if (head == NULL)
    {
        printf("Takimda henuz oyuncu yok!\n");
    }
    
    while (tmp != NULL){
        printf("Adi: %s Yasi: %d Numarasi: %d Pozisyonu: %s \n                  |\n                  |",tmp->name, tmp->age, tmp->number, tmp->position);        tmp = tmp->next;
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


