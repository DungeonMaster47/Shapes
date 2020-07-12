#pragma once

#include <vector>
#include "Shape.h"
#include "IMouseHandler.h"

template<class T>
class ShapeMouseHandler : public IMouseHandler
{
	static_assert(std::is_base_of<Shape, T>::value, "ShapeMouseHandler<T>: T must be derived from Shape");
public:
	ShapeMouseHandler(const QColor& c, std::vector<std::unique_ptr<Shape>>& s);
	void mousePress(QMouseEvent* e) override;
	void mouseMove(QMouseEvent* e) override;
	void mouseRelease(QMouseEvent* e) override;
private:
	const QColor& color;
	std::vector<std::unique_ptr<Shape>>& shapes;
};

template<class T>
ShapeMouseHandler<T>::ShapeMouseHandler(const QColor& c, std::vector<std::unique_ptr<Shape>>& s) : color(c), shapes(s) { }

template<class T>
void ShapeMouseHandler<T>::mousePress(QMouseEvent * e)
{
	if (e->button() == Qt::MouseButton::LeftButton)
	{
		shapes.push_back(std::make_unique<T>(e->pos(), 0, 0, color));
	}
}

template<class T>
void ShapeMouseHandler<T>::mouseMove(QMouseEvent * e)
{
	if ((e->buttons() & Qt::MouseButton::LeftButton) != 0)
	{
		QPoint diff = e->pos() - shapes.back()->pos();
		shapes.back()->setSize(QSize(diff.x(), diff.y()));
	}
}

template<class T>
void ShapeMouseHandler<T>::mouseRelease(QMouseEvent * e)
{
}
