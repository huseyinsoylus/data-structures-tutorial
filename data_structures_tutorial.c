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
#include <sys/ioctl.h>
#include <unistd.h>
//___________________________________________________________________________________

//--------------------------------------Define Area---------------------------------

//___________________________________________________________________________________

//-------------------------------------Global Variables------------------------------
char * giv_girdi;
struct winsize sw_cmd_width;
//___________________________________________________________________________________




//----------------------------------Function Declare Area----------------------------
int ifp_is_it_equal(char * expression1, char * expression2)
{
    return !strcmp(expression1,expression2);
}

//___________________________________________________________________________________

//----------------------------------Print '-' Functions----------------------------
void vfp_print_window_size_ch(char ch, struct winsize w)
{
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int iv_window_column = w.ws_col;
    
    for(int i = 0;i < iv_window_column; i++)
    {
        printf("%c",ch);
    }
    
    printf("\n");
}
//___________________________________________________________________________________

//----------------------------------Print Color Functions----------------------------
void vfp_color_change(char * color_name)
{
    if(strcmp(color_name,"Yellow")==0)
    {
        printf("\033[0;33m");
    }
    else
    {
        printf("\033[0m");
    }
}
//___________________________________________________________________________________

void vf_print_education_list()
{
    vfp_color_change("default");
    printf("Eğitim Listesi\n");
    
    vfp_print_window_size_ch('-',sw_cmd_width);
    printf("1-)Bağlantılı Liste\n2-)Çift Yönlü Bağlantılı Liste\n3-)Çevrimli Bağlantılı liste\n4-)Yığıt\n5-)Kuyruk\n\n");
    printf("Hangi eğitime girmek istiyorsanız sıra numarasını yazınız.\nEğitimi sonlandırmak için exit - Exit yazınız.\n");
    vfp_print_window_size_ch('-',sw_cmd_width);
}
//___________________________________________________________________________________

int main(int argc, char * argv[])
{
    //Console clear
    system("clear");
    
    giv_girdi = malloc(sizeof(char)*10);
    printf("Veri yapıları ve algoritmalar eğitim programına hoşgeldiniz.\n\n");
    printf("Eğitim Listesi\n--------------------------------------------\n1-)Bağlantılı Liste\n2-)Çift Yönlü Bağlantılı Liste\n3-)Çevrimli Bağlantılı liste\n4-)Yığıt\n5-)Kuyruk\n\n");
    printf("Hangi eğitime girmek istiyorsanız sıra numarasını yazınız.\nEğitimi sonlandırmak için exit - Exit yazınız.\n");
    
    while(1)
    {
	printf("Eğitim Girişi:");
	scanf("%s",giv_girdi);
	//printf("%s",giv_girdi);
	if(ifp_is_it_equal(giv_girdi,"1"))
	{
	    printf("Bağlantılı Liste Eğitimine Hoşgeldiniz.\n");
	}
	else if(ifp_is_it_equal(giv_girdi,"2"))
	{
	    printf("Çift Bağlantılı Liste Eğitimine Hoşgeldiniz.\n");
	}
	else if(ifp_is_it_equal(giv_girdi,"3"))
	{
	    printf("Çevrimli Liste Eğitimine Hoşgeldiniz.\n");
	}
	else if(ifp_is_it_equal(giv_girdi,"4"))
	{
	    printf("Yığıt Eğitimine Hoşgeldiniz.\n");
	}
	else if(ifp_is_it_equal(giv_girdi,"5"))
	{
	    printf("Kuyruk Liste Eğitimine Hoşgeldiniz.\n");
	}
	else if(ifp_is_it_equal(giv_girdi,"exit") || ifp_is_it_equal(giv_girdi,"Exit"))
	{
	    printf("Programdan çıkılıyor. İyi günler dileriz.\n");
	    _Exit(0);
	}
	else
	{
	    printf("Giriş yaptığınız değer geçersizdir.\n");
	}
    }
    

}
