#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct infos{
    char name[20];
    int hp;

};

void what_is_your_name(struct infos *);
void giving_damage(int ,char,struct infos *,struct infos *);


int main()
{
    int n;
    printf("Oyunu kac kisi oynayacak? \n");
    scanf("%d",&n);

    char kisi[10];


    struct infos *players = (struct infos*)calloc(n,sizeof(struct infos));

    for(int i=0; i<n; i++) {
        printf("Lutfen %d. karakterinizin adini giriniz : \n",i+1);
        what_is_your_name(players[i].name);
        printf("Oyuncu adi : %s",players[i].name);
        players[i].hp = 30;

    }

    printf("Kime saldirmak istersiniz ? \n");
    scanf("%s",&kisi);

    for (int i = 0;i<n;i++) {
        giving_damage(n,kisi,players[i].name,players[i].hp);
    }
        return 0;
}

void what_is_your_name(struct infos *ptr1){
    scanf(" %[^\n]s",ptr1->name);
    //printf("Karakteriniz basari ile olusturulmustur.\nOlusturulan karakterinizin adi : %s\n",ptr1 ->name);
}



void giving_damage(int n,char kisi,struct infos *ptr2,struct infos *ptr3){

    int randomnum;
    randomnum = (rand() % 5) + 1;
    printf("Bu el vuracaginiz hasar %d'dir",randomnum);



    for(int i=0 ; i < n ; i++){
        if (kisi == *ptr2[i].name){
            ptr3[i].hp -= randomnum;
        }
    }
}