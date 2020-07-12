#include "Line.h"

Line::Line(std::vector<std::unique_ptr<Shape>>& s, int firstShapeIndex, int secondShapeIndex) : shapes(s), firstShapeIdx(firstShapeIndex), secondShapeIdx(secondShapeIndex) { }

void Line::draw(QPainter& qp)
{
	if (firstShapeIdx >= 0 && secondShapeIdx >= 0)
	{
		qp.setPen(QPen(colour, 2));
		qp.drawLine(shapes[firstShapeIdx]->center(), shapes[secondShapeIdx]->center());
	}
}

int Line::firstShapeIndex()
{
	return firstShapeIdx;
}

int Line::secondShapeIndex()
{
	return secondShapeIdx;
}

const QColor& Line::color()
{
	return colour;
}

void Line::setColor(const QColor& c)
{
	colour = c;
}

void Line::setFirstShapeIndex(int firstShapeIndex)
{
	firstShapeIdx = firstShapeIndex;
}

void Line::setSecondShapeIndex(int secondShapeIndex)
{
	secondShapeIdx = secondShapeIndex;
}
