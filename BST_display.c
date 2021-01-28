//
//  Created by Archie Liu on 2020-03-05.
//  Copyright © 2020 Archie Liu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct _node {
    int num;
    int depth;
    struct _node *left;
    struct _node *right;
} Node;


Node *insert(Node *root, int num){

    if (root==NULL) {
        Node *tar = (Node *)calloc(1, sizeof(Node));
        tar->num = num;
        return tar;
    }
    else if (num > root->num) {
        root->right = (insert(root->right, num));
    }
    else if (num < root->num) {
        root->left = (insert(root->left, num));
    }
    return root;
}



Node *insert2(Node *root, int num, int depth){

    if (root==NULL) {
        Node *tar = (Node *)calloc(1, sizeof(Node));
        tar->num = num;
        tar->depth = depth;
        return tar;
    }
    else if (num > root->num) {
        depth ++;
        root->right = (insert2(root->right, num, depth));
    }
    else if (num < root->num) {
        depth ++;
        root->left = (insert2(root->left, num, depth));
    }
    return root;
}




void print_tree(Node *node) {
    if(node == NULL) {
        printf("STOP\n");
    }
    else {
        printf("%d (%d)\n", node->num, node->depth);
        print_tree(node->left);
        print_tree(node->right);
    }

}

void print_graph(Node *node, char str[5][10]){

    char chr[2] = {(char)(node->num+48)};
    strcat(str[node->depth], chr);
    if (node->left != NULL){
        print_graph(node->left, str);
    } else {
        strcat(str[node->depth+1], "-");
    }
    if (node->right != NULL){
        print_graph(node->right, str);
    } else {
        strcat(str[node->depth+1], "-");
    }
    
}


int temp[100] = {0};

void Display(Node *root, int depth){
    
    // if it is not the first level, then we need to draw "branches"
    if (depth != 0) {
        for (int i=0; i < depth-1; i++) {
            printf(temp[i] ? "    " : "│   ");
        }
        printf(temp[depth-1] ? "└── " : "├── ");
    }
    
    // Having finished drawing branches, we need to draw "leaf"
    if (root == NULL) { // it is an empty LEAF!!
        printf("(null)\n");
        return;
    }

    if (root->left == NULL && root->right == NULL) { // it is a non-empty LEAF!!
        printf("%d\n", root->num);
        return;
    }
    
    //print the first level number
    printf("%d\n", root->num);
    
    
    temp[depth] = 0; //left
    Display(root->left, depth + 1);
    
    temp[depth] = 1; //right
    Display(root->right, depth + 1);
}





int main() {

    Node *root = (Node *)calloc(1, sizeof(Node));

    // put your array here to generate and display the BST
    int arr[10] = {9,3,7,2,5,1,4,6,8}; 

    root->num = arr[0];
    
    for (int i=1; i<9; i++){
        insert(root, arr[i]);
    }
    
    Display(root, 0);

    return 0;
    
}
