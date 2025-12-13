#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>

#include "Dice/dice.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QFormLayout* m_form = nullptr;
    QLineEdit* m_inputLE = nullptr;
    QLabel* m_resultLabel = nullptr;
    QPushButton* m_rollBtn = nullptr;
    QWidget* m_gambleWidget = nullptr;

    std::vector<Dice> m_diceVec;

private slots:
    void roll();
};
#endif // MAINWINDOW_H
