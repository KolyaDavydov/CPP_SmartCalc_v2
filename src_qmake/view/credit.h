#ifndef CREDIT_H
#define CREDIT_H

#include <QWidget>

#include "../controller/controller.h"
#include "result_credit.h"
// extern "C" {
// #include "s21_smartcalc.h"
// }

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
}  // namespace s21
#endif  // CREDIT_H
