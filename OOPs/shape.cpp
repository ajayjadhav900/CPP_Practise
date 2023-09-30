#include <iostream>
#include <string>

// Abstract base class for the drawing strategy
class DrawStrategy
{
public:
    virtual void draw() = 0;
    virtual ~DrawStrategy() {}
};

// Concrete drawing strategy for OpenGL
class OpenGLDrawStrategy : public DrawStrategy
{
public:
    void draw() override
    {
        // Implement OpenGL drawing logic here
        std::cout << "Drawing using OpenGL" << std::endl;
    }
};

// Concrete drawing strategy for Metal
class MetalDrawStrategy : public DrawStrategy
{
public:
    void draw() override
    {
        // Implement Metal drawing logic here
        std::cout << "Drawing using Metal" << std::endl;
    }
};

// Abstract base class for the serialization strategy
class SerializeStrategy
{
public:
    virtual void serialize() = 0;
    virtual ~SerializeStrategy() {}
};

// Concrete serialization strategy for little-endian format
class LittleEndianSerializeStrategy : public SerializeStrategy
{
public:
    void serialize() override
    {
        // Implement little-endian serialization logic here
        std::cout << "Serializing in Little Endian format" << std::endl;
    }
};

// Concrete serialization strategy for big-endian format
class BigEndianSerializeStrategy : public SerializeStrategy
{
public:
    void serialize() override
    {
        // Implement big-endian serialization logic here
        std::cout << "Serializing in Big Endian format" << std::endl;
    }
};

// Abstract base class for shapes
class Shape
{
protected:
    DrawStrategy *drawStrategy;
    SerializeStrategy *serializeStrategy;

public:
    Shape(DrawStrategy *draw, SerializeStrategy *serialize)
        : drawStrategy(draw), serializeStrategy(serialize) {}

    virtual ~Shape()
    {
        delete drawStrategy;
        delete serializeStrategy;
    }

    virtual void draw() = 0;
    virtual void serialize() = 0;
};

// Concrete Circle class
class Circle : public Shape
{
public:
    Circle(DrawStrategy *draw, SerializeStrategy *serialize)
        : Shape(draw, serialize) {}

    void draw() override
    {
        drawStrategy->draw();
    }

    void serialize() override
    {
        serializeStrategy->serialize();
    }
};

// Concrete Square class
class Square : public Shape
{
public:
    Square(DrawStrategy *draw, SerializeStrategy *serialize)
        : Shape(draw, serialize) {}

    void draw() override
    {
        drawStrategy->draw();
    }

    void serialize() override
    {
        serializeStrategy->serialize();
    }
};

int main()
{
    DrawStrategy *openGLDraw = new OpenGLDrawStrategy();
    DrawStrategy *metalDraw = new MetalDrawStrategy();
    SerializeStrategy *littleEndianSerialize = new LittleEndianSerializeStrategy();
    SerializeStrategy *bigEndianSerialize = new BigEndianSerializeStrategy();

    Shape *openGLSquare = new Square(openGLDraw, littleEndianSerialize);
    Shape *metalSquare = new Square(metalDraw, bigEndianSerialize);
    Shape *openGLCircle = new Circle(openGLDraw, littleEndianSerialize);
    Shape *metalCircle = new Circle(metalDraw, bigEndianSerialize);

    openGLSquare->draw();
    openGLSquare->serialize();
    metalSquare->draw();
    metalSquare->serialize();
    openGLCircle->draw();
    openGLCircle->serialize();
    metalCircle->draw();
    metalCircle->serialize();

    delete openGLSquare;
    delete metalSquare;
    delete openGLCircle;
    delete metalCircle;

    return 0;
}
