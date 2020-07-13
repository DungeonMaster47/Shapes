#include "Shape.h"

Shape::Shape(QPoint p, int w, int h, QColor c) noexcept : m_position(p), m_width(w), m_height(h), m_color(c) {}

QSize Shape::size() const noexcept
{
	return QSize(m_width, m_height);
}

QRect Shape::rect() const noexcept
{
	return QRect(m_position, QSize(m_width, m_height));
}

QPoint Shape::center() const noexcept
{
	QPoint result = m_position;
	result.rx() += m_width/2;
	result.ry() += m_height/2;
	return result;
}

QPoint Shape::pos() const noexcept
{
	return m_position;
}

QColor Shape::color() const noexcept
{
	return m_color;
}

void Shape::setSize(QSize size) noexcept
{
	m_width = size.width();
	m_height = size.height();
}

void Shape::setPos(QPoint p) noexcept
{
	m_position = p;
}

void Shape::setColor(QColor c) noexcept
{
	m_color = c;
}
