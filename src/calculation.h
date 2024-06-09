#ifndef CALCULATION_H
#define CALCULATION_H

#include <QString>
#include "operationtype.h"

class Calculation
{
public:
    Calculation(double v1, double v2, double res, OperationType op)
        : value1(v1), value2(v2), result(res), operationType(op) {}

    double getValue1() const { return value1; }
    double getValue2() const { return value2; }
    double getResult() const { return result; }
    QString getOperationString() const;

private:
    double value1;
    double value2;
    double result;
    OperationType operationType;
};

#endif // CALCULATION_H
