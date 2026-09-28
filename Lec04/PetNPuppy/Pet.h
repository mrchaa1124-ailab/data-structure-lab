#pragma once
#include <iostream>
#include <string>

using namespace std;

// Base Class: Pet
class Pet {
protected: // Accessible by derived classes like Puppy
    string name;
    int age;
    string type;

public:
    // Constructor to initialize base pet info
    Pet(string n, int a, string t) {
        name = n;
        age = a;
        type = t;
    }

    // Getters
    string getName() { return name; }
    int getAge() { return age; }
    string getType() { return type; }

    void printInfo() {
        cout << "[Pet Info] Name: " << name << ", Age: " << age << ", Type: " << type << endl;
    }
};

// Derived Class: Puppy inherits Pet
class Puppy : public Pet {
public:
    // Constructor calling the base class constructor
    Puppy(string n, int a) : Pet(n, a, "Dog") {}

    // Unique function for Puppy
    void bark() {
        cout << name << " says: Woof! Woof!" << endl;
    }
};

