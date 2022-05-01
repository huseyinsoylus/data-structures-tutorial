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
    printf("1-)Bağlantılı Liste\n2-)Çift Yönlü Bağlantılı Liste\n3-)Yığıt\n4-)Kuyruk\n5-)İkili Arama Ağacı\n\n");
    printf("Hangi eğitime girmek istiyorsanız sıra numarasını yazınız.\nEğitimi sonlandırmak için exit - Exit yazınız.\n");
    vfp_print_window_size_ch('-',sw_cmd_width);
}
//___________________________________________________________________________________

//----------------------------------Are Char Strings Equal---------------------------
void vfp_delete_enter_char(char * gets_input)
{
    int iv_lenght = strlen(gets_input);
    gets_input[iv_lenght-1]='\0';
}
//___________________________________________________________________________________

//----------------------------------Print Linked List Menu Functions-----------------
void vf_print_linked_list_menu()
{
    vfp_color_change("Yellow");
    
    printf("Bağlantılı Liste Eğitimine Hoşgeldiniz.\n");
    vfp_print_window_size_ch('-',sw_cmd_width);
    printf("1-)Bilgilendirme\n2-)Bağlantılı Liste Oluştur(10)\n3-)Eleman Ekle\n4-)Eleman Sil\n5-)Eleman Güncelle\n6-)Listeyi Göster\n7-)Listeyi Sil\n8-)Bir Üst Menüye Dön\n");
    vfp_print_window_size_ch('-',sw_cmd_width);
    
    vfp_color_change("");
}
//___________________________________________________________________________________

//----------------------------------LINKED LIST ALL FUNCTİONS--------------------------------------

//----------------------------------Print Linked List Info Func----------------------
void vf_print_linll_info()
{
    printf("Bilgilendirme:\n");
    printf("Her düğüm yalnızca bir sonraki düğümün adresi barındırır bunun sonucu olarak tek yönde okuma yapılabilir, bir düğümden önceki düğüme erişilemez. Düğüm yapısı C programlama dilinde struct kullanılarak yapılır.\n");
    vfp_print_window_size_ch('-',sw_cmd_width);

}
//___________________________________________________________________________________

//-------------------------------Create Linked List Struct---------------------------
struct linked_list 
{
    int value;                     //Data of the node
    struct linked_list *nextptr;           //Address of the next node
}*linked_root;
//___________________________________________________________________________________


//-------------------------------Create Random Linked List----------------------------

void vfp_create_linked_list_rnd(struct linked_list *root,int iv_list_lenght){
    
    if(root == NULL){
        perror("No memory is allocated for the linked list to be created\n");
    }  

    struct linked_list * tmp = malloc(sizeof(struct linked_list *));
    if(tmp == NULL){
        perror("Error creating memory for variable tmp\n"); //Bellek olusturma kontrolu.
    }

    tmp = root;
    if(root != NULL && root->nextptr == NULL){

        for(int i = 1;i<iv_list_lenght;i++){
    
        struct linked_list *sp_new_node = malloc(sizeof(struct linked_list *));
        tmp->nextptr = sp_new_node;
        sp_new_node->value = rand() % 50;
        tmp = sp_new_node; 
        }

    }
    else{
        perror("Root node is empty or already a list.\n");
    }
    
    printf("Bağlı liste başarıyla oluşturuldu.\n");
    vfp_print_window_size_ch('-',sw_cmd_width);
}
//___________________________________________________________________________________

//-------------------------------Print Linked List-----------------------------------
void vfp_print_linked_list(struct linked_list * root){

    if(root == NULL){
        perror("The linked list is empty.\n");
    }  

	struct linked_list * tmp = malloc(sizeof(struct linked_list *));
    if(tmp == NULL){
        perror("Error creating memory for pointer tmp\n"); //Bellek olusturma kontrolu.
    }
    tmp = root;
    int i=1;
	while(tmp != NULL){
	    printf("%d. Deger = %5d\n",i,tmp->value);
	    tmp=tmp->nextptr;
        i++;

	}
    vfp_print_window_size_ch('-',sw_cmd_width);
}
//___________________________________________________________________________________

//____________________________________LINKED LIST ALL________________________________
int main(int argc, char * argv[])
{
    //Console clear
    system("clear");
    
    giv_girdi = malloc(sizeof(char)*10);
    printf("Veri yapıları ve algoritmalar eğitim programına hoşgeldiniz.\n\n");
    
    vf_print_education_list();
    
    while(1)
    {
        //printf("1-)Bağlantılı Liste\n2-)Çift Yönlü Bağlantılı Liste\n3-)Yığıt\n4-)Kuyruk\n5-)İkili Arama Ağacı\n\n");
	printf("Eğitim Girişi:");
	fflush(stdin);
	fgets(giv_girdi,10,stdin);
	vfp_delete_enter_char(giv_girdi);
	//printf("%s",giv_girdi);
	
	/*print '-'*/	
        vfp_print_window_size_ch('-',sw_cmd_width);
	
	if(ifp_is_it_equal(giv_girdi,"1"))
	{
	//printf("1-)Bilgilendirme\n2-)Bağlantılı Liste Oluştur\n3-)Eleman Ekle\n4-)Eleman Sil\n5-)Eleman Güncelle\n6-)Listeyi Göster\n7-)Listeyi Sil\n8-)Bir Üst Menüye Dön\n");
	    
	    struct linked_list * sp_list = malloc(sizeof(struct linked_list*));
	    
	    vf_print_linked_list_menu();
	    char * cp_bagli_liste_giris = (char*)malloc(sizeof(char)*10);
	    
	    while(1)
	    {
	        fflush(stdin);
	    	printf("Seçeneği girin:");
	        fgets(cp_bagli_liste_giris,10,stdin);
	        vfp_delete_enter_char(cp_bagli_liste_giris);
	        
		/*print '-'*/
	        vfp_print_window_size_ch('-',sw_cmd_width);
	        
	        if(ifp_is_it_equal(cp_bagli_liste_giris,"1"))
		{
		    vf_print_linll_info();
		}
		else if(ifp_is_it_equal(cp_bagli_liste_giris,"2"))
		{
		    vfp_create_linked_list_rnd(sp_list,10);
		}
		else if(ifp_is_it_equal(cp_bagli_liste_giris,"3"))
		{
		    
		}
		else if(ifp_is_it_equal(cp_bagli_liste_giris,"4"))
		{
		    
		}
		else if(ifp_is_it_equal(cp_bagli_liste_giris,"5"))
		{
		    
		}
		else if(ifp_is_it_equal(cp_bagli_liste_giris,"6"))
		{
		    vfp_print_linked_list(sp_list);
		}
		else if(ifp_is_it_equal(cp_bagli_liste_giris,"7"))
		{
		    
		}
		else if(ifp_is_it_equal(cp_bagli_liste_giris,"8"))
		{
		    vf_print_education_list();
		    break;	
		}
		else if(ifp_is_it_equal(cp_bagli_liste_giris,"exit") || ifp_is_it_equal(cp_bagli_liste_giris,"Exit"))
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
