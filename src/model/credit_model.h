#ifndef SRC_MODEL_CREDIT_MODEL_H
#define SRC_MODEL_CREDIT_MODEL_H

namespace s21 {
/**
 * @brief содержит методы для расчета кредита (ануитентный и дифферинцированый)
 */
class CreditModel {
 public:
  CreditModel() {}
  ~CreditModel() {}
  double **annuity_credit_calc(double sum, int months, double percent);
  double **dif_credit_calc(double sum, int months, double percent);
};
}  // namespace s21

#endif  // SRC_MODEL_CREDIT_MODEL_H