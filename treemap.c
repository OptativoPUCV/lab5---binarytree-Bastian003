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
  TreeMap * mapa=(TreeMap*)malloc(sizeof(TreeMap));
  mapa->root=NULL;
  mapa->lower_than = lower_than;
  mapa->current=NULL;
  if(mapa==NULL){
    return NULL;
  }
  return mapa;
}


void insertTreeMap(TreeMap * tree, void* key, void * value) {
/*  if(tree==NULL){
    return;
  }
  TreeNode * nuevomapa= createTreeNode( key,  value);
  
    if(nuevomapa==NULL){
    return;
  }
  if(tree->root==NULL){
    tree->root=nuevomapa;
    tree->current=nuevomapa;


    return;
  }
  TreeNode* posicion=tree->root;
  TreeNode * padre = 0;
  
  while(posicion!=NULL){
    padre=posicion;
    int resultado =tree->lower_than(key,posicion->pair->key);
    if(resultado==0){
      free(nuevomapa);
      return;
    }else if(resultado>0){
      posicion=posicion->right;
      
    }else if(resultado<0){
      posicion=posicion->left;
      
    }
  }
  nuevomapa->parent=padre;
  int padreS=tree->lower_than(key,padre->pair->key);
  if(padreS>0){
    padre->right=nuevomapa;
    
  }else if(padreS<0){
    padre->left=nuevomapa;
    
  }
  tree->current=nuevomapa;
*/
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
  if(tree ==NULL){
    return NULL;
  }
  if(tree->root==NULL){
    return NULL;
  }
  //solucionar esta funcion que me actualiza todo tranqui pero no encuntra la clave y no me retorna null
  TreeNode* posicion=tree->root;

  while(posicion !=NULL){
    int resultado =tree->lower_than(key,posicion->pair->key);
    if(resultado==0){
      tree->current=posicion->pair;
      return posicion->pair;
    }else if(resultado>0){
      posicion=posicion->right;
      
    }else if(resultado<0){
      posicion=posicion->left;
      
    }
  }
 
  tree->current=NULL;
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
