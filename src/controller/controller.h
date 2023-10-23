#ifndef SRC_CONTROLLER_CONTROLLER_H_
#define SRC_CONTROLLER_CONTROLLER_H_

#include "../model/credit_model.h"
#include "../model/model.h"

namespace s21 {
/**
 * @brief Класс является связующим звеном между интерфейсом
 * калькулятора и логикой. Предназначен для отделения логики от интерфейса
 *
 */
class Controller {
 private:
  Model model_;
  CreditModel credit_model_;

 public:
  Controller() {}
  ~Controller() {}
  double Calculate(std::string& str, double x);
  int Validate(std::string& str);

  double** Annuity_credit_calc(double sum, int months, double percent);
  double** Dif_credit_calc(double sum, int months, double percent);
};
}  // namespace s21

#endif  // SRC_CONTROLLER_CONTROLLER_H_