#include <stdio.h>
#include <stdlib.h>


//Run program with
//gcc -o file1.c file2.c ...

struct list_item{
  int value;
  struct list_item *next;
};

void append (struct list_item *first, int x); /*put x at end of list*/
void prepend (struct list_item *first, int x);/*put x at the start of list*/
void print (struct list_item *first); /*prints all elements in the list*/
/*input_sorted: find the first element in the list larger than x and input x right before that element*/
void input_sorted(struct list_item *first, int x);
void clear (struct list_item *first); /*free everything dynamically sorted*/

int main( int argc, char ** argv){
  struct list_item root;
  root.value = -1; /* This value is always ignored*/
  root.next = NULL; // pointer
  append(&root,3);
  append(&root, 69);
  append(&root, 'A');
  append(&root, 43);
  prepend(&root, 43);
  input_sorted(&root, 45);
  print(&root);
  clear(&root);
  append(&root, 57);
  print(&root);
  clear(&root);
  clear(&root);
}

void append (struct list_item *first, int x){
  while(first->next != NULL){
      first = first->next;
  }
  struct list_item *node = NULL;
  node = (struct list_item *) malloc(sizeof(struct list_item));
  node->value = x;
  node->next = NULL;
  first->next = node;
}

void prepend(struct list_item *first, int x){
  struct list_item *node = NULL;
  node = (struct list_item *) malloc(sizeof(struct list_item));
  node->value = x;
  node->next = first->next;
  first->next = node;
}

void print(struct list_item *first){
  first = first->next;
    printf("Value \t Adress \t\t Next\n");
  while(first != NULL){
    printf("%d \t %p \t %p\n", first->value,first, first->next);
    //printf("%d ", first->value);
    first = first->next;
  }
  printf("\n");
}

void input_sorted(struct list_item *first, int x){
    struct list_item *node;
    while(first->value < x){
      node = first;
      first = first->next;
    }
    prepend(node, x);
}

void clear(struct list_item *first){
  struct list_item *node = first->next; // kopierar 1a element så jag har tillgång till root efter
  struct list_item *next; // Kopia av next innan free, minnes ändras efter det
  while(node != NULL){
    next = node->next;
    free(node);
    node = next; //Då node är fri måste jag sätta den till kopians next igen
  }
  first->next = NULL;
}
