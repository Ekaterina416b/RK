// ConceptualExample.cpp
#include "ConceptualExample.h"
#include <iostream>
#include <stdexcept>

namespace ConceptualExample {

    void Rectangle::draw() {
        std::cout << "> Rectangle::draw()" << std::endl;
    }

    void Square::draw() {
        std::cout << "> Square::draw()" << std::endl;
    }

    void Circle::draw() {
        std::cout << "> Circle::draw()" << std::endl;
    }

    std::shared_ptr<IShape> ShapeFactory::getShape(ShapeKind shapeType) {
        std::shared_ptr<IShape> shapePtr;

        switch (shapeType) {
            case ShapeKind::Rectangle:
                shapePtr = std::make_shared<Rectangle>();
                break;
            case ShapeKind::Square:
                shapePtr = std::make_shared<Square>();
                break;
            case ShapeKind::Circle:
                shapePtr = std::make_shared<Circle>();
                break;
            default:
                throw std::runtime_error("Invalid Shape Kind");
        }

        return shapePtr;
    }

    void test_without_factory() {
        Rectangle rect;
        rect.draw();

        Circle circle;
        circle.draw();

        Square square;
        square.draw();
    }

    void test_with_factory() {
        ShapeFactory shapeFactory;
        std::shared_ptr<IShape> shape;

        shape = shapeFactory.getShape(ShapeFactory::ShapeKind::Circle);
        shape->draw();

        shape = shapeFactory.getShape(ShapeFactory::ShapeKind::Rectangle);
        shape->draw();

        shape = shapeFactory.getShape(ShapeFactory::ShapeKind::Square);
        shape->draw();
    }
}

void test_conceptual_example() {
    using namespace ConceptualExample;
    test_without_factory();
    test_with_factory();
}
