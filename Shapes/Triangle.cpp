#include "Triangle.h"

Triangle::Triangle(QPoint p, int w, int h, QColor c) : Shape(p, w, h, c) 
{ 
	setSize(QSize(w, h));
}

void Triangle::setSize(QSize size)
{
	r = (size.width() + size.height()) / 2;
	width = r*2;
	height = r*2;
}

QPoint rotate(QPoint point, QPoint axis, double angle)
{
	point.rx() -= axis.x();
	point.ry() -= axis.y();

	QPoint result;
	result.rx() = cos(angle)*point.x() - sin(angle)*point.y();
	result.ry() = sin(angle)*point.x() + cos(angle)*point.y();

	result.rx() += axis.x();
	result.ry() += axis.y();

	return result;
}

void Triangle::draw(QPainter & qp)
{
	QPoint a = position;
	a.rx() += r;

	QPoint b = rotate(a, center(), 2 * acos(-1) / 3);
	QPoint c = rotate(b, center(), 2 * acos(-1) / 3);

	qp.setPen(QPen(colour, PEN_WIDTH));
	qp.drawLine(a, b);
	qp.drawLine(a, c);
	qp.drawLine(c, b);
}

