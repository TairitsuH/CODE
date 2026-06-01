#include<iostream>
using namespace std;

class Animal
{
protected:
    string name;

public:
    Animal(string s)
    :name(s)
    {}

    virtual void Speak() = 0;
};

class Tiger: public Animal
{
public:
    Tiger(string name)
    :Animal(name)
    {}

    void Speak()
    {
        cout << "Hello,I am " << name << ",AOOO." << endl;
    }
};

class Dog: public Animal
{
public:
    Dog(string name)
    :Animal(name)
    {}

    void Speak()
    {
        cout << "Hello,I am " << name << ",WangWang." << endl;
    }
};

class Duck: public Animal
{
public:
    Duck(string name)
    :Animal(name)
    {}

    void Speak()
    {
        cout << "Hello,I am " << name << ",GAGA." << endl;
    }
};

class Pig: public Animal
{
public:
    Pig(string name)
    :Animal(name)
    {}

    void Speak()
    {
        cout << "Hello,I am " << name << ",HENGHENG." << endl;
    }
};

int main()
{
    int t; cin >> t;
    while(t--)
    {
        string type, name; 
        int age;
        cin >> type >> name >> age;
        if(type == "Tiger")
        {
            Animal* a = new Tiger(name);
            a->Speak();
        }
        else if(type == "Dog")
        {
            Animal* a = new Dog(name);
            a->Speak();
            
        }
        else if(type == "Duck")
        {
            Animal* a = new Duck(name);
            a->Speak();

        }
        else if(type == "Pig")
        {
            Animal* a = new Pig(name);
            a->Speak();

        }
        else
        {
            cout << "There is no " << type << " in our Zoo." << endl;
        }
    }
    return 0;
}