#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
	char *name;
	struct list_elem elem;
};

void insert (struct list *student_list) {
  struct student *s;
  char n[20];
  s = (struct student *)malloc(sizeof(*s));
  s->name = (char*)malloc(20*sizeof(char));
  printf("%s\n", "Enter Student Name");
  scanf("%s", s->name);
  list_push_back(student_list, &s->elem);
}

void delete (struct list *student_list) {
  char * input = (char *) malloc(20*sizeof(char));
  printf("%s\n","Name to delete: ");
  scanf("%s", input);
  struct list_elem *e;
  for (e = list_begin (student_list); e != list_end (student_list); e = list_next (e)){
    printf("inside loop\n" );
    struct student *s = list_entry(e, struct student, elem);
    if(strcmp(s->name, strcat(input, "\n"))){
      printf("DELETE");
      list_remove(e);
      free(s->name);
      free(s);
      free(input);
      return;
    }
  }
}

void list (struct list *student_list) {
  struct list_elem *e;
  for (e = list_begin (student_list); e != list_end (student_list); e = list_next (e)){
    struct student *s = list_entry(e, struct student, elem);
    printf("%s\n", s->name);
  }
}

void clear(struct list *student_list){
  struct list_elem *e;
  for (e = list_begin (student_list); e != list_end (student_list); e = list_next (e)){
    struct student *s = list_entry(e, struct student, elem);
    list_remove(e);
    free(s->name);
    free(s);
  }
}

void quit (struct list *student_list) {
  clear(student_list);
  list(student_list);
  exit(1);
}

int main() {
	struct list student_list;
	list_init (&student_list);
	int opt;

	do {
		printf("Menu:\n");
		printf("1 - Insert student\n");
		printf("2 - Delete student\n");
		printf("3 - List students\n");
		printf("4 - Exit\n");
		scanf("%d", &opt);
		switch (opt) {
			case 1:
				{
					insert(&student_list);
					break;
				}
			case 2:
				{
					delete(&student_list);
					break;
				}
			case 3:
				{
					list(&student_list);
					break;
				}

			case 4:
				{
					quit(&student_list);
					break;
				}
			default:
				{
					printf("Quit? (1/0):\n");
					scanf("%d", &opt);
					if (opt)
						quit(&student_list);
					break;
				}
		}
	} while(1);

	return 0;
}
