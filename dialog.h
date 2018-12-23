#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
   void  displayMessage(const QString& message );
    ~Dialog();


signals:
    /*!
        This signal is emitted from the C++ side and the text displayed on the HTML client side.
    */
    void sendText(const QString &text);
public slots:
    /*!
        This slot is invoked from the HTML client side and the text displayed on the server side.
    */
    void receiveText(const QString &text)
    {
        displayMessage(tr("Received message: %1").arg(text));
    }

private slots:
  void clicked(bool key);


private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H









