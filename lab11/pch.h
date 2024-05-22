#pragma once

#include "gtest/gtest.h"

template<class T>
void sortElemente(T* list, unsigned int& nrElem)
{
    unsigned int i, j, ok = 1;
    T aux;
    nrElem--;
    for (i = 0; i < nrElem && ok; i++)
        for (j = i + 1; j < nrElem + 1; j++)
            if (-list[i] > -list[j])
            {
                aux = list[i];
                list[i] = list[j];
                list[i] = aux;
                ok = 0;
            }
}