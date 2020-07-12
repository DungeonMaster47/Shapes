#include "Shape.h"

Shape::Shape(QPoint p, int w, int h, QColor c) : position(p), width(w), height(h), colour(c) {}

QRect Shape::rect() const
{
	return QRect(position, QSize(width, height));
}

QPoint Shape::center() const
{
	QPoint result = position;
	result.rx() += width/2;
	result.ry() += height/2;
	return result;
}

QPoint Shape::pos() const
{
	return position;
}

QColor Shape::color() const
{
	return colour;
}

void Shape::setSize(QSize size)
{
	width = size.width();
	height = size.height();
}

void Shape::setPos(QPoint p)
{
	position = p;
}

void Shape::setColor(QColor c)
{
	colour = c;
}
