#include<iostream>
#include<math.h>
#include<time.h>

using namespace std;

#define M 4
#define N 5

float x[M][N]={1,1,0,3,4,2,1,-1,1,1,3,-1,-1,3,-3,-1,2,3,-1,4};
float y[M][N]={1,-1,2,-1,-8,2,-2,3,-3,20,1,1,1,0,-2,1,-1,4,3,4};
float b[M]={0};
float n[M]={0};
/*展示矩阵*/
void display(float x[M][N])
{
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<x[i][j]<<"     ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}
/*输入矩阵元素*/
 void getinto(float x[M][N])
 {
    cout<<"请输入矩阵"<<endl;
 }
/*选主元,当前为第j列，从第i行开始*/
bool choicemain(float x[M][N], int i,int j)
{

    float temp=x[i][j];
    int v,w;
    float sum=0;
    v=i;
    w=i;
    for(int q=i;q<M;q++)
    {
        sum= sum+x[q][j]*x[q][j];
    }
    if(sum==0) return false;
    for(int u=i;u<M;u++)
    {
        if(fabs(temp)<=fabs(x[u][j])) 
        {
            w=u;
            temp=x[u][j];
        }
    }
    //cout<<"交换"<<v<<"  "<<w<<endl;
    /*****交换元素，第u和第v交换，从第j列开始******/
    for(int t=j;t<N;t++)
    {
        temp =x[w][t];
        x[w][t]=x[v][t];
        x[v][t]=temp;

    }
    //cout<<"交换后"<<endl;
    //display(x);
}

/*对矩阵进行高斯消元*/
void trans(float x[M][N])
{
    double Lik=0;
    int i=0,j=0;
    for(;i<M;i++)
    {
        choicemain(x,i,i);
        for(int u=i+1;u<M;u++){
            Lik = x[u][i]/x[i][i];
            //cout<<Lik<<endl;
            for(int j=i;j<N;j++)
            {
                //cout<<x[u][j]<<" "<<Lik<<"  "<<x[i][j]<<endl;
                x[u][j]=x[u][j]-Lik*x[i][j];
            }   
        }
        //display(x);
    }
}

void get_value(float x[M][N])
{
    for(int i=M-1;i>=0;i--)
    {
        float sum=0;
        for(int j=i+1;j<N-1;j++)
        {
            sum+=x[i][j]*n[j];
        }
        n[i]=(x[i][N-1]-sum)/x[i][i];
    }
}

int main()
{
    cout<<"初始矩阵"<<endl;
    display(y);
    trans(y);   
    get_value(y);
    cout<<endl;
    cout<<"计算结果"<<endl;
    cout<<n[0]<<"  "<<n[1]<<"  "<<n[2]<<"  "<<n[3]<<endl;


    system("pause");
    return 0;
}
