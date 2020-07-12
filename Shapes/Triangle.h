#pragma once
#include "Shape.h"

class Triangle : public Shape
{
public:
	Triangle(QPoint p, int w, int h, QColor c);
	void setSize(QSize) override;
	void draw(QPainter& qp) override;
private:
	int r;
};

