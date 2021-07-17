//
// Created by Administrator on 2021/7/17.
//
#include <iostream>

class Animal
{
public:
    int data;

    Animal()
    {
        printf("Animal this prt=%p,sizeof=%d\n", this, sizeof(Animal));
    }

    void animalSay()
    {
        printf("data prt=%p,this prt=%p\n", &this->data, this);
        std::cout << "i am Animal" << std::endl;
    }
};

class Alive
{
public:
    int data;

    Alive()
    {
        printf("Alive this prt=%p,sizeof=%d\n", this, sizeof(Alive));
    }

    void aliveSay()
    {
        printf("data prt=%p,this prt=%p\n", &this->data, this);
        std::cout << "i am Alive" << std::endl;
    }
};

class Dog : public Animal, public Alive
{
public:
    int data;

    Dog()
    {
        printf("Dog this prt=%p,sizeof=%d\n", this, sizeof(Dog));
    }

    void dogSay()
    {
        printf("data prt=%p,this prt=%p\n", &this->data, this);
        std::cout << "i am Dog" << std::endl;
    }

    void aliveSay()
    {
        printf("Dog aliveSay => this prt=%p\n", this);
    }
};

void thisDemo()
{
    Dog *dog = new Dog();
    dog->animalSay();
    dog->aliveSay();
    ((Alive *) dog)->aliveSay();
    dog->dogSay();
    delete dog;
}