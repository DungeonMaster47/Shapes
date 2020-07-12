#include "Rectangle.h"

Rectangle::Rectangle(QPoint p, int w, int h, QColor c) : Shape(p, w, h, c) { }

void Rectangle::draw(QPainter& qp)
{
	qp.setPen(QPen(color(), PEN_WIDTH));
	qp.drawRect(rect());
}

