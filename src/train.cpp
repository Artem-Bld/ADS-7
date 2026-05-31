// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr), carCount(0) {}

Train::~Train() {
    if (!first) return;
    Car* current = first;
    do {
        Car* next = current->next;
        delete current;
        current = next;
    } while (current != first);
}

void Train::addCar(bool light) {
    Car* newCar = new Car(light);
    
    if (!first) {
        newCar->next = newCar;
        newCar->prev = newCar;
        first = newCar;
    } else {
        Car* last = first->prev;
        newCar->next = first;
        newCar->prev = last;
        last->next = newCar;
        first->prev = newCar;
    }
    carCount++;
}

int Train::getOpCount() {
    return countOp;
}

int Train::getActualLength() {
    return carCount;
}

int Train::getLength() {
    if (!first) return 0;
    if (carCount < 2) return carCount;
    Car* start = first;
    bool originalStartLight = start->light;
    start->light = false;
    for (int k = 1; ; k++) {
        Car* current = start;
        for (int i = 0; i < k; i++) {
            current = current->next;
            countOp++;
        }
        current->light = true;
        for (int i = 0; i < k; i++) {
            current = current->prev;
            countOp++;
        }
        if (current != start) {
            start->light = false;
            continue;
        }
        if (start->light == true) {
            start->light = originalStartLight;
            return k;
        }
        start->light = false;
    }
}
