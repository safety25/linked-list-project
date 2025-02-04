#ifndef LIB_H_ 
#define LIB_H_
#include <stdio.h>
#include "SCL.c"

//Her oyuncunun spesifik bir forma numarası olduğu için forma numarasını girdiğinizde o oyuncunun ismini ve mevkisini bulabileceğiniz foknsiyon
player *find_player(player *head, player *tail);

//takımdaki bütün oyuncuların bütün özelliklerini komut satırına yapıştırır
void print_players(player *head, player *tail);

//takıma yeni oyuncu ekleme fonksiyonu, takıma yeni oyuncu gireceği zamnan bilgilerini terminalden isteyerek ard arda ekleyen fonksiyon
player *insert_player(player *head, player *tail);

//Takımdaki her kişinin eşsiz bir forma numarası olacağı için forma numarasını girdiğiniz bir oyuncuyu takımdan çıkarma fonksiyonu.
player *extract_player(player *head, player *tail);

//Terminalden istediğin fonksiyonları çalıştırmak için gerekli olan fonksiyon
int menu();

#endif