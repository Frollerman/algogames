#include "dice.h"

//!
//! \brief Dice::Dice - конструктор для кастомного дайса (дефолтный)
//! \param numFaces - кол-во граней
//! \param maxFace - максимальное значение грани
//! \param faceDiff - разница между гранями
//! \param parent - родительский объект
//!
Dice::Dice(unsigned int numFaces, unsigned int maxFace, unsigned int faceDiff, QObject *parent)
    : QObject{parent},
      m_maxFace(maxFace),
      m_numFaces(numFaces),
      m_faceDiff(faceDiff)
{
    fillFaces(m_maxFace, m_faceDiff);

    if(m_faces.empty()) {
        Q_ASSERT_X(false, "Assert failed! No faces for dice!", "dice.cpp, constructor");
    }
}

//!
//! \brief Dice::Dice - конструктор стандартных дайсов в зависимости от переданного типа
//! \param type - тип дайса
//! \param parent
//!
Dice::Dice(DiceType type, QObject *parent)
    : QObject(parent)
{
    m_faceDiff = 1;
    switch(type) {
    case DiceType::D2:
        m_maxFace = 2;
        m_numFaces = 2;
        break;
    case DiceType::D4:
        m_maxFace = 4;
        m_numFaces = 4;
        break;
    case DiceType::D6:
        m_maxFace = 6;
        m_numFaces = 6;
        break;
    case DiceType::D8:
        m_maxFace = 8;
        m_numFaces = 8;
        break;
    case DiceType::D10:
        m_maxFace = 10;
        m_numFaces = 10;
        break;
    case DiceType::D12:
        m_maxFace = 12;
        m_numFaces = 12;
        break;
    case DiceType::D20:
        m_maxFace = 20;
        m_numFaces = 20;
        break;

    default:
        m_maxFace = 6;
        m_numFaces = 6;
        break;
    }

    fillFaces(m_maxFace, m_faceDiff);
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

    if(m_faces.size() != m_numFaces) {
        Q_ASSERT_X(false, "Assert failed! faces count is wrong!", "dice.cpp");
    }
}
