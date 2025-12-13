#ifndef DICE_H
#define DICE_H

#include <time.h>
#include <stdlib.h>
#include <QDebug>
#include <QObject>

enum DiceType {
    D_CUSTOM = 0,
    D2,
    D4,
    D6,
    D8,
    D10,
    D12,
    D20
};

//!
//! \brief The Dice class - base class for any dice
//!

class Dice : public QObject
{
    Q_OBJECT
public:
    explicit Dice(unsigned int numFaces, unsigned int maxFace, unsigned int faceDiff, QObject *parent = nullptr);
    explicit Dice(DiceType type, QObject *parent = nullptr);

    unsigned int rollTheDice();

protected:

    unsigned int m_numFaces = 6;
    unsigned int m_maxFace = 6;
    unsigned int m_faceDiff = 1;

    DiceType type = D_CUSTOM;
    std::vector<unsigned int> m_faces;


    bool checkResult(unsigned int result);

    void fillFaces(unsigned int maxFace, unsigned int faceDiff);

signals:
};

#endif // DICE_H
