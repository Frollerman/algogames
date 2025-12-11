#include "d6.h"

d6::d6(QObject *parent)
    : Dice{parent}
{
    m_maxFace = 6;
    m_numFaces = 6;
    m_faceDiff = 1;
    m_faces = {1, 2, 3, 4, 5, 6};
}
