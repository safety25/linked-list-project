#ifndef LIB_H_ 
#define LIB_H_
#include <stdio.h>
#include "DLL.c"

//insert_player fonksiyonunu kullanmak için gerekli olan parametreleri alan ve bu parametlerelere
//hafızada yer açan fonksiyon
player *add_player (int new_number, int new_age, char new_name[], char new_position[]);

//Oyuncunun adını girdiğinizde onu bulup özelliklerini yazdıran fonksiyon.
player *find_player(player *head);

//takımdaki bütün oyuncuların bütün özelliklerini komut satırına yapıştırır
void print_players(player *head);

//takıma yeni oyuncu ekleme fonksiyonu, takıma yeni oyuncu gireceği zamnan bilgilerini terminalden isteyerek ard arda ekleyen fonksiyon
player *insert_player(player *head);

//Takımdaki her kişinin eşsiz bir forma numarası olacağı için forma numarasını girdiğiniz bir oyuncuyu takımdan çıkarma fonksiyonu.
player *extract_player(player *head);

//Terminalden istediğin fonksiyonları çalıştırmak için gerekli olan fonksiyon
int menu();

#endif