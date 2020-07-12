#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QToolBar>
#include <QMessageBox>
#include <QAction>
#include <QPainter>
#include <QLabel>
#include <QLayout>
#include <QColorDialog>
#include <algorithm>
#include "DrawingField.h"
#include "ShapeMouseHandler.h"
#include "MoveMouseHandler.h"
#include "LineMouseHandler.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);

private:
	void createToolbar();
	void uncheckToolButtons();
	void onOpenFile();
	void onSaveFile();
	void onCircle(bool checked);
	void onRectangle(bool checked);
	void onTriangle(bool checked);
	void onLine(bool checked);
	void onMove(bool checked);
	void onColor();

	DrawingField* frame;
	QToolBar* toolbar;
	QAction* color;
};
