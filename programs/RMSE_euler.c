#include<stdio.h>
#include<math.h>

#define SQ(x) ((x)*(x))

double calc_x(double t);
double calc_y(double t);

const double f = 7.292E-5;
const int last_t=524288;
const int max_dt=8192;

int main(void){
  double u0=2;
  double v0=0;
  double x0=0;
  double y0=0;

  int dt;
  int i,j,k;

  double x[2],y[2],u[2],v[2];

  for(dt = 2; dt<=max_dt ; dt*=2){
    x[0]=x0;
    y[0]=y0;
    u[0]=u0;
    v[0]=v0;

    for(i=2;i<=last_t/dt;i++){
      x[1]=x[0]+u[0]*dt;
      y[1]=y[0]+v[0]*dt;
      u[1]=u[0]-f*v[0]*dt;
      v[1]=v[0]+f*u[0]*dt;

      x[0]=x[1];
      y[0]=y[1];
      u[0]=u[1];
      v[0]=v[1];
    }

    printf("dt=%d, RMSE=%lf (at t=%d)\n", dt, sqrt(SQ(x[1]-calc_x(last_t))+SQ(y[1]-calc_y(last_t))),last_t);
  }
  return 0;
}


double calc_x(double t){
  return 2 / f * sin ( f * t );
}

double calc_y(double t){
  return 2/f * cos ( f * t ) - 2/f ;
}

