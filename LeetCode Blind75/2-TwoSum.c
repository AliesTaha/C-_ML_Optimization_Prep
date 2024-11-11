#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    int value; 
}node;

typedef struct {
    int size;
    node* pairs;
}hashmap;

hashmap* create_hashmap(int size){
    hashmap* map= (hashmap*) malloc(sizeof(hashmap));
    map->size=size;
    map->pairs= (node*) malloc(size * sizeof(node));
    for (int i=0; i<size; i++){
        node tmp;
        tmp.key=-1;
        tmp.value=-1;
        map->pairs[i]=tmp;
    }
    return map;
}

void free_hashmap(hashmap* map){
    free(map->pairs);
    free(map);
}

int hash(int key, int size){
    return abs(key)%size;
}

void insert(hashmap* map, int key, int value, int size){
    int index= hash(key, size);
    while (map->pairs[index].key!=-1){
        index= ((index+1 )% map->size);
    }
    map->pairs[index].key=key;
    map->pairs[index].value=value;
}

int find(hashmap* map, int key){
    int index=hash(key, map->size);

    while (map->pairs[index].key!= key){
        if (map->pairs[index].key==-1){
            return -1;
        }
        index=((index+1)%(map->size));
    }
    return (map->pairs[index].value);
}

int* two_sum(int values[], int target, int size){
    hashmap* map= create_hashmap(size);
    int * ret= (int*) malloc(2* sizeof(int));
    for (int i=0; i<size; i++){
        int diff= target- values[i];
        int found=find(map, diff);
        if (found!=-1){
            ret[0]=i;
            ret[1]=found;
            free_hashmap(map);
            return ret;
        }
        else{
            insert(map, values[i], i, size);
        }
    }
    free_hashmap(map);
    return NULL;
}

int main(){
    int arr[]= {1,3,5,6,9,2,12,10};
    int * ret = two_sum(arr, 15, 8);
    printf("%d, %d", ret[0], ret[1]);
    free(ret);
    return 0;
}
