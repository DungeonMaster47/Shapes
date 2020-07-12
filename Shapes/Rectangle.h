#pragma once
#include "Shape.h"

class Rectangle : public Shape
{
public:
	Rectangle(QPoint p, int w, int h, QColor c);
	virtual void draw(QPainter& qp);
};

