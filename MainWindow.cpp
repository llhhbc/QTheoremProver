#include "MainWindow.hpp"
#include "ui_MainWindow.h"
#include <QSignalMapper>
MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	buttons =
	{
		ui->pushButton_2,
		ui->pushButton_3,
		ui->pushButton_4,
		ui->pushButton_5,
		ui->pushButton_6,
		ui->pushButton_7,
		ui->pushButton_8,
		ui->pushButton_9
	};
	QSignalMapper *signalMapper = new QSignalMapper(this);
	connect(signalMapper, SIGNAL(mapped( QString )), this, SIGNAL(AppendString( QString )));
	for ( auto i : buttons )
	{
		signalMapper->setMapping( i, i->text( ) );
		connect( i, SIGNAL(clicked()), signalMapper, SLOT(map()));
	}
}

MainWindow::~MainWindow( ) { delete ui; }

void MainWindow::AppendString( const QString & str )
{
	QString new_str( ui->lineEdit->text( ) );
	new_str.insert( ui->lineEdit->cursorPosition( ), str );
	ui->lineEdit->setText( new_str );
}
