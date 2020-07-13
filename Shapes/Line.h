#pragma once
#include <QPainter>
#include "Shape.h"

class Line
{
public:
	Line(VecUnqPtrShape& s, int firstShapeIndex = -1, int secondShapeIndex = -1, QColor c = Qt::black) noexcept;
	void draw(QPainter& qp);
	int firstShapeIndex() const noexcept;
	int secondShapeIndex() const noexcept;
	const QColor& color() const noexcept;
	void setColor(const QColor& c) noexcept;
	void setFirstShapeIndex(int firstShapeIndex) noexcept;
	void setSecondShapeIndex(int secondShapeIndex) noexcept;
private:
	VecUnqPtrShape& m_shapes;
	int m_firstShapeIdx;
	int m_secondShapeIdx;
	QColor m_color;
};

