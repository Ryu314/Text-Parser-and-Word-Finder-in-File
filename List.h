//
// Created by R Yu on 10/19/2020.
//

#ifndef HOMEWORK_7_LIST_H
#define HOMEWORK_7_LIST_H
#include <iostream>
using namespace std;

template<class T>
class Node {
public:
    T data;
    Node *next;
    Node(T y) {
        data = y;
        next = NULL;
    }
    Node(){
        data = NULL;
        next = NULL;
    }
    T getData(){
        return data;
    }
};
template<class T>
class NodeList {
private:
    Node<T> *head;
    Node<T> *tail;
public:
    NodeList () {
        head = NULL;
        tail = NULL;
    }
    Node<T> getNode(T data){
        Node<T> *temp = head;
        while(temp->next != NULL and temp->data.getData() != data){
            temp = temp->next;
        }
        return temp->data.getData();
    }
    void insertTail(T data) {
        Node<T>* newNode = new Node<T>(data);
        Node<T> *temp = head;
        Node<T> *tail = head;

        if(head == NULL){
            head = tail = newNode;

        }
        else if(head->next == NULL){
            head->next = newNode;
            tail = head->next;
        }
        else {
            while (temp != NULL) {
                tail = tail->next;
                temp = tail->next;
            }
            tail->next = newNode;
            tail = newNode;

        }

    }
    void insertHead(T item2) {
        Node<T> *newNode = new Node<T>(item2);
        if (tail == NULL )
            tail = newNode;
        newNode->next = head;
        head = newNode;
    }
    /*void swap(T item2){
        Node<T> *temp = head;
        if(temp->freq != item1 or temp->data != item2) {
            Node<T> *temp2 = temp->next;
            if (temp2->freq == item1 and temp2 -> data == item2) {
                temp->next = temp2->next;
                temp2->next = temp;
                head = temp2;
            }
            else{
                Node<T> *temp3 = temp2->next;


                while ((temp3->freq != item1 or temp3->data != item2) and temp3->next != NULL) {
                    temp = temp->next;
                    temp2 = temp2->next;
                    temp3 = temp3->next;
                }
                if (temp3->freq == NULL) {
                    cout << "Not found" << endl;
                }
                else {
                    temp->next = temp3;
                    temp2->next = temp3->next;
                    temp3->next = temp2;
                }
            }
        }
    }
    bool contains(T item2){
        Node<T> *temp = head;
        while(temp->next != NULL){
            if(temp->data.getData() == item2){
                return true;
            }
            else{
                temp = temp->next;
            }
        }
        return false;
    }
    void insert(int x, T item){
        Node<T> *temp = head;
        Node<T> *newNode = new Node<T>(item);
        while(freq < temp->freq and temp->next != NULL){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }*/
    void deleteTail() {
        if (head->next == NULL) {
            head = NULL;
            delete(tail);
            tail = NULL;
        }
        else {
            Node<T> *temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            tail = temp;
            delete(temp->next);
            tail ->next = NULL;
        }
    }
    void printList(){
        Node<T> *temp = head;
        while(temp != NULL){
            cout << temp->data << ", ";
            temp = temp->next;
        }
    }
    Node<T> *getTail(){
        return tail;
    }

};
#endif //HOMEWORK_7_LIST_H
