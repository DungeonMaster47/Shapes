#pragma once
#include "Shape.h"

class Rectangle : public Shape
{
public:
	Rectangle(QPoint p, int w, int h, QColor c) noexcept;
	virtual void draw(QPainter& qp);
};

