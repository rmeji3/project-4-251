#pragma once

#include "shape.h"
#include <iostream>

using namespace std;

class ShapeNode
{
  public:
    Shape *value;
    ShapeNode *next;
};

class CanvasList
{
  private:
    int listSize;
    ShapeNode *listFront;

  public:
    CanvasList();
    CanvasList(const CanvasList &);
    CanvasList operator=(const CanvasList &);
    
    virtual ~CanvasList();
    void clear();

    void insertAfter(int, Shape *);
    void push_front(Shape *);
    void push_back(Shape *);
    
    void removeAt(int);
    Shape* pop_front();
    Shape* pop_back();

    ShapeNode* front() const;
    bool isempty() const;
    int size() const;

    int find(int x, int y) const;
    Shape* shapeAt(int) const;
    
    void draw() const;
    void printAddresses() const;
};
/*
default constructor used to set values to default
*/
CanvasList::CanvasList()
{
  listSize = 0;
  listFront = nullptr;
}
/*
this function allocates space and creates a deep copy from the canvas in the parameter for this canvas

*/
CanvasList::CanvasList(const CanvasList & x)
{
  listFront = nullptr;//first set default values
  listSize = 0;
  //loops until the end of the list
  for(ShapeNode* temp = x.listFront; temp; temp = temp->next)
  {
    //creates a new shape and pushes it back to the new canvas shapeNode list
    Shape * newShape = temp->value->copy();
    push_back(newShape);
  }
}
/*
this function is for the '=' operator
it will first check if they are already equal to avoid redundant code, then clear the Canvas list otherwise and copy over the shapes
*/
CanvasList CanvasList::operator=(const CanvasList &x)
{
  if(this == &x)//if it already is the same dont copy
    return *this;

  clear();//delete all node from this just in case we have nodes
  
  //loops until the end of the list
  for(ShapeNode* temp = x.listFront; temp; temp = temp->next)
  {
    //creates a new shape and pushes it back to the new canvas shapeNode list
    Shape * newShape = temp->value->copy();
    push_back(newShape);
  }
  return *this;
}
//destuctor will clear the nodes and shapes in every node
CanvasList::~CanvasList()
{
    clear();
}
//this function will delete all nodes in the list
void CanvasList::clear()
{
  // Loop through the list, deleting each node
  while (listFront != nullptr)
  {
    ShapeNode *temp = listFront;
    listFront = listFront->next;
    delete temp->value;
    delete temp;
  }
  listFront = nullptr;

  // make sure to reset listSize to 0
  listSize = 0;
}
/*
 * this function will insert a shape after a certain index in the canvas list
 * it takes in the shape to add and the index
 * it adds after that index
 */
void CanvasList::insertAfter(int index, Shape *shapeToAdd)
{
  if (index < 0 || index >= listSize) 
  {
    return;
  }

  ShapeNode *curr = listFront;

  // Loop through the list until we reach the desired   node
  for (int i = 0; i < index; i++)
  {
    curr = curr->next;
  }
 // Create a new ShapeNode for the shape to add
  ShapeNode *newShape = new ShapeNode();
  newShape->value = shapeToAdd;
  newShape->next = curr->next;

  // Insert the new ShapeNode into the list and increment the size of the list
  curr->next = newShape;
  listSize++;
}
  /*
 * this function will create a shape node to add to the front of the list
the parameter is the shape to add the to the node list
first you create a temp ShapeNode and store the shape
then you add it to the front
be sure to update the size of the new list
*/
void CanvasList::push_front(Shape *currShape)
{
    //new temp node to store the shape to add
    ShapeNode *temp = new ShapeNode();
    temp->value = currShape;

    //move to front of list and update the head of the list
    temp->next = this->listFront;
    this->listFront = temp;

    //update the size of the list
    listSize++;
}

 
/*
 * this function will create a shape node to add to the end of the list
the parameter is the shape to add the to the node list
first you allocate a temp ShapeNode and store the shape
you have to get another temp pointer to the end of the list by looping through all the way
then you add it to the end
be sure to update the size of the new list
*/
void CanvasList::push_back(Shape *currShape)
{
    //new temp node to store the shape to add
    ShapeNode *nodeToAppend = new ShapeNode();
    nodeToAppend->value = currShape;
    nodeToAppend->next = nullptr;

    //loop through to the end of the list
    ShapeNode *temp = listFront;
    if(temp != nullptr)
    {
      while(temp->next != nullptr)
      {
          temp = temp->next;
      }
    
    
      //append node to back of list
      temp->next = nodeToAppend;
     
    }
    else
    {
      listFront = nodeToAppend;
    }
  
    //update the size of the list
    listSize++;
    
}
/*
this function will remove a certain node and shape at a certain index of the canvas list
*/
void CanvasList::removeAt(int index)
{
  if (index < 0 || index >= listSize)
      return;

  ShapeNode *prev = nullptr;
  ShapeNode *curr = listFront;

  // Loop through the list until we reach the desired node
  for (int i = 0; i < index; i++) {
      prev = curr;
      curr = curr->next;
  }

  // Remove the node from the list
  if (prev)
      prev->next = curr->next;
  else
      listFront = curr->next;
  delete curr->value;
  delete curr;
  //reduce the size after deleting one
  listSize--;
}
/*
 * this will delete the shape node at the front and return that deleted shape
 * you have to make a new pointer to the second node and then another shape pointer to the shape at the front before
 * deleting it. then you have to decrease the size of the list and return the popped shape
 */
Shape* CanvasList::pop_front()
{
    if (isempty()) {
        return nullptr;
    }

    ShapeNode* temp = listFront;
    Shape* deletedShape = temp->value;

    listFront = listFront->next;
    delete temp;

    listSize--;
    return deletedShape;
}

/*
 * this will delete the shape node at the end and return that deleted shape
 * you have to make a new pointer to the second to last node and then another shape pointer to the shape your deleting before
 * deleting it. then you have to decrease the size of the list and return the popped shape
 */
Shape* CanvasList::pop_back()
{
  if (isempty()) {
    return nullptr;
  }
  else if(listSize == 1)
  {
    Shape *deletedShape = listFront->value;
    delete listFront;
    listFront = nullptr;
    listSize--;
    return deletedShape;
  }
  else
  {
    ShapeNode * secondToLast = listFront;
    
    for(int i = 0; i < listSize-2; i++)
    {
      secondToLast = secondToLast->next;
    }
    Shape* lastShape = secondToLast->next->value;
    delete secondToLast->next;
    secondToLast->next = nullptr;
    listSize--;
    return lastShape;
  }
}
//this function returns the ShapeNode in the front of //the canvas list
ShapeNode* CanvasList::front() const
{
  return listFront;
}
bool CanvasList::isempty() const
{
  return listSize == 0;
}
int CanvasList::size() const
{
    return listSize;
}
/*
returns index linked list in which it finds the shape at the coordinates in the parameter
  */
int CanvasList::find(int x, int y) const
{
  ShapeNode* temp = listFront;
  for(int i = 0; i < listSize; i++)
  {
    if(temp->value->getX() == x && temp->value->getY() == y)
      return i;
    temp = temp->next;
  }
  return -1;
}
/*
Returns the shape at the index in the parameter
*/
Shape* CanvasList::shapeAt(int index) const
{
  if(isempty())//if the list is empty return a null value
  {
    return nullptr;
  }
  else if(index > listSize-1)//if the index is greater than the list
  {
    return nullptr;
  }
  else//if not return the index
  {
    ShapeNode* temp = listFront;
    for(int i = 0; i < index; i++)//first loop until that index on the linked list
    {
      temp = temp->next;
    }
    return temp->value;//return the shape
  }
  
}
/*this function will print of the stats of the individual shapes in the entire list, the virtual keyword will appropriately check what type of shape it is after compiling to print out their name and unique stats*/
void CanvasList::draw() const
{
  ShapeNode * temp = listFront;
  while(temp != nullptr)
  {
    temp->value->printShape();
    temp = temp->next;
  }
  
}
/*
This function will print out all the addresses of the shapes in the linked list and each shapeNode address too
*/
void CanvasList::printAddresses() const
{
  //first loop through each shape and print out individual shapes
  ShapeNode * temp = listFront;
  for(int i = 0; i < listSize; i++)
  {
    cout << "Node Address: " << temp << "\t";
    cout << "Shape Address: " << temp->value << endl;
    temp = temp->next;
  }
}
