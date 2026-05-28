#include <stdio.h>
#include <stdlib.h>

typedef struct {
    
    int length;
    int* start;
    int capacity;

}vector;

void vector_init(vector* v){


    int* ptr = malloc(sizeof(int) * 50);

    if (ptr == NULL)
        exit(1);

    v->capacity = 50;
    v->length = 0;
    v->start = ptr;

}

void vector_destruct(vector* v ){

    free(v->start);
    v->start = NULL;

}

void push_back(vector* v, int x){

    if (v->capacity == v->length ){

        // the vector is full, time to allocate more space
        int *p = realloc(v->start, (v->capacity + 50)*sizeof(int));
        if (p == NULL)
            exit(1);
        v->start = p;
        v->capacity +=50;
        printf("reallocation successful\n");
    }
   
    
    v->start[v->length] = x;
    v->length++;

}

void pop_back(vector* v){
    
    v->length--;

}

int main(){

    vector v; 
    vector_init(&v);
    for(int i=0; i<70; i++){
        push_back(&v, i);
    }
    printf("70 elements have been added to the array succefully");
    
    vector_destruct(&v);


    return 0;
}