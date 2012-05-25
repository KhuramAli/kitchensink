#include "tablewidget_view.h"
#include "ui_tablewidget_view.h"

#include <QTableWidget>


TableWidget_View::TableWidget_View(QWidget *parent)
   : QWidget(parent), ui(new Ui::TableWidget_View)
{
   ui->setupUi(this);   
   setWindowTitle("Table Widget / Table View");

   setUpWidget();
   setUpView();

   // adjust the size
   QSize size = this->size();
   setMinimumWidth( size.width() );
   setMinimumHeight( size.height() );
}

TableWidget_View::~TableWidget_View()
{
   delete ui;
}

void TableWidget_View::setUpWidget()
{
   QStringList headers;
   headers << tr("Name") << tr("Type") << tr("First Aired");

   // next line of code can be used if UI is created by hand
   // tableWidget = new QTableWidget(0, 3);

   ui->tableWidget->setRowCount(0);
   ui->tableWidget->setColumnCount(3);

   // name the columns
   ui->tableWidget->setHorizontalHeaderLabels(headers);

   // resize the last column
   // ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

   ui->tableWidget->horizontalHeader()->setResizeMode(0, QHeaderView::Stretch);
   ui->tableWidget->horizontalHeader()->setResizeMode(1, QHeaderView::Stretch);

   ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
   ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

   // data
   int row = ui->tableWidget->rowCount();

   QTableWidgetItem *nameItem  = new QTableWidgetItem("The Good Wife");
   QTableWidgetItem *typeItem  = new QTableWidgetItem(tr("Drama/Legal"));
   QTableWidgetItem *airedItem = new QTableWidgetItem("2009");

   ui->tableWidget->insertRow(row);
   ui->tableWidget->setItem(row, 0, nameItem);
   ui->tableWidget->setItem(row, 1, typeItem);
   ui->tableWidget->setItem(row, 2, airedItem);

   //
   nameItem  = new QTableWidgetItem("Doctor Who");
   typeItem  = new QTableWidgetItem(tr("Science Fiction"));
   airedItem = new QTableWidgetItem("1963");

   ui->tableWidget->insertRow(row);
   ui->tableWidget->setItem(row, 0, nameItem);
   ui->tableWidget->setItem(row, 1, typeItem);
   ui->tableWidget->setItem(row, 2, airedItem);

   //
   nameItem  = new QTableWidgetItem("ER");
   typeItem  = new QTableWidgetItem(tr("Drama/Medical"));
   airedItem = new QTableWidgetItem("1994");

   ui->tableWidget->insertRow(row);
   ui->tableWidget->setItem(row, 0, nameItem);
   ui->tableWidget->setItem(row, 1, typeItem);
   ui->tableWidget->setItem(row, 2, airedItem);

   //
   nameItem  = new QTableWidgetItem("Friends");
   typeItem  = new QTableWidgetItem(tr("Comdey"));
   airedItem = new QTableWidgetItem("1994");

   ui->tableWidget->insertRow(row);
   ui->tableWidget->setItem(row, 0, nameItem);
   ui->tableWidget->setItem(row, 1, typeItem);
   ui->tableWidget->setItem(row, 2, airedItem);

   //
   nameItem  = new QTableWidgetItem("Stargate");
   typeItem  = new QTableWidgetItem(tr("Science Fiction"));
   airedItem = new QTableWidgetItem("1997");

   ui->tableWidget->insertRow(row);
   ui->tableWidget->setItem(row, 0, nameItem);
   ui->tableWidget->setItem(row, 1, typeItem);
   ui->tableWidget->setItem(row, 2, airedItem);

   // sort now
   ui->tableWidget->sortItems(0,Qt::AscendingOrder);

   // signals - complies but will fail at run time since tableClicked is not defined!
   connect(ui->tableWidget, SIGNAL(cellPressed(int,int)),this, SLOT(tableClicked(int,int)));
}

void TableWidget_View::setUpView()
{
   // setup
   m_model = new QStandardItemModel;
   m_model->setColumnCount(3);
   m_model->setHeaderData(0, Qt::Horizontal, "Name");
   m_model->setHeaderData(1, Qt::Horizontal, "Type");
   m_model->setHeaderData(2, Qt::Horizontal, "First Aired");     

   //
   ui->tableView->setModel(m_model);
   ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
   ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
   ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

   ui->tableView->setColumnWidth(0, 175);
   ui->tableView->setColumnWidth(1, 175);   

   // resize the last column
   // ui->tableView->horizontalHeader()->setStretchLastSection(true);

   ui->tableView->horizontalHeader()->setResizeMode(0, QHeaderView::Stretch);
   ui->tableView->horizontalHeader()->setResizeMode(1, QHeaderView::Stretch);

   // data
   int row = m_model->rowCount();

   QStandardItem *nameItem  = new QStandardItem("The Good Wife");
   QStandardItem *typeItem  = new QStandardItem(tr("Drama/Legal"));
   QStandardItem *airedItem = new QStandardItem("2009");

   m_model->insertRow(row);
   m_model->setItem(row, 0, nameItem);
   m_model->setItem(row, 1, typeItem);
   m_model->setItem(row, 2, airedItem);

   //
   nameItem  = new QStandardItem("Doctor Who");
   typeItem  = new QStandardItem(tr("Science Fiction"));
   airedItem = new QStandardItem("1963");

   m_model->insertRow(row);
   m_model->setItem(row, 0, nameItem);
   m_model->setItem(row, 1, typeItem);
   m_model->setItem(row, 2, airedItem);

   //
   nameItem  = new QStandardItem("ER");
   typeItem  = new QStandardItem(tr("Drama/Medical"));
   airedItem = new QStandardItem("1994");

   m_model->insertRow(row);
   m_model->setItem(row, 0, nameItem);
   m_model->setItem(row, 1, typeItem);
   m_model->setItem(row, 2, airedItem);

   //
   nameItem  = new QStandardItem("Friends");
   typeItem  = new QStandardItem(tr("Comedy"));
   airedItem = new QStandardItem("1994");

   m_model->insertRow(row);
   m_model->setItem(row, 0, nameItem);
   m_model->setItem(row, 1, typeItem);
   m_model->setItem(row, 2, airedItem);

   //
   nameItem  = new QStandardItem("Stargate");
   typeItem  = new QStandardItem(tr("Science Fiction"));
   airedItem = new QStandardItem("1997");

   m_model->insertRow(row);
   m_model->setItem(row, 0, nameItem);
   m_model->setItem(row, 1, typeItem);
   m_model->setItem(row, 2, airedItem);

   // sort now
   m_model->sort(0,Qt::AscendingOrder);
}