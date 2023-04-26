#include "MyRender.h"

MyRender::~MyRender()
{
    drawable.reset();
}

void MyRender::on_awake()
{
    Component::on_awake();
}
