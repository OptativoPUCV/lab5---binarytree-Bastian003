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
  if(tree==NULL){
    return ;
  }
  TreeNode* nuevo=createTreeNode( key, value); 
  tree->current=tree->root;
  while(tree->current !=NULL){
    int resultado =tree->lower_than(key,tree->current->pair->key);
    if(is_equal(tree,key,tree->current->pair->key)){
      return;
    }
    if(resultado==0){
      if(tree->current->right==NULL){
        tree->current->left=nuevo;
        nuevo->parent=tree->current;
      }
      tree->current=tree->current->right;
    }else{
      if(tree->current->left==NULL){
        tree->current->left=nuevo;
        nuevo->parent=tree->current;
      }
      tree->current=tree->current->left;
      
     
    }
   
  }

  

  

}

TreeNode * minimum(TreeNode * x){
  while(x->left==NULL){
    x=x->left;
  }
  return x;
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

  TreeNode* posicion=tree->root;

  while(posicion !=NULL){
    int resultado =tree->lower_than(key,posicion->pair->key);
    if(is_equal(tree,key,posicion->pair->key)){
      tree->current=posicion;
     
      return tree->current->pair;
    }else if(resultado==0){
      posicion=posicion->right;
    }else{
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
