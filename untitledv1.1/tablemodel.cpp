#include "tablemodel.h"

tablemodel::tablemodel(QObject *parent)
    :QAbstractTableModel(parent)
{

}

tablemodel::tablemodel(QList<Item> items, QObject *parent)
    :QAbstractTableModel (parent), items(items)
{

}

int tablemodel::rowCount(const QModelIndex &parent) const
{
    /*The Q_UNUSED() macro prevents the compiler
     from generating warnings regarding unused parameters. */

    Q_UNUSED(parent);
    return items.size();
}

int tablemodel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    /*
     * This always returns a set number because we dont add
     * any columns while the program is running (as of now).
     * The 9 columns: itemid, brand, typeofitem,colorofitem,cost,sold,weight,profit,date
    */
    return 9;
}

QVariant tablemodel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();
    if(index.row() >=items.size() || index.row() <0)
        return QVariant();
    if(role == Qt::DisplayRole) {
        const auto &item = items.at(index.row());
        switch (index.column()){
        case 0: return item.itemId;
        case 1: return item.brand;
        case 2: return item.typeOfItem;
        case 3: return item.colorOfItem;
        case 4: return item.cost;
        case 5: return item.sold;
        case 6: return item.weight;
        case 7: return item.profit;
        case 8: return item.dateAdded;
        default: return QVariant();
       }

    }
    return QVariant();
}
//names and orientation of header and tabs
QVariant tablemodel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role!=Qt::DisplayRole)
        return QVariant();
    if(orientation == Qt::Horizontal){
        /* this switch is decided by ^method above
           typeofitem is 0, colorofitem is 1, etc...*/
        switch (section){
        case 0: return tr("Item #");
        case 1: return tr("Item Brand");
        case 2: return tr("Item Type");
        case 3: return tr("Item Color");
        case 4: return tr("Item Cost ($)");
        case 5: return tr("Selling Price ($)");
        case 6: return tr("Weight (oz)");
        case 7: return tr("Profit ($)");
        case 8: return tr("Date Added");
        default: return QVariant();

        }
    }
    return QVariant();
}
//called b4 new data is added to properly display information when added
bool tablemodel::insertRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    int totalRows=rows;
    beginInsertRows(QModelIndex(), position, position+totalRows-1);//-1 because we count our same position twice
    for(int row=0;row < totalRows;++row)
        items.insert(position, {int(), QString(), QString(), QString(), int(),int(), float(), int(), QString() });
    endInsertRows();
    return true;

}
bool tablemodel::removeRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    int totalRows=rows;
    beginRemoveRows(QModelIndex(),position, (position+totalRows-1));
    for(int row=0; row < totalRows; ++row)
        items.removeAt(position);

    endRemoveRows();
    return true;
}

bool tablemodel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.isValid() && role == Qt::EditRole){
        int row = index.row();

        auto item = items.value(row);
        // CHANGE THIS IF YOU PLAN ON ADDING MORE COLUMNS DUMBASS

        switch (index.column()){
        case 0: item.itemId = value.toInt();
            break;
        case 1: item.brand = value.toString();
            break;
        case 2: item.typeOfItem = value.toString();
            break;
        case 3: item.colorOfItem = value.toString();
            break;
        case 4: item.cost = value.toInt();
            break;
        case 5: item.sold = value.toInt();
            break;
        case 6: item.weight = value.toFloat();
            break;
        case 7:item.profit = value.toInt();
            break;
        case 8: item.dateAdded = value.toString();
            break;
        default: return false;
        }
        items.replace(row,item);
        emit dataChanged(index,index,{role});

        return true;
        }
        return false;
/* Refresher: If "if" is true AND the switch statement runs its
 * default, return false. If "if" is true but switch breaks, return true.
 * If "if" is false, then return false;
 * */
}

Qt::ItemFlags tablemodel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

QList<Item> tablemodel::getItems() const
{
    return items;
}
