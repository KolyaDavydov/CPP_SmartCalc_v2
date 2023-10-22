#ifndef GRAPH_H
#define GRAPH_H

#include <QVector>
#include <QWidget>

#include "../controller/controller.h"

// extern "C" {
// #include "s21_smartcalc.h"
// }

namespace Ui {
class Graph;
}
namespace s21 {
class Graph : public QWidget {
  Q_OBJECT

 public:
  explicit Graph(QWidget *parent = nullptr);
  ~Graph();

  void print_graph(QString function);

 private slots:
  void push_draw();

 private:
  Ui::Graph *ui;

  s21::Controller controller_;
};
}  // namespace s21
#endif  // GRAPH_H
