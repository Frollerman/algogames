#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // ui->setupUi(this);
    m_gambleWidget = new QWidget(this);

    m_form = new QFormLayout(this);
    m_inputLE = new QLineEdit();
    m_resultLabel = new QLabel("Результат");
    m_rollBtn = new QPushButton("Выкинуть кости");

    connect(m_rollBtn, &QPushButton::clicked, this, &MainWindow::roll);

    m_form->addRow("Ваша ставка: ", m_inputLE);
    m_form->addRow("Результат: ", m_resultLabel);
    m_form->addWidget(m_rollBtn);

    m_gambleWidget->setLayout(m_form);
    this->setCentralWidget(m_gambleWidget);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::roll()
{
    std::vector<Dice> diceVec;

    Dice* dice = new d6(this);

    m_resultLabel->setText(QString::number(dice->rollTheDice()));

    dice->deleteLater();
}
