#include "Points.h"

namespace Factory03 {
    Point::Point(double x, double y, PointType t) : m_x{x}, m_y{y}, m_type{t} {}

    Point Point::NewCartesian(double x, double y) {
        return {x, y, PointType::cartesian};
    }

    Point Point::NewPolar(double a, double b) {
        return {a * cos(b), a * sin(b), PointType::polar};
    }

    std::ostream& operator<<(std::ostream& os, const Point& obj) {
        return os << "x: " << obj.m_x << " y: " << obj.m_y;
    }
}

namespace Factory04 {
    Point::Point(double x, double y, PointType t) : m_x{x}, m_y{y}, m_type{t} {}

    Point PointFactory::NewCartesian(double x, double y) {
        return {x, y, PointType::cartesian};
    }

    Point PointFactory::NewPolar(double a, double b) {
        return {a * cos(b), a * sin(b), PointType::polar};
    }

    std::ostream& operator<<(std::ostream& os, const Point& obj) {
        return os << "x: " << obj.m_x << " y: " << obj.m_y;
    }
}

namespace Factory05 {
    Point::Point(double x, double y) : m_x{x}, m_y{y} {}

    Point Point::Factory::NewCartesian(double x, double y) {
        return {x, y};
    }

    Point Point::Factory::NewPolar(double r, double theta) {
        return {r * cos(theta), r * sin(theta)};
    }

    std::ostream& operator<<(std::ostream& os, const Point& obj) {
        return os << "x: " << obj.m_x << " y: " << obj.m_y;
    }
}

void test_real_world_example_points() {
    Factory03::Point p1 = Factory03::Point::NewPolar(5.0, M_PI_4);
    std::cout << p1 << std::endl;

    Factory04::Point p2 = Factory04::PointFactory::NewPolar(5.0, M_PI_4);
    std::cout << p2 << std::endl;

    Factory05::Point p3 = Factory05::Point::Factory::NewCartesian(2, 3);
    std::cout << p3 << std::endl;
}
