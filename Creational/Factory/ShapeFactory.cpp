#include <iostream>
#include <memory>

class Shape
{
public:
    virtual void draw() const = 0;
};

class Circle : public Shape
{
public:
    Circle() = default;

private:
    void draw() const override
    {
        std::cout << "Inside Circle::draw" << std::endl;
    }
};

class Square : public Shape
{
public:
    Square() = default;

private:
    void draw() const override
    {
        std::cout << "Inside Square::draw" << std::endl;
    }
};

class Triangle : public Shape
{
public:
    Triangle() = default;

private:
    void draw() const override
    {
        std::cout << "Inside Triangle::draw" << std::endl;
    }
};

class ShapeFactory
{
public:
    enum class ShapeType : int8_t
    {
        CIRCLE = 0U,
        SQUARE = 1U,
        TRIANGLE = 2U

    };

    // Enum vs enum class
    /*
    enum Color : int8_t
    {
        RED = 0U
    };
    enum Card : int8_t
    {
        RED = 0U // Error because  there is RED declared before if we use enum class this RED will have local scope
    };
    */

    /**
     * Right now this method is static as we dont require any argument to create factory. If we require something to create factory/shape we shouldn't make this method as static
     */
    static std::shared_ptr<Shape> getShape(const ShapeType &shapeType)
    {
        std::shared_ptr<Shape> shape;
        switch (shapeType)
        {
        case ShapeType::CIRCLE:
            shape = std::make_shared<Circle>();
            break;
        case ShapeType::SQUARE:
            shape = std::make_shared<Square>();
            break;
        case ShapeType::TRIANGLE:
            shape = std::make_shared<Triangle>();
            break;
        default:
            break;
        }

        return shape;
    }
};
int main()
{
    // enum class A
    // {
    //     R
    // };
    // int a = A::R; // Error implicit typecasting not done because of enum class.
    auto shape = ShapeFactory::getShape(ShapeFactory::ShapeType::CIRCLE);
    shape->draw();
    shape = ShapeFactory::getShape(ShapeFactory::ShapeType::TRIANGLE);
    shape->draw();
    shape = ShapeFactory::getShape(ShapeFactory::ShapeType::SQUARE);
    shape->draw();

    return 0;
}