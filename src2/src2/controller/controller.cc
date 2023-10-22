#include "controller.h"
namespace s21 {

/**
 * @brief вычисляет переданное выражение-строку
 *
 * @param str - ссылка на выражение-строку
 *
 * @param x - значение независимой переменной x
 *
 * @returns результат выражения
 */
double Controller::Calculate(std::string& str, double x) {
  return this->model_.Calculator(str, x);
}

/**
 * @brief проверяет выражение строку на правильность
 *
 * @param str - ссылка на выражение-строку
 *
 * @returns 0 - если выражение правильное, 1 - не правильное
 */
int Controller::Validate(std::string& str) {
  return this->model_.Validator(str);
}

/**
 * @brief аннуитентный тип расчета ежемесячных платежей
 *
 * @param sum сумма кредита
 * @param months срок кредита в месяцах
 * @param percent ставка годовых %
 *
 * @returns расчет ежемесячных платежей
 */
double** Controller::Annuity_credit_calc(double sum, int months,
                                         double percent) {
  return this->credit_model_.annuity_credit_calc(sum, months, percent);
}

/**
 * @brief дифферинцированный тип расчета ежемесячных платежей
 *
 * @param sum сумма кредита
 * @param months срок кредита в месяцах
 * @param percent ставка годовых %
 *
 * @returns расчет ежемесячных платежей
 */
double** Controller::Dif_credit_calc(double sum, int months, double percent) {
  return this->credit_model_.dif_credit_calc(sum, months, percent);
}
}  // namespace s21