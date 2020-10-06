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
        double getRadius() const;
        void setRadius(double radius);
};


#endif /* CIRCLE_H_ */