#include "dec2hex.h"

Dec2Hex::Dec2Hex()
    : QObject()
{
}

QString Dec2Hex::input() const
{
    return m_input;
}

void Dec2Hex::setInput(const QString &str)
{
    m_input = str;
}

QString Dec2Hex::output() const
{
    return m_output;
}

void Dec2Hex::setOutput(const QString &str)
{
    m_output = str;
}

QStringList Dec2Hex::history() const
{
    return m_history;
}

void Dec2Hex::convertNew()
{
    convert();
    addHist();
    qDebug() << history();
}

void Dec2Hex::convertHistory(const int &ind)
{
    if (ind < m_history.size()) {
        setInput(m_history[ind]);
        convert();
    }
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
    QStringList list2 = m_input.split(QLatin1Char(','), Qt::SkipEmptyParts);
    m_output = QString::number(list2[0].toInt(), 16).toUpper();
    for (int i=1; i<list2.size(); ++i) {
        m_output += ',';
        m_output += QString::number(list2[i].toLongLong(), 16).toUpper();
    }
}

void Dec2Hex::addHist()
{
    m_history.insert(0, m_input);
    if (m_history.size() >= maxHis) {
        m_history.pop_back();
    }
}


