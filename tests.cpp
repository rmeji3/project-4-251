/// @filename tests.cpp
/// @date March 7, 2023
///  Rafael Mejia
///  CS 251

/// Provided testing file to implement
/// framework based tests in. The example
/// below uses the Catch testing framework
/// version that uses a single .hpp file.

// This tells Catch to provide a main()
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "shape.h"
#include "canvaslist.h"

using namespace std;

// Shape tests
TEST_CASE("testing default Shape constructor")
{
    Shape shape; // create Shape object using default constructor
    REQUIRE(shape.getX() == 0);
    REQUIRE(shape.getY() == 0);
}

TEST_CASE("testing Shape parameterized constructor")
{
    Shape shape(10, 5); // create Shape object using parameterized constructor
    REQUIRE(shape.getX() == 10);
    REQUIRE(shape.getY() == 5);
}

TEST_CASE("testing Shape copy()")
{
    Shape shape1(10, 5); // create first Shape object
    Shape shape2; // create second Shape object
    shape1.copy(shape2); // copy shape1 into shape2
    REQUIRE(shape1 != shape2); // ensure a deep copy was made
    REQUIRE(shape1.getX() == shape2.getX()); // compare x values of the two Shapes
    REQUIRE(shape1.getY() == shape2.getY()); // compare y values of the two Shapes
}

TEST_CASE("testing Shape getters")
{
    Shape shape(10, 5); // create Shape object using parameterized constructor
    REQUIRE(shape.getX() == 10);
    REQUIRE(shape.getY() == 5);
}

TEST_CASE("testing Shape setters")
{
    Shape shape; // create Shape object using default constructor
    shape.setX(10); // set x value of Shape
    shape.setY(5); // set y value of Shape
    REQUIRE(shape.getX() == 10);
    REQUIRE(shape.getY() == 5);
}


// Circle tests
TEST_CASE("testing default Circle constructor")
{
    Circle circle; // create Circle object using default constructor
    REQUIRE(circle.getX() == 0);
    REQUIRE(circle.getY() == 0);
    REQUIRE(circle.getRadius() == 0);
}

TEST_CASE("testing Circle parameterized constructor")
{
    Circle circle(10); // create Circle object using parameterized constructor
    REQUIRE(circle.getRadius() == 10);
    Circle circle2(10, 5, 4);
    REQUIRE(circle2.getRadius() == 10);
    REQUIRE(circle2.getX() == 5);
    REQUIRE(circle2.getY() == 4);
}

TEST_CASE("testing Circle copy()")
{
    Circle circle1(10, 5, 9); // create first Circle object
    Circle circle2; // create second Circle object
    circle1.copy(circle2); // copy circle1 into circle2
    REQUIRE(circle1 != circle2); // ensure a deep copy was made
    REQUIRE(circle1.getX() == circle2.getX()); // compare x values of the two Circles
    REQUIRE(circle1.getY() == circle2.getY()); // compare y values of the two Circles
    REQUIRE(circle1.getRadius() == circle2.getRadius()); // compare radius values of the two Circles
}

TEST_CASE("testing Circle getters")
{
    Circle circle(10, 5, 9); // create Circle object using parameterized constructor
    REQUIRE(circle.getX() == 10);
    REQUIRE(circle.getY() == 5);
    REQUIRE(circle.getRadius() == 9);
}

TEST_CASE("testing Circle setters")
{
    Circle circle; // create Circle object using default constructor
    circle.setX(10); // set x value of Circle
    circle.setY(5); // set y value of Circle
    REQUIRE(circle.getX() == 10);
    REQUIRE(circle.getY() == 5);
}

TEST_CASE("Testing default Canvas constructor") {
CanvasList yes;
// Ensure the front of the list is null and the size is 0
REQUIRE(yes.front() == nullptr);
REQUIRE(yes.size() == 0);
}

TEST_CASE("Testing copy constructor") {
CanvasList one;
CanvasList two(one);
// Ensure that the size of the copied list is 0 and its front is null
REQUIRE(two.size() == 0);
REQUIRE(two.front() == nullptr);
CanvasList three;
Shape s(10,12);
one.push_back(s);
CanvasList four(three);
// Ensure that the size of the copied list is 1 and its first shape has the correct coordinates
REQUIRE(four.size() == 1);
REQUIRE(four.front().getX() == 10);
REQUIRE(four.front().getY() == 12);
}

TEST_CASE("Testing assignment operator") {
CanvasList one;
Shape s(10,12);
one.push_back(s);
CanvasList three;
Shape s2(10,12);
one.push_back(s2);
CanvasList four = three;
// Ensure that the size of the copied list is 1 and its first shape has the correct coordinates
REQUIRE(four.size() == 1);
REQUIRE(four.front().getX() == 10);
REQUIRE(four.front().getY() == 12);
}

TEST_CASE("Testing clear()") {
CanvasList one;
Shape s(10,12);
one.push_back(s);
one.clear();
// Ensure the list is now empty
REQUIRE(one.size() == 0);
REQUIRE(one.front() == nullptr);
}

TEST_CASE("Testing insertAfter()") {
CanvasList one;
Shape s(10,12);
one.push_back(s);
Circle c;
one.push_back(c);
Rectangle r;
// Ensure that inserting a shape at an invalid index does not modify the list
one.insertAfter(-1,r);
REQUIRE(one.size() == 2);
REQUIRE(one.pop_back() == c);
one.push_back(c);
// Ensure that inserting a shape at an index greater than the list size does not modify the list
one.insertAfter(100,r);
REQUIRE(one.size() == 2);
REQUIRE(one.pop_back() == c);
one.push_back(c);
// Ensure that inserting a shape at a valid index modifies the list correctly
one.insertAfter(1,r);
REQUIRE(one.size() == 3);
REQUIRE(one.pop_back() == r);
}

TEST_CASE("Testing push_front()") {
CanvasList one;
Shape s(10,12);
one.push_back(s);
Circle c;
one.push_front(c);
// Ensure that push_front() adds the shape to the front of the list
REQUIRE(one.size() == 2);
REQUIRE(one.pop_front() == c);
}

TEST_CASE("Testing push_back()") {
CanvasList one;
Shape s(10,12);
one.push_back(s);
Circle c;
one.push_back(c);
// Ensure that push_back() adds the shape to the back of the list
REQUIRE(one.size() == 2);
REQUIRE(one.pop_back() == c);
}

// Test removeAt() function
TEST_CASE("testing removeAt()")
{
CanvasList one;
Shape s(10,12);
Shape s2(1,2);
Rectangle s3(4,6);

// Add some shapes to the list
one.push_back(s);
one.push_back(s2);
one.push_back(s3);

// Remove a shape from the list
removeAt(0);

// Check if the list size is correct and if the correct shape was removed
REQUIRE(one.size() == 2);
REQUIRE(one.pop_front() == s2);
}

// Test pop_front() function
TEST_CASE("TESTING POP_FRONT()")
{
CanvasList one;
Shape s(10,12);

// Add a shape to the back of the list
one.push_back(s);

Circle c;

// Add a shape to the front of the list
one.push_front(c);

// Check if the list size is correct and if the correct shape was popped from the front
REQUIRE(one.size() == 2);
REQUIRE(one.pop_front() == c);
}

// Test pop_back() function
TEST_CASE("TESTING POP BACK")
{
CanvasList one;
Shape s(10,12);

// Add a shape to the back of the list
one.push_back(s);

Circle c;

// Add a shape to the back of the list
one.push_back(c);

// Check if the list size is correct and if the correct shape was popped from the back
REQUIRE(one.size() == 2);
REQUIRE(one.pop_back() == s);
}

// Test front() function
TEST_CASE("TESTING FRONT()")
{
CanvasList one;
Shape s(10,12);

// Add a shape to the back of the list
one.push_back(s);

Circle c;

// Add a shape to the back of the list
one.push_back(c);

// Check if the correct shape is returned by the front() function and if nullptr is returned when the list is empty
REQUIRE(one.front() == c);
one.clear();
REQUIRE(one.front() == nullptr);
}

// Test isempty() function
TEST_CASE("TESTING isempty()")
{
CanvasList one;
Shape s(10,12);

// Add a shape to the back of the list
one.push_back(s);

Circle c;

// Add a shape to the back of the list
one.push_back(c);

// Check if the isempty() function returns the correct value when the list is not empty and when it is empty
REQUIRE(!one.isempty());
one.clear();
REQUIRE(one.isempty());
}

// Test size() function
TEST_CASE("TESTING size()")
{
CanvasList one;
Shape s(10,12);

// Add a shape to the back of the list
one.push_back(s);

Circle c;

// Add a shape to the back of the list
one.push_back(c);

// Check if the size() function returns the correct value when the list is not empty and when it is empty
REQUIRE(one.size() == 2);
one.clear();
REQUIRE(one.size() == 0);
}
TEST_CASE("TESTING find()") {
    // Create a new canvas list
    CanvasList one;
    // Create two shapes and add them to the canvas list
    Shape s(10,12);
    one.push_back(s);
    Rectangle c(10,12);
    one.push_back(c);
    // Check if the first occurrence of a shape with dimensions (10,12) is found at index 0
    REQUIRE(one.find(10,12) == 0);
    // Clear the canvas list
    one.clear();
    // Check that the shape with dimensions (10,12) is not found anymore
    REQUIRE(one.find(10,12) == -1);
}

TEST_CASE("TESTING shapeAt()") {
    // Create a new canvas list
    CanvasList one;
    // Create two shapes and add them to the canvas list
    Shape s(10,12);
    one.push_back(s);
    Rectangle c(10,12);
    one.push_back(c);
    // Check if the shape at index 0 is equal to the first shape created
    REQUIRE(one.shapeAt(0) == s);
    // Check if the shape at index 1 is equal to the second shape created
    REQUIRE(one.shapeAt(1) == c);
    // Clear the canvas list
    one.clear();
    // Check that the shape at index 1 is not found anymore
    REQUIRE(one.shapeAt(1) == nullptr);
}
