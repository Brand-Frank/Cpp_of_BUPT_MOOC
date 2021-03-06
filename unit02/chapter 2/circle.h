/*
    @类声明
 */

/* 避免头文件被多次包含 */
#ifndef CIRCLE_H_
#define CIRCLE_H_

class Circle {
    private:
        // The radius of this circle
        double radius;

    public:
        Circle();   /* 函数声明 */
        Circle(double newRadius);
        double getArea();
};


#endif /* CIRCLE_H_ */