#include "PID.h"
#include <cmath>
#include <iostream>
using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    PID::Kp=Kp;
    PID::Ki=Ki;
    PID::Kd=Kd;
    p_error=d_error=i_error=0.0;
    
    //whether twiddle
    flag_twiddle=false;
    dp={0.1*Kp, 0.1*Kd, 0.1*Ki};
    step=1;
    param_index=1;
    n_settle_steps=100;
    n_eval_steps=1000;
    err_sum=0;
    err_best=std::numeric_limits<double>::max();
    
    flag_adding=false;
    flag_minus=false;
    
}

void PID::UpdateError(double cte) {
    if(step==1){
        p_error=cte;
    }
    d_error=cte-p_error;
    p_error=cte;
    i_error+=cte;
    
    if(step % (n_settle_steps+n_eval_steps) > n_settle_steps){
        err_sum+=pow(cte,2);
    }
    
    //twiddle
    if(flag_twiddle && step % (n_settle_steps+n_eval_steps) > n_settle_steps){
    //if(flag_twiddle && step>n_settle_steps && step<n_settle_steps+n_eval_steps){
        cout << "step: " << step << endl;
        cout << "total error: " << err_sum << endl;
        cout << "best error: " << err_best << endl;
        
        if(err_sum<err_best){
            err_best=err_sum;
            if(step!= n_settle_steps+n_eval_steps){
                dp[param_index]*=1.1;
            }
            //next parameter
            param_index=(param_index+1)%3;
            flag_adding=flag_minus=false;
        }
        if(flag_adding==false && flag_minus==false){
            ChangeParameters(param_index,dp[param_index]);
            flag_adding=true;
        }
        else if(flag_adding==true && flag_minus==false){
            ChangeParameters(param_index,-2*dp[param_index]);
            flag_minus=true;
        }else{
            //when flag_adding==true && flag_minus==true
            ChangeParameters(param_index,dp[param_index]);
            dp[param_index]*=0.9;
            param_index=(param_index+1)%3;
            flag_adding=flag_minus=false;
        }
        err_sum=0;
        cout<<"new parameters"<<endl;
        cout<<"P:"<<Kp<<",I:"<<Ki<<",D:"<<Kd<<endl;
        
    }
    step++;
}

double PID::TotalError() {
    return 0.0;
}

void PID::ChangeParameters(int index, double amount) {
    if (index == 0) {
        Kp += amount;
    }
    else if (index == 1) {
        Kd += amount;
    }
    else if (index == 2) {
        Ki += amount;
    }
}

