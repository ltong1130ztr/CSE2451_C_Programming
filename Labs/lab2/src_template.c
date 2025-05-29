#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

/*
why do you have to link the math library in C when using GCC
https://stackoverflow.com/questions/1033898/why-do-you-have-to-link-the-math-library-in-c
*/

struct list_node {
    char name[40];
    double grade;
    struct list_node * next;
};

typedef struct list_node Node;
Node * create_node(char * name, double grade);
Node * push_data(char * name, double grade, Node * list);
void print_list(Node * list);

// void delete_list(Node * list); // question 1
// int grade_stats(Node * list, double * mean, double * std); // question 2
// Node * file_to_list(char * file_path); // question 3

// bonus questions
// double min_grade(Node * list);
// double max_grade(Node * list);
// double apply(Node * list, ? );

int main(void) {

    // test list functions
    Node * list = create_node("Tom", 93.5);
    list = push_data("Adam", 94.6, list);
    list = push_data("Ada", 99.9, list);
    list = push_data("Nick", 85.3, list);

    // normal list
    print_list(list);
    // empty list
    print_list(NULL);

    // question 2, test cases
    // double mean = -1, std = -1;
    // int count = grade_stats(list, &mean, &std);
    // printf("number of students: %d\ngrade mean: %.3lf\ngrade std: %.4lf\n", count, mean, std);

    // question 1, test case
    // delete_list(list);

    // question 3, test case
    // list is pointing to a memory block that is freed
    // assign new address to list pointer
    // list = file_to_list("text.txt");
    // print_list(list);

    // bonus, test cases
    // printf("grade min: %.3lf\n", apply(list, min_grade));
    // printf("grade max: %.3lf\n", apply(list, max_grade));

    // delete newly assigned memory blocks by file_to_list
    // delete_list(list);

    return 0;
}


Node * create_node(char * name, double grade) {
    Node * node = malloc(sizeof(*node));
    // abort if malloc failed
    assert(node != NULL);
    // abort if input name is longer than 39 non-terminating chars
    assert(strlen(name) <= 39);
    strncpy(node->name, name, 39);
    node->grade = grade;
    node->next = NULL;
    return node;
}

Node * push_data(char * name, double grade, Node * list) {
    Node * head = create_node(name, grade);
    head->next = list;
    return head;
}

void print_list(Node * list) {
    if (list == NULL) {
        printf("empty list\n");
        return;
    }
    while (list->next != NULL) {
        printf("(%s, %.3lf)->", list->name, list->grade);
        list = list->next;
    }
    printf("(%s, %.3lf)->NULL\n", list->name, list->grade);
}

// question 1
/*
void delete_list(Node * list) {
    // your implementation here
}
*/

// qestion 2
/*
int grade_stats(Node * list, double * mean, double * std) {
    // your implementation here
}
*/

// question 3
/*
Node * file_to_list(char * file_path) {
    // your implementation here
    // remember to close the file after read
    // you can read with fscanf in here
    // you can use push_data to create the linked list
}
*/

// bonus
/*
double min_grade(Node * list) {
    // your implementation here
}
*/

/*
double max_grade(Node * list) {
    // your implementation here
}
*/

/*
// what's the proper declaration for the 2nd input parameter?
double apply(Node * list, ? ) {
    // your implementation here, it can be done in one line
}
*/
