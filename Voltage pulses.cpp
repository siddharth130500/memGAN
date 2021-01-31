#include<bits/stdc++.h>
using namespace std;

int range(double G)
{
    if(G<=5.16) return 0;
    if(G<=10) return 1;
    if(G<=17.8) return 2;
    if(G<=31.6) return 3;
    if(G<=56.2) return 4;
    if(G<=100) return 5;
    if(G<=178) return 6;
    if(G<=316) return 7;
}

double A[8][10]={{1.55e-4,-0.47,-3.851,9.369,10.4,-1.26,-0.02,0.82,-0.57,0.94},
{1.55e-4,-0.47,-3.769,7.512,8.419,-1.22,-0.02,0.84,-0.57,0.81},
{1.55e-4,-0.47,-3.729,6.801,7.582,-1.03,-0.02,0.72,-0.47,0.63},
{1.55e-4,-0.47,-3.517,6.180,6.851,-0.78,-0.01,0.53,-0.33,0.45},
{1.55e-4,-0.47,-3.426,5.946,6.558,-0.37,5e-3,0.15,-0.01,0.11},
{1.55e-4,-0.47,-3.373,5.005,5.792,0.14,0.01,-0.29,0.31,-0.21},
{1.55e-4,-0.47,-3.422,4.936,5.840,0.34,0.01,-0.41,0.37,-0.29},
{1.55e-4,-0.47,-3.572,4.864,5.785,0.26,0.01,-0.29,0.25,-0.20}};

double B[8][10]={{-0.89e-4,0.89,8.96,6.2,-10.90,0.04,2e-4,0.02,5e-3,0.03},
{-0.89e-4,0.51,6.88,6.2,-8.61,-5e-3,-4e-4,-2e-3,-0.01,0.02},
{-0.89e-4,0.34,4.93,6.2,-8.14,-0.07,-3e-3,-0.07,-0.05,-0.02},
{-0.89e-4,0.25,3.63,6.2,-7.77,-0.11,-4e-3,-0.11,-0.09,-0.03},
{-0.89e-4,0.23,2.91,6.2,-7.42,-0.15,-6e-3,-0.17,-0.13,-0.06},
{-0.89e-4,0.21,2.33,6.2,-7.30,-0.12,-5e-3,-0.16,-0.13,-0.06},
{-0.89e-4,0.22,1.93,6.2,-7.10,-0.04,-2e-3,-0.10,-0.11,-0.04},
{-0.89e-4,0.28,1.68,6.2,-7.00,0.10,3e-3,0.02,-0.05,-4e-3}};

double c0s(double G) {int k=range(G); return A[k][0];}
double c1s(double G) {int k=range(G); return A[k][1];}
double c2s(double G) {int k=range(G); return A[k][2];}
double c3s(double G) {int k=range(G); return A[k][3];}
double c4s(double G) {int k=range(G); return A[k][4];}
double d0s(double G) {int k=range(G); return A[k][5];}
double d1s(double G) {int k=range(G); return A[k][6];}
double d2s(double G) {int k=range(G); return A[k][7];}
double d3s(double G) {int k=range(G); return A[k][8];}
double d4s(double G) {int k=range(G); return A[k][9];}

double c0r(double G) {int k=range(G); return B[k][0];}
double c1r(double G) {int k=range(G); return B[k][1];}
double c2r(double G) {int k=range(G); return B[k][2];}
double c3r(double G) {int k=range(G); return B[k][3];}
double c4r(double G) {int k=range(G); return B[k][4];}
double d0r(double G) {int k=range(G); return B[k][5];}
double d1r(double G) {int k=range(G); return B[k][6];}
double d2r(double G) {int k=range(G); return B[k][7];}
double d3r(double G) {int k=range(G); return B[k][8];}
double d4r(double G) {int k=range(G); return B[k][9];}


int main()
{
    double Go=3.5;
    double res=1e9;
    double Vps_f,Vpr_f,tp_f;

    double deltaGset,deltaGreset;
    for(double tp=1.0;tp<=100.0;tp=tp+0.5)
    {
        for(double Vps=-0.8;Vps>=-1.5;Vps=Vps-0.1)
        {
                for(double Vpr=0.8;Vpr<=1.15;Vpr=Vpr+0.1)
                {
                    Go=3.5;
                    double sum=0.0;
                    while(Go<=315){
                        double Dms = c0s(Go)*(1-tanh(c1s(Go)*(log(tp)-c2s(Go))))*(tanh(c3s(Go)*Vps-c4s(Go))+1);
                        //double Dd2ds = Dms*(d0s(Go)+d1s(Go)*(log(tp))*(log(tp))+d2s(Go)*Vps*log(tp)+d3s(Go)*Vps*Vps*log(tp)+d4s(Go)*Vps*Vps*Vps);
                        deltaGset=Dms;
                        double Dmr = c0r(Go)*(-1-tanh(c1r(Go)*(log(tp)-c2r(Go))))*(tanh(c3r(Go)*Vpr-c4r(Go))-1);
                        //double Dd2dr = Dmr*(d0r(Go)+d1r(Go)*(log(tp))*(log(tp))+d2r(Go)*Vpr*log(tp)+d3r(Go)*Vpr*Vpr*log(tp)+d4r(Go)*Vpr*Vpr*Vpr);
                        deltaGreset=Dmr;

                        sum=sum+pow((abs(deltaGreset)-abs(deltaGset)),2);

                        Go=Go+0.5;
                    }
                    if(sum<res)
                    {
                        Vps_f=Vps; Vpr_f=Vpr; tp_f=tp;
                        res=sum;
                    }
                }
        }
    }

    cout<<"Vps = "<<Vps_f<<"\nVpr = "<<Vpr_f<<"\ntp = "<<tp_f<<"\n\n";

}
