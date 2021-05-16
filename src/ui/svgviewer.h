#pragma once
#include <qgraphicsview.h>

QT_BEGIN_NAMESPACE
class QGraphicsSvgItem;
class QSvgRenderer;
class QWheelEvent;
class QPaintEvent;
QT_END_NAMESPACE

class SVGViewer : public QGraphicsView
{
	Q_OBJECT
public:
	enum RendererType { Native, OpenGL, Image };
	explicit SVGViewer(QWidget* parent = nullptr);

	bool openFile(const QString& fileName);
	void setRenderer(RendererType type = Native);
	void drawBackground(QPainter* p, const QRectF& rect) override;

	QSize svgSize() const;
	QSvgRenderer* renderer() const;

private slots:
	void setViewBackground(bool enable);
	void setViewOutline(bool enable);

protected:
	void paintEvent(QPaintEvent* event) override;

private:
	RendererType m_renderer;

	QGraphicsSvgItem* m_svgItem;
	QGraphicsRectItem* m_backgroundItem;
	QGraphicsRectItem* m_outlineItem;

	QImage m_image;
};


