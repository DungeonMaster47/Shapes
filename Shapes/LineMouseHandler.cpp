#include "LineMouseHandler.h"

LineMouseHandler::LineMouseHandler(DrawingField* owner) noexcept : IMouseHandler(owner), m_currentLine(owner->shapes) { }

void LineMouseHandler::mousePress(QMouseEvent * e)
{
	if (e->button() != Qt::MouseButton::LeftButton)
		return;

	for (size_t i = 0; i < m_owner->shapes.size(); ++i)
	{
		if (m_owner->shapes[i]->rect().contains(e->pos()))
		{
			QColor selectedColor = m_owner->shapes[i]->color(); //change shape color to more transparent to show selection
			selectedColor.setAlpha(127);
			m_owner->shapes[i]->setColor(selectedColor);

			m_currentLine.setFirstShapeIndex(i);
			m_isShapeSelected = true;
			break;
		}
	}
}

void LineMouseHandler::mouseRelease(QMouseEvent * e)
{
	if (e->button() != Qt::MouseButton::LeftButton)
		return;

	if (m_isShapeSelected)
	{
		QColor oldColor = m_owner->shapes[m_currentLine.firstShapeIndex()]->color(); //change shape color back
		oldColor.setAlpha(255);
		m_owner->shapes[m_currentLine.firstShapeIndex()]->setColor(oldColor);

		for (size_t i = 0; i < m_owner->shapes.size(); ++i)
		{
			if (m_owner->shapes[i] == m_owner->shapes[m_currentLine.firstShapeIndex()])
				continue;

			if (m_owner->shapes[i]->rect().contains(e->pos()))
			{
				m_currentLine.setSecondShapeIndex(i);
				m_currentLine.setColor(m_owner->color());
				m_owner->lines.push_back(m_currentLine);
				break;
			}
		}
		m_isShapeSelected = false;
	}
}
