#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>  // для всплывающих окон
#include <QPushButton>
#include <QVector>
#include <cctype>

#include "../controller/controller.h"
#include "credit.h"
#include "graph.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
namespace s21 {

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  Graph *graph_window;
  Credit *credit_window;

  s21::Controller controller_;

  // хедеры для наших функций
 private slots:

  void print_num();
  void print_funct();
  void print_oper();
  void print_dot();
  void print_AC();
  void print_del();
  void print_equal();
  void print_graph();
};
}  // namespace s21
#endif  // MAINWINDOW_H
