#pragma once

#include <QMouseEvent>

class IMouseHandler
{
public:
	IMouseHandler() { };
	virtual void mousePress(QMouseEvent* e) { };
	virtual void mouseMove(QMouseEvent* e) { };
	virtual void mouseRelease(QMouseEvent* e) { };
	virtual ~IMouseHandler() { };
};

typedef IMouseHandler DefaultMouseHandler;
