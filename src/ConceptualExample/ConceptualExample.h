// ConceptualExample.h
#ifndef CONCEPTUAL_EXAMPLE_H
#define CONCEPTUAL_EXAMPLE_H

#include <memory>
#include <string>

namespace ConceptualExample {

    class IShape {
    public:
        virtual ~IShape() {}
        virtual void draw() = 0;
    };

    class Rectangle : public IShape {
    public:
        Rectangle() {}
        void draw() override;
    };

    class Square : public IShape {
    public:
        Square() {}
        void draw() override;
    };

    class Circle : public IShape {
    public:
        Circle() {}
        void draw() override;
    };

    class ShapeFactory {
    public:
        enum class ShapeKind {
            Rectangle,
            Square,
            Circle,
            None
        };

        std::shared_ptr<IShape> getShape(ShapeKind shapeType);
    };

    void test_without_factory();
    void test_with_factory();
}

void test_conceptual_example();

#endif // CONCEPTUAL_EXAMPLE_H
