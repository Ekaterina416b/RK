#ifndef POINTS_H
#define POINTS_H

#include <iostream>
#include <cmath>

enum class PointType { cartesian, polar };

namespace Factory03 {
    class Point {
    private:
        double m_x;
        double m_y;
        PointType m_type;
        Point(double x, double y, PointType t);
    public:
        static Point NewCartesian(double x, double y);
        static Point NewPolar(double a, double b);
        
        // Добавьте дружественную функцию для оператора <<
        friend std::ostream& operator<<(std::ostream& os, const Point& obj);
    };
}

namespace Factory04 {
    class Point {
        friend class PointFactory;
    private:
        double m_x;
        double m_y;
        PointType m_type;
        Point(double x, double y, PointType t);
    public:
        // Добавьте дружественную функцию для оператора <<
        friend std::ostream& operator<<(std::ostream& os, const Point& obj);
    };

    class PointFactory {
    public:
        static Point NewCartesian(double x, double y);
        static Point NewPolar(double a, double b);
    };
}

namespace Factory05 {
    class Point {
    private:
        double m_x;
        double m_y;
        Point(double x, double y);
    public:
        struct Factory {
            static Point NewCartesian(double x, double y);
            static Point NewPolar(double r, double theta);
        };
        
        // Добавьте дружественную функцию для оператора <<
        friend std::ostream& operator<<(std::ostream& os, const Point& obj);
    };
}

void test_real_world_example_points();

#endif // POINTS_H
