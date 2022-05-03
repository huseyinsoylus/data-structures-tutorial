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
#include <limits.h>
//___________________________________________________________________________________

//--------------------------------------Define Area---------------------------------


//-------------------------------------Global Variables------------------------------
char * giv_girdi;
struct winsize sw_cmd_width;
//___________________________________________________________________________________




//----------------------------------Function Declare Area----------------------------

//______________________________________GLOBAL FUNCTİONS_____________________________________

//----------------------------------İs It Equal Functions----------------------------
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

//----------------------------------Print Education Functions----------------------------
void vf_print_education_list()
{
    vfp_color_change("default");
    printf("Eğitim Listesi\n");
    
    vfp_print_window_size_ch('-',sw_cmd_width);
    printf("1-)Bağlantılı Liste\n2-)Kuyruk\n3-)Yığıt\n4-)İkili Arama Ağacı\n\n");
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

//-----------------------------İn Char Out İnt Value---------------------------
int charToInt(char c){
	int num = 0;

	//Substract '0' from entered char to get
	//corresponding digit
	num = c - '0';

	return num;
}
//___________________________________________________________________________________

//-----------------------------İn Char Array Out İnt Value---------------------------
int ifp_parameter_to_int(char parameter[])
{
  int lenght = strlen(parameter);
  int toplam = 0;
  int katsayi=1;
  for(int i = lenght-1;i>=0;i--)
  {
    int sayisal_deger=0;
    //printf("kaRAKTER %c",parameter[i]);
    sayisal_deger = charToInt(parameter[i]);
    //printf("sAYI KARŞILIGI %d",sayisal_deger);
    toplam += ((sayisal_deger*katsayi));
    katsayi*=10;
  }

  return toplam;
}
//___________________________________________________________________________________

//______________________________________GLOBAL FUNCTİONS_____________________________________


//_________________________________LINKED LIST ALL FUNCTİONS______________________________________

//-------------------------------Create Linked List Struct---------------------------
struct linked_list 
{
    int value;                     //Data of the node
    struct linked_list *nextptr;           //Address of the next node
};
//___________________________________________________________________________________

//----------------------------------Print Linked List Menu Functions-----------------
void vf_print_linked_list_menu()
{
    vfp_color_change("Yellow");
    
    printf("Bağlantılı Liste Eğitimine Hoşgeldiniz.\n");
    vfp_print_window_size_ch('-',sw_cmd_width);
    printf("1-)Bilgilendirme\n2-)Bağlantılı Liste Oluştur\n3-)Eleman Ekle\n4-)Eleman Sil\n5-)Eleman Güncelle\n6-)Listeyi Göster\n7-)Listeyi Sil\n8-)Bir Üst Menüye Dön\n9-)Eğitimi sonlandırmak için exit - Exit yazınız.\n");
    vfp_print_window_size_ch('-',sw_cmd_width);
    
    vfp_color_change("");
}
//___________________________________________________________________________________

//----------------------------------Print Linked List Info Func----------------------
void vf_print_linkl_info()
{
    printf("Bağlı Liste Bilgilendirme:\n");
    printf("Her düğüm yalnızca bir sonraki düğümün adresi barındırır bunun sonucu olarak tek yönde okuma yapılabilir, bir düğümden önceki düğüme erişilemez. Düğüm yapısı C programlama dilinde struct kullanılarak yapılır.\n");
    vfp_print_window_size_ch('-',sw_cmd_width);

}
//___________________________________________________________________________________


//-------------------------------Create Random Linked List----------------------------

void vfp_create_linked_list_rnd(struct linked_list *root){
    
    if(root == NULL){
        perror("Fail: No memory is allocated for the linked list to be created\n");
    }  

    struct linked_list * tmp = (struct linked_list*)malloc(sizeof(struct linked_list *));
    if(tmp == NULL){
        perror("Fail: Error creating memory for variable tmp\n"); //Bellek olusturma kontrolu.
    }
    
    char cv_list_count[10];
    printf("Bağlı liste uzunluğunu girin:");
    fgets(cv_list_count,10,stdin);
    vfp_delete_enter_char(cv_list_count);
    long int iv_list_lenght = ifp_parameter_to_int(cv_list_count);
    
    tmp = root;
    if(root != NULL && root->nextptr == NULL){

        for(int i = 1;i<iv_list_lenght;i++){
    
        struct linked_list *sp_new_node = (struct linked_list*)malloc(sizeof(struct linked_list *));
        tmp->nextptr = sp_new_node;
        sp_new_node->value = rand() % 50;
        tmp = sp_new_node; 
        }
        printf("Bağlı liste başarıyla oluşturuldu.\n");
    }
    else{
        perror("Fail: Root node is empty or already a list.\n");
    }
    
    vfp_print_window_size_ch('-',sw_cmd_width);
}
//___________________________________________________________________________________


//-------------------------------Add Linked List-----------------------------------

void vfp_add_linked_list(struct linked_list * root)
{
    char cv_add_value[10];
    printf("Eklenecek elemanı girin:");
    fgets(cv_add_value,10,stdin);
    vfp_delete_enter_char(cv_add_value);
    long int iv_list_add_value = ifp_parameter_to_int(cv_add_value);
    
    
    struct linked_list *new_node;
    if(new_node == NULL)
    {
        perror("Fail: The new_node structure pointer is not allocated.\n");
    }
    new_node = (struct linked_list*)malloc(sizeof(struct linked_list));
    new_node->value = iv_list_add_value;
    new_node->nextptr = NULL;
    
    struct linked_list *temp = root;
    while(temp->nextptr != NULL){
    temp = temp->nextptr;
    }

    temp->nextptr = new_node;
    printf("Eleman bağlı listeye başarı ile eklendi.\n");
    vfp_print_window_size_ch('-',sw_cmd_width);
}
//___________________________________________________________________________________


//-------------------------------Delete Linked List-----------------------------------
// Delete a node
void vfp_delete_linked_elements(struct linked_list * head_ref) {
 
    char cv_del_value[10];
    printf("Silinecek elemanı girin:");
    fgets(cv_del_value,10,stdin);
    vfp_delete_enter_char(cv_del_value);
    long int iv_list_del_value = ifp_parameter_to_int(cv_del_value); 
 
    struct linked_list *temp = head_ref, *prev;

    if (temp != NULL && temp->value == iv_list_del_value) {
    head_ref = temp->nextptr;
    free(temp);
    return;
    }
    // Find the key to be deleted
    while (temp != NULL && temp->value != iv_list_del_value) {
    prev = temp;
    temp = temp->nextptr;
    }

    // If the key is not present
    if (temp == NULL) 
    {
        printf("Silinecek eleman listede bulunmuyor\n");
        vfp_print_window_size_ch('-',sw_cmd_width);
        return;
    }
    else
    {
        printf("%ld Elemanı başarıyla silindi.\n",iv_list_del_value);
        vfp_print_window_size_ch('-',sw_cmd_width);
    }

    // Remove the node
    prev->nextptr = temp->nextptr;

    free(temp);
}
//___________________________________________________________________________________

//-------------------------------Update Linked List-----------------------------------
void vfp_update_link_list(struct linked_list * head) {

    //start from the first link
    struct linked_list* current = head;

    //if list is empty
    if(head == NULL) 
    {  
        return;
    }
    
    
    char cv_search_value[10];
    printf("Güncellenecek elemanı girin:");
    fgets(cv_search_value,10,stdin);
    vfp_delete_enter_char(cv_search_value);
    long int iv_list_search_value = ifp_parameter_to_int(cv_search_value);
    
    char cv_upt_value[10];
    printf("Güncel değeri girin:");
    fgets(cv_upt_value,10,stdin);
    vfp_delete_enter_char(cv_upt_value);
    long int iv_list_upt_value = ifp_parameter_to_int(cv_upt_value);
    
   //navigate through list
    while(current->value != iv_list_search_value) 
    {
       //if it is last node
        if(current->nextptr == NULL) 
        {
            printf("Güncellenecek değer listede bulunamadı.\n");
            return;
        } 
        else 
        {
         //go to next link
            current = current->nextptr;
        }
        if(current->value == iv_list_search_value)
        {
            current->value = iv_list_upt_value;
            printf("%ld değeri %ld ile başarılı bir şekilde güncellenmiştir.\n",iv_list_search_value,iv_list_upt_value);
            break;
        }
    }
     
    vfp_print_window_size_ch('-',sw_cmd_width);	
   //if data found, return the current Link
   //return current;
}
//___________________________________________________________________________________

//-------------------------------Print Linked List-----------------------------------
void vfp_print_linked_list(struct linked_list * root){

    if(root == NULL){
        perror("Fail: The linked list is empty.\n");
    }  

	struct linked_list * tmp = (struct linked_list*)malloc(sizeof(struct linked_list *));
    if(tmp == NULL){
        perror("Fail: Error creating memory for pointer tmp\n"); //Bellek olusturma kontrolu.
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

//-------------------------------Delete Linked List-----------------------------------
void vfp_delete_linked_list(struct linked_list * root)
{
    root->nextptr=NULL;
    root = NULL;
    printf("Liste başarıyla silindi.\n");
    vfp_print_window_size_ch('-',sw_cmd_width);
}
//___________________________________________________________________________________

//____________________________________LINKED LIST ALL________________________________

//###################################################################################

//____________________________________QUEUE ALL______________________________________

//----------------------------------Create Queue Struct -----------------------------
// A structure to represent a queue
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};
//___________________________________________________________________________________

//---------------------------------Print Queue MENU-----------------------------------
void vf_print_queue_menu()
{
    vfp_color_change("Yellow");
    
    printf("Kuyruk Eğitimine Hoşgeldiniz.\n");
    vfp_print_window_size_ch('-',sw_cmd_width);
    printf("1-)Bilgilendirme\n2-)Kuyruk Oluştur\n3-)Sıraya Ekle\n4-)Sıradan Çıkar\n5-)Sıradaki Elemanı Göster\n6-)Sondaki Elemanı Göster\n7-)Kuyruğu Sil\n8-)Bir Üst Menüye Dön\n9-)Eğitimi sonlandırmak için exit - Exit yazınız.\n");
    vfp_print_window_size_ch('-',sw_cmd_width);
    
    vfp_color_change("");
}
//___________________________________________________________________________________


//----------------------------------Print Queue Info Func----------------------
void vf_print_queue_info()
{
    printf("Kuyruk Bilgilendirme:\n");
    printf("Kuyruk, eleman eklemelerin sondan (rear) ve eleman çıkarmaların bastan (front) yapıldığı, (First InFirst Out-İlk Gelen İlk Çıkar –FIFO) olarak modellenen, doğrusal bir veri saklama yapısıdır.\n");
    printf("--> Bir elemanın kuyruğa girmesi insert(literatürde put, add veya enqueue olarak da geçer) işlemi iken listeden silinmesi remove (delete veya dequeue) işlemidir.\n");
    printf("--> Insert’ler kuyruğun arkasından yapılırken, remove’lar kuyruğun önünden yapılırlar.\n");
    printf("--> Boş bir kuyruktan eleman silmeye çalışmak underflow hatası üretirken, dolu bir kuyruğa eleman eklemeye çalışmak overflow hatası üretir.\n");
    printf("--> Kuyruk yapısı, yığın yapısına oldukça benzemektedir. İkisinde de eleman ekleme işlemi en sondan yapılmaktadır.\n");
    printf("--> Aralarındaki fark eleman çıkartmanın yığın yapısında en sondan, kuyruk yapısında ise en baştan yapılmasıdır.\n");
    vfp_print_window_size_ch('-',sw_cmd_width);

}
//___________________________________________________________________________________

//---------------------------------Initialize Queue -----------------------------------
struct Queue* sf_create_queue()
{
    char cv_unsig_capacity_value[10];
    printf("Kuyruk kapasitesini girin:");
    fgets(cv_unsig_capacity_value,10,stdin);
    vfp_delete_enter_char(cv_unsig_capacity_value);
    unsigned iv_unsig_capacity_value = ifp_parameter_to_int(cv_unsig_capacity_value);
    
    struct Queue* queue = (struct Queue*)malloc(
        sizeof(struct Queue));
    queue->capacity = iv_unsig_capacity_value;
    queue->front = queue->size = 0;
 
    // This is important, see the enqueue
    queue->rear = iv_unsig_capacity_value - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    printf("Kuyruk %d kapasitesi ile başarıyla oluşturuldu.\n",iv_unsig_capacity_value);
    vfp_print_window_size_ch('-',sw_cmd_width);
    return queue;
}
//___________________________________________________________________________________

//---------------------------------Is Full Queue -----------------------------------
int ifp_is_full_queue(struct Queue* queue)
{
    return (queue->size == queue->capacity);
}
//___________________________________________________________________________________

//---------------------------------Is Emty Queue -----------------------------------
int ifp_is_empty_queue(struct Queue* queue)
{
    return (queue->size == 0);
}
//___________________________________________________________________________________

//---------------------------------Enqueue Function -----------------------------------
void vfp_enqueue(struct Queue* queue)
{
    
    if(queue == NULL)
    {
        printf("Kuyruk oluşturulmamış. Oluşturmak için 2 Komutu ile devam edin.\n");
        vfp_print_window_size_ch('-',sw_cmd_width);
    }
    else
    {
	char cv_que_add_value[10];
	printf("Kuyruğa eklenecek elemanı girin:");
	fgets(cv_que_add_value,10,stdin);
	vfp_delete_enter_char(cv_que_add_value);
	unsigned iv_add_que_value = ifp_parameter_to_int(cv_que_add_value);

	if (ifp_is_full_queue(queue))
	return;
	queue->rear = (queue->rear + 1)
		  % queue->capacity;
	queue->array[queue->rear] = iv_add_que_value;
	queue->size = queue->size + 1;
	printf("%d Kuyruğa alındı.\n", iv_add_que_value);
	vfp_print_window_size_ch('-',sw_cmd_width);
    }
    

}
//___________________________________________________________________________________

//---------------------------------Dequeue Function -----------------------------------
void vfp_dequeue(struct Queue* queue)
{
    if(queue == NULL)
    {
        printf("Kuyruk oluşturulmamış. Oluşturmak için 2 Komutu ile devam edin.\n");
        vfp_print_window_size_ch('-',sw_cmd_width);
    }
    else
    {
	if (ifp_is_empty_queue(queue))
	{
	    printf("Sırada bekleyen kimse yok. Kuyruk boş.\n");
	}
	int item = queue->array[queue->front];
	queue->front = (queue->front + 1)
		   % queue->capacity;
	queue->size = queue->size - 1;
	printf("%d elemanının kuyrukta işi bitmiştir.\n",item);
	vfp_print_window_size_ch('-',sw_cmd_width);
    }
}
//___________________________________________________________________________________

//---------------------------------Queue Front Function -----------------------------------
void vfp_queue_front(struct Queue* queue)
{
    if(queue == NULL)
    {
        printf("Kuyruk oluşturulmamış. Oluşturmak için 2 Komutu ile devam edin.\n");
        vfp_print_window_size_ch('-',sw_cmd_width);
    }
    else
    {
	if (ifp_is_empty_queue(queue))
	{
	    printf("Sırada bekleyen kimse yok. Kuyruk boş.\n");
	    vfp_print_window_size_ch('-',sw_cmd_width);
	}
	vfp_print_window_size_ch('-',sw_cmd_width);
	printf("Kuyrukta bekleyen sıradaki eleman %d\n",queue->array[queue->front]);
    }
}
//___________________________________________________________________________________

//---------------------------------Queue Rear Function -----------------------------------
void vfp_queue_rear(struct Queue* queue)
{
    if(queue == NULL)
    {
        printf("Kuyruk oluşturulmamış. Oluşturmak için 2 Komutu ile devam edin.\n");
        vfp_print_window_size_ch('-',sw_cmd_width);
    }
    else
    {
	if (ifp_is_empty_queue(queue))
	{
	    printf("Sırada bekleyen kimse yok. Kuyruk boş.\n");
	    vfp_print_window_size_ch('-',sw_cmd_width);
	}
	printf("Kuyruğun sonundaki eleman %d\n",queue->array[queue->rear]);
	vfp_print_window_size_ch('-',sw_cmd_width);
    }
}
//___________________________________________________________________________________


//____________________________________QUEUE ALL______________________________________

//###################################################################################

//____________________________________STACK ALL______________________________________


//---------------------------------Stack Struct Create-------------------------------
struct stack_node {
    int data;
    struct stack_node* next;
};
//___________________________________________________________________________________

//---------------------------------Print Stack MENU-----------------------------------
void vf_print_stack_menu()
{
    vfp_color_change("Yellow");
    
    printf("Yığıt Eğitimine Hoşgeldiniz.\n");
    vfp_print_window_size_ch('-',sw_cmd_width);
    printf("1-)Bilgilendirme\n2-)Yığıt Oluştur\n3-)Push\n4-)Pop\n5-)Peek\n6-)Yığıtı Sil\n8-)Bir Üst Menüye Dön\nEğitimi sonlandırmak için exit - Exit yazınız.\n");
    vfp_print_window_size_ch('-',sw_cmd_width);
    
    vfp_color_change("");
}
//___________________________________________________________________________________


//----------------------------------Print Queue Info Func----------------------------
void vf_print_stacks_info()
{
    printf("Stack Bilgilendirme:\n");
    printf("Stack, doğrusal artan bir veri yapısı olup; Insert (push) ve Delete (pop) işlemleri, Listenin sadece “top” adı verilen bir ucunda yani stack’in en üstünden gerçekleştirilir. Bu nedenle stack Son Giren İlk Çıkar (Last In First Out-LIFO) mantığı ile işleyen bir veri yapısıdır.\n");
    vfp_print_window_size_ch('-',sw_cmd_width);

}
//___________________________________________________________________________________

//----------------------------------Create Stack Function----------------------------
void vfp_create_stack(struct stack_node * stack)
{
    stack=malloc(sizeof(struct stack_node*));
    printf("Stack başarıyla oluştutuldu.\n");
    vfp_print_window_size_ch('-',sw_cmd_width);
}
//___________________________________________________________________________________

//--------------------------------Is Empty Stack Function----------------------------
int ifp_is_empty_stack(struct stack_node* root)
{
    return !root;
}
//___________________________________________________________________________________

//--------------------------------New Node Stack Function----------------------------
struct stack_node* new_node(int data)
{
    struct stack_node* stackNode =(struct stack_node*)malloc(sizeof(struct stack_node));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}
//___________________________________________________________________________________

//--------------------------------Push Stack Function--------------------------------
void vfp_push_stack(struct stack_node** root)
{
    char cv_stack_add_value[10];
    printf("Yığıta atılacak elemanı girin:");
    fgets(cv_stack_add_value,10,stdin);
    vfp_delete_enter_char(cv_stack_add_value);
    int iv_add_stack_value = ifp_parameter_to_int(cv_stack_add_value);
    
    struct stack_node* stackNode = new_node(iv_add_stack_value);
    stackNode->next = *root;
    *root = stackNode;
    printf("%d Eleman yığıta eklendi\n", iv_add_stack_value);
    vfp_print_window_size_ch('-',sw_cmd_width);
}
//___________________________________________________________________________________

//-----------------------------------Pop Stack Function------------------------------

void vfp_pop_stack(struct stack_node** root)
{
    if (ifp_is_empty_stack(*root))
    {
        printf("Stack boş.\n");
    }
    else
    {
        struct stack_node* temp = *root;
	*root = (*root)->next;
	int popped = temp->data;
	free(temp);
	printf("%d elemanı yığıttan çıkarıldı.\n",popped);
	vfp_print_window_size_ch('-',sw_cmd_width);
    }
    
}

//___________________________________________________________________________________

//-----------------------------------Peek Stack Function------------------------------
int ifp_stack_peek(struct stack_node* root)
{
    if (ifp_is_empty_stack(root))
    {
        printf("Yığıt boş.\n");
    }
    else
    {
        printf("Yığıtın en üstündeki eleman --> %d\n",root->data);
        vfp_print_window_size_ch('-',sw_cmd_width);
    }
}
//___________________________________________________________________________________

void vfp_delete_stack(struct stack_node * root)
{
    root = NULL;
    printf("Yığıt silindi.\n");
    vfp_print_window_size_ch('-',sw_cmd_width);
}

//____________________________________STACK ALL______________________________________

/*
*
*
*
*
*
*
*
*
*		MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN  
*
*
*
*
*
*
*
*/


int main(int argc, char * argv[])
{
    //Console clear
    system("clear");
    
    giv_girdi = (char*)malloc(sizeof(char)*10);
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
	    
	    struct linked_list * sp_list = (struct linked_list*)malloc(sizeof(struct linked_list*));//Bir üst listeye çıkıldığında liste kaybolur.
	    
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
		    vf_print_linkl_info();
		}
		else if(ifp_is_it_equal(cp_bagli_liste_giris,"2"))
		{
		    vfp_create_linked_list_rnd(sp_list);
		}
		else if(ifp_is_it_equal(cp_bagli_liste_giris,"3"))
		{
		    vfp_add_linked_list(sp_list);
		}
		else if(ifp_is_it_equal(cp_bagli_liste_giris,"4"))
		{
		    vfp_delete_linked_elements(sp_list);
		}
		else if(ifp_is_it_equal(cp_bagli_liste_giris,"5"))
		{
		    vfp_update_link_list(sp_list);
		}
		else if(ifp_is_it_equal(cp_bagli_liste_giris,"6"))
		{
		    vfp_print_linked_list(sp_list);
		}
		else if(ifp_is_it_equal(cp_bagli_liste_giris,"7"))
		{
		    vfp_delete_linked_list(sp_list);
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
		    vfp_print_window_size_ch('-',sw_cmd_width);
		}
	    }
	}
	else if(ifp_is_it_equal(giv_girdi,"2"))
	{
	    struct Queue* queue;  
	    
	    vf_print_queue_menu();
	    char * cp_kuyruk_giris = (char*)malloc(sizeof(char)*10);
	    
	    while(1)
	    {
	    //printf("1-)Bilgilendirme\n2-)Kuyruk Oluştur\n3-)Sıraya Ekle\n4-)Sıradan Çıkar\n5-)Sıradaki Elemanı Göster\n6-)Sondaki Elemanı Göster\n7-)Kuyruğu Sil\n8-)Bir Üst Menüye Dön\n");
	        fflush(stdin);
	    	printf("Seçeneği girin:");
	        fgets(cp_kuyruk_giris,10,stdin);
	        vfp_delete_enter_char(cp_kuyruk_giris);
	        
		/*print '-'*/
	        vfp_print_window_size_ch('-',sw_cmd_width);
	        
	        if(ifp_is_it_equal(cp_kuyruk_giris,"1"))
		{
		    vf_print_queue_info();
		}
		else if(ifp_is_it_equal(cp_kuyruk_giris,"2"))
		{
		    queue=sf_create_queue();
		}
		else if(ifp_is_it_equal(cp_kuyruk_giris,"3"))
		{
		    vfp_enqueue(queue);
		}
		else if(ifp_is_it_equal(cp_kuyruk_giris,"4"))
		{
		    vfp_dequeue(queue);
		}
		else if(ifp_is_it_equal(cp_kuyruk_giris,"5"))
		{
		    vfp_queue_front(queue);
		}
		else if(ifp_is_it_equal(cp_kuyruk_giris,"6"))
		{
		    vfp_queue_rear(queue);
		}
		else if(ifp_is_it_equal(cp_kuyruk_giris,"7"))
		{
		    queue=NULL;
		    printf("Kuyruk silindi.\n");
		}
		else if(ifp_is_it_equal(cp_kuyruk_giris,"8"))
		{
		    vf_print_education_list();
		    break;	
		}
		else if(ifp_is_it_equal(cp_kuyruk_giris,"exit") || ifp_is_it_equal(cp_kuyruk_giris,"Exit"))
		{
		    printf("Programdan çıkılıyor. İyi günler dileriz.\n");
		    _Exit(0);
		}
		else
		{
		    printf("Giriş yaptığınız değer geçersizdir.\n");
		    vfp_print_window_size_ch('-',sw_cmd_width);
		}
	    }
	}
	else if(ifp_is_it_equal(giv_girdi,"3"))
	{
	    struct stack_node* root=NULL;  
	    vf_print_stack_menu();
	    char * cp_stack_giris = (char*)malloc(sizeof(char)*10);
	    
	    while(1)
	    {
	    //printf("1-)Bilgilendirme\n2-)Yığıt Oluştur\n3-)Push\n4-)Pop\n5-)Peek\n6-)Yığıtı Sil\n8-)Bir Üst Menüye Dön\nEğitimi sonlandırmak için exit - Exit yazınız.\n");
	        fflush(stdin);
	    	printf("Seçeneği girin:");
	        fgets(cp_stack_giris,10,stdin);
	        vfp_delete_enter_char(cp_stack_giris);
	        
		/*print '-'*/
	        vfp_print_window_size_ch('-',sw_cmd_width);
	        
	        if(ifp_is_it_equal(cp_stack_giris,"1"))
		{
		    vf_print_stacks_info();
		}
		else if(ifp_is_it_equal(cp_stack_giris,"2"))
		{
		   vfp_create_stack(root);
		}
		else if(ifp_is_it_equal(cp_stack_giris,"3"))
		{
		    vfp_push_stack(&root);
		}
		else if(ifp_is_it_equal(cp_stack_giris,"4"))
		{
		    vfp_pop_stack(&root);
		}
		else if(ifp_is_it_equal(cp_stack_giris,"5"))
		{
		    ifp_stack_peek(root);
		}
		else if(ifp_is_it_equal(cp_stack_giris,"6"))
		{
		    vfp_delete_stack(root);
		}
		else if(ifp_is_it_equal(cp_stack_giris,"7"))
		{
		}
		else if(ifp_is_it_equal(cp_stack_giris,"8"))
		{
		    vf_print_education_list();
		    break;	
		}
		else if(ifp_is_it_equal(cp_stack_giris,"exit") || ifp_is_it_equal(cp_stack_giris,"Exit"))
		{
		    printf("Programdan çıkılıyor. İyi günler dileriz.\n");
		    _Exit(0);
		}
		else
		{
		    printf("Giriş yaptığınız değer geçersizdir.\n");
		    vfp_print_window_size_ch('-',sw_cmd_width);
		}
	    }
	}
	else if(ifp_is_it_equal(giv_girdi,"4"))
	{
	    printf("İkili Arama Ağacı Eğitimine Hoşgeldiniz.\n");
	}
	else if(ifp_is_it_equal(giv_girdi,"exit") || ifp_is_it_equal(giv_girdi,"Exit"))
	{
	    printf("Programdan çıkılıyor. İyi günler dileriz.\n");
	    _Exit(0);
	}
	else
	{
	    printf("Giriş yaptığınız değer geçersizdir.\n");
	    vfp_print_window_size_ch('-',sw_cmd_width);
	}
    }
}														
