#include "util.h"
#include "listview.h"
#include "ui_listview.h"

#include <QSortFilterProxyModel>
#include <QStringListModel>
#include <QListView>
#include <QAbstractItemModel>
#include <QModelIndex>

ListView::ListView(QWidget *parent)
   : QWidget(parent), ui(new Ui::ListView)
{
   ui->setupUi(this);
   setWindowTitle("List View Model");

   // m_noSort = false;

   //
   QStringListModel *model = new QStringListModel(this);
   model->setStringList( getData() );

   //
   m_proxyModel = new QSortFilterProxyModel(this);
   m_proxyModel->setSourceModel(model);
   m_proxyModel->setSortCaseSensitivity(Qt::CaseInsensitive);
   m_proxyModel->sort(0, Qt::AscendingOrder);
   m_proxyModel->setDynamicSortFilter(true);

   //
   ui->listView->setModel(m_proxyModel);
   ui->listView->setEditTriggers(QAbstractItemView::AnyKeyPressed | QAbstractItemView::DoubleClicked);

   // adjust the size
   QSize size = this->size();
   this->setMinimumHeight( size.height() );

   // signal
   //connect( model, SIGNAL( dataChanged(const QModelIndex &, const QModelIndex &) ),
   //    this, SLOT( reSort(const QModelIndex &, const QModelIndex &)) );

   connect( ui->insert_PB,  SIGNAL(clicked()), this, SLOT(addRow()) );
   connect( ui->delete_PB,  SIGNAL(clicked()), this, SLOT(delRow()) );
}

ListView::~ListView()
{
   delete ui;
}

QStringList ListView::getData()
{
   QStringList data;

   data << "gallon" << "ounce" << "pinch" << "pound" << "cup"
        << "pint" << "quart" << "tsp" << "Tbsp" << "bunch" << "jigger" ;

   return data;
}

void ListView::addRow()
{
   // sort off
   m_proxyModel->setDynamicSortFilter(false);
   m_proxyModel->sort(-1);

   int row = ui->listView->currentIndex().row();
   m_proxyModel->insertRows(row,1);

   // get index
   QModelIndex index = m_proxyModel->index(row, 0);
   //    m_proxyModel->setData(index, QVariant("NEW"), Qt::EditRole);

   // select and edit
   ui->listView->setCurrentIndex(index);
   ui->listView->edit(index);

   // sort on
   m_proxyModel->setDynamicSortFilter(true);
   m_proxyModel->sort(0, Qt::AscendingOrder);
}

void ListView::delRow()
{
   m_proxyModel->removeRows(ui->listView->currentIndex().row(), 1);
}



