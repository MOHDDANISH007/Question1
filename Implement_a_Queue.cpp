#include <bits/stdc++.h> 
class Queue {
    int* arr;
    int qfront;
    int rear;
    int size;
public:
    Queue() {
        size = 100000;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(qfront == rear)
            return true;
        else 
            return false;
    }

    void enqueue(int data) {
        if(rear == size)
            return;
        arr[rear++] = data;
    }

    int dequeue() {
        if(qfront == rear)
            return -1;
        int var = arr[qfront];
        arr[qfront] = -1;
        qfront++;
        return var;
