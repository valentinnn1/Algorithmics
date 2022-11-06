#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
   int data;    //promenliva za stoynostta na elementite v spisuka
   int key;     //promenliva za index-a na elementite v spisuka
   struct node *next;   //pointer, koyto sochi kum sledvashtiq element
};

struct node *head = NULL;   //pointer ot tipa na structurata, koyto sochi kum purviqt element (glavata) na spisuka
struct node *current = NULL;//pointer ot tipa na structurata, koyto sochi tekushtiqt element (za iterirane)

void printList() {  //funkciq za pokazvane na elementite na spisuka
   struct node *ptr = head; //pointer, koyto sochi kum tekushtiq element za obhozhdane
   printf("\n[ ");

   //start from the beginning
   while(ptr != NULL) { //da se vurti dokato elementa, kum koyto sochi pointera e razlichen ot NULL
      printf("(%d,%d) ",ptr->key,ptr->data);    //nasochvame pointera kum indeksa i kum stoynostta i go printirame
      ptr = ptr->next;  //nasochvame pointera kum sledvashtiqt element
   }

   printf(" ]");
}

void insertFirst(int key, int data) {   //funkciq za dobavqne na element nay otpred v spisuka
   struct node *link = (struct node*) malloc(sizeof(struct node));  //zadelqne na neobhodimata pamet za elementa

   link->key = key; //nasochvane na pointera kum indeksa, zadavane na stoynost na indeksa po podadeniq argument vuv funkciqta
   link->data = data;   //nasochvane na pointera kum stoynostta, zadavane na stoynost na stoynostta po podadeniq argument vuv funkciqta

   link->next = head;   //nasochvane na pointera kum predishniq purvi element

   head = link; //zadavame adresa na glavata s noviq purvi element
}

struct node* deleteFirst() {    //funkciq za iztrivane na purviq element vuv spisuka (pop-vane pri stekovete i opashkite)

   struct node *tempLink = head;    //zapazvame referenciq kum purviqt element (glavata)

   head = head->next;   //promenqme pointera na glavata kum sledvashtiqt element, i po tozi nachin predishniq purvi izpada ot psisuka

   return tempLink; //vrushtame osvobodeniqt element
}

bool isEmpty() {    //proverqva dali spisuka e prazen
   return head == NULL; //vrushta true ako pointera na glavata sochi kum NULL, toest spisuka e prazen
}

int length() {  //funkciq za dulzhinata na spisuka
   int length = 0;
   struct node *current;    //tekushtiq element, izpolzvan za obhozhdane na spisuka

   for(current = head; current != NULL; current = current->next) {  //nasochvame tekushtiq element da zapoche ot glavata, dokato sochi kum element, razlichen ot NULL, da se nasochva kum sledvashtiqt element
      length++; //i da se uvelichava dulzhinata na elementa
   }

   return length;   //vrushtame goleminata na spisuka
}

struct node* find(int key) {    //funkciq za namirane na element po index

   struct node* current = head; //nasochvame "iteratora" kum purviqt element na spisuka (glavata)

   if(head == NULL) {   //pravim proverka dali spisuka ne e prazen
      return NULL;      //ako e prazen prekratqvame izpulnenieto na funkciqta i vrushtame NULL
   }

   //navigate through list
   while(current->key != key) { //vurtim cikula dokato indeksa na tekushtiqt element ne suvpadne s podadeniqt index na funkciqta

      if(current->next == NULL) {   //ako dostignem krayniqt element i ne sme namerili turseniqt, prekratqvame izpulnenieto na funkciqta
         return NULL;               // i vrushtame NULL
      } else {
         current = current->next;   //nasochvame iteratora kum sledvashtiqt element
      }
   }

   return current;  //ako sme namerlili elementa s turseniqt index, vrushtame pointera, koyto go sochi
}

struct node* delete(int key) {  //funkciq za iztrivane na element po podaden index

   struct node* current = head; //nasochvane na "iteratora" kum purviqt element (glavata)
   struct node* previous = NULL;//suzdavane na pointer, koyto sochi kum predishniqt element; neobhodimo ni e za da prenasochim pointera kum elementa sled tozi, koyto shte iztriem

   if(head == NULL) {   //proverka dali spisuka ne e prazen
      return NULL;      //prekratqvane na izpulnenieto na funkciqta
   }

   while(current->key != key) { //obhozhdane dokato ne se nameri elementa s podadeniq index

      if(current->next == NULL) {   //ako sme dostignali do posledniqt element i ne sme namerili suvpadeniq prekratqvame izpulnenieto na funkciqta
         return NULL;
      } else {
         previous = current;    //zadavame stoynostta na predishniq element sus adresa na tekushtiqt
         current = current->next;   //nasochvame "iteratora" kum sledvashtiqt lement
      }
   }

   if(current == head) {    //proverka dali elementa koyto iskame da iztriem ne e purviqt (glavata)
      head = head->next;    //ako iztrivame purviqt element nasochvame pointera na glavata kum sledvashtiqt lement, za da ne izgubim vruzkata
   } else {
      previous->next = current->next;   //izolirame iztritiqt element, kato nasochvame predishniq element, kum sledvashtiqt
   }

   return current;  //vrushtame pointera, koyto sochi kum iztritiqt element
}

void sort() {   //funkciq za sortirane na spisuka (izpolzvame buble sort)

   int i, j, k, tempKey, tempData;
   struct node *current;    //"iterator" za tekushtiq element
   struct node *next;       //pointer za sledvashtiqt element

   int size = length();     //izvikvame funkciqta za goleminata na spisuka
   k = size ;

   for ( i = 0 ; i < size - 1 ; i++, k-- ) {
      current = head;   //nasochvame tekushtiqt element kum glavata
      next = head->next;    //nasochvame pointera next kum sledvashtiqt element sled glavata

      for ( j = 1 ; j < k ; j++ ) {

         if ( current->data > next->data ) {    //ako tekushtiqt element e po golqm ot sledvashtiqt im razmenqme stoynostite i indeksite posredstvom treta promenliva
            tempData = current->data;
            current->data = next->data;
            next->data = tempData;

            tempKey = current->key;
            current->key = next->key;
            next->key = tempKey;
         }

         current = current->next; //nasochvame iteratora kum sledvashtiqt element
         next = next->next; //nasochvame sledvashtiqt element kum po-sledvashtiqt
      }
   }
}

void main() {
    char command[10];
    int n=0, element=0, itemToFound=0, itemToDelete=0; //n - broqt na elementite, koito iskame da vuvedem v spisuka, element - stoynostta na dadeniqt element
    do{
        printf("command (Add, Print, Delete, Find(by index), DelByIndex, Sort, END): ");
        scanf("%s", command);
        if(strcmp(command, "Add")==0){
            printf("n=");
            scanf("%d", &n);
            for(int i=1; i<=n; i++){
                printf("[%d]:", i);
                scanf("%d", &element);  //vuvezhdame stoynost na lokalnata promenliva
                insertFirst(i,element); //izvikvame funkciqta insertFirst i predavame stoynostta ot lokalnata promenliva element
            }
        }

        else if(strcmp(command, "Print")==0){
            printf("Original List: ");
            printList();     //izvikvame funkciqta za pechatane na spisuka
            printf("\n");
        }

        else if(strcmp(command, "Delete")==0){
            while(!isEmpty()) {  //izvikvame funkciqta "isEmpty" za da proverqvame koga spisuka shte se izprazni
              struct node *temp = deleteFirst();    //sled tova izvikvame funkciqta deleteFirst, dokato spisuka e pulen i iztrivame elementite postepenno
              printf("Deleted value: (%d,%d) \n",temp->key,temp->data);  //pechatame indeksa i stoynostta na iztritiqt element
           }
        }

        else if(strcmp(command, "Find")==0)
        {
            printf("Item to find: ");
           scanf("%d", &itemToFound);
           struct node *foundLink = find(itemToFound);    //izvikvame funkciqta za namirane na element po index i prisvoqvame pointera na lokalna promenliva

           if(foundLink != NULL) {  //ako elementa e nameren
              printf("Element found: (%d,%d) ",foundLink->key,foundLink->data);    //printirame indeksa i stoynostta na elementa
              printf("\n");
           } else {
              printf("Element not found.\n"); //ako ne e nameren printirame suotvetnoto suobshtenie
           }
        }


       else if (strcmp(command, "DelByIndex")==0){
            printf("Item to delete: ");
            scanf("%d", &itemToDelete);
            delete(itemToDelete);   //izvikvame funkciqta za iztrivane na element
            printf("List after deleting an item: ");
            printList();    //izvikvame funkciqta za printirane na spisuka
            printf("\n");
            struct node *foundLink = find(itemToDelete); //izvikvame funkciqta za namirane na elementa i prisvoqvame pointera na lokalna promenliva

            if(foundLink != NULL) {     //proverqvame, ako elementa ne sochi NULL, e nameren
               printf("Element found: (%d,%d) ",foundLink->key,foundLink->data);   //printirame indexa i stoynostta na elementa
               printf("\n");
            } else {
              printf("Element not found.\n"); //ako ne go namerim printirame suotvetnoto suobshtenie
           }
       }

        else if(strcmp(command, "Sort")==0){
           sort();  //izvikvame funkciqta za sortirane
           printf("List after sorting the data: ");
           printList(); //i printirame noviq spisuk
           printf("\n");
        }

    }while(strcmp(command, "END")!=0);
}
