#include "MyTransform.h"

void MyTransform::on_awake()
{
    Component::on_awake();
}

MyTransform::~MyTransform()
{
    // No dynamically allocated memory to clean-up.
}
