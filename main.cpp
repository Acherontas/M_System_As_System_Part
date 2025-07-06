/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/*
 * File:   main.cpp
 * Author: Aionnio
 *
 * Created on January 20, 2024, 10:16 PM
 */

 /*
 The M System
M 1 2 3 4 5 6
1 1 5 7 8 4 2
2 2 1 5 7 8 4
3 3 6 3 6 3 6
4 4 2 1 5 7 8
5 5 7 8 4 2 1
6 6 3 6 3 6 3
7 7 8 4 2 1 5
8 8 4 2 1 5 7
9 9 0 0 0 0 0
 */

#include <cstdlib>
#include <iostream>
using namespace std;

void print_da_System()
{
cout<<"The M System \n";
cout<<"M 1 2 3 4 5 6 \n";
cout<<"1 1 5 7 8 4 2 \n";
cout<<"2 2 1 5 7 8 4 \n";
cout<<"3 3 6 3 6 3 6 \n";
cout<<"4 4 2 1 5 7 8 \n";
cout<<"5 5 7 8 4 2 1 \n";
cout<<"6 6 3 6 3 6 3 \n";
cout<<"7 7 8 4 2 1 5 \n";
cout<<"8 8 4 2 1 5 7 \n";
cout<<"9 9 0 0 0 0 0 \n";
}


int arr_t[6]={5,1,2,4,8,7};
int ask_system=0;
int getSum(int n){
        int sum = 0;
        while (n != 0) {
            sum = sum + n % 10;
            n = n / 10;
        }
        if(sum>9){return getSum(sum);}
        if(sum<=9){return sum;}
    return 0;
}

int fnd(int by_me){
   int xli=0;int nt=0;
   for(int i=0;i<=6;i++)
   {
      if(by_me==arr_t[i]){xli=i;nt=1;}
      if(nt==1){break;}
   }
   return xli;
}


int fnd_fpos(int min_pos,int max_pos,int current_pos,int pivot){
   int praxi=current_pos-pivot;
   praxi=abs(praxi);
   //cout<<"min pos " << min_pos << "  max pos " << max_pos << "  current pos " << current_pos << " pivot " << pivot <<"\n";
   //cout<<"praxi " << praxi <<" :: \n" ;
   int xv=0;
   int mark_xv=0;
   int stp=0;
   int posx=0;int cnt=0;int fli=0;
   xv=current_pos-1;
   while(7>min_pos){
            mark_xv=xv;
            //cout<<"xv " << xv << " :: \n";
            stp+=1;
            if(xv<0){
                        //cout<<"entering if " << " " ;
	                	xv=max_pos-1;
                        mark_xv=xv;
                        //cout<<"returning from if " << xv <<"\n";
                        fli+=1;
                     }
        cnt+=1;
        if(cnt==pivot && fli==0){posx=mark_xv; //cout<<"returning cnt praxi posx " << cnt << " " << praxi << " " << posx <<"\n";
                                 break;}
        if(cnt==pivot && fli>0){posx=mark_xv+1; //cout<<"returning cnt praxi posx " << cnt << " " << praxi << " " << posx <<"\n";
                                break;}
        min_pos+=1;
        xv=xv-1;
    }
    //cout<<posx <<"\n";
    return posx;
}

int main(int argc, char** argv) {
    cout<<"enter 1,2,3,4,5,6 for ur M System: \n";
    cout<<"if 0 all systems will shown up\n";
    cin>>ask_system;
    cout<<"\n";
    int mynum;
   // cout<<"\n";
   // cout<<"printing the System\n";
   // print_da_System();
   // cout<<"\n";
   // cout<<"\n";
    cout<<"enter ur number\n";
    cin>>mynum;
    int ys,yys,zs,zzs,zzi;
    int y,yy,z,zz,zi;
    int lri=0;int nps=0;
    int gnr=0;
    int main_sum=getSum(mynum);
     if(ask_system==0){
        cout<<"M1 non shifting  " << mynum << " ::= " << main_sum << " \n";
        y=(mynum<<5);ys=getSum(y);
        cout<<"M2 shifts << 5 | " << y << " ::= " << ys << " \n";
        yy=(mynum<<4);yys=getSum(yy);
        cout<<"M3 shifts << 4 | " << (yy)<< " ::= " << yys << " \n";
        z=(mynum<<3);zs=getSum(z);
        cout<<"M4 shifts << 3 | " << (z)<< " ::= " << zs << " \n";
        zz=(mynum<<2);zzs=getSum(zz);
        cout<<"M5 shifts << 2 | " << (zz)<< " ::= " << zzs << " \n";
        zi=(mynum<<1);zzi=getSum(zi);
        cout<<"M6 shifts << 1 | " <<(zi)<< " ::= " << zzi << " \n";
        return 0;
    }
    if(main_sum==3){cout<<"ur number is 6\n";return 0;}
    if(main_sum==6){cout<<"ur number is 3\n";return 0;}
    if(main_sum==9){cout<<"ur number is 9\n";return 0;}
    if(ask_system==2){
        y=(mynum<<5);ys=getSum(y);
        cout<<"M2 shifts << 5 | " << y << " ::= " << ys << " \n";
        lri=fnd(ys);
        nps=fnd_fpos(0,5,lri,5);
        cout<<"returning : " << lri << " @nps " << nps << "  ::= " << arr_t[nps]<<"\n";
        gnr=ys;
        }
    if(ask_system==3){
        yy=(mynum<<4);yys=getSum(yy);
        cout<<"M3 shifts << 4 | " << (yy)<< " ::= " << yys << " \n";
        lri=fnd(yys);
        nps=fnd_fpos(0,5,lri,4);
        cout<<"returning : " << lri << " @nps " << nps << "  ::= " << arr_t[nps]<<"\n";
        gnr=yys;
        }
    if(ask_system==4){
        z=(mynum<<3);zs=getSum(z);
        cout<<"M4 shifts << 3 | " << (z)<< " ::= " << zs << " \n";
        lri=fnd(zs);
        nps=fnd_fpos(0,5,lri,3);
        cout<<"returning : " << lri << " @nps " << nps << "  ::= " << arr_t[nps]<<"\n";
        gnr=zs;
        }
    if(ask_system==5){
        zz=(mynum<<2);zzs=getSum(zz);
        cout<<"M5 shifts << 2 | " << (zz)<< " ::= " << zzs << " \n";
        lri=fnd(zzs);
        nps=fnd_fpos(0,5,lri,2);
        cout<<"returning : " << lri << " @nps " << nps << "  ::= " << arr_t[nps]<<"\n";
        gnr=zzs;
        }
    if(ask_system==6){
        zi=(mynum<<1);zzi=getSum(zi);
        cout<<"M6 shifts << 1 | " <<(zi)<< " ::= " << zzi << " \n";
        lri=fnd(zzi);
        nps=fnd_fpos(0,5,lri,1);
        cout<<"returning : " << lri << " @nps " << nps << "  ::= " << arr_t[nps]<<"\n";
        gnr=zzi;
        }

    if(gnr==3){cout<<"its 6\n";}
    if(gnr==6){cout<<"its 3\n";}
    if(gnr==9){cout<<"its 9\n";}
    cout<<"M1 non shifting  " << mynum << " ::= " << main_sum << " \n";

    return 0;
}

