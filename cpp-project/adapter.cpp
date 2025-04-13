#include <iostream>
#include <string>
#include <memory>

class InternalClass {
public:
    std::string fetch() const {
        return "get user info";
    }
};

class ExternalClass {
public:
    std::string search() const {
        return "get user info";
    }
};

class Adapter {
private:
    std::shared_ptr<ExternalClass> external;
public:
    Adapter(std::shared_ptr<ExternalClass> external) : external(external) {}

    std::string fetch() const {
        return external->search();
    }
};

int main() {
    InternalClass internal;
    std::cout << internal.fetch() << std::endl;

    auto external = std::make_shared<ExternalClass>();
    Adapter adapter(external);
    std::cout << adapter.fetch() << std::endl;

    return 0;
}