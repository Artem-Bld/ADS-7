// Copyright 2021 NNTU-CS

#include "train.h"
#include <iostream>

Train::Train() : countOp(0), first(nullptr), length(0) {}

Train::~Train() {
    if (!first) return;
    
    Car* current = first;
    Car* nextCar = nullptr;
    
    do {
        nextCar = current->next;
        delete current;
        current = nextCar;
    } while (current != first);
}

void Train::addCar(bool light) {
    Car* newCar = new Car(light);
    
    if (!first) {
        first = newCar;
        first->next = first;
        first->prev = first;
    } else {
        Car* last = first->prev;
        last->next = newCar;
        newCar->prev = last;
        newCar->next = first;
        first->prev = newCar;
    }
    length++;
}

int Train::getLength() {
    if (!first) return 0;
    countOp = 0;
    first->light = false;
    int wagonCount = 1;
    Car* current = first->next;
    bool found = false;
    while (!found) {
        if (current->light) {
            current->light = false;
            for (int i = 0; i < wagonCount; i++) {
                current = current->next;
                countOp++;
            }
            if (!current->light) {
                found = true;
            } else {
                current = current->next;
                countOp++;
                wagonCount++;
            }
        } else {
            current->light = true;
            current = current->next;
            countOp++;
            wagonCount++;
        }
    }
    return wagonCount;
}

int Train::getOpCount() const {
    return countOp;
}

void Train::resetOpCount() {
    countOp = 0;
}

int Train::getActualLength() const {
    return length;
}
