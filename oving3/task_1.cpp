const double pi = 3.141592;

class Circle {
    double radius; //variable should be declared at the top
    public:
        Circle(double radius_);
        double get_area() const; //Since we are working with pi, the area should be a double
        double get_circumference() const;

};

// ==> Implementasjon av klassen Circle

Circle::Circle(double radius_) : radius(radius_) {} //Wrong use of names | should not have public attribute

double Circle::get_area() const{ //Made the function return double | added const attribute
    return pi * radius * radius;
}

double Circle::get_circumference() const { //Added correct return type
    return 2.0 * pi * radius;
}
