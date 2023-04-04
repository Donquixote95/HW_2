#include <stdio.h>
#include <iostream>
#include "Electronics.h"

using namespace std;

Electronics::Electronics(int aSize) {
    size = aSize;
}

int Electronics::GetSize(void) {
    return(size);
}

void Electronics::SetSize(int aSize){
    size = aSize;
}

TV::TV(int aSize)
    : Electronics(aSize)
    { }

void TV::PrintSelf(void){
    printf("It is a TV, Size=%d, Price=%.lf\n", GetSize(), GetSize()*1.8);
}

Cellphone::Cellphone(int aSize)
    : Electronics(aSize)
    { }

void Cellphone::PrintSelf(void){
    printf("It is a Cellphone, Size=%d, Price=%.lf\n", GetSize(), GetSize()*0.7);
}

Computer::Computer(int aSize)
    : Electronics(aSize)
    { }

void Computer::PrintSelf(void){
    printf("It is a Cellphone, Size=%d, Price=%.lf\n", GetSize(), GetSize()*0.6);
}

Laptop::Laptop(int aSize)
    : Computer(aSize)
    { }

void Laptop::PrintSelf(void){
    if (GPU == 0)
        printf("It is a Laptop with %d GPUs, Size=%d, Price=%.lf, Total Price=%.lf\n", GPU, GetSize(), GetSize()*0.6, GetSize()*0.6);
    else if (GPU == 1)
        printf("It is a Laptop with %d GPUs, Size=%d, Price=%.lf, Total Price=%.lf\n", GPU, GetSize(), GetSize()*0.6*2, GetSize()*0.6*2 + GPU_price);
    else if (GPU == 2)
        printf("It is a Laptop with %d GPUs, Size=%d, Price=%.lf, Total Price=%.lf\n", GPU, GetSize(), GetSize()*0.6*2, GetSize()*0.6*2 + GPU_price);
}

void Laptop::AddGPU(Computer *aGPU){
    
    GPU++;

    if (GPU1 == NULL){
        GPU1 = aGPU;
        GPU_price = GPU1->GetSize()*0.6;
        }

    else {
        GPU2 = aGPU;
        GPU_price = GPU_price + GPU2->GetSize()*0.6;
        }
}

