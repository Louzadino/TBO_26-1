#include "bst.h"
#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int key;
    Node* parent;
    Node* right_node;
    Node* left_node;
};

struct BST
{
    Node* root;
    int size;
};

Node* create_node(int key) {

    Node* new_node = (Node*) malloc(sizeof(Node));

    if (new_node == NULL) {
        printf("ERRO: falha ao alocar novo nó");
        return NULL;
    }

    new_node->key = key;
    new_node->parent = NULL;
    new_node->left_node = NULL;
    new_node->right_node = NULL;

    return new_node;
}

void print_node(Node* n) {
    
    printf("Chave: %d\n", n->key);
    printf("Filho esquerda:\n");
    if (!n->left_node) printf("NULL\n");
    else printf("EXISTE\n");

    printf("Filho direita:\n");
    if (!n->right_node) printf("NULL\n");
    else printf("EXISTE\n");
}

// Para desalocar a árvore inteira
void destroy_node(Node* n) {

    if (n) {
        destroy_node(n->left_node);
        destroy_node(n->right_node);
        free(n);
    }
}

BST* create_bst() {

    BST* bst = (BST*) malloc(sizeof(BST));

    if (bst == NULL) {
        printf("ERRO: falha ao alocar a árvore");
        return NULL;
    }

    bst->root = NULL;
    bst->size = 0;

    return bst;
}

void insert_bst(BST* bst, Node* node_z) {

    Node* node_y = NULL;
    Node* node_x = bst->root;

    while (node_x != NULL) {
        node_y = node_x;
        if (node_z->key < node_x->key) {
            node_x = node_x->left_node;
        } else {
            node_x = node_x->right_node;
        }
    }

    node_z->parent = node_y;
    if (node_y == NULL) {
        bst->root = node_z;
    } else if (node_z->key < node_y->key) {
        node_y->left_node = node_z;
    } else {
        node_y->right_node = node_z;
    }
}

Node* bst_root(BST* bst) {
    return bst->root;
}

int bst_height(Node* n) {

    if (n == NULL) return -1;

    int height_left = bst_height(n->left_node);
    int height_right = bst_height(n->right_node);

    // Usar a logica de que a altura de 1 no é a altura do seu filho mais alto + 1

    if (height_left > height_right) {
        return 1 + height_left;
    } else {
        return 1 + height_right;
    }
}

void destroy_bst(BST* bst) {

    if (bst) {
        destroy_node(bst->root);
        free(bst);
    }
}

void rec_pre_order_traversal(Node* t) {

    if (t == NULL) return;
    
    // Visitar nó
    printf("%d\n", t->key);
    
    // Visitar sub arvore da esquerda
    rec_pre_order_traversal(t->left_node);

    // Visitar sub arvore da direite
    rec_pre_order_traversal(t->right_node);
}

void rec_in_order_traversal(Node* t) {

    if (t == NULL) return;

    // Visitar sub arvore da esquerda
    rec_pre_order_traversal(t->left_node);

    // Visitar nó
    printf("%d\n", t->key);

    // Visitar sub arvore da direite
    rec_pre_order_traversal(t->right_node);
}

void rec_post_order_traversal(Node* t) {

    if (t == NULL) return;

    // Visitar sub arvore da esquerda
    rec_pre_order_traversal(t->left_node);

    
    // Visitar sub arvore da direite
    rec_pre_order_traversal(t->right_node);
    
    // Visitar nó
    printf("%d\n", t->key);
}
