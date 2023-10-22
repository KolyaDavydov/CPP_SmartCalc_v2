#ifndef CREDIT_H
#define CREDIT_H

#include <QWidget>

#include "result_credit.h"

#include "../controller/controller.h"
extern "C" {
#include "s21_smartcalc.h"
}

namespace Ui {
class Credit;
}
namespace s21 {
class Credit : public QWidget {
  Q_OBJECT

 public:
  explicit Credit(QWidget *parent = nullptr);
  ~Credit();

 private slots:
  void show_result();

 private:
  Ui::Credit *ui;
  Result_credit *result_credit_window;

  s21::Controller controller_;
};
}
#endif  // CREDIT_H
