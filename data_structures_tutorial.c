/*
Huseyin Soylu - 171418012
Marmara Universitesi Bilgisayar Muhendisligi Bolumu
BLM2002-Veri Yapilari ve Algoritmalar Dersi - Donem Projesi

Asagidaki program veri yapıları dersinde öğretilen temel veri türlerinin anlaşılması ve pratikte nasıl kullanıldıkları 
hakkında kullanıcıya bilgi kazandırmayı hedefler.

Kodlama yapilirken macar notasyonu esas alinmis ve tum degiskenler icin asagida 
belirtilen esaslarda kodlama yapilmistir. 
_____________________________________________________________________________________

------For Variable-----------------
variable = v; tip sonrasi eki
-------------------------------

------Use Case-----------------
integer icin = iv;
char icin =cv;
double icin = dv;
float icin = fv;
-------------------------------
_____________________________________________________________________________________

------For Pointer------------------
pointer = p; tip sonrasi eki
-------------------------------

------Use Case-----------------
int pointer icin = ip;
char pointer icin = cp;
-------------------------------
_____________________________________________________________________________________

------ For Array---------------
array = a; tip sonrasi eki
-------------------------------

------Use Case-----------------
int array = ia;
char array = ca;
-------------------------------
_____________________________________________________________________________________

------For Function-------------
function = f; tip sonrasi eki
-------------------------------

------Use Case-----------------
int geri donuslu fonksiyon = if;
char geri donuslu fonksiyon = cf;

int pointer geri donuslu fonksiyon = ipf;
char pointer geri donuslu fonksiyon = cpf;

geri donussuz fonksiyon icin = vf;
-------------------------------
_____________________________________________________________________________________

------For Function Parameter---
parameter = p;
-------------------------------

------Use Case-----------------
int geri donuslu parametreli fonsiyon = ifp;
int pointer donuslu parametreli fonksiyon = ipfp;

Seklinde tanimlanmistir.
-------------------------------
________________________________________________________________________________________
*/
//--------------------------------------Program Area--------------------------------------

//--------------------------------------Program Libraries---------------------------------
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
//___________________________________________________________________________________


//-------------------------------------Global Variables------------------------------
char * giv_girdi;
//___________________________________________________________________________________




//----------------------------------Function Declare Area----------------------------
int ifp_is_it_equal(char * expression1, char * expression2)
{
    return !strcmp(expression1,expression2);
}

//___________________________________________________________________________________



int main(int argc, char * argv[])
{
    giv_girdi = malloc(sizeof(char)*10);
    printf("Veri yapıları ve algoritmalar eğitim programına hoşgeldiniz.\n\n");
    printf("Eğitim Listesi\n--------------------------------------------\n1-)Bağlantılı Liste\n2-)Çift Yönlü Bağlantılı Liste\n3-)Çevrimli Bağlantılı liste\n4-)Yığıt\n5-)Kuyruk\n\n");
    printf("Hangi eğitime girmek istiyorsanız sıra numarasını yazınız.\nEğitimi sonlandırmak için 0 yazınız.\n");
    //printf("%c",giv_girdi);
    
    scanf("%s",giv_girdi);
    //printf("%s",giv_girdi);
    if(ifp_similarity_check(giv_girdi,"1"))
    {
        printf("Bağlantılı Liste Eğitimine Hoşgeldiniz.\n");
    }
    
    
    
    
    
    

}
