#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
#include <QList>


// this will be what i actually enter into the list/array
struct Item
{
    //these will always be in this order
    int itemId;
    QString brand;
    QString typeOfItem;
    QString colorOfItem;
    int cost;
    int sold;
    float weight;
    int profit;
    QString dateAdded;

    bool operator==(const Item &other) const
    {
        return  itemId == other.itemId && brand == other.brand &&
                typeOfItem == other.typeOfItem && colorOfItem == other.colorOfItem &&
                cost == other.cost && sold == other.sold && weight == other.weight &&
                profit == other.profit && dateAdded == other.dateAdded;
    }
};

//does some shit
inline QDataStream &operator<<(QDataStream &stream, const Item &item)
{
    return stream << item.itemId << item.brand << item.typeOfItem <<
                     item.colorOfItem << item.cost << item.sold <<
                    item.weight << item.profit << item.dateAdded;
}

inline QDataStream &operator>>(QDataStream &stream, Item &item)
{
    return stream >> item.itemId >> item.brand >> item.typeOfItem >>
                     item.colorOfItem >> item.cost >> item.sold >>
                    item.weight >> item.profit >> item.dateAdded;
}

//one colon denotes inheritance- tablemodel inherits from QAbstractTableModel
class tablemodel : public QAbstractTableModel
{
    Q_OBJECT
public:
    tablemodel(QObject *parent = 0);
    tablemodel(QList<Item> items, QObject *parent = 0);

    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data (const QModelIndex &index, int role) const override;
    QVariant headerData (int section, Qt::Orientation orientation, int role) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role=Qt::EditRole) override;
    bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;
    bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;
    QList<Item> getItems() const;

private:
    QList<Item> items;
};

#endif // TABLEMODEL_H
