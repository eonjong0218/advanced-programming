#include <iostream>
#include <memory>
#include <string>

class Animal {
public:
    virtual std::string speak() const = 0; // 순수 가상 함수
    virtual ~Animal() = default; // 가상 소멸자
};

class Dog : public Animal {
public:
    std::string speak() const override {
        return "Woof!";
    }
};

class Cat : public Animal {
public:
    std::string speak() const override {
        return "Meow!";
    }
};

class AnimalFactory {
public:
    std::unique_ptr<Animal> createAnimal(const std::string& animalType) {
        if (animalType == "dog") {
            return std::make_unique<Dog>();
        } else if (animalType == "cat") {
            return std::make_unique<Cat>();
        } else {
            return nullptr;
        }
    }
};

int main() {
    AnimalFactory factory;

    auto dog = factory.createAnimal("dog");
    if (dog) {
        std::cout << "Dog says: " << dog->speak() << std::endl;
    }

    auto cat = factory.createAnimal("cat");
    if (cat) {
        std::cout << "Cat says: " << cat->speak() << std::endl;
    }

    auto unknown = factory.createAnimal("bird");
    if (!unknown) {
        std::cout << "Unknown animal type!" << std::endl;
    }

    return 0;
}