// Copyright 2021 NNTU-CS

#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
  Car *wagon = new Car{light, nullptr, nullptr};
  if (first == nullptr) {
    first = wagon;
    first->next = first;
    first->prev = first;
  } else {
    wagon->next = first;
    wagon->prev = first->prev;
    first->prev->next = wagon;
    first->prev = wagon;
  }
}

int Train::getLength() {
  if (first == nullptr) return 0;

  countOp = 0;
  first->light = true;
  Car *pointer = first;

  while (true) {
    int distanceToIlluminated = 0;

    do {
      pointer = pointer->next;
      countOp++;
      distanceToIlluminated++;
    } while (!pointer->light);

    pointer->light = false;

    Car *backup = pointer;
    for (int j = 0; j < distanceToIlluminated; j++) {
      backup = backup->prev;
      countOp++;
    }

    if (!backup->light) {
      return distanceToIlluminated;
    }
    pointer = backup;
  }
}

int Train::getOpCount() {
  return countOp;
}
