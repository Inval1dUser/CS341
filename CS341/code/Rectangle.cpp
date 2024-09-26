#include "Rectangle.h"

Rectangle::Rectangle()
{
    x_= 10;
    y_= 15;
}

Rectangle::Rectanlge(int x, int y) 
{
    x_ = x;
    y_ = y;
}

int Rectangle::getX() {
    return x_;
}

double Rectangle::getArea() {
    return x * y;
}
