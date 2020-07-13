#pragma once
#include "Shape.h"

class Circle : public Shape
{
public:
	Circle(QPoint p, int w, int h, QColor c = Qt::black) noexcept;
	void draw(QPainter& qp) override;
};

