#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QDoubleSpinBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QThread>

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
    QVBoxLayout* m_vBox = nullptr;
    QLineEdit* m_inputLE = nullptr;
    QDoubleSpinBox* m_numOfDice = nullptr;
    std::vector<QLabel*> m_resultLabels;
    QPushButton* m_rollBtn = nullptr;
    QPushButton* m_resetBtn = nullptr;
    QWidget* m_gambleWidget = nullptr;

    std::vector<Dice*> m_diceVec;
    unsigned int m_numDice = 1;

    void setHBoxInVBox();

private slots:
    void roll();
    void fillDice();
    void setNumDice(double value);
    void resetDice();
};
#endif // MAINWINDOW_H
