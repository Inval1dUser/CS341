#ifndef SHAPE_H
#define SHAPE_H

class Shape {
    public:
        Shape();
        virtual ~Shape();
        virtual double getarea() = 0;

    private:
        double area_;
}

#endif // !SHAPE_H




