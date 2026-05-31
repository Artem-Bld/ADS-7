// Copyright 2021 NNTU-CS

#include "train.h"

Train::Train() {
    countOp = 0;
    first = nullptr;
}

void Train::addCar(bool light) {
    Car* wagon = new Car();
    wagon->light = light;
    wagon->next = nullptr;
    wagon->prev = nullptr;
    
    if (first == nullptr) {
        first = wagon;
        first->next = first;
        first->prev = first;
        return;
    }
    
    Car* tail = first->prev;
    tail->next = wagon;
    wagon->prev = tail;
    wagon->next = first;
    first->prev = wagon;
}

int Train::getLength() {
    if (first == nullptr) {
        return 0;
    } 
    countOp = 0;
    bool originalState = first->light;
    first->light = !originalState;
    int wagonCounter = 0;
    Car* traveler = first;
    do {
        traveler = traveler->next;
        countOp++;
        wagonCounter++;
    } while (traveler->light != first->light);
    first->light = originalState;
    return wagonCounter;
}

int Train::getOpCount() {
    return countOp;
}
