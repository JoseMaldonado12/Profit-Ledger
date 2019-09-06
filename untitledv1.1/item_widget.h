/*This is technically the main class involved as it provides
 *   functions to add, edit and remove contacts,
 *  to save the contacts to a file and to load them from a file.*/

#ifndef ITEM_WIDGET_H
#define ITEM_WIDGET_H

#include "newitemtab.h"
#include "tablemodel.h"

#include <QItemSelection>
#include <QTableWidget>
#include <QMap>

QT_BEGIN_NAMESPACE
class QSortFilterProxyModel;
class QItemSelectionModel;
QT_END_NAMESPACE

class item_widget : public QTabWidget
{
    Q_OBJECT

public:
    item_widget(QWidget *parent = 0);
    void readFromFile(const QString &fileName);
    void writeToFile(const QString &fileName);
    int counter=0;
    void calculateTotal();
public slots:
    void showAddEntryDialog();
    void addEntry(int itemId,QString brand, QString typeOfItem, QString colorOfItem,
                  int cost,int sold,float weight,int profit, QString dateAdded);

    void editEntry();
    void totalProfit();
    void removeEntry();




signals:
    void selectionChanged(const QItemSelection &selected);

private:

    void setupTabs();
    QMap<int,int> globalProfitList;
    tablemodel *table;
    newitemtab *newItemTab;
    QSortFilterProxyModel *proxyModel;
};

#endif // ITEM_WIDGET_H
