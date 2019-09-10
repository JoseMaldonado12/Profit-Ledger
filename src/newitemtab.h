#ifndef NEWITEMTAB_H
#define NEWITEMTAB_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QLabel;
class QPushButton;
class QVBoxLayout;
QT_END_NAMESPACE



class newitemtab : public QWidget
{
    Q_OBJECT

public:
    newitemtab(QWidget *parent = 0);

public slots:
    void addEntry();

signals :
    void sendDetails(int itemId, QString brand, QString typeOfItem, QString colorOfItem,
                     int cost, int sold, float weight, int profit, QString dateAdded);

private :
    QLabel *descriptionLabel;
    QPushButton *addButton;
    QVBoxLayout *mainLayout;
};

#endif // NEWITEMTAB_H
