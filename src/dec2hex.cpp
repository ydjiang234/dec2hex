#include "dec2hex.h"

Dec2Hex::Dec2Hex()
    : QObject()
{
}

int Dec2Hex::input()
{
    return m_input;
}

void Dec2Hex::setInput(const int &str)
{
    m_input = str;
    convert();
}

QString Dec2Hex::output()
{
    return m_output;
}

void Dec2Hex::setOutput(const QString &str)
{
    m_output = str;
}

QString Dec2Hex::formatHex(const QString &str) const
{
    switch (str.length()) {
        default: {
            return "E703";
            break;
        }
        case 1: {
            return "0" + str + "00";
            break;
        }
        case 2: {
            return str + "00";
            break;
        }
        case 3: {
            return str.right(2) + "0" + str.left(1);
            break;
        }
        case 4: {
            return str.right(2) + str.left(2);
            break;
        }
    }
}

void Dec2Hex::convert()
{
    m_output = formatHex(QString::number(m_input, 16).toUpper());
}


