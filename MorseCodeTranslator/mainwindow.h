#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QString;

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

private:
  void setFile(QString &file);

  Ui::MainWindow *ui;
  QString m_file;
};

#endif // MAINWINDOW_H
