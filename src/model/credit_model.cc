/**
 * @file credit_model.cc
 * @author Kolya Davydov
 * @brief функции для расчета выплаты кредита при заданных условиях
 * @version 2.0
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "credit_model.h"

#include <cmath>

namespace s21 {
/**
 * @brief аннуитентный тип расчета ежемесячных платежей
 *
 * @param sum сумма кредита
 * @param months срок кредита в месяцах
 * @param percent ставка годовых %
 * @returns расчет ежемесячных платежей
 */
double** CreditModel::annuity_credit_calc(double sum, int months,
                                          double percent) {
  //   double result[months][5];
  double** result = new double*[months];
  for (int i = 0; i < months; i++) {
    result[i] = new double[5];
  }

  int tmp_months = months;
  double tmp_sum = sum;
  int i = 1;
  double percent_on_month = percent / 1200;

  double sum_month =
      sum * ((percent_on_month * pow(1 + percent_on_month, months)) /
             (pow(1 + percent_on_month, months) - 1));
  sum_month = (round(sum_month * 100)) / 100;

  double percent_sum_first_month = sum * percent_on_month;
  percent_sum_first_month = (ceil(percent_sum_first_month * 100)) / 100;

  double main_sum_month = sum_month - percent_sum_first_month;
  main_sum_month = (ceil(main_sum_month * 100)) / 100;

  tmp_sum -= main_sum_month;
  tmp_months--;
  result[0][0] = 1;
  result[0][1] = sum_month;
  result[0][2] = main_sum_month;
  result[0][3] = percent_sum_first_month;
  result[0][4] = tmp_sum;
  for (; tmp_months > 0; tmp_months--) {
    double percent_sum_month = tmp_sum * percent_on_month;
    percent_sum_month = (round(percent_sum_month * 100)) / 100;
    main_sum_month = sum_month - percent_sum_month;
    tmp_sum -= main_sum_month;
    if (tmp_sum < 0.01) {
      tmp_sum = 0;
    }
    main_sum_month = sum_month - percent_sum_month;
    tmp_sum = (round(tmp_sum * 100)) / 100;
    i++;
    result[i - 1][0] = i;
    result[i - 1][1] = sum_month;
    result[i - 1][2] = main_sum_month;
    result[i - 1][3] = percent_sum_month;
    result[i - 1][4] = tmp_sum;
  }
  return result;
}

/**
 * @brief дифферинцированный тип расчета ежемесячных платежей
 *
 * @param sum сумма кредита
 *
 * @param months срок кредита в месяцах
 *
 * @param percent ставка годовых %
 *
 * @returns расчет ежемесячных платежей
 */
double** CreditModel::dif_credit_calc(double sum, int months, double percent) {
  // double result[months][5];

  double** result = new double*[months];
  for (int i = 0; i < months; i++) {
    result[i] = new double[5];
  }

  double main_sum_month = sum / months;
  main_sum_month = (round(main_sum_month * 100)) / 100;
  double tmp_sum = sum;

  for (int i = 0; i < months; i++) {
    double percent_sum_month = (sum - main_sum_month * i) * percent / 100 / 12;
    double sum_month = main_sum_month + percent_sum_month;
    percent_sum_month = (round(percent_sum_month * 100)) / 100;
    sum_month = (round(sum_month * 100)) / 100;
    tmp_sum -= main_sum_month;
    if (tmp_sum < 0.01) {
      tmp_sum = 0;
    }
    tmp_sum = (floor(tmp_sum * 100)) / 100;
    result[i][0] = i + 1;
    result[i][1] = sum_month;
    result[i][2] = main_sum_month;
    result[i][3] = percent_sum_month;
    result[i][4] = tmp_sum;
  }
  return result;
}
}  // namespace s21