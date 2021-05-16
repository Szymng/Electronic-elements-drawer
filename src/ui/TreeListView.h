#pragma once

#include <QListWidget>

class TreeListView : public QListWidget
{
	Q_OBJECT

public:
	TreeListView(QWidget *parent);
	~TreeListView();
};
