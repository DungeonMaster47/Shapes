#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QToolBar>
#include <QMessageBox>
#include <QAction>
#include <QLayout>
#include <QColorDialog>
#include "DrawingField.h"
#include "ShapeMouseHandler.h"
#include "MoveMouseHandler.h"
#include "LineMouseHandler.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);
	
	static constexpr size_t ICON_SIZE = 64;
private:
	void createToolbar();
	void checkToolButtons(bool check);
	void onOpenFileBtn();
	void onSaveFileBtn();
	template<class T>
	void onShapeBtn(bool checked);
	void onLineBtn(bool checked);
	void onMoveBtn(bool checked);
	void onColorBtn();

	DrawingField* m_frame;
	QToolBar* m_toolbar;
	QAction* m_color;
};

template<class T>
void MainWindow::onShapeBtn(bool checked)
{
	static_assert(std::is_base_of<Shape, T>::value, "ShapeMouseHandler<T>: T must be derived from Shape");
	if (checked)
	{
		checkToolButtons(false);
		m_frame->setMouseHandler(std::make_unique<ShapeMouseHandler<T>>(m_frame));
	}
	else
	{
		m_frame->setMouseHandler(std::make_unique<DefaultMouseHandler>(m_frame));
	}
}