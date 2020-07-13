#pragma once

#include <QMouseEvent>

class DrawingField;

class IMouseHandler
{
public:
	IMouseHandler(DrawingField* owner) : m_owner(owner){ };
	virtual void mousePress(QMouseEvent* e) { };
	virtual void mouseMove(QMouseEvent* e) { };
	virtual void mouseRelease(QMouseEvent* e) { };
	virtual ~IMouseHandler() { };
protected:
	DrawingField* m_owner;
};

typedef IMouseHandler DefaultMouseHandler;
