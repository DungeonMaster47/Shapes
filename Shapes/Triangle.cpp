#include "Triangle.h"

Triangle::Triangle(QPoint p, int w, int h, QColor c) noexcept : Shape(p, w, h, c)
{ 
	setSize(QSize(w, h));
}

void Triangle::setSize(QSize size) noexcept
{
	m_radius = size.width()/2;
	m_width = m_radius*2;
	m_height = m_radius*2;
}

QPoint rotate(QPoint point, const QPoint& axis, double angle) noexcept
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

void Triangle::draw(QPainter& qp)
{
	QPoint a = m_position;
	a.rx() += m_radius;

	QPoint b = rotate(a, center(), 2 * acos(-1) / 3);
	QPoint c = rotate(b, center(), 2 * acos(-1) / 3);

	qp.setPen(QPen(m_color, PEN_WIDTH));
	qp.drawLine(a, b);
	qp.drawLine(a, c);
	qp.drawLine(c, b);
}

