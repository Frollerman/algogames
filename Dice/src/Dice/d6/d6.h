#ifndef D6_H
#define D6_H

#include "../dice.h"

class d6 : public Dice
{
    Q_OBJECT
public:
    explicit d6(QObject *parent = nullptr);
};

#endif // D6_H
