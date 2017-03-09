#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "morseconverter.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private slots:

  void on_loadButton_clicked();

  void on_saveButton_clicked();

  void on_translateButton_clicked();

private:
  void setFile(QString &file);
  void changeTranslationType();

  Ui::MainWindow *ui;
  QString m_file;
  MorseConverter m_converter;
  const QStringList m_comboBoxModel;
};

#endif // MAINWINDOW_H
