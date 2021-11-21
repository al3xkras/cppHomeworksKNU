#ifndef HOMEWORK19_NUMBERLIST_H
#define HOMEWORK19_NUMBERLIST_H

#include <iostream>

template <typename T>
struct Node {
    T data;
    Node *next;
};

template <typename T>class NumberList{
private:
    Node<T> *head;
public:
    NumberList(){
        head = NULL;
    }

    friend std::ostream &operator<<(std::ostream &os, const NumberList &list) {
        os << "NumberList: [";
        Node<T> *temp = list.head;
        while(temp) {
            os<<(temp->data)<<", ";
            temp = temp->next;
        }
        os<<"]";
        delete temp;
        return os;
    }

    void push(T val){
        auto *n = new Node<T>();
        n->data = val;
        n->next = head;
        head = n;
    }

    T pop(){
        if(head) {
            T p = head->data;
            head = head->next;
            return p;
        }
    }

    T findClosestTo(T val) {
        T output;
        double min_dist = 3e307;
        T closest = NULL;

        Node<T> *temp = head;
        while(temp) {
            double d = dist(temp->data, val);
            if(d<min_dist) {
                min_dist = d;
                closest = temp->data;
            }
            temp = temp->next;
        }
        delete temp;
        return closest;
    }

    double dist(T t1, T t2){
        return std::abs(t1-t2);
    }
};


#endif //HOMEWORK19_NUMBERLIST_H
