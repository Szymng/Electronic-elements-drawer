#include "application.h"

static inline QString picturesLocation()
{
    return QStandardPaths::standardLocations(QStandardPaths::PicturesLocation).value(0, QDir::currentPath());
}

Application::Application(QWidget *parent) : QMainWindow(parent)
{
    ui.setupUi(this);
}

void Application::OpenFile()
{
    QFileDialog dialog(this);
    dialog.setAcceptMode(QFileDialog::AcceptOpen);
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setMimeTypeFilters(QStringList() << "image/svg+xml" << "image/svg+xml-compressed");
    dialog.setWindowTitle(tr("Open SVG Diagram"));
    dialog.setNameFilter(tr("Diagrams (*.svg)"));
    dialog.setViewMode(QFileDialog::Detail);

    while (dialog.exec() == QDialog::Accepted && !LoadFile(dialog.selectedFiles().constFirst()));
}

bool Application::LoadFile(const QString& fileName)
{
    if (!QFileInfo::exists(fileName) || !ui.graphicsView->openFile(fileName)) {
        QMessageBox::critical(this, tr("Open SVG File"),
            tr("Could not open file '%1'.").arg(QDir::toNativeSeparators(fileName)));
        return false;
    }

    if (!fileName.startsWith(":/")) {
        m_currentPath = fileName;
        setWindowFilePath(fileName);
        const QSize size = ui.graphicsView->svgSize();
        const QString message = tr("Opened %1, %2x%3").arg(QFileInfo(fileName).fileName()).arg(size.width()).arg(size.width());
        statusBar()->showMessage(message);
    }

    //const QSize availableSize = this->screen()->availableGeometry().size();
    //resize(ui.graphicsView->sizeHint().expandedTo(availableSize / 4) + QSize(80, 80 + menuBar()->height()));

    return true;
}

void Application::AddNewResistor()
{
    document_.AddElement(resistor, "Resistor");
    QMessageBox notify;
    notify.setText("Added resistor.");
    notify.exec();
    auto fileName = QString{ "tmp.svg" };
    document_.SaveToFile(fileName.toStdString());
    LoadFile(fileName);
}

void Application::AddNewCapacitor()
{
    document_.AddElement(capacitor, "Capacitor");
    QMessageBox notify;
    notify.setText("Added capacitor.");
    notify.exec();
    auto fileName = QString{ "tmp.svg" };
    document_.SaveToFile(fileName.toStdString());
    LoadFile(fileName);
}

void Application::SaveOpen()
{
    QFileDialog dialog(this);
    dialog.setAcceptMode(QFileDialog::AcceptOpen);
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setMimeTypeFilters(QStringList() << "image/svg+xml" << "image/svg+xml-compressed");
    dialog.setWindowTitle(tr("Open SVG Diagram"));
    dialog.setNameFilter(tr("Diagrams (*.svg)"));
    dialog.setViewMode(QFileDialog::Detail);

    auto fileName = dialog.getSaveFileName(this, tr("Save file"), "document1.svg", tr("Diagrams (*.svg)"));
    document_.SaveToFile(fileName.toStdString());
    document_ = Document();
}
