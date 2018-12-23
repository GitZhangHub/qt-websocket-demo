#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(clicked(bool)));
}

void Dialog::displayMessage(const QString& message)
{
    ui->textEdit->append(message);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::clicked(bool key)
{
    const QString text = ui->lineEdit->text();

    if (text.isEmpty()) {
        ui->textEdit->append("[waring] send message is null!");
        return;
    }

    emit sendText(text);
    displayMessage(tr("Sent message: %1").arg(text));

    ui->lineEdit->clear();


}
