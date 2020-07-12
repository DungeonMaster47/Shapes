#pragma once
#include <QPainter>
#include "Shape.h"

class Line
{
public:
	Line(std::vector<std::unique_ptr<Shape>>& s, int firstShapeIndex = -1, int secondShapeIndex = -1);
	void draw(QPainter& qp);
	int firstShapeIndex();
	int secondShapeIndex();
	const QColor& color();
	void setColor(const QColor& c);
	void setFirstShapeIndex(int firstShapeIndex);
	void setSecondShapeIndex(int secondShapeIndex);
private:
	std::vector<std::unique_ptr<Shape>>& shapes;
	int firstShapeIdx;
	int secondShapeIdx;
	QColor colour = Qt::black;
};

