#pragma once
#include "../core/document.h"
#include <QtWidgets/QMainWindow>
#include <QPaintDevice>
#include <QtSvg>
#include <QString>
#include "ui_application.h"
#include "svgviewer.h"
#include "TreeListView.h"

class SVGViewer;

QT_BEGIN_NAMESPACE
class QAction;
class QGraphicsView;
class QGraphicsScene;
class QGraphicsRectItem;
class QLabel;
QT_END_NAMESPACE

class Application : public QMainWindow
{
    Q_OBJECT

public:
    Application(QWidget *parent = Q_NULLPTR);
    bool LoadFile(const QString &path);

public slots:
    void OpenFile();
    void AddNewResistor();
    void AddNewCapacitor();
    void SaveOpen();

private slots:
    
private:
    
    Ui::ApplicationClass ui;
    Document document_;
    QSharedPointer<TreeListView> tree_;
    QString m_currentPath;
};
