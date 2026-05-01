#ifndef BST_H
#define BST_H

typedef struct Node Node;

typedef struct BST BST;

// Operações para estrutura node

/** 
 * O valor do nó é a própria chave
 */ 
Node* create_node(int key);

/**
 * Função para debug
 */
void print_node(Node* n);

/**
 * Recebe um nó e libera a memória ocupada
 */
void destroy_node(Node* n);

// Operações para estrutura bst

/**
 * Cria a árvore binária de busca
 * e retorna
 */
BST* create_bst();

/**
 * Inserção de um nó na BST
 */
void insert_bst(BST* bst, Node* node_z);

/**
 * Retorna a raiz da BST
 */
Node* bst_root(BST* bst);

/**
 * Retorna a altura da BST
 */
int bst_height(Node* n);

/**
 * Libera a mamória alocada pela BST
 */
void destroy_bst(BST* bst);

// Caminhamentos

/**
 * Caminhamento pre-order traversal recursivo
 * Visita nó 
 * Caminha recursivamente na sub arvore esquerda
 * Caminha recursivamente na sub arvore direita
 */
void rec_pre_order_traversal(Node* t);

/**
 * Caminhamento in-order traversal recursivo
 * Caminha recursivamente na sub arvore esquerda
 * Visita nó 
 * Caminha recursivamente na sub arvore direita
 */
void rec_in_order_traversal(Node* t);

/**
 * Caminhamento in-order traversal recursivo
 * Caminha recursivamente na sub arvore esquerda
 * Caminha recursivamente na sub arvore direita
 * Visita nó 
 */
void rec_post_order_traversal(Node* t);

#endif