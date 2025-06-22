/******************************************************************************

    Animal-->Dog/Cat.       Product
    Animal_creator-->Random_creator/Sequential Creator.          Creator 

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Creating for Product
class IAnimal{
    public:
    virtual void show()=0;
};
class Dog: public IAnimal{
    
    public:
    void show(){
        cout<<"Product created for Dog"<<endl;
    }
};
class Cat: public IAnimal{
    
    public:
    void show(){
        cout<<"Product created for Cat"<<endl;
    }
};

// Creating for Creator Interface and concrete sub Creator

class IAnimal_creator{
    public:
    virtual IAnimal* create_Animal()=0;
    
};

class Random_creator: public IAnimal_creator{
    public:
    IAnimal* create_Animal(){
        if(rand()%2==0){
            IAnimal* object=new Dog();
            return object;
        }
        else
           {
               IAnimal* object=new Cat();
               return object;
           }
    }
};
class Input_creator: public IAnimal_creator{
    public:
    string what;
    Input_creator(string s){
       what=s; 
    }
    IAnimal* create_Animal(){
        if(what=="Dog"){
          IAnimal* object=new Dog();
            return object ; 
        }
        else
           {
               IAnimal* object=new Cat();
               return object;
           }
    }
};

int main()
{
   IAnimal_creator* object=new Random_creator();
   IAnimal* animal=object->create_Animal();
   animal->show();
   
   cout<<"new type of factory i want to create"<<endl;
   string s;
   cout<<"choose between Dog / Cat"<<endl;
   cin >>s;
   
   IAnimal_creator* Input_creator_object=new Input_creator(s);
   IAnimal* animal_type=Input_creator_object->create_Animal();
   animal_type->show();
   
}
