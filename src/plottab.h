﻿#ifndef PLOTTAB_H
#define PLOTTAB_H

#include <QWidget>

#include "mysettings.h"
#include "mycustomplot.h"

namespace Ui
{
class PlotTab;
}

class PlotTab : public QWidget
{
    Q_OBJECT

public:
    explicit PlotTab(QWidget *parent = nullptr);
    ~PlotTab();

public slots:
    void newData(const QByteArray &data);
private:
    Ui::PlotTab *ui;

    QString* plotBuf;
    quint64 plotCounter;
    QCPItemTracer* plotTracer;
    QCPItemText* plotText;
    int plotSelectedId = 0;
    QString plotSelectedName;
    QString plotFrameSeparator;
    QString plotDataSeparator;
    QString plotClearFlag;
    double plotXAxisWidth;
    QSharedPointer<QCPAxisTickerTime> plotTimeTicker = QSharedPointer<QCPAxisTickerTime>(new QCPAxisTickerTime);
    QSharedPointer<QCPAxisTicker> plotDefaultTicker;
    QTime plotTime;

signals:

private slots:
    void onQCPLegendDoubleClick(QCPLegend *legend, QCPAbstractLegendItem *item);
    void onQCPAxisDoubleClick(QCPAxis *axis);
    void onQCPMouseMoved(QMouseEvent *event);
    void onQCPSelectionChanged();
    void onXAxisChangedByUser(const QCPRange &newRange);
    void on_plot_tracerCheckBox_stateChanged(int arg1);
    void on_plot_fitXButton_clicked();
    void on_plot_fitYButton_clicked();
    void on_plot_dataNumBox_valueChanged(int arg1);
    void on_plot_clearButton_clicked();
    void on_plot_legendCheckBox_stateChanged(int arg1);
    void on_plot_advancedBox_stateChanged(int arg1);
    void on_plot_frameSpTypeBox_currentIndexChanged(int index);
    void on_plot_dataSpTypeBox_currentIndexChanged(int index);
    void on_plot_scatterBox_stateChanged(int arg1);
    void on_plot_frameSpEdit_editingFinished();
    void on_plot_dataSpEdit_editingFinished();
    void on_plot_clearFlagTypeBox_currentIndexChanged(int index);
    void on_plot_clearFlagEdit_editingFinished();
    void on_plot_XTypeBox_currentIndexChanged(int index);
    void savePlotPreference();
    void loadPreference();
private:
    MySettings *settings;
    void updateTracer(double x);

    void initQCP();
    void initSettings();
};

#endif // PLOTTAB_H