#ifndef DEC2HEX_H
#define DEC2HEX_H

#include <QObject>
#include <QMetaType>

class Dec2Hex : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int input READ input WRITE setInput)
    Q_PROPERTY(QString output READ output WRITE setOutput)
public:
    Dec2Hex();

    int input();
    void setInput(const int &value);
    QString output();
    void setOutput(const QString &str);

protected:
    QString formatHex(const QString &str) const;
    Q_INVOKABLE void convert();

    int m_input = 0;
    QString m_output = "0000";
};


#endif // DEC2HEX_H
