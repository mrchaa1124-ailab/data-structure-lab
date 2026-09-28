#include "Pet.h"

int main() {
    cout << "--- 1. Testing Base Pet Class ---" << endl;
    // Create a generic Pet object (e.g., a cat)
    Pet genericPet("Nabi", 3, "Cat");
    genericPet.printInfo();
    cout << "Name via getter: " << genericPet.getName() << endl;
    cout << endl;

    cout << "--- 2. Testing Derived Puppy Class ---" << endl;
    // Create a Puppy object (Type is automatically set to "Dog" by the constructor)
    Puppy myPuppy("Coco", 2);

    // Puppy can use functions inherited from Pet
    myPuppy.printInfo();
    cout << "Puppy Age via getter: " << myPuppy.getAge() << endl;

    // Puppy can use its own unique function
    myPuppy.bark();

    return 0;
}
