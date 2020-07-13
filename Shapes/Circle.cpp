#include "Circle.h"

Circle::Circle(QPoint p, int w, int h, QColor c) noexcept : Shape(p, w, h, c) { }

void Circle::draw(QPainter& qp)
{
	qp.setPen(QPen(color(), PEN_WIDTH));
	qp.drawEllipse(rect());
}
