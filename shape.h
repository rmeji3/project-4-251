#pragma once
/*
      Rafael Mejia
      cs 251
      march 27 2023


*/
using namespace std;

class Shape
{
    protected:
        int x;
        int y;

    public: 
        Shape();
        Shape(int x, int y);

        virtual ~Shape();
        virtual Shape* copy();

        int getX() const;
        int getY() const;
        void setX(int);
        void setY(int);
        
        virtual void printShape() const;
};
//default constructor gives the values default values
Shape::Shape()
{
  x = 0;
  y = 0;
}
//paramterized constructor allows the user to pick the values
Shape::Shape(int x, int y)
{
  this->x = x;
  this->y = y;
}
//destructor
Shape::~Shape()
{}
/*
We make a new shape and copy over the data from the current shape
*/

//copy function returns a deep copy of a new shape from 'this' shape
Shape* Shape::copy()
{
  Shape * newShape = new Shape();
  newShape->x = x;
  newShape->y = y;
  return newShape;
}
//returns x value
int Shape::getX()const
{
  return x;
}
//returns y value
int Shape::getY()const
{
  return y;
}
//allows user to set the x value
void Shape::setX(int x)
{
  this->x = x;
}
//allows the user to set the y value
void Shape::setY(int y)
{
  this->y = y;
}
//prints "shape" and its coords
void Shape::printShape() const
{
    cout << "It's a Shape at x: " << x << ", y: " << y << endl;
}

class Circle : public Shape 
{
    private:
        int radius;

    public: 
        Circle();
        Circle(int r);
        Circle(int x, int y, int r);

        virtual ~Circle();
        virtual Circle* copy();
        
        int getRadius() const;
        void setRadius(int r);
        
        virtual void printShape() const;
};
//default constructor gives the default values
Circle::Circle()
{
  x = 0;
  y = 0;
  radius = 0;
}
//allows the user to set the radius
Circle::Circle(int r)
{
  radius = r;
}
//parameterized constructor
Circle::Circle(int x, int y, int r)
{
  this-> x = x;
  this ->y = y;
  radius = r;
}
Circle::~Circle(){}

Circle* Circle::copy()
{
  return new Circle{this->x,this->y, radius};
}
int Circle::getRadius() const
{
  return radius;
}
void Circle::setRadius(int r)
{
  radius = r;
}

void Circle::printShape() const
{
  cout << "It's a Circle at x: " << x << ", y: " << y << ", radius: " << radius << endl;
}


class Rectangle : public Shape 
{
    private:
        int width;
        int height;

    public: 
        Rectangle();
        Rectangle(int w, int h);
        Rectangle(int x, int y, int w, int h);
        
        virtual ~Rectangle();
        virtual Rectangle* copy();
        
        int getWidth() const;
        int getHeight() const;
        void setWidth(int);
        void setHeight(int);
        
        virtual void printShape() const;
};
Rectangle::Rectangle()
{
  width = 0;
  height = 0;
  x = 0;
  y = 0;
}
Rectangle::Rectangle(int w, int h)
{
  x = 0;
  y = 0;
  width = w;
  height = h;
}
Rectangle::Rectangle(int x, int y, int w, int h)
{
  this->x = x;
  this->y = y;
  width = w;
  height = h;
  
}

Rectangle::~Rectangle()
{}
Rectangle* Rectangle::copy()
{
  return new Rectangle{this->x,
  this->y,
  width,
  height};
}
int Rectangle::getWidth() const
{
  return width;
}
int Rectangle::getHeight() const
{
  return height;
}
void Rectangle::setWidth(int width)
{
  this->width = width;
}
void Rectangle::setHeight(int height)
{
  this->height = height;
}
        
void Rectangle::printShape() const
{
   cout << "It's a Rectangle at x: " << x << ", y: " << y << " with width: " << width << " and height: " << height<< endl;
}

class RightTriangle : public Shape 
{
    private:
        int base;
        int height;

    public: 
        RightTriangle();
        RightTriangle(int b, int h);
        RightTriangle(int x, int y, int b, int h);
        
        virtual ~RightTriangle();
        virtual RightTriangle* copy();
        
        int getBase() const;
        int getHeight() const;
        void setBase(int);
        void setHeight(int);

        virtual void printShape() const;
};
RightTriangle::RightTriangle()
{
  x = 0;
  y = 0;
  base = 0;
  height = 0;
}
RightTriangle::RightTriangle(int b, int h)
{
  base = b;
  height = h;
  x = 0;
  y = 0;
}
RightTriangle::RightTriangle(int x, int y, int b, int h)
{
  this->x =x;
  this->y = y;
  base = b;
  height = h;
}
        
RightTriangle::~RightTriangle()
{}
RightTriangle* RightTriangle::copy()
{
  return new RightTriangle{
    this->x, this->y,this->base,this->height
  };
}
        
int RightTriangle::getBase() const
{
  return base;
}
int RightTriangle::getHeight() const
{
  return height;
}
void RightTriangle::setBase(int base)
{
  this->base = base;
}
void RightTriangle::setHeight(int height)
{
  this->height = height;
}

void RightTriangle::printShape() const
{
  cout << "It's a Right Triangle at x: " << x << ", y: "<< y << " with base: " << base <<" and height: " << height << endl;
}