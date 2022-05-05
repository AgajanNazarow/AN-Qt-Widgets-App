#include "notepad.h"
#include "./ui_notepad.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

Notepad::Notepad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Notepad)
{
    ui->setupUi(this);
}

Notepad::~Notepad()
{
    delete ui;
}

void Notepad::on_actionNew_triggered()
{
    currentFile.clear();
    ui->textEdit->setText(QString());
}

void Notepad::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(fileName);
    currentFile = fileName;
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}

void Notepad::on_actionSave_triggered()
{

}

void Notepad::on_actionSave_As_triggered()
{

}

void Notepad::on_actionPrint_triggered()
{

}

void Notepad::on_actionExit_triggered()
{
    QCoreApplication::quit();
}

