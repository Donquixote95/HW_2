#pragma once

class Electronics {
    public:
        Electronics(int aSize);

        int GetSize(void);        
        void SetSize(int aSize);  

        virtual void PrintSelf(void) = 0;
        
    protected:
        int size;
};

class TV : public Electronics{
    public:
        TV(int aSize);

        virtual void PrintSelf(void);
};

class Cellphone : public Electronics {
    public:
        Cellphone(int aSize);

        virtual void PrintSelf(void);
};

class Computer : public Electronics {
    public:
        Computer(int aSize);

        virtual void PrintSelf(void);
};

class Laptop : public Computer {
   public: 
        Laptop(int aSize);

        virtual void AddGPU(Computer *aGPU);
        virtual void PrintSelf(void);

   protected:
        int GPU;
        float GPU_price;
        Computer * GPU1;
        Computer * GPU2;   
};