#ifndef FUNCTIONWIDGET_H
#define FUNCTIONWIDGET_H

#include <QWidget>
#include <QDebug>
#include <QQueue>
#include <QByteArray>
#include <QThread>
#include <QTableView>
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "databuffer.h"
#include "bladerfdriver.h"
#include "demodulator.h"
namespace Ui {
class FunctionWidget;
}

class FunctionWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FunctionWidget(QWidget *parent = nullptr);
    ~FunctionWidget();
public Q_SLOTS:
    void openBoard();
    void closeBoard();
    void insertRecord(BlePacket packet);
private:
    Ui::FunctionWidget *ui;
    BladerfDriver *mBoard;
    QSqlDatabase mDatabase;
    QSqlTableModel *mModel;
    QTableView *mView;
    Demodulator *mDemod;
};

#endif // FUNCTIONWIDGET_H
