#include <iostream>
#include <vector>
#include <string>

class Shape {
public:
    int X;
    int Y;
    std::string color;

    Shape() : X(0), Y(0), color("") {}

    Shape(const Shape& source) : X(source.X), Y(source.Y), color(source.color) {}

    virtual Shape* clone() const = 0;
};

class Rectangle : public Shape {
public:
    int width;
    int height;

    Rectangle() : width(0), height(0) {}

    Rectangle(const Rectangle& source) : Shape(source), width(source.width), height(source.height) {}

    Shape* clone() const override {
        return new Rectangle(*this);
    }
};

class Circle : public Shape {
public:
    int radius;

    Circle() : radius(0) {}

    Circle(const Circle& source) : Shape(source), radius(source.radius) {}

    Shape* clone() const override {
        return new Circle(*this);
    }
};

class Application {
public:
    std::vector<Shape*> shapes;

    Application() {
        Circle* circle = new Circle();
        circle->X = 10;
        circle->Y = 10;
        circle->radius = 20;
        shapes.push_back(circle);

        Circle* anotherCircle = dynamic_cast<Circle*>(circle->clone());
        shapes.push_back(anotherCircle);

        Rectangle* rectangle = new Rectangle();
        rectangle->width = 10;
        rectangle->height = 20;
        shapes.push_back(rectangle);
    }

    void businessLogic() {
        std::vector<Shape*> shapesCopy;

        for (Shape* s : shapes) {
            shapesCopy.push_back(s->clone());
        }

        // Cleanup: delete original shapes
        for (Shape* s : shapes) {
            delete s;
        }

        // Now, shapesCopy contains exact copies of the original shapes.
        // ...
        
        // Cleanup: delete copied shapes
        for (Shape* s : shapesCopy) {
            delete s;
        }
    }
};

int main() {
    Application app;
    app.businessLogic();
    return 0;
}
