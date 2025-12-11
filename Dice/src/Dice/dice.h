#ifndef DICE_H
#define DICE_H

#include <time.h>
#include <stdlib.h>
#include <QDebug>
#include <QObject>

//!
//! \brief The Dice class - base class for any dice
//!

class Dice : public QObject
{
    Q_OBJECT
public:
    explicit Dice(QObject *parent = nullptr);

    unsigned int rollTheDice();

protected:

    std::vector<unsigned int> m_faces;
    unsigned int m_numFaces;
    unsigned int m_maxFace;
    unsigned int m_faceDiff;

    bool checkResult(unsigned int result);

signals:
};

#endif // DICE_H
