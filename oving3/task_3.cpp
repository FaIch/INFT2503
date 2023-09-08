#include <string>
#include <utility>
using namespace std;

const double sales_tax = 1.25;

class Commodity{
    string name;
    int id;
    double price;

    public:
    Commodity(string name, long id, double price);
    string get_name() const;
    long get_id() const;
    double get_price(double quantity = 1) const;
    void set_price(double price_);
    double get_price_with_sales_tax(double quantity) const;
};

Commodity::Commodity(string name, long id_, double price) : name(std::move(name)), id(id_), price(price) {};

string Commodity::get_name() const{
    return name;
}

long Commodity::get_id() const{
    return id;
}

double Commodity::get_price(double quantity) const {
    return price * quantity;
}

void Commodity::set_price(double price_) {
    price = price_;
}

double Commodity::get_price_with_sales_tax(double quantity) const {
    return price * sales_tax * quantity;
}