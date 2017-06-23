#ifndef PID_H
#define PID_H
#include <vector>

class PID {
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;


  /*
   * twiddle
   */
    std::vector<double> dp;
    int step, param_index, n_settle_steps, n_eval_steps;
    double err_sum,err_best;
    bool flag_twiddle=false;
    bool flag_adding, flag_minus;
    
  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();
    
    void ChangeParameters(int,double);
};

#endif /* PID_H */
