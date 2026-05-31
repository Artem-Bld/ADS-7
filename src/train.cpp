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
    bool firstLight = first->light;
    first->light = !firstLight;
    int length = 1;
    Car* current = first->next;
    countOp++;
    while (current->light != first->light) {
        current = current->next;
        countOp++;
        length++;
        if (length > 1000000) {
            first->light = firstLight;
            return -1;
        }
    }
    first->light = firstLight;
    return length;
}

int Train::getOpCount() {
    return countOp;
}
