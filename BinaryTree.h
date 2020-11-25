//
// Created by R Yu on 10/19/2020.
//

#ifndef HOMEWORK_7_BINARYTREE_H
#define HOMEWORK_7_BINARYTREE_H
#include "List.h"
using namespace std;
template<class T>
class BSTNode {
public:
    T el;
    BSTNode<T> *left, *right;
    NodeList<int> *list;
    BSTNode() {
        left = right = 0;
    }
    BSTNode(const T& e, BSTNode<T> *l = 0, BSTNode<T> *r = 0, NodeList<int> *aList = 0) {
        el = e; left = l; right = r;
        list = aList;
    }
};

template<class T>
class BST {
protected:
    BSTNode<T>* root;
public:
    BST() { root = 0; }
    //~BST() { clear(); }
    //void clear() { clear(root); root = 0; }
    bool isEmpty() const { return root == 0; }

// more methods to be added
    T* search(BSTNode<T>* p, const T& el) const {
        while (p != 0) {
            if (el == p->el)
                return &p->el;
            else if (el < p->el)
                p = p->left;
            else p = p->right;
        }
        return 0;
    }

    void insert(const T& el, int line) {
        BSTNode<T> *p = root,
                *prev = 0;

        while (p != 0) { // find a place for inserting new node;
            prev = p;
            if (el < p->el)
                p = p->left;
            else if (el == p->el){
                break;
            }
            else p = p->right;
        }

        if(p != 0) {
            if(el == p->el) {
                p->list->insertTail(line);
            }
        }
        else {
            NodeList<int> *list = new NodeList<int>();
            list->insertTail(line);
            if (root == 0) {
                root = new BSTNode<T>(el, 0, 0, list);
            } else if (el < prev->el) {
                prev->left = new BSTNode<T>(el, 0, 0, list);
            } else {
                prev->right = new BSTNode<T>(el, 0, 0, list);
            }
        }
    }
    BSTNode<T> *getRoot(){
        return root;
    }
    void printTree(BSTNode<T> *x){
        if(x == 0){
            return;
        }
        else{
            cout << x->el << ",    ";
            x->list->printList();
            cout << endl;
            printTree(x->left);
            printTree(x->right);
        }
    }
};
#endif //HOMEWORK_7_BINARYTREE_H
