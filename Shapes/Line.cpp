#include "Line.h"

Line::Line(VecUnqPtrShape& s, int firstShapeIndex, int secondShapeIndex) noexcept : m_shapes(s), m_firstShapeIdx(firstShapeIndex), m_secondShapeIdx(secondShapeIndex) { }

void Line::draw(QPainter& qp)
{
	if (m_firstShapeIdx >= 0 && m_secondShapeIdx >= 0)
	{
		qp.setPen(QPen(m_color, 2));
		qp.drawLine(m_shapes[m_firstShapeIdx]->center(), m_shapes[m_secondShapeIdx]->center());
	}
}

int Line::firstShapeIndex() const noexcept
{
	return m_firstShapeIdx;
}

int Line::secondShapeIndex() const noexcept
{
	return m_secondShapeIdx;
}

const QColor& Line::color() const noexcept
{
	return m_color;
}

void Line::setColor(const QColor& c) noexcept
{
	m_color = c;
}

void Line::setFirstShapeIndex(int firstShapeIndex) noexcept
{
	m_firstShapeIdx = firstShapeIndex;
}

void Line::setSecondShapeIndex(int secondShapeIndex) noexcept
{
	m_secondShapeIdx = secondShapeIndex;
}
