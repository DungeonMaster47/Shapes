#pragma once
#include "Shape.h"

class Circle : public Shape
{
public:
	Circle(QPoint p, int w, int h, QColor c = Qt::black);
	void draw(QPainter& qp) override;
};

