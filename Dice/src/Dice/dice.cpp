#include "dice.h"

Dice::Dice(unsigned int numFaces, unsigned int maxFace, unsigned int faceDiff, QObject *parent)
    : QObject{parent}
{
    m_maxFace = maxFace;
    m_numFaces = numFaces;
    m_faceDiff = faceDiff;
    fillFaces(m_maxFace, m_faceDiff);

    if(m_faces.empty()) {
        Q_ASSERT_X(false, "Assert failed! No faces for dice!", "dice.cpp, constructor");
    }
}

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

void Dice::fillFaces(unsigned int maxFace, unsigned int faceDiff)
{
    for(unsigned int i = 0 + faceDiff; i <= maxFace;) {
        m_faces.push_back(i);
        i = i + faceDiff;
    }
}
