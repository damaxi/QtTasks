#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QString>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow),
      m_file(QDir::home().absolutePath()), m_converter() {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_loadButton_clicked() {
  QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), m_file,
                                                  tr("Text (*.txt)"));
  setFile(fileName);
  QFile inputFile(fileName);
  inputFile.open(QIODevice::ReadOnly | QFile::Text);
  QTextStream stream(&inputFile);
  ui->textEdit->setText(stream.readAll());
}

void MainWindow::on_saveButton_clicked() {
  QString fileName = QFileDialog::getOpenFileName(this, tr("Save File"), m_file,
                                                  tr("Text (*.txt)"));
  setFile(fileName);
  QFile outputFile(fileName);
  outputFile.open(QIODevice::WriteOnly | QFile::Text);
  QTextStream stream(&outputFile);
  stream << ui->textEdit->toPlainText();
}

void MainWindow::setFile(QString &file) {
  if (file == m_file)
    return;

  m_file = file;
}

void MainWindow::on_translateButton_clicked() {
  const QString &translated = m_converter.decode(ui->textEdit->toPlainText());
  ui->textEdit->setText(translated);
}
