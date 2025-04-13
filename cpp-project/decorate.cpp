#include <iostream>
#include <memory>

class Coffee {
public:
    virtual int cost() const {
        return 5;
    }
    virtual ~Coffee() = default;
};

class CoffeeDecorator : public Coffee {
protected:
    std::shared_ptr<Coffee> coffee;
public:
    CoffeeDecorator(std::shared_ptr<Coffee> coffee) : coffee(coffee) {}
    int cost() const override {
        return coffee->cost();
    }
};

class MilkDecorator : public CoffeeDecorator {
public:
    MilkDecorator(std::shared_ptr<Coffee> coffee) : CoffeeDecorator(coffee) {}
    int cost() const override {
        return coffee->cost() + 2;
    }
};

class SugarDecorator : public CoffeeDecorator {
public:
    SugarDecorator(std::shared_ptr<Coffee> coffee) : CoffeeDecorator(coffee) {}
    int cost() const override {
        return coffee->cost() + 1;
    }
};

int main() {
    // 기본 커피
    std::shared_ptr<Coffee> coffee = std::make_shared<Coffee>();
    std::cout << "Coffee cost: " << coffee->cost() << std::endl; // 5

    // 우유 추가
    std::shared_ptr<Coffee> coffeeWithMilk = std::make_shared<MilkDecorator>(coffee);
    std::cout << "Coffee with milk cost: " << coffeeWithMilk->cost() << std::endl; // 7

    // 설탕 추가
    std::shared_ptr<Coffee> coffeeWithSugar = std::make_shared<SugarDecorator>(coffee);
    std::cout << "Coffee with sugar cost: " << coffeeWithSugar->cost() << std::endl; // 6

    // 우유와 설탕 추가
    std::shared_ptr<Coffee> coffeeWithMilkAndSugar = std::make_shared<SugarDecorator>(coffeeWithMilk);
    std::cout << "Coffee with milk and sugar cost: " << coffeeWithMilkAndSugar->cost() << std::endl; // 8

    return 0;
}