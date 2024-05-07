#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treemap.h"

typedef struct TreeNode TreeNode;


struct TreeNode {
    Pair* pair;
    TreeNode * left;
    TreeNode * right;
    TreeNode * parent;
};

struct TreeMap {
    TreeNode * root;
    TreeNode * current;
    int (*lower_than) (void* key1, void* key2);
};

int is_equal(TreeMap* tree, void* key1, void* key2){
    if(tree->lower_than(key1,key2)==0 &&  
        tree->lower_than(key2,key1)==0) return 1;
    else return 0;
}


TreeNode * createTreeNode(void* key, void * value) {
    TreeNode * new = (TreeNode *)malloc(sizeof(TreeNode));
    if (new == NULL) return NULL;
    new->pair = (Pair *)malloc(sizeof(Pair));
    new->pair->key = key;
    new->pair->value = value;
    new->parent = new->left = new->right = NULL;
    return new;
}

TreeMap * createTreeMap(int (*lower_than) (void* key1, void* key2)) {
    // Reserva de memoria para el mapa
    TreeMap * map = (TreeMap *)malloc(sizeof(TreeMap));
    if (!map) {
        return NULL; // Error: no se pudo reservar memoria
    }

    // Inicialización de variables
    map->root = NULL;
    map->current = NULL;
    map->lower_than = lower_than;

    return map;
}


void insertTreeMap(TreeMap * tree, void* key, void * value) {

}

TreeNode * minimum(TreeNode * x){

    return NULL;
}


void removeNode(TreeMap * tree, TreeNode* node) {

}

void eraseTreeMap(TreeMap * tree, void* key){
    if (tree == NULL || tree->root == NULL) return;

    if (searchTreeMap(tree, key) == NULL) return;
    TreeNode* node = tree->current;
    removeNode(tree, node);

}




Pair * searchTreeMap(TreeMap * tree, void* key) {
    // Comenzar la búsqueda desde la raíz
    // Inicializa el nodo actual como la raíz del árbol
    tree->current = tree->root;

    // Realiza la búsqueda en el árbol
    while (tree->current != NULL) {
        // Compara la clave del nodo actual con la clave buscada
        int comparison_result = tree->lower_than(key, tree->current->pair->key);
        
        // Si las claves son iguales, se encontró el nodo
        if (comparison_result == 0) {
            return tree->current->pair;
        }
        // Si la clave buscada es menor, busca en el subárbol izquierdo
        else if (comparison_result < 0) {
            tree->current = tree->current->left;
        }
        // Si la clave buscada es mayor, busca en el subárbol derecho
        else {
            tree->current = tree->current->right;
        }
    }

    // Si no se encontró la clave, retorna NULL
    return NULL;
}


Pair * upperBound(TreeMap * tree, void* key) {
    return NULL;
}

Pair * firstTreeMap(TreeMap * tree) {
    return NULL;
}

Pair * nextTreeMap(TreeMap * tree) {
    return NULL;
}
