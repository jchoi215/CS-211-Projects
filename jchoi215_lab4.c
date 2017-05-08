#include <stdio.h>

typedef struct p{
       int id1;
       char name;
       int id2;
       char c;
       float percentage;
}p;

typedef struct p_C{
       float percentage;
       int id1;
       int id2;
       char c;
       char name;
}p_C;

// ===============================================

typedef struct q{
char first[10];
char middle_initial;
char last[10];
double salary;
int numinhousehold;
}q;

typedef struct q_C{
double salary;
int numinhousehold;
char first[10];
char last[10];
char middle_initial;
}q_C;

// ===============================================

typedef struct r{
char b;
int a[2];
int i;
char c;
int *p;
};

typedef struct r_C{
  int a[2];
  int i;
  int *p;
  char b;
  char c;
}r_C;

// ================================================

typedef struct linked{
    int d;
    struct linked *next;
    struct linked *prev;
    char c;
};

typedef struct linked_C{
    int d;
    char c;
    struct linked *next;
    struct linked *prev;
}linked_C;

// =================================================

typedef struct mat{
	int a[4][3];
	char b[10];
	double d;
	int c[3][3];
};

typedef struct mat_C{
	int a[4][3];
  int c[3][3];
	char b[10];
	double d;
}mat_C;

// ===================================================

void main()
{
printf("Problem 1:\n");
p p_AS_IS;
printf("Old Size: %d\n", p_AS_IS);
p_C p_with_changes;
printf("New Size: %d\n", p_with_changes);


printf("Problem 2:\n");
q part2a;
printf("Old Size: %d\n", part2a);
q_C part2b;
printf("New Size: %d\n", part2b);


printf("Problem 3:\n");
q part3a;
printf("Old Size: %d\n", part3a);
q_C part3b;
printf("New Size: %d\n", part3b);


printf("Problem 4:\n");
q part4a;
printf("Old Size: %d\n", part4a);
q_C part4b;
printf("New Size: %d\n", part4b);


printf("Problem 5:\n");
q part5a;
printf("Old Size: %d\n", part5a);
q_C part5b;
printf("New Size: %d\n", part5b);


}
