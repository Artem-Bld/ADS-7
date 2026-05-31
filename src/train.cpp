// Copyright 2021 NNTU-CS

#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
    Car* newCar = new Car;
    newCar->light = light;
    newCar->next = nullptr;
    newCar->prev = nullptr;
    
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
}

int Train::getLength() {
    if (!first) return 0;
    countOp = 0;
    first->light = false;
    int wagonCount = 1;
    Car* current = first->next;
    countOp++;
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

int Train::getOpCount() {
    return countOp;
}
