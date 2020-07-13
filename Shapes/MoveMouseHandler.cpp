#include "MoveMouseHandler.h"

MoveMouseHandler::MoveMouseHandler(DrawingField* owner) noexcept : IMouseHandler(owner) { }

void MoveMouseHandler::mousePress(QMouseEvent* e)
{
	if (e->button() != Qt::MouseButton::LeftButton)
		return;

	for (auto& s : m_owner->shapes)
	{
		if (s->rect().contains(e->pos()))
		{
			m_currentShape = &(*s);
			m_prevPos = e->pos();
			m_isShapeSelected = true;
			break;
		}
	}
}

void MoveMouseHandler::mouseMove(QMouseEvent* e)
{
	if (m_isShapeSelected)
	{
		m_currentShape->setPos(m_currentShape->pos() + (e->pos() - m_prevPos));
		m_prevPos = e->pos();
	}
}

void MoveMouseHandler::mouseRelease(QMouseEvent* e)
{
	if (e->button() != Qt::MouseButton::LeftButton)
		return;

	if (m_isShapeSelected)
	{
		m_isShapeSelected = false;
		m_currentShape = nullptr;
	}
}

