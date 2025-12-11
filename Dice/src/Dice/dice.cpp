#include "dice.h"

Dice::Dice(QObject *parent)
    : QObject{parent}
{}

unsigned int Dice::rollTheDice()
{
    unsigned int dice = 0;

    srand((int)time(NULL));

    dice = 1 + rand() % m_maxFace;

    if(checkResult(dice)) {
        return dice;
    } else {
        dice = rollTheDice();
    }

    return dice;
}

bool Dice::checkResult(unsigned int result)
{
    if(!m_faces.empty()){
        if(std::find(m_faces.begin(), m_faces.end(), result) != m_faces.end()) {
            return true;
        } else {
            return false;
        }
    } else {
        qDebug() << "Vector is empty!";
        Q_ASSERT_X(false, "Assert failed! dice vector m_faces is empty!", "dice.cpp");
    }
}
