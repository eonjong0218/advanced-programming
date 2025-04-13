#include <iostream>
#include <string>
#include <memory>

class Person {
public:
    std::string name;
    int age;
    std::string address;

    Person() : name(""), age(0), address("") {}
};

class PersonBuilder {
private:
    std::shared_ptr<Person> person;

public:
    PersonBuilder() : person(std::make_shared<Person>()) {}

    PersonBuilder& withName(const std::string& name) {
        person->name = name;
        return *this; // 자기 자신 반환
    }

    PersonBuilder& withAge(int age) {
        person->age = age;
        return *this; // 자기 자신 반환
    }

    PersonBuilder& withAddress(const std::string& address) {
        person->address = address;
        return *this; // 자기 자신 반환
    }

    std::shared_ptr<Person> build() {
        return person;
    }
};

int main() {
    auto person = PersonBuilder()
        .withName("홍길동")
        .withAge(20)
        .withAddress("양산시 부산대학로")
        .build();

    std::cout << "Name: " << person->name << std::endl;
    std::cout << "Age: " << person->age << std::endl;
    std::cout << "Address: " << person->address << std::endl;

    return 0;
}