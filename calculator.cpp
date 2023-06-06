#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Product {
public:
    Product(const std::string& name, int quantity): _name(name), _quantity(quantity) {}

    const std::string& getName() const { return _name; }
    int getQuantity() const { return _quantity; }

    void setQuantity(int quantity) { _quantity = quantity; }

private:
    std::string _name;
    int _quantity;
};

class Warehouse {
public:
    void addProduct(const std::shared_ptr<Product>& product) {
        _products.push_back(product);
    }

    void removeProduct(const std::string& name) {
        for(auto it = _products.begin(); it != _products.end(); ++it) {
            if((*it)->getName() == name) {
                _products.erase(it);
                break;
            }
        }
    }

    void displayProducts() const {
        for(const auto& product: _products) {
            std::cout << "Product name: " << product->getName() << ", Quantity: " << product->getQuantity() << '\n';
        }
    }

private:
    std::vector<std::shared_ptr<Product>> _products;
};

int main() {
    Warehouse warehouse;
    
    std::shared_ptr<Product> product1 = std::make_shared<Product>("Apple", 100);
    std::shared_ptr<Product> product2 = std::make_shared<Product>("Banana", 200);

    warehouse.addProduct(product1);
    warehouse.addProduct(product2);

    warehouse.displayProducts();

    warehouse.removeProduct("Apple");

    warehouse.displayProducts();

    return 0;
}