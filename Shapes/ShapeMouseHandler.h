#pragma once

#include <vector>
#include "Shape.h"
#include "IMouseHandler.h"
#include "DrawingField.h"

template<class T>
class ShapeMouseHandler : public IMouseHandler
{
	static_assert(std::is_base_of<Shape, T>::value, "ShapeMouseHandler<T>: T must be derived from Shape");
public:
	ShapeMouseHandler(DrawingField* owner) noexcept;
	void mousePress(QMouseEvent* e) override;
	void mouseMove(QMouseEvent* e) override;
};

template<class T>
ShapeMouseHandler<T>::ShapeMouseHandler(DrawingField* owner) noexcept : IMouseHandler(owner) { }

template<class T>
void ShapeMouseHandler<T>::mousePress(QMouseEvent * e)
{
	if (e->button() == Qt::MouseButton::LeftButton)
	{
		m_owner->shapes.push_back(std::make_unique<T>(e->pos(), 0, 0, m_owner->color()));
	}
}

template<class T>
void ShapeMouseHandler<T>::mouseMove(QMouseEvent * e)
{
	if ((e->buttons() & Qt::MouseButton::LeftButton) != 0)
	{
		QPoint diff = e->pos() - m_owner->shapes.back()->pos();
		m_owner->shapes.back()->setSize(QSize(diff.x(), diff.y()));
	}
}
