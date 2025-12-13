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
    m_numOfDice = new QDoubleSpinBox();
    m_numOfDice->setSingleStep(1.0);
    m_numOfDice->setValue(1.0);
    m_numOfDice->setMinimum(1.0);
    m_numDice = (int)(m_numOfDice->value());
    connect(m_numOfDice, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::setNumDice);

    m_rollBtn = new QPushButton("Выкинуть кости");
    m_resetBtn = new QPushButton("Сброс");
    connect(m_rollBtn, &QPushButton::clicked, this, &MainWindow::roll);
    connect(m_resetBtn, &QPushButton::clicked, this, &MainWindow::resetDice);

    m_vBox = new QVBoxLayout();

    m_form->addRow("Ваша ставка: ", m_inputLE);
    m_form->addRow("Кол-во кубов: ", m_numOfDice);

    m_form->addWidget(m_rollBtn);
    m_form->addWidget(m_resetBtn);

    m_vBox->addLayout(m_form);

    setHBoxInVBox();

    m_gambleWidget->setLayout(m_vBox);
    this->setCentralWidget(m_gambleWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setHBoxInVBox()
{
    QHBoxLayout* hBox = new QHBoxLayout();

    if(m_resultLabels.empty()) {
        fillDice();
        for(auto& label : m_resultLabels) {
            hBox->addWidget(label);
        }
    }

    m_vBox->children().last();
    m_vBox->addLayout(hBox);
}

void MainWindow::roll()
{
    m_resetBtn->setEnabled(false);
    m_rollBtn->setEnabled(false);

    if(!m_diceVec.empty()) {
        for(auto& dice : m_diceVec) {
            dice->rollTheDice();
            QThread::sleep(1);
        }
    }

    m_resetBtn->setEnabled(true);
    m_rollBtn->setEnabled(true);
}

void MainWindow::fillDice()
{
    if(!m_resultLabels.empty()) {
        m_resultLabels.clear();
    }
    m_diceVec.clear();

    if(m_diceVec.empty()) {
        for(unsigned int i = 0; i < m_numDice; ++i) {
            Dice* newDice = new Dice(DiceType::D6);
            m_diceVec.push_back(newDice);
        }
    }

    if(!m_diceVec.empty()) {
        for(unsigned int i = 0; i < m_diceVec.size(); ++i) {
            QLabel* newResultLabel = new QLabel("1");
            m_resultLabels.push_back(newResultLabel);
        }
    }

    resetDice();
}

void MainWindow::setNumDice(double value)
{
    m_numDice = (int)value;
    fillDice();
}

void MainWindow::resetDice()
{
    if(!m_resultLabels.empty()) {
        for(unsigned int i = 0; i < m_resultLabels.size(); ++i) {
            m_resultLabels[i]->setText("1");
        }
    }
}
