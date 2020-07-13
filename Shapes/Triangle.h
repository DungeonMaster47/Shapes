#pragma once
#include "Shape.h"

class Triangle : public Shape
{
public:
	Triangle(QPoint p, int w, int h, QColor c) noexcept;
	void setSize(QSize) noexcept override;
	void draw(QPainter& qp) override;
private:
	int m_radius;
};

