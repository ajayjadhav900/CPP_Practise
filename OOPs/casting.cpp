#include <iostream>

class Shape
{
public:
    virtual void printArea() const = 0;
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    void printArea() const override
    {
        double area = 3.14159 * radius * radius;
        std::cout << "Circle Area: " << area << std::endl;
    }
};

class Rectangle : public Shape
{
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    void printArea() const override
    {
        double area = width * height;
        std::cout << "Rectangle Area: " << area << std::endl;
    }
};

int main()
{
    Shape *shape1 = new Circle(5.0);
    Shape *shape2 = new Rectangle(3.0, 4.0);

    // Casting shape1 to Circle and calling specific Circle methods
    Circle *circlePtr = static_cast<Circle *>(shape1);
    if (circlePtr != nullptr)
    {
        std::cout << "Circle specific method called: ";
        circlePtr->printArea();
    }

    // Casting shape2 to Rectangle and calling specific Rectangle methods
    Rectangle *rectanglePtr = dynamic_cast<Rectangle *>(shape1);
    if (rectanglePtr != nullptr)
    {
        std::cout << "Rectangle specific method called: ";
        rectanglePtr->printArea();
    }

    delete shape1;
    delete shape2;

    return 0;
}
