#include "IUpdateable.h"

void IUpdateable::on_awake()
{
    Component::on_awake();
}

IUpdateable::~IUpdateable()
{
    // No dynamically allocated memory to clean-up.
}
