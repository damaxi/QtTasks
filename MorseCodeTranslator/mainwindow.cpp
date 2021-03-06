#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QString>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow),
      m_file(QDir::home().absolutePath()), m_converter(),
      m_comboBoxModel({{tr("Morse -> Letters")}, {tr("Letters -> Morse")}}) {
  ui->setupUi(this);
  ui->comboBox->addItems(m_comboBoxModel);
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
  QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), m_file,
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

void MainWindow::changeTranslationType()
{
  if (ui->comboBox->currentIndex())
    ui->comboBox->setCurrentIndex(0);
  else
    ui->comboBox->setCurrentIndex(1);
}

void MainWindow::on_translateButton_clicked() {
  if (ui->comboBox->currentText() == m_comboBoxModel.first()) {
    QString origin = ui->textEdit->toPlainText();
    if (!m_converter.validate(std::move(origin))) {
      QMessageBox::warning(this, tr("Morse decoder"),
                           tr("Your input contains illegal character"));
      return;
    }
    const QString &translated = m_converter.decode(std::move(origin));
    ui->textEdit->setText(translated);
  } else {
    const QString &translated = m_converter.code(ui->textEdit->toPlainText());
    ui->textEdit->setText(translated);
  }
  changeTranslationType();
}
