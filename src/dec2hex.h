#ifndef DEC2HEX_H
#define DEC2HEX_H

#include <QObject>
#include <QStringListModel>
#include <QDebug>

class Dec2Hex : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString input READ input WRITE setInput)
    Q_PROPERTY(QString output READ output WRITE setOutput)
    Q_PROPERTY(QStringListModel* model READ model)
public:
    Dec2Hex();

    QString input() const;
    void setInput(const QString &value);
    QString output() const;
    void setOutput(const QString &str);

    QStringListModel* model() const;

    Q_INVOKABLE void convertNew();
    Q_INVOKABLE void convertHistory(const int &ind);

protected:
    QString formatHex(const QString &str) const;
    void convert();
    void addHist();

    QString m_input = "0";
    QString m_output = "0";
    QStringListModel *m_model;
    const int maxHis = 20;
};


#endif // DEC2HEX_H
