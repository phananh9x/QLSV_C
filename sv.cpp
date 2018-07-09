#include <string.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <iomanip> 
#include <conio.h>
#include "mylib.h"
#include <windows.h>


using namespace std;
const int KEY_ESC = 27;
const int KEY_UP = 72;
const int KEY_DOWN = 80;
const int KEY_LEFT = 75;
const int KEY_RIGHT = 77;
const int KEY_ENTER = 13;
const int KEY_BACKSPACE = 8;
const int KEY_F1 = 59;
const int KEY_F2 = 60;
const int KEY_F3 = 61;
const int KEY_F4 = 62;
const int KEY_F5 = 63;
const int KEY_F6 = 64;
const int KEY_SPACE = 32;
double ceil ( double );

char MENU[5][30] = {"  1.Quan Ly Lop         ","  2.Quan Ly Sinh Vien   " ,"  3.Quan Ly Mon Hoc     ","  4.Quan Ly Diem        ", "  5.Thoat               "};
char MENUDIEM[5][30]={"  1.Xem Diem Sinh Vien  ","  2.Tong Ket Diem SV    "};

char MENUCHUCNANG[6][30]={" F1 "," F2 "," F3 "," F4 "," F5 "," ESC"};
char MENUCHUCNANGCHU[6][30]={":THEM",":SUA",":XOA",":TIM KIEM",":XEM LOP",":THOAT"};

char MENUCHUCNANGDIEM[6][30]={" ESC"," F1 "," F2"};
char MENUCHUCNANGCHUDIEM[6][30]={":THOAT",":CAP NHAT DIEM",":XOA DIEM"};

char MENUCHUCNANGTONGDIEM[6][30]={" ESC"," F1 "};
char MENUCHUCNANGCHUTONGDIEM[6][30]={":THOAT",":XEM MON HOC"};
using namespace std;
const int MAXLIST = 50;

struct DIEM
{
	char MAMH[30];
	int LAN;
	float DIEMSV;
	
};
struct NODE_DIEM
{
	DIEM diem;
	NODE_DIEM *next;
};
typedef NODE_DIEM *PTRDIEM;
struct MONHOC
{
	char MAMH[30];
	char TENMH[40];
	int STCLT;
	int STCTH;
};

struct NODEMONHOC
{
	MONHOC monhoc;
	NODEMONHOC* left;
	NODEMONHOC* right;
};
typedef struct NODEMONHOC* PTRMONHOC;

struct SINHVIEN
{
	char MASV[30];
	char HO[30];
	char TEN[30];
	char PHAI[5];
	char SDT[30];
	PTRDIEM contro;
};
struct NODE_SV
{
	SINHVIEN sv;
	NODE_SV *next;
};
typedef NODE_SV *PTRSV;


struct LOP
{
	char MALOP[30];
	char TENLOP[30];
	int NIEMKHOA;
	PTRSV contro;
};
struct list_LOP
{
	int n = 0;
	LOP *lop[MAXLIST];	
};



void ToMauMenuCon(int background,int textcolor,int vitri,char menu[][30])
{
	setcolor(background,textcolor);
	gotoxy(30,5+vitri*4); cout<<"                        ";
	gotoxy(30,6+vitri*4); cout<<menu[vitri];
	gotoxy(30,7+vitri*4); cout<<"                        ";
}

void VeNutCo(char s[],int x,int y,int textcolorCO)
{
	SetColor(textcolorCO);
	gotoxy(x + 2 ,y + 3 );
	cout<<(char)201;
	for(int i=0;i<7;i++)
	{
	cout<<(char)205;
	}
	cout<<(char)187;
	gotoxy(x +2 , y+4);
	cout<<(char)186;
	gotoxy(x + 10 , y +4 );
	cout<<(char)186;
	gotoxy(x +2 ,y +5 );
	cout<<(char)200;
	for(int i=0;i<7;i++)
	{
	cout<<(char)205;
	}
	cout<<(char)188;
	gotoxy(x +5 ,y+4) ;
	cout<<s;
}
//struct list_MH
//{
//	int n;
//	MONHOC mh[MAXLIST];	
//};
void VeNutKhong(char s[],int x,int y,int textcolorKHONG,int len){
	SetColor(textcolorKHONG);
	gotoxy(x + len-9 ,y + 3 );
	cout<<(char)201;
	for(int i=0;i<7;i++)
	{
	 cout<<(char)205;
	}
	cout<<(char)187;
	gotoxy(x +len-9 , y+4);
	cout<<(char)186;
	gotoxy(x + len-1 , y +4 );
	cout<<(char)186;
	gotoxy(x +len-9 ,y +5 );
	cout<<(char)200;
	for(int i=0;i<7;i++)
	{
	 cout<<(char)205;
	}
	cout<<(char)188;
	gotoxy(x +len -7 ,y+4) ;
	cout<<s;
}
void HopThoai(char p[],char s[][10],int x,int y ,int background,int textcolor,int textcolorCO,int textcolorKHONG)
{
	gotoxy(x,y);
	SetColor(textcolor);
	int len=strlen(p);
	
	len=len+2;
	cout<<(char)218;
	for ( int i = 0 ; i < len ; i++ )
		cout<<(char)196;
	cout<<(char)191;

	for ( int i = 0 ; i < 6 ; i ++ )
	{
		for ( int j = 0 ; j < len+2 ; j++ )
		{
			if ( j == 0 || j == len+1 )
			{
				gotoxy(x + j ,y + 1 + i );
				cout<<(char)179;
			}
			else
			{
				gotoxy(x + j , y + 1 + i);
				cout<<" ";
			}
		}
	}
	gotoxy(x,y + 7 );
	cout<<(char)192;
	for ( int i = 0 ; i < len ; i++ )
		cout<<(char)196;
	cout<<(char)217; 
	
	setcolor(background,textcolor);
	gotoxy(x+2 ,y +1 ); cout<<p;

    VeNutCo(s[0],x,y,textcolorCO);

	VeNutKhong(s[1],x,y,textcolorKHONG,strlen(p));
}

int HopThoaiYESNO(char p[],char s[][10],int x,int y ,int background,int textcolor,int textcolorCO,int textcolorKHONG){
	char key;
	int chon=0;
	int check=0;
	setcolor(background,textcolor);
	HopThoai(p,s,x,y,background,textcolor,textcolorCO,textcolorKHONG);
	VeNutKhong(s[1],x,y,28,strlen(p));
	do{
	  key=getch();
	  switch(key)
	  {
	  	case KEY_LEFT:
	  		chon =1;
	  		VeNutKhong(s[1],x,y,textcolorKHONG,strlen(p));
	  		VeNutCo(s[0],x,y,28);
	  		break;
	  	case KEY_RIGHT:
	  		chon=0;
	  		VeNutCo(s[0],x,y,textcolorCO);
	  		VeNutKhong(s[1],x,y,28,strlen(p));
	  		break;	
	  	case KEY_ENTER:
	  		check=1;
	  		break;
	  	case KEY_ESC:
	  		return 2;
	  		break;	
	  }	
	}
	while(check!=1);
	
	return chon;
	
	}
	
void MauMenuConMacDinh(int background,int textcolor,int soluong,char menu[][30]){
	for(int i=0;i<soluong;i++)
	{
		ToMauMenuCon(background,textcolor,i,menu);
	}
}
	

void ToMauMenuChinh(int background,int textcolor,int vitri)
{
	if(vitri > -1)
	{
	 setcolor(background,textcolor);
	 gotoxy(0,5+vitri*4); cout<<"                        ";
	 gotoxy(0,6+vitri*4); cout<<MENU[vitri];
	 gotoxy(0,7+vitri*4); cout<<"                        ";
	}
}

void ThongBao(char s[],int background,int textcolor ,int cot,int hang)
{
	do
	{
		setcolor(background, textcolor);
		gotoxy(cot,hang); cout<<s;
		Sleep(700);
		gotoxy(cot,hang); for(int i=0 ;i<strlen(s); i++) cout<<" ";
		Sleep(300);
	}
	while(!kbhit());
	getch();
	gotoxy(cot,hang); for(int i=0 ; i<strlen(s) ; i++) cout<<" ";
}

void ColorMenuNormal(){
	setcolor(16,15);
	for(int i=0;i<5;i++){
		ToMauMenuChinh(28,15,i);
		}
	}


void VeNutChucNang(int i,char menu1[][30],int background,int colortext){
	setcolor(16,3);
	gotoxy(5,28);
	cout<<"MENU CHUC NANG :";
	setcolor(background,colortext);
	if(i > -1){
	if(i<3)
	{
	 gotoxy(12+21*i,30);
	 cout<<"      ";
	 gotoxy(12+21*i,31);
	 cout<<"      ";
	 gotoxy(12+21*i,32);
	 cout<<"      ";
	 gotoxy(12+21*i,31);
	 cout<<" "<<menu1[i];
	}
	else
	{
	 gotoxy(12+21*(i-3),34);
	 cout<<"      ";
	 gotoxy(12+21*(i-3),35);
	 cout<<"      ";
	 gotoxy(12+21*(i-3),36);
	 cout<<"      ";
	 gotoxy(12+21*(i-3),35);
	 cout<<" "<<menu1[i];
	}
	}
	}
void VeTextMenuChucNang(int i,char menu2[][30],int background,int colortext){
	setcolor(background,colortext);
	if(i<3)
	{
	 gotoxy(19+21*i,31);
	 cout<<menu2[i];
	}
	else
	{
	 gotoxy(19+21*(i-3),35);
	 cout<<menu2[i];
	}
}	

void VeNutChucNangDiem(int i,char menu1[][30],int background,int colortext){
	setcolor(16,3);
	gotoxy(5,30);
	cout<<"MENU CHUC NANG :";
	setcolor(background,colortext);
	if(i > -1)
	{
	  gotoxy(10+24*i,32);
	  cout<<"      ";
	  gotoxy(10+24*i,33);
	  cout<<"      ";
	  gotoxy(10+24*i,34);
	  cout<<"      ";
	  gotoxy(10+24*i,33);
	  cout<<" "<<menu1[i];
	}
	}
void VeTextMenuChucNangDiem(int i,char menu2[][30],int background,int colortext){
	
	setcolor(background,colortext);
	gotoxy(17+24*i,33);
	cout<<menu2[i];
	
}	
void MenuChucNangDiem(char menu1[][30],char menu2[][30],int background,int colortext,int colortext1,int x,int y,int len){
	    gotoxy(x,y);
	    char key;
	    int chon=-1;
	    for(int i=0;i<len;i++) {
		  VeNutChucNangDiem(i,menu1,background,colortext);
	    }
	    for(int i=0;i<len;i++) {
		  VeTextMenuChucNangDiem(i,menu2,16,colortext1);
	   }
	}

void MenuChucNang(char menu1[][30],char menu2[][30],int background,int colortext,int colortext1,int x,int y,int len,int islop){
	    gotoxy(x,y);
	    char key;
	    int chon=-1;
	    for(int i=0;i<len;i++) {
	      if(islop==1&&i==4){
	      	 i++;
	      }
		  VeNutChucNang(i,menu1,background,colortext);
	    }
	    for(int i=0;i<len;i++) {
	    if(islop==1&&i==4){
	      	 i++;
	      }
		  VeTextMenuChucNang(i,menu2,16,colortext1);
	   }
	}

void HienThiTrang(int TongTrang, int TrangHienTai , int x ,int y , int background,int textcolor , int textcolor1)
{
    gotoxy(x,y)  ;   cout<<(char)218;
	for(int i= 0 ; i< 17 ; i++)  cout<<(char)196;   cout<<(char)191 ;
	gotoxy(x, y+1 );          cout<<(char)179;                                   setcolor(background,textcolor);
	cout<< " Trang :  "<< ( TrangHienTai+1 ) <<" / " << ( TongTrang ) <<"  ";    setcolor( background,textcolor1 );
	cout<<(char)179;
	gotoxy(x, y+2 ); cout<<(char)192;
	for(int i= 0 ; i< 17 ; i++)  cout<<(char)196;   cout<<(char)217 ;
	setcolor(background,textcolor);
	gotoxy(x+56,y+1);
}	
char HamNhapDuLieu(int x,int y,int dodai,char *num,int isnhap){
	char getnum;
    int i=0,check=0;
    setcolor(16,15);
    gotoxy(x,y);
    while((getnum=getch())!=KEY_ENTER&&getnum!=KEY_ESC)
    {
    	
    if(getnum>='0'&&getnum<='9'&&i<dodai)
    {
        num[i]=getnum;
        putchar(getnum);
        i++;
    }
    if(getnum>='A'&&getnum <='Z'&&i<dodai){
    	num[i]=getnum;
    	putchar(getnum);
        i++;
    }
    if(getnum>='a'&&getnum <='z'&&i<dodai){
    	num[i]=getnum;
    	putchar(getnum);
        i++;
    }
    check=i;
    if(getnum==KEY_SPACE&&num[check-1]!=KEY_SPACE&&isnhap==1&&i<dodai){
    	num[i]=getnum;
    	putchar(getnum);
        i++;
    	 }
    if(getnum==KEY_BACKSPACE&&i>0){
    	i--;
		gotoxy(x + i ,y);
		cout<<" ";
	    gotoxy(x + i ,y);
     }
    if(getnum==KEY_F5)
	{
    	num[i]='\0';
    	return getnum;
    }
    if(getnum==KEY_F4)
	{
    	num[i]='\0';
    	return getnum;
    }	
   }
   num[i]='\0';
   return getnum;
}

char HamNhapDuLieu2(int x,int y,int &i,int dodai,char *num,int isnhap){
	int getnum;
    int check=0;
    setcolor(16,15);
    gotoxy(x,y);
    if(i > 0)
	{
    	cout<<num;
    }
    do
    {
     getnum=getch();
     if (getnum == 0 || getnum == 224)
	 {
	 	getnum=getch();
	 	if(getnum==KEY_DOWN||getnum==KEY_UP)
	    {
		  num[i]='\0';
    	  return getnum;
	    }	
	    if(getnum==KEY_F5||getnum==KEY_F4)
		{
    	  num[i]='\0';
    	  return getnum;
        }
     }
	 else
	 {	
       if(((getnum>='0'&&getnum<='9')||(getnum>='A'&&getnum <='Z')||(getnum>='a'&&getnum <='z'))&&i<dodai)
       {
         num[i] = char(getnum);
		 cout<<num[i];
		 i++;
       }
       check=i;
       if(getnum==KEY_SPACE&&num[check-1]!=KEY_SPACE&&isnhap==1&&i<dodai)
	   {
    	 num[i] = char(getnum);
		 cout<<num[i];
		 i++;
    	}
        if(getnum==KEY_BACKSPACE&&i>0)
		{
    	  i--;
		  gotoxy(x + i ,y);
		  cout<<" ";
	      gotoxy(x + i ,y);
        }
      }
   }
   while(getnum!=KEY_ENTER&&getnum!=KEY_ESC);
   num[i]='\0';
   return getnum;
}

char HamNhapDiem(int x,int y,int  &i,int dodai,char *num){
	char getnum;
    setcolor(16,15);
    gotoxy(x,y);
    if(i > 0)
	{
      cout<<num;
    }
    while((getnum=getch())!=KEY_ENTER&&getnum!=KEY_ESC)
    {
    if(getnum==KEY_DOWN||getnum==KEY_UP||getnum==KEY_LEFT||getnum==KEY_RIGHT)
	{
		num[i]='\0';
    	return getnum;
	}		
    if((getnum>='0'&&getnum<='9'||getnum=='.')&&i<dodai)
    {
        num[i]=getnum;
        putchar(getnum);
        i++;
    }
    if(getnum==KEY_BACKSPACE&&i>0){
    	i--;
		gotoxy(x + i ,y);
		cout<<" ";
		num[i]='\0';
	    gotoxy(x + i ,y);
    }
   }
   num[i]='\0';
   return getnum;
}

void VeEditText(int x,int y,char *text){
	setcolor(27,16);
	gotoxy(x,y);   cout<<text;
	gotoxy(x,y+1); for(int i=0;i<strlen(text);i++)cout<<" ";
	gotoxy(x,y+2); for(int i=0;i<strlen(text);i++)cout<<" ";
	setcolor(16,15);
	gotoxy(x+2,y+1); for(int i=0;i<(strlen(text)-4);i++)cout<<" ";  
	}
char nhap_so(int x,int y,int &bien)
{
	char num[10],getnum;
    int i=0;
    setcolor(16,15);
    gotoxy(x,y);
    while((getnum=getch())!=13&&getnum!=KEY_ESC)
    {
    if(getnum>='0'&&getnum<='9'&&i<9)
    {
    num[i]=getnum;
    putchar(getnum);
    i++;
    }
    if(getnum==KEY_BACKSPACE&&i>0){
    	i--;
		gotoxy(x + i ,y);
		cout<<" ";
	    gotoxy(x + i ,y);
    }
   }
    bien=atoi(num);
    return getnum;
} 
char nhap_so2(int x,int y,int &i,char *num)
{
	char getnum;
    setcolor(16,15);
    gotoxy(x,y);
    if(i > 0)
	{
      cout<<num;
    }
    while((getnum=getch())!=13&&getnum!=KEY_ESC)
    {
    if(getnum==KEY_DOWN||getnum==KEY_UP)
	{
		num[i]='\0';
    	return getnum;
	}		
    if(getnum>='0'&&getnum<='9'&&i<9)
    {
    num[i]=getnum;
    putchar(getnum);
    i++;
    }
    if(getnum==KEY_BACKSPACE&&i>0){
    	i--;
		gotoxy(x + i ,y);
		cout<<" ";
	    gotoxy(x + i ,y);
    }
   }
   num[i]='\0';
   return getnum;
} 
void NhapSinhVien(){
	VeEditText(30,5,(char *) "    Nhap Ma SV           ");
	VeEditText(30,8,(char *) "    Nhap Ho SV           ");
	VeEditText(30,11,(char *)"    Nhap Ten SV          ");
	VeEditText(30,14,(char *)"    Nhap GT SV           ");
	VeEditText(30,17,(char *)"    Nhap SDT             ");
	}
void NhapLop(){
	setcolor(27,16);
	VeEditText(22,5,(char *)"            Nhap Ma Lop            ");
	VeEditText(22,8,(char *)"            Nhap Ten Lop           ");
	VeEditText(22,11,(char *)"          Nhap Nien khoa           ");
	}
void NhapMonHoc(){
	VeEditText(30,5,(char *) "     Nhap Ma MH             ");
	VeEditText(30,8,(char *) "     Nhap Ten MH            ");
	VeEditText(30,11,(char *)"     Nhap STCLT             ");
	VeEditText(30,14,(char *)"     Nhap STCTH             ");
	}
	
void NhapDiem(){
	VeEditText(30,5,(char *)"    Nhap Ma SV     ");
	VeEditText(30,8,(char *)"    Nhap Ma MH     ");
	VeEditText(30,11,(char *)"   Nhap Lan Thi    ");
	VeEditText(30,14,(char *)"    Nhap Diem      ");
	}

void BangMH ( int maxTrang ,int x ,int y)
{
	setcolor(16,15);
	gotoxy(x,y);          cout<<(char)218;
	for(int i=0;i<5;i++)  cout<<(char)196;   cout<<(char)194 ;
	for(int i=0;i<13;i++) cout<<(char)196;  cout<<(char)194 ;
	for(int i=0;i<31;i++) cout<<(char)196;   cout<<(char)194;
	for(int i=0;i<10;i++) cout<<(char)196;   cout<<(char)194;
	for(int i=0;i<10;i++) cout<<(char)196;   cout<<(char)191;

	gotoxy(x,y+1); cout<<(char)179<<" STT "<<(char)179<<"    MA MH    "<<(char)179<<"            TEN MH             "<<(char)179<<" SO TC LT "<<(char)179<<" SO TC TH "<<(char)179;

	gotoxy(x,y+2); cout<<(char)195;
	for(int i=0;i<5;i++)  cout<<(char)196;   cout<<(char)197 ;
	for(int i=0;i<13;i++) cout<<(char)196;  cout<<(char)197 ;
	for(int i=0;i<31;i++) cout<<(char)196;   cout<<(char)197;
	for(int i=0;i<10;i++) cout<<(char)196;   cout<<(char)197;
	for(int i=0;i<10;i++) cout<<(char)196;   cout<<(char)180;

	gotoxy(x,y+3+maxTrang); cout<<(char)192;
	for(int i=0;i<5;i++)  cout<<(char)196;   cout<<(char)193 ;
	for(int i=0;i<13;i++) cout<<(char)196;   cout<<(char)193 ;
	for(int i=0;i<31;i++) cout<<(char)196;   cout<<(char)193 ;
	for(int i=0;i<10;i++) cout<<(char)196;   cout<<(char)193 ;
	for(int i=0;i<10;i++) cout<<(char)196;   cout<<(char)217;
	for(int i =  0 ; i < maxTrang  ; i++)
	{
		gotoxy( x , y +3+  i );
		cout<<(char)179<<"     "<<(char)179<<"             "<<(char)179<<"                               "<<(char)179<<"          "<<(char)179<<"          "<<(char)179;
	}
	}
void BangLOP ( int maxTrang ,int x ,int y)
{
	setcolor(16,15);
	gotoxy(x,y);          cout<<(char)218;
	for(int i=0;i<5;i++)  cout<<(char)196;   cout<<(char)194 ;
	
	for(int i=0;i<13;i++) cout<<(char)196;  cout<<(char)194 ;
	for(int i=0;i<31;i++) cout<<(char)196;   cout<<(char)194;
	for(int i=0;i<33;i++) cout<<(char)196;   cout<<(char)191;

	gotoxy(x,y+1); cout<<(char)179<<" STT "<<(char)179<<"    MA LOP   "<<(char)179<<"            TEN LOP            "<<(char)179<<"            NIEN KHOA            "<<(char)179;

	gotoxy(x,y+2); cout<<(char)195;
	for(int i=0;i<5;i++)  cout<<(char)196;   cout<<(char)197;
	for(int i=0;i<13;i++) cout<<(char)196;  cout<<(char)197;
	for(int i=0;i<31;i++) cout<<(char)196;   cout<<(char)197;
	for(int i=0;i<33;i++) cout<<(char)196;   cout<<(char)180;
	gotoxy(x,y+3+maxTrang); cout<<(char)192;
	for(int i=0;i<5;i++)  cout<<(char)196;   cout<<(char)193;
	for(int i=0;i<13;i++) cout<<(char)196;   cout<<(char)193;
	for(int i=0;i<31;i++) cout<<(char)196;   cout<<(char)193;
	for(int i=0;i<33;i++) cout<<(char)196;   cout<<(char)217;
	
	for(int i =  0 ; i < maxTrang  ; i++)
	{
		gotoxy( x , y +3+  i );
		cout<<(char)179<<"     "<<(char)179<<"             "<<(char)179<<"                               "<<(char)179<<"                                 "<<(char)179;
	}
}
	
void BangSV ( int maxTrang ,int x ,int y)
  {
	setcolor(16,15);
	gotoxy(x,y);          cout<<(char)218;
	for(int i=0;i<5;i++)  cout<<(char)196;   cout<<(char)194 ;
	for(int i=0;i<13;i++) cout<<(char)196;  cout<<(char)194 ;
	for(int i=0;i<16;i++) cout<<(char)196;   cout<<(char)194;
	for(int i=0;i<18;i++) cout<<(char)196;   cout<<(char)194;
	for(int i=0;i<14;i++) cout<<(char)196;   cout<<(char)194;
	for(int i=0;i<14;i++) cout<<(char)196;   cout<<(char)191;
	gotoxy(x,y+1); cout<<(char)179<<" STT "<<(char)179<<"    MA SV    "<<(char)179<<"     HO SV      "<<(char)179<<"      TEN SV      "<<(char)179<<" GIOI TINH SV "<<(char)179<<"     SDT      "<<(char)179;
                                                                                                                                                    
	gotoxy(x,y+2); cout<<(char)195;
	for(int i=0;i<5;i++)  cout<<(char)196;   cout<<(char)197 ;
	for(int i=0;i<13;i++) cout<<(char)196;  cout<<(char)197 ;
	for(int i=0;i<16;i++) cout<<(char)196;   cout<<(char)197;
	for(int i=0;i<18;i++) cout<<(char)196;   cout<<(char)197;
	for(int i=0;i<14;i++) cout<<(char)196;   cout<<(char)197;
	for(int i=0;i<14;i++) cout<<(char)196;   cout<<(char)180;
	gotoxy(x,y+3+maxTrang); cout<<(char)192;
	for(int i=0;i<5;i++)  cout<<(char)196;   cout<<(char)193 ;
	for(int i=0;i<13;i++) cout<<(char)196;   cout<<(char)193 ;
	for(int i=0;i<16;i++) cout<<(char)196;   cout<<(char)193 ;
	for(int i=0;i<18;i++) cout<<(char)196;   cout<<(char)193 ;
	for(int i=0;i<14;i++) cout<<(char)196;   cout<<(char)193;
	for(int i=0;i<14;i++) cout<<(char)196;   cout<<(char)217;
	for(int i =  0 ; i < maxTrang  ; i++)
	{
		gotoxy( x , y +3+  i );
		cout<<(char)179<<"     "<<(char)179<<"             "<<(char)179<<"                "<<(char)179<<"                  "<<(char)179<<"              "<<(char)179<<"              "<<(char)179;
	}
	}	

void BangDiem ( int maxTrang ,int x ,int y)
  {
	gotoxy(x,y);          cout<<(char)218;
	for(int i=0;i<5;i++)  cout<<(char)196;   cout<<(char)194 ;
	for(int i=0;i<11;i++) cout<<(char)196;  cout<<(char)194 ;
	for(int i=0;i<14;i++) cout<<(char)196;   cout<<(char)194;
	for(int i=0;i<15;i++) cout<<(char)196;   cout<<(char)194;
	for(int i=0;i<10;i++) cout<<(char)196;   cout<<(char)194;
	for(int i=0;i<10;i++) cout<<(char)196;   cout<<(char)191;
	gotoxy(x,y+1); cout<<(char)179<<" STT "<<(char)179<<"   MA SV   "<<(char)179<<"      HO      "<<(char)179<<"      TEN      "<<(char)179<<"DIEM LAN 1"<<(char)179<<"DIEM LAN 2"<<(char)179;
	gotoxy(x,y+2); cout<<(char)195;                                                                         
	for(int i=0;i<5;i++)   cout<<(char)196;   cout<<(char)197 ;
	for(int i=0;i<11;i++) cout<<(char)196;  cout<<(char)197 ;
	for(int i=0;i<14;i++) cout<<(char)196;   cout<<(char)197;
	for(int i=0;i<15;i++) cout<<(char)196;   cout<<(char)197;
	for(int i=0;i<10;i++) cout<<(char)196;   cout<<(char)197;
	for(int i=0;i<10;i++) cout<<(char)196;   cout<<(char)180;
	gotoxy(x,y+3+maxTrang); cout<<(char)192;
	for(int i=0;i<5;i++)  cout<<(char)196;   cout<<(char)193 ;
	for(int i=0;i<11;i++) cout<<(char)196;   cout<<(char)193;
	for(int i=0;i<14;i++) cout<<(char)196;   cout<<(char)193;
	for(int i=0;i<15;i++) cout<<(char)196;   cout<<(char)193;
	for(int i=0;i<10;i++) cout<<(char)196;   cout<<(char)193;
	for(int i=0;i<10;i++) cout<<(char)196;   cout<<(char)217;
	for(int i =  0 ; i < maxTrang  ; i++)
	{
		gotoxy( x , y+3+  i );
		cout<<(char)179<<"     "<<(char)179<<"           "<<(char)179<<"              "<<(char)179<<"               "<<(char)179<<"          "<<(char)179<<"          "<<(char)179;
	}
	}	
void BangDiemTongKet( int maxTrang ,int x ,int y)
  {
	gotoxy(x,y);          cout<<(char)218;
	for(int i=0;i<3;i++)  cout<<(char)196;   cout<<(char)194 ;
	for(int i=0;i<10;i++) cout<<(char)196;  cout<<(char)194 ;
	for(int i=0;i<26;i++) cout<<(char)196;   cout<<(char)194;
	for(int i=0;i<10;i++) cout<<(char)196;   cout<<(char)194;
	for(int i=0;i<10;i++) cout<<(char)196;   cout<<(char)194;
	for(int i=0;i<10;i++) cout<<(char)196;   cout<<(char)191;
	gotoxy(x,y+1); cout<<(char)179<<"STT"<<(char)179<<"   MA SV  "<<(char)179<<"         HO VA TEN        "<<(char)179<<"          "<<(char)179<<"          "<<(char)179<<"          "<<(char)179;
	gotoxy(x,y+2); cout<<(char)195;             //                             "                              "
	for(int i=0;i<3;i++)   cout<<(char)196;   cout<<(char)197 ;
	for(int i=0;i<10;i++) cout<<(char)196;  cout<<(char)197 ;
	for(int i=0;i<26;i++) cout<<(char)196;   cout<<(char)197;
	for(int i=0;i<10;i++) cout<<(char)196;   cout<<(char)197;
	for(int i=0;i<10;i++) cout<<(char)196;   cout<<(char)197;
	for(int i=0;i<10;i++) cout<<(char)196;   cout<<(char)180;
	gotoxy(x,y+3+maxTrang); cout<<(char)192;
	for(int i=0;i<3;i++)  cout<<(char)196;   cout<<(char)193 ;
	for(int i=0;i<10;i++) cout<<(char)196;   cout<<(char)193;
	for(int i=0;i<26;i++) cout<<(char)196;   cout<<(char)193;
	for(int i=0;i<10;i++) cout<<(char)196;   cout<<(char)193;
	for(int i=0;i<10;i++) cout<<(char)196;   cout<<(char)193;
	for(int i=0;i<10;i++) cout<<(char)196;   cout<<(char)217;
	
	for(int i =  0 ; i < maxTrang  ; i++)
	{
		gotoxy( x , y+3+  i );
		cout<<(char)179<<"   "<<(char)179<<"          "<<(char)179<<"                          "<<(char)179<<"          "<<(char)179<<"          "<<(char)179<<"          "<<(char)179;
	}
	}	
///////////////////Thao tac mon hoc //////////////////////////////
const char *filePathMonHoc = "MonHoc.txt";
fstream fileMonHoc;
//Mon Hoc
void KhoiTao(PTRMONHOC &treemh) { treemh = NULL; }

int Insert_node(PTRMONHOC &treemh, MONHOC mh)
{
	if (treemh == NULL)
	{
		treemh = new NODEMONHOC;
		treemh->monhoc = mh;
		treemh->left = NULL;
		treemh->right = NULL;
		return 1;
	}
	else
	{
		if (_stricmp(mh.MAMH, treemh->monhoc.MAMH) < 0)
		{
			Insert_node(treemh->left, mh);
		}
		else if (_stricmp(mh.MAMH, treemh->monhoc.MAMH) > 0)
		{
			Insert_node(treemh->right, mh);
		}
	}
}

PTRMONHOC SearchMaMH(PTRMONHOC &treemh, char *mamh)
{
	PTRMONHOC p = treemh;
	while (p != NULL && (_stricmp(p->monhoc.MAMH, mamh) != 0))
	{
		if (_stricmp(mamh, p->monhoc.MAMH) < 0)
			p = p->left;
		else if (_stricmp(mamh, p->monhoc.MAMH) > 0)
			p = p->right;
	}
	return p;
}

int TongSoMH(PTRMONHOC &treemh)
{
	if (treemh == NULL)
	{
		return 0;
	}
	return 1 + TongSoMH(treemh->left) + TongSoMH(treemh->right);
}
int HamHieuChinhMonHoc(PTRMONHOC &treemh, MONHOC mh)
{
	if (treemh != NULL)
	{
		if (_stricmp(treemh->monhoc.MAMH, mh.MAMH) == 0)
		{
			treemh->monhoc = mh;
			return 1;
		}else {
			HamHieuChinhMonHoc(treemh->left, mh);
			HamHieuChinhMonHoc(treemh->right, mh);
		}
	}
}
int HamXoaMonHoc(PTRMONHOC &treemh, PTRMONHOC p)
{
	if (treemh == NULL) return 0;
	else if (_stricmp(treemh->monhoc.MAMH, p->monhoc.MAMH) > 0) HamXoaMonHoc(treemh->left, p);
	else if (_stricmp(treemh->monhoc.MAMH, p->monhoc.MAMH) < 0) HamXoaMonHoc(treemh->right, p);
	else if (_stricmp(treemh->monhoc.MAMH, p->monhoc.MAMH) == 0)
	{
		if (treemh->left == NULL)
		{
			treemh = treemh->right;
			return 1;
		}
		else if (treemh->right == NULL)
		{
			treemh = treemh->left;
			return 1;
		}
		else if (treemh->left != NULL && treemh->right != NULL)
		{
			PTRMONHOC s = treemh, q = s->left;
			// S la cha cua Q, Q la Node phai nhat cua cay con trai cua P
			if (q->right != NULL)
			{
				while (q->right != NULL)
				{
					s = q;
					q = q->right;
				}
				p->monhoc = q->monhoc;
				s->right = q->left;
			}
			else
			{
				p->monhoc = q->monhoc;
				s->left = q->left;
			}
			delete q;
			return 1;
		}
	}
}

void OpenFileMH()
{
	fileMonHoc.open(filePathMonHoc, ios::out);
}

void GhiFileTongMonHoc(PTRMONHOC &treemh)
{
	int tongsoMH = TongSoMH(treemh);
	fileMonHoc.write((char *)&tongsoMH, sizeof(int));
}

void GhiFileMonHoc(PTRMONHOC &treemh)
{
	if (treemh != NULL)
	{
		fileMonHoc.write((char *)&treemh->monhoc, sizeof(MONHOC));
		GhiFileMonHoc(treemh->left);
		GhiFileMonHoc(treemh->right);
	}
}

void CloseFileMH()
{
	fileMonHoc.close();
}


void DocFileMonHoc(PTRMONHOC &treemh)
{

	MONHOC mh; int tongsoMH = 0;
	fileMonHoc.open(filePathMonHoc, ios::in);
	fileMonHoc.read((char *)&tongsoMH, sizeof(int));
	KhoiTao(treemh);
	if (tongsoMH > 0)
	{
		for (int i = 0; i < tongsoMH; i++)
		{
			fileMonHoc.read((char *)&mh, sizeof(MONHOC));
			Insert_node(treemh, mh);
		}
	}
	fileMonHoc.close();
}

int SearchMaMH(MONHOC mh[],char *mamh, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (_stricmp(mh[i].MAMH, mamh) == 0)
			return i;
	}
	return -1;
}
int SearchMaMHDSTT(PTRMONHOC &treemh, MONHOC mh[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (_stricmp(mh[i].MAMH, treemh->monhoc.MAMH) == 0)
			return i;
	}
	return -1;
}

void DSTTMonHoc(PTRMONHOC &treemh, MONHOC mh[], int &n)
{
	if (treemh != NULL)
	{
		DSTTMonHoc(treemh->left, mh, n);
		if (SearchMaMHDSTT(treemh, mh, n) == -1) { mh[n] = treemh->monhoc; n++; }
		DSTTMonHoc(treemh->right, mh, n);
	}
}

void SapXepMH(MONHOC mh[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (_stricmp(mh[i].TENMH, mh[j].TENMH) > 0)
			{
				MONHOC t = mh[i];
				mh[i] = mh[j];
				mh[j] = t;
			}
		}
	}
}


//*******Them mon hoc**************////////////

//int Them_MH(list_MH &listMH,MONHOC mh,int n){
//	if(n < 0 || n > listMH.n+1 || listMH.n == MAXLIST) return 0;
//	listMH.n= n;
//	listMH.mh[n-1]=mh;
//	return 1;
//}
//*******Kiem tra ma mon hoc**************////////////
//int KiemtraMAMH(list_MH &listMH,char *MAMH){
//	for(int i=0;i<listMH.n;i++)
//	{
//		if(strcmp(listMH.mh[i].MAMH,MAMH)==0)
//		{
//		   return i;
//		}
//	}
//	return -1;
//}
//*******Luu file mon hoc**************////////////

//int Luu_MH(list_MH &listMH,char *tenfile){
//	fstream file;
//	file.open(tenfile,ios::out|ios::binary);
//	if(!file) {  return 0; };
//	for(int i=0;i<listMH.n;i++)
//		file.write((char *)(&listMH.mh[i]),sizeof(MONHOC));
//	file.close();	
//	return 1;
//}
	
//*******Doc file mon hoc**************////////////

//void LayDS_MH(list_MH &listMH,char *tenfile){
//	fstream file;
//	file.open(tenfile,ios::in|ios::binary);
//	if(!file) { cout<<"\nFile"<<tenfile<<" khong ton tai"; return ; };
//	int i=0;
//	MONHOC mh;
//	while(file.peek()!=EOF){
//		i++;
//		file.read((char *)(&mh),sizeof(MONHOC));
//		Them_MH(listMH,mh,i);
//	}
//	file.close();	
//}
//*******Sua mon hoc**************////////////
int Sua_MH(PTRMONHOC &listMH, char *MAMH){
	MONHOC mh;
	char stclt[4],stcth[4];
	int vtmamh=0,vttenmh=0,vtstclt=0,vtstcth=0;
	char c;
	if(MAMH != NULL){
		strcpy(mh.MAMH,MAMH);
		 NHAPTENMH:	        
	        c=HamNhapDuLieu2(24,9,vttenmh,30,mh.TENMH,1);
	        if(c==KEY_ESC)
			{
	        	return 2;
	        }
	        while(strlen(mh.TENMH)==0&&(c==KEY_ENTER||c==KEY_DOWN)){
	        	ThongBao((char *)"Ban Chua Nhap Ten Mon Hoc !!",16,28,25,40);
	        	goto NHAPTENMH;
	        }
	        if(c==KEY_UP)
			{
				goto NHAPTENMH;
	        }
	        if(c==KEY_DOWN)
			{
				goto NHAPSTCLTMH;
	        }
NHAPSTCLTMH:        
	        c=nhap_so2(32,12,vtstclt,stclt);
	        if(c==KEY_ESC)
			{
	        	return 2;
	        }
	        while(strlen(stclt)==0&&(c==KEY_ENTER||c==KEY_DOWN)){
	        	ThongBao((char *)"Ban Chua Nhap STCLT Mon Hoc !!",16,28,25,40);
	        	goto NHAPSTCLTMH;
	        }
	        if(c==KEY_UP)
			{
				goto NHAPTENMH;
	        }
	        if(c==KEY_DOWN)
			{
				goto NHAPSTCTHMH;
	        }
   NHAPSTCTHMH:	        
	        c=nhap_so2(32,15,vtstcth,stcth);
	        if(c==KEY_ESC)
			{
	        	return 2;
	        }
	        if(c==KEY_UP)
			{
				goto NHAPSTCLTMH;
	        }
	        if(c==KEY_DOWN)
			{
				goto NHAPSTCTHMH;
	        }
	        while(strlen(stcth) ==0&&c==KEY_ENTER){
	        	ThongBao((char *)"Ban Chua Nhap STCTH Mon Hoc !!",16,28,25,40);
	        	goto NHAPSTCTHMH;
	        }
	    mh.STCLT=atoi(stclt);
		mh.STCTH=atoi(stcth);       
		HamHieuChinhMonHoc(listMH, mh);
		return 1;
		}
	return 0;
	}
//*******Xoa mon hoc**************////////////
//int Xoa_MH(list_MH &listMH,int vitri){
//	if(vitri!=-1){
//	  if(vitri<listMH.n-1)
//	  {
//	    for(int i=vitri;i<listMH.n-1;i++)
//		  listMH.mh[i]=listMH.mh[i+1];	
//	  }
//	listMH.n--;
//	return 1;
//	}else{
//		return 0;
//	}
//	}
//*******Tim kiem mon hoc**************////////////	
void Timkiem_MH(PTRMONHOC &listMH,PTRMONHOC p){
		gotoxy(5, 43); cout<< ( 1 );
		gotoxy(13,43); cout<<p->monhoc.MAMH ;
		gotoxy(28,43); cout<<p->monhoc.TENMH ;
		gotoxy(58,43); cout<<p->monhoc.STCLT ;
		gotoxy(69,43); cout<<p->monhoc.STCTH ;		
	}
	
//*******Nhap mon hoc**************////////////

//void NhapMH(list_MH &listMH){
//	MONHOC mh;
//	int n =0;
//	char kt[]=" ";
//	cout<<"\nNhap ma mon hoc :"; fflush(stdin); gets(mh.MAMH);
//	while(strcmp(mh.MAMH,kt)!=0){
//		    if(KiemtraMAMH(listMH,mh.MAMH)!=-1){
//		    	cout<<"\nMa mon hoc bi trung!";
//		    	 cout<<"\nNhap ma mon hoc :"; fflush(stdin); gets(mh.MAMH);
//		    	 continue;
//		    	}
//			cout<<"\nNhap ten mon hoc :"; fflush(stdin); gets(mh.TENMH);
//			cout<<"\nNhap so tinh chi li thuyet :"; cin>>mh.STCLT;
//			cout<<"\nNhap so tinh chi thuc hanh :"; cin>>mh.STCTH;
//			n++;
//			Them_MH(listMH,mh,n);
//			cout<<"\nNhap ma mon hoc ke:"; fflush(stdin); gets(mh.MAMH);
//			}
//}
//*******Them lop hoc***************//////////////
int Them_Lop(list_LOP &listLOP,LOP *lop,int n){
	if(n < 0 || n > listLOP.n+1 || listLOP.n ==MAXLIST) return 0;
	listLOP.lop[n-1]=lop;
	listLOP.n=n;
	return 1;
	}
//*******Kiem tra ma lop hoc***************//////////////	
int KiemTra_Lop(list_LOP &listLOP,CHAR * MALOP){
	for(int i=0;i<listLOP.n;i++){
		if(strcmp(listLOP.lop[i]->MALOP,MALOP)==0){
			return i;
		}
	}
	return -1;
}	
//*******Sua lop hoc***************//////////////
int Sua_LOP(list_LOP & listLOP,int vitri,LOP *lop){
	if(vitri!=-1){
	    listLOP.lop[vitri]=lop;
		return 1;
	}else{
		return -1;
	}
}
//*******Xoa lop hoc***************//////////////
int Xoa_LOP(list_LOP & listLOP,int vitri){
	if(vitri!=-1){
	 if(listLOP.lop[vitri]->contro==NULL){
	 	if(vitri<listLOP.n-1)
		 {
		   for(int i =vitri;i<listLOP.n-1;i++)
		      listLOP.lop[i]=listLOP.lop[i+1];
		 }
		listLOP.n--;
		return 1;
		}
		else
		{
			return 0;
		}   
	}
	else
	{
		return -1;
	}
}
//*******Tim kiem lop hoc***************//////////////
int Timkiem_LOP(list_LOP & listLOP,int vitri){
	if(vitri!=-1){
		gotoxy(15,43); cout<< 1;
		gotoxy(21,43); cout<<listLOP.lop[vitri]->MALOP ;
		gotoxy(37,43); cout<<listLOP.lop[vitri]->TENLOP ;
		gotoxy(70,43); cout<<listLOP.lop[vitri]->NIEMKHOA ;
	}
}
//*******Luu file mon hoc**************////////////

int Luu_LOP(list_LOP &listLOP,char *tenfile){
	fstream file;
	file.open(tenfile,fstream::out|fstream::trunc);
	if(!file) { cout<<"\nFile"<<tenfile<<" khong ton tai"; return 0; };
	file<<listLOP.n<<endl;
	for(int i=0;i<listLOP.n;i++) {
		file<<listLOP.lop[i]->MALOP<<endl<<listLOP.lop[i]->NIEMKHOA<<endl<<listLOP.lop[i]->TENLOP<<endl;
	}
//		file.write((char *)(&listLOP.lop[i]),sizeof(LOP));
	file.close();
	return 1;
	}
//*******Doc file lop**************////////////

void LayDS_LOP(list_LOP &listLOP,char *tenfile){
	fstream file;
	file.open(tenfile,fstream::in | fstream::out | fstream::app);
	if(file.fail()) { file.open(tenfile,ios::out|ios::binary); return; };
//std::ifstream file(tenfile);
//	if(!file){cout<<"\n Khong the mo file "<<tenfile; return;};
	int i=0;
	file>>i;
	std::string str = "phan mem";
	while(i >0){
		LOP *lop = new LOP;	
		
		file>>lop->MALOP;
		file>>lop->NIEMKHOA;
		std::getline(file, str);
		std::getline(file, str);
		strcpy(lop->TENLOP, str.c_str());
		lop->contro=NULL;
		listLOP.lop[listLOP.n++] =  lop;
		lop = NULL;
		delete lop;
		i--;
	}

	

	}

//*******Nhap lop hoc***************//////////////
void Nhap_Lop(list_LOP &listLOP){
	LOP *lop = new LOP;
	int n =0;
	 cout<<"\nNhap ma lop :";fflush(stdin); gets(lop->MALOP);
	while(strcmp(lop->MALOP," ")!=0){
	 if(KiemTra_Lop(listLOP,lop->MALOP)!=-1){
	 	cout<<"Ma lop bi trung !";
	 	cout<<"\nNhap ma lop :";fflush(stdin); gets(lop->MALOP);
	 	continue;
	 }
	 cout<<"Nhap ten lop :";fflush(stdin); gets(lop->TENLOP);
	 n++;
	 Them_Lop(listLOP,lop,n);
	 cout<<"Nhap ma lop ke:";fflush(stdin); gets(lop->MALOP);
	}
	delete lop;
}
//*******Xuat lop hoc***************//////////////
void Xuat_Lop(list_LOP &listLOP){
    for(int i=0;i<listLOP.n;i++){
    	cout<<"\nMa lop :"<<listLOP.lop[i]->MALOP;
		cout<<"\nTen lop :"<<listLOP.lop[i]->TENLOP;
    	}
}


//*******Them vao dau danh sach sinh vien**************////////////
int ThemDau_SV(PTRSV &listSV ,SINHVIEN sv){
	PTRSV p =new NODE_SV;
	sv.contro = NULL;
	p->sv=sv;
	p->next=listSV;
	listSV=p;
	return 1;
}
//*******Them vao cuoi danh sach sinh vien**************////////////

void ThemCuoi_SV(PTRSV &listSV ,SINHVIEN sv){
	PTRSV p =new NODE_SV;
	p->sv=sv;
	p->next=NULL;
	if(listSV==NULL){
		listSV = p;
		return;
	}
	PTRSV q,tam;
	for(q=listSV;q!=NULL;q=q->next);
	q->next=p;
}
//*******Kiem tra ma sinh vien**************////////////
PTRSV Kiemtra_SV(list_LOP &listLOP ,char *MASV){
	for(int i=0;i<listLOP.n;i++){
	for(PTRSV p =listLOP.lop[i]->contro;p!=NULL;p=p->next){
		if(strcmp(p->sv.MASV,MASV)==0){
			return p;
		}
	}
	}
	return NULL;
}
//*******Tim vi tri sinh vien trong lop**************////////////
int Timvitri_SV(list_LOP &listLOP ,char *MASV){
	for(int i=0;i<listLOP.n;i++){
	for(PTRSV p =listLOP.lop[i]->contro;p!=NULL;p=p->next){
		if(strcmp(p->sv.MASV,MASV)==0){
			return i;
		}
	}
	}
	return -1;
}
//*******So sinh vien trong lop**************////////////
int Dem_SV(list_LOP &listLOP ,int vitri){
	int dem=0;
	for(PTRSV p =listLOP.lop[vitri]->contro;p!=NULL;p=p->next){
		dem++;
	}
	return dem;
}
//*******Tim kiem sinh vien**************////////////

void TimKiem_SV(list_LOP &listLOP ,char *MASV){
	PTRSV p =Kiemtra_SV(listLOP,MASV);
	if(p!=NULL)
	{
    	gotoxy(6, 43); cout<< ( 1 );
		gotoxy(13,43); cout<<p->sv.MASV ;
		gotoxy(28,43); cout<<p->sv.HO ;
		gotoxy(45,43); cout<<p->sv.TEN ;
		gotoxy(65,43); cout<<p->sv.PHAI ;
    	gotoxy(76,43); cout<<p->sv.SDT ;
	}
}

PTRSV SearchMaSV(list_LOP &listLOP, char *masv)
{
	PTRSV p;
	for (int i = 0; i < listLOP.n; i++)
	{
		for (p = listLOP.lop[i]->contro; p != NULL; p = p->next)
		{
			if (_stricmp(p->sv.MASV, masv) == 0) return p;
		}
	}
	return NULL;
}
//*******Sua sinh vien**************////////////

int Sua_SV(list_LOP &listLOP ,char *MASV){
		int vitri=Timvitri_SV(listLOP,MASV);
	int vttensv=0,vthosv=0,vtgioitinh=0,vtsdt=0;
	char c;
	SINHVIEN sv;
	if(vitri!=-1){
	for(PTRSV p =listLOP.lop[vitri]->contro ;p!=NULL;p=p->next)
	{
		if(strcmp(p->sv.MASV,MASV)==0)
		{
		    VeEditText(30,8,(char *) "       Nhap Ho SV        ");
	        VeEditText(30,11,(char *)"       Nhap Ten SV       ");
	        VeEditText(30,14,(char *)"       Nhap GT SV        ");
	        VeEditText(30,17,(char *)"       Nhap SDT          ");
			strcpy(sv.MASV,MASV);
    NHAPHOSV:       
		    c=HamNhapDuLieu2(32,9,vthosv,20,sv.HO,1);
	        if(c==KEY_ESC)
			{
	        	return 2;
	        }
	        while(strlen(sv.HO)==0&&(c==KEY_ENTER||c==KEY_DOWN))
			{
	        	ThongBao((char *)"Ban Chua Nhap Ho SV !!",16,28,25,36);
	        	goto NHAPHOSV;
	        }
	        if(c==KEY_DOWN)
			{
				goto NHAPTENSV;
	        }
	        if(c==KEY_UP)
			{
				goto NHAPHOSV;
	        }
	
	NHAPTENSV:        
		    c=HamNhapDuLieu2(32,12,vttensv,20,sv.TEN,1);
	        if(c==KEY_ESC)
			{
	        	return 2;
	        }
	        while(strlen(sv.TEN)==0&&(c==KEY_ENTER||c==KEY_DOWN))
			{
	        	ThongBao((char *)"Ban Chua Nhap Ten SV !!",16,28,25,36);
	        	goto NHAPTENSV;
	        }
	        if(c==KEY_DOWN)
			{
				goto NHAPGTSV;
	        }
	        if(c==KEY_UP)
			{
				goto NHAPHOSV;
	        }
	    
	NHAPGTSV:      
		    c=HamNhapDuLieu2(32,15,vtgioitinh,30,sv.PHAI,1);
	        if(c==KEY_ESC)
			{
	        	return 2;
	        }
	        while(strlen(sv.PHAI)==0&&c==KEY_ENTER)
			{
	        	ThongBao((char *)"Ban Chua Nhap Gioi Tinh SV !!",16,28,25,36);
	        	goto NHAPGTSV;
	        }
	        if(c==KEY_UP)
			{
				goto NHAPGTSV;
	        }
	        if(c==KEY_DOWN)
			{
				goto NHAPSDT;
	        }
	NHAPSDT:      
		    c=HamNhapDuLieu2(32,18,vtsdt,30,sv.SDT,1);
	        if(c==KEY_ESC)
			{
	        	return 2;
	        }
	        while(strlen(sv.SDT)==0&&c==KEY_ENTER)
			{
	        	ThongBao((char *)"Ban Chua Nhap SDT SV !!",16,28,25,36);
	        	goto NHAPSDT;
	        }
	        if(c==KEY_UP)
			{
				goto NHAPGTSV;
	        }
	        if(c==KEY_DOWN)
			{
				goto NHAPSDT;
	        }
			p->sv=sv;
			return 1;
		}
	}
	}
	return 0;
}
//*******Xoa sinh vien**************////////////
int Xoa_SV(list_LOP &listLOP ,char *MASV){
	PTRSV q,truoc;
	int dem=0,check=0;
	int vitri=Timvitri_SV(listLOP,MASV);
	if(vitri!=-1)
	{
	q=listLOP.lop[vitri]->contro;
	while(q!=NULL&&strcmp(q->sv.MASV,MASV)!=0)
	{
		check++;
		truoc = q;
		q=q->next;
		if(q!=NULL&&strcmp(q->sv.MASV,MASV)==0){
			dem++;
		}
	}
	if(check == 0)
	{
	 listLOP.lop[vitri]->contro =q->next;
	 }
	else
	if(check > 0 && dem > 0)
	{
	 truoc->next=q->next;
	 }
	 delete q;
	 return 1;
    }
	return 0;
}
//*******Xuat danh sach sinh vien**************////////////

void Xuat_SV(list_LOP &listLOP){
	for(int i=0;i<listLOP.n;i++){
	for(PTRSV p =listLOP.lop[i]->contro;p!=NULL;p=p->next)
	{
	    cout<<"\nMa sinh vien :"<<(p->sv.MASV);
		cout<<"\nHo ten sinh vien :"<<(p->sv.HO)<<" "<<(p->sv.TEN);
		cout<<"\nNhap gioi tinh :"<<(p->sv.PHAI);
	}
}
}
//*******Luu danh sach sinh vien**************////////////
int LuuDS_SV(list_LOP &listLOP,char *tenfile){
	fstream file;
	SINHVIEN sv;
	file.open(tenfile,ios::out|ios::binary|ios::trunc);
	if(!file) 
	{
		cout<<"\n Khong the mo file "<<tenfile; return 0;
	}
	for(int i =0;i<listLOP.n;i++)
	{
	  for(PTRSV p =listLOP.lop[i]->contro;p!=NULL;p=p->next)
	  {
		sv =p->sv;
		sv.contro=NULL;
//		cout<<(char*)(&i);
		file.write((char*)(&i),sizeof(int));
		file.write((char*)(&sv),sizeof(SINHVIEN));
	  }
	}
	file.close();
	return 1;
}
//*******Lay danh sach sinh vien tu file**************////////////
void LayDS_SV(list_LOP &listLOP,char *tenfile){
	fstream file;
	file.open(tenfile,ios::in|ios::binary);
//	if(file.fail()) { file.open(tenfile,ios::out|ios::binary); return; };
	if(!file){cout<<"\n Khong the mo file "<<tenfile; return;};
	SINHVIEN sv;
	int n;
	for ( int i = 0 ; i < listLOP.n  ; i++ )
	{
		listLOP.lop[i]->contro = NULL;
	}
	while(file.peek()!=EOF){	
	    file.read((char*)(&n),sizeof(int));
	    file.read((char*)(&sv),sizeof(SINHVIEN));
	    sv.contro=NULL;
	    ThemDau_SV(listLOP.lop[n]->contro,sv);
	}
	file.close();
}
//*******Lay danh sach sinh vien tu file**************////////////
void Nhap_SV(PTRSV &listSV,list_LOP &listLOP){
	SINHVIEN sv;
	char kt[]=" ";
	cout<<"\nNhap ma sinh vien :"; fflush(stdin); gets(sv.MASV);
	while(strcmp(sv.MASV," ")!=0){
		if(Kiemtra_SV(listLOP,sv.MASV)!=NULL)
		{
			cout<<"ma sinh vien bi trung!";
			cout<<"\nNhap ma sinh vien lai:"; fflush(stdin); gets(sv.MASV);
			continue;
		}
	    cout<<"Nhap ho sinh vien :"; fflush(stdin); gets(sv.HO);
		cout<<"Nhap ten sinh vien :"; fflush(stdin); gets(sv.TEN);
		cout<<"Nhap gioi tinh :"; fflush(stdin); gets(sv.PHAI);
		ThemDau_SV(listSV,sv);
		cout<<"Nhap ma sinh vien ke:"; fflush(stdin); gets(sv.MASV);
	}
	
}
//*******Sap xep sach sinh vien theo chu cai**************////////////
void Sapxep_SV(list_LOP &listLOP,int vitri){
	
	PTRSV q,p,minp;
	SINHVIEN min;
	char homin[30];
	char tenmin[30];
    char ho[30];
    char ten[30];
	for(PTRSV q=listLOP.lop[vitri]->contro;q!=NULL;q=q->next)
	{
		min =q->sv;
		minp=q;
	  for(p=q->next;p!=NULL;p=p->next)
	  {
	  	 strcpy(homin,min.HO);
	  	 strcpy(tenmin,min.TEN);
	  	 strcpy(ho,p->sv.HO);
	  	 strcpy(ten,p->sv.TEN);
	  	 if(strcmp(strupr(strcat(strcat(tenmin," "),homin)),
		   strupr(strcat(strcat(ten," "),ho)))==1)
		   {
		   	min = p->sv;
		   	minp=p;
		   }
	  }
	  minp->sv=q->sv;
	  q->sv=min;	
	}
	
}
//*******Menu chuc nang mon hoc**************////////////

char menu_SV(){
	char chucnangsv;
	do
	{
		system("cls");
		cout<<"\n\t\t*********CHUONG TRINH QUAN LY SINH VIEN**********\n";
		cout<<"\t\t***                                           ***\n";
		cout<<"\t\t***    CAC THAO TAC TREN DANH SACH SINH VIEN: ***\n";
		cout<<"\t\t***\t1:  Hien thi danh sach sinh vien      ***\n";
		cout<<"\t\t***\t2:  Them sinh vien moi                ***\n";
		cout<<"\t\t***\t3:  Sua sinh vien                     ***\n";
		cout<<"\t\t***\t4:  Xoa sinh vien                     ***\n";
		cout<<"\t\t***\t5:  Tim kiem sinh vien                ***\n"; 
		cout<<"\t\t***\t6:  Sap xep sinh vien                 ***\n"; 
		cout<<"\t\t***\t0:  Quay ve menu chinh                ***\n";
		cout<<"\t\t*************************************************\n";
		cout<<"\n\tchuc nang ban chon:";
		chucnangsv=getche();
	}
	while(chucnangsv<'0' || chucnangsv>'6');
	return chucnangsv;
}

//*******Thao tac diem**************////////////

//*******Them vao dau danh sach diem**************////////////
void ThemDau_DIEM(PTRDIEM &listDIEM ,DIEM diem){
	PTRDIEM p =new NODE_DIEM;
	p->diem=diem;
	p->next=listDIEM;
	listDIEM=p;
}


//*******Tim kiem diem sinh vien**************////////////

//void TimKiem_DIEM(PTRDIEM &listDIEM ,char *MASV,char *MAMH){
//	int kt=0;
//	for(PTRDIEM p =listDIEM;p!=NULL;p=p->next)
//	{
//		if(strcmp(p->diem.MASV,MASV)==0&&strcmp(p->diem.MAMH,MAMH)==0)
//		{
//    	  cout<<"\nMa sinh vien :"<<(p->diem.MASV);
//		  cout<<"\nMa mon hoc :"<<(p->diem.MAMH);
//		  cout<<"\nDiem sinh vien :"<<(p->diem.DIEMSV);
//		  cout<<"\nLan thi :"<<(p->diem.LAN);
//		  kt++;
//        }
//    }
//    if(kt==0)
//	{
//   	   cout<<"\nKhong tim thay sinh vien !";
//    }
//}

//*******Xoa tat ca diem co ma sinh vien**************////////////
//int Xoa_ALL_DIEM(PTRDIEM &listDIEM ,char *MASV){
//	PTRDIEM p,q; int dem=0;
//	while(listDIEM!=NULL&&(listDIEM->diem.MASV,MASV)==0)
//	{
//		p=listDIEM ; 
//		dem++;
//		listDIEM=listDIEM->next;
//		delete p;
//	}
//	if(listDIEM==NULL) return dem;
//	p=listDIEM;
//	while(p->next!=NULL)
//	{
//		if(strcmp(p->next->diem.MASV,MASV)==0)
//		{
//			q=p->next;
//			p->next =q->next;
//			delete q;
//			dem++;
//		}
//		else
//		{
//			p=p->next;
//		}
//	}
//	return dem;
//}
//*******Xoa tat ca diem co ma sinh vien va ma mon hoc**************////////////
//int Xoa_ALL_DIEM_MH(PTRDIEM &listDIEM ,char *MASV,char *MAMH){
//	PTRDIEM p,q; int dem=0;
//	while(listDIEM!=NULL&&(listDIEM->diem.MASV,MASV)==0&&strcmp(listDIEM->diem.MAMH,MAMH)==0)
//	{
//		p=listDIEM ; 
//		listDIEM=listDIEM->next;
//		dem++;
//		delete p;
//	}
//	if(listDIEM==NULL) return dem;
//	p=listDIEM;
//	while(p->next!=NULL)
//	{
//		if(strcmp(p->next->diem.MASV,MASV)==0&&strcmp(p->next->diem.MAMH,MAMH)==0)
//		{
//			q=p->next;
//			p->next =q->next;
//			delete q;
//			dem++;
//		}
//		else
//		{
//			p=p->next;
//		}
//	}
//	return dem;
//}
//*******Xoa tat ca diem co ma sinh vien**************////////////
int Xoa_MH_DIEM(PTRDIEM listDIEM ,char *MAMH){
	PTRDIEM p,q; int dem=0;
	while(listDIEM!=NULL&&strcmp(listDIEM->diem.MAMH,MAMH)==0)
	{
		p=listDIEM ; 
		dem++;
		listDIEM=listDIEM->next;
		delete p;
	}
	if(listDIEM==NULL) return dem;
	p=listDIEM;
	while(p->next!=NULL)
	{
		if(strcmp(p->next->diem.MAMH,MAMH)==0)
		{
			q=p->next;
			p->next =q->next;
			delete q;
			dem++;
		}
		else
		{
			p=p->next;
		}
	}
	return dem;
}
int TongMonHocmotSV(PTRDIEM p)
{
	int tongso = 0;
	for (PTRDIEM First = p; First != NULL; First = First->next)
	{
		tongso++;
	}
	return tongso;
}

//*******Luu danh sach diem**************////////////
int LuuDS_DIEM(list_LOP &listLOP,char *tenfile){
	fstream file;
	DIEM diem;
	SINHVIEN sv;
	file.open(tenfile,fstream::out|fstream::trunc);
	if(!file) 
	{
	   return 0;
	}
//	for(int i =0;i<listLOP.n;i++)
//	{
//	  for(PTRSV p =listLOP.lop[i]->contro;p!=NULL;p=p->next)
//	  {
//		sv =p->sv;
//		file.write((char*)(&sv),sizeof(SINHVIEN));
//		cout<<(char*)(&i);
//		for(PTRDIEM q =p->sv.contro;q!=NULL;q=q->next)
//		{
//			file.write((char*)(&sv),sizeof(SINHVIEN));
//			diem =q->diem;
//			file.write((char*)(&diem),sizeof(DIEM));
//		}
//	  }
//	}

	for(int i =0;i<listLOP.n;i++)
	{
	  for(PTRSV p =listLOP.lop[i]->contro;p!=NULL;p=p->next)
	  {
		int somh = TongMonHocmotSV(p->sv.contro);
//		file.write((char *)&somh, sizeof(int));
			
		if (somh > 0)
		{
			file<<somh<<endl;
			for (PTRDIEM q = p->sv.contro; q != NULL; q = q->next)
			{
//				file.write((char *)&q->diem, sizeof(DIEM));
				file<<q->diem.LAN<<endl<<q->diem.DIEMSV<<endl<<q->diem.MAMH<<endl;
				
			}
		}
	  }
	}
	file<<'\0';

	file.close();
	return 1;
}

//*******Lay danh sach diem sinh vien tu file**************////////////
void LayDS_DIEM(list_LOP &listLOP,char *tenfile){
	fstream file;
	file.open(tenfile,ios::in|ios::binary);
//	if(file.fail()) { file.open(tenfile,ios::out|ios::binary); return; };
	if(!file){cout<<"\n Khong the mo file "<<tenfile; return;};
	
	SINHVIEN sv;
	int siso, somh;
//	int n;
while(file.peek()!=EOF )
		{
for (int i = 0; i < listLOP.n; i++)
{
		
	 for(PTRSV p =listLOP.lop[i]->contro;p!=NULL;p=p->next)
	  {
	  		
			file>>somh;		
			
		
	//		file.read((char *)&somh, sizeof(int));
			if (somh > 0)
			{
				p->sv.contro = NULL;
				for (int k = 0; k < somh; k++)
				{
				DIEM diem;
				file>>diem.LAN>>diem.DIEMSV>>diem.MAMH;
	//				file.read((char *)&diem, sizeof(DIEM));
					ThemDau_DIEM(p->sv.contro, diem);
					
					
				}
			}
		}
	}
}
//	
//	while(file.peek()!=EOF)
//	{
//		file.read((char*)(&sv),sizeof(SINHVIEN));
//	    file.read((char*)(&diem),sizeof(DIEM));
//	    ThemDau_DIEM(sv.contro,diem);	
//	    
//	}
	
	file.close();
}

//*******Thao tac menu lop**************////////////
void thaotacmenuLOP(list_LOP &listLOP)
{

	int tongtrang,trang=0;
	int vitri=-1;
	int vtmalop=0,vttenlop=0,vtnienkhoa=0;
	int stclt,stcth;
	char COKHONG[][10]={"CO","KHONG"};
	char key,c;
	listLOP.n=0;
	char tenfilelop[]="LOP.txt";
	char tenfilesv[]="SINHVIEN.txt";
	LayDS_LOP(listLOP,tenfilelop);
	LayDS_SV(listLOP,tenfilesv);
	while(1)
//	LOP *lop = new LOP;
	{
XUATDS:	
	LOP *lop = new LOP;
    vtmalop=0,vttenlop=0,vtnienkhoa=0;
    setcolor(16,15);
    system("cls");
    setcolor(28,15);
    gotoxy(25,1);cout<<"                              ";
	gotoxy(25,2);cout<<"         DANH SACH LOP        ";
	gotoxy(25,3);cout<<"                              ";
	if(listLOP.n < 15)
	{
		tongtrang=1;
	}
	else
	{
		tongtrang =listLOP.n/15 +1;
	}
	BangLOP(15,12,5);
    HienThiTrang( tongtrang, trang , 20 ,24 ,16,14 , 15);
    cout<<"["<<(char)24<<"]"<<" Tro Lai | Tiep Theo ["<<(char)25<<"]";
	setcolor(16,15);
	int dong=-1;
	
	for(int i=trang*15;i<15+15*trang&&i<listLOP.n;i++)
	{
		gotoxy(15, 9+dong); cout<< ( i +1 );
		gotoxy(21,9+dong); cout<<listLOP.lop[i]->MALOP ;
		gotoxy(37,9+dong); cout<<listLOP.lop[i]->TENLOP ;
		gotoxy(70,9+dong); cout<<listLOP.lop[i]->NIEMKHOA ;
		dong++;
	}
	if(listLOP.n < 0)
	{
		ThongBao((char *)"Chua co lop trong danh sach !",16,28,25,40);
	}
	MenuChucNang(MENUCHUCNANG,MENUCHUCNANGCHU,28,15,15,2,15,6,1);
	do
	{
		key=getch();
	}
	while(key!=KEY_F1&&key!=KEY_F2&&key!=KEY_F3&&key!=KEY_F4&&key!=KEY_ESC&&key!=KEY_DOWN&&key!=KEY_UP);
	
	switch(key)
	{
		
		char malop[30],tenlop[40],nienkhoa[10];
		case KEY_DOWN:
			if( tongtrang > 1  && trang + 1 < tongtrang )
				{
					trang ++ ;
					goto XUATDS;
				}
			break;
			case KEY_UP:
			if( tongtrang > 1  && trang > 0 )
				{
					trang -- ;
					goto XUATDS;
				}
			break;
		case KEY_F1:
			VeNutChucNang(0,MENUCHUCNANG,15,16);
			NhapLop();
  NHAPMALOP:      
		    c=HamNhapDuLieu2(24,6,vtmalop,10,lop->MALOP,0);
	        if(c==KEY_ESC)
			{
	        	goto XUATDS;
	        }
	        while(strlen(lop->MALOP)==0&&(c==KEY_ENTER||c==KEY_DOWN))
			{
	        	ThongBao((char *)"Ban Chua Nhap Ma Lop !!",16,28,25,40);
	        	goto NHAPMALOP;
	        }
	        while(KiemTra_Lop(listLOP,lop->MALOP)!=-1)
			{
				ThongBao((char *)"Ma Lop Da Ton Tai !!",16,28,25,40);
	        	goto NHAPMALOP;
	        }
	        if(c==KEY_UP)
			{
				goto NHAPMALOP;
	        }
	        if(c==KEY_DOWN)
			{
				goto NHAPTENLOP;
	        }
   NHAPTENLOP:	        
	        c=HamNhapDuLieu2(24,9,vttenlop,30,lop->TENLOP,1);
	        if(c==KEY_ESC)
			{
	        	goto XUATDS;
	        }
	        while(strlen(lop->TENLOP)==0&&(c==KEY_ENTER))
			{
	        	ThongBao((char *)"Ban Chua Nhap Ten Lop !!",16,28,25,40);
	        	goto NHAPTENLOP;
	        }
	        if(c==KEY_UP)
			{
				goto NHAPMALOP;
	        }
	        if(c==KEY_DOWN)
			{
				goto NHAPNIENKHOA;
	        }
//	        if(Them_Lop(listLOP,lop,listLOP.n+1)==1)
//			{
//	        	ThongBao((char *)"Them Lop Hoc Thanh cong !!",16,28,25,40);
//	        }
//			else
//			{
//	        	ThongBao((char *)"Het Bo Nho Lop !!",16,28,25,40);	
//	        }
	NHAPNIENKHOA:
			c=nhap_so2(24,12,vtnienkhoa,nienkhoa);
	        if(c==KEY_ESC)
			{
	        	goto XUATDS;
	        }
	        while(strlen(nienkhoa)==0&&(c==KEY_ENTER))
			{
	        	ThongBao((char *)"Ban Chua Nhap Nien Khoa !!",16,28,25,40);
	        	goto NHAPNIENKHOA;
	        }
	        if(c==KEY_UP)
			{
				goto NHAPTENLOP;
	        }
	        if(c==KEY_DOWN)
			{
				goto NHAPNIENKHOA;
	        }
	        lop->NIEMKHOA= atoi(nienkhoa);
	        if(Them_Lop(listLOP,lop,listLOP.n+1)==1)
			{
			
	        	ThongBao((char *)"Them Lop Hoc Thanh cong !!",16,28,25,40);
	        }
			else
			{
				
	        	ThongBao((char *)"Het Bo Nho Lop !!",16,28,25,40);	
	        }
	        lop= NULL;
			delete lop;
			break;
		case KEY_F2:
			VeNutChucNang(1,MENUCHUCNANG,15,16);
			VeEditText(22,5,(char *)"            Nhap Ma Lop           ");
			c=HamNhapDuLieu(24,6,10,lop->MALOP,0);
	        if(c==KEY_ESC)
			{
	        	goto XUATDS;
	        }
	        while(strlen(lop->MALOP)==0&&c==KEY_ENTER)
			{
	        	ThongBao((char *)"Ban Chua Nhap Ma Lop !!",16,28,25,40);
	        	c=HamNhapDuLieu(24,6,10,lop->MALOP,0);
	        }
			vitri=KiemTra_Lop(listLOP,lop->MALOP);
			if(vitri!=-1)
			{
				VeEditText(22,8,(char *)"            Nhap Ten Lop          ");
				c=HamNhapDuLieu(24,9,30,lop->TENLOP,1);
			
	        	if(c==KEY_ESC)
				{
	        		goto XUATDS;
	       		}
		        while(strlen(lop->TENLOP)==0&&c==KEY_ENTER)
				{
		        	ThongBao((char *)"Ban Chua Nhap Ten Lop !!",16,28,25,40);
		        	c=HamNhapDuLieu(24,9,30,lop->TENLOP,1);
		        }
		        VeEditText(22,11,(char *)"            Nhap Nien Khoa        ");
		        c=nhap_so2(24,12,vtnienkhoa,nienkhoa);
		        if(c==KEY_ESC)
				{
		        	goto XUATDS;
		        }
		        while(strlen(nienkhoa)==0&&(c==KEY_ENTER))
				{
		        	ThongBao((char *)"Ban Chua Nhap Nien Khoa !!",16,28,25,40);
		        	c=nhap_so2(24,12,vtnienkhoa,nienkhoa);
		        }
		        lop->NIEMKHOA= atoi(nienkhoa);
			
		        Sua_LOP(listLOP,vitri,lop);
		        lop= NULL;
				delete lop;
		        ThongBao((char *)"Sua Thanh Cong Lop !!",16,28,25,40);
			}
			else
			{
				ThongBao((char *)"Khong Tim Thay Ma Lop !!",16,28,25,40);		
			}
			break;	
		case KEY_F3:
			VeNutChucNang(2,MENUCHUCNANG,15,16);
			VeEditText(30,5,(char *)"    Nhap Ma Lop    ");
			c=HamNhapDuLieu(32,6,10,malop,0);
	        if(c==KEY_ESC)
			{
	        	goto XUATDS;
	        }
	         while(strlen(malop)==0&&c==KEY_ENTER)
			{
	        	ThongBao((char *)"Ban Chua Nhap Ma Lop !!",16,28,25,40);
	        	c=HamNhapDuLieu(32,6,10,malop,0);
	        }
			vitri=KiemTra_Lop(listLOP,malop);
			if(vitri!=-1)
			{
				int kq=HopThoaiYESNO((char *)"Ban Co Muon Xoa Lop ?",COKHONG,24,7,3,15,15,15);
				if(kq==1)
				{
					int n=Xoa_LOP(listLOP,vitri);
					if(n==1)
					{
					   ThongBao((char *)"Xoa Thanh Cong Lop !!",16,28,25,40);
					}
					else
					if(n==0)
					{
						ThongBao((char *)"Lop Co Sinh Vien Khong Xoa Duoc !!",16,28,25,40);
					}
					else
					{
						ThongBao((char *)"Xoa That Bai Lop !!",16,28,25,40);
					}
					}
			}
			else
			{
				ThongBao((char *)"Khong Tim Thay Ma Lop !!",16,28,25,40);		
			}
			break;	
			
		case KEY_F4:
			VeNutChucNang(3,MENUCHUCNANG,15,16);
			VeEditText(30,5,(char *)"    Nhap Ma Lop    ");
			c=HamNhapDuLieu(32,6,10,malop,0);
	        if(c==KEY_ESC)
			{
	        	goto XUATDS;
	        }
	        while(strlen(malop)==0&&c==KEY_ENTER)
			{
	        	ThongBao((char *)"Ban Chua Nhap Ma Lop !!",16,28,25,40);
	        	c=HamNhapDuLieu(32,6,10,malop,0);
	        }
			vitri=KiemTra_Lop(listLOP,malop);
			if(vitri!=-1)
			{
				BangLOP(2,12,40);
				Timkiem_LOP(listLOP,vitri);
				do
				{
					c=getch();
				}
				while(c!=KEY_ENTER&&c!=KEY_ESC);
				goto XUATDS; 	
			}
			else
			{
				ThongBao((char *)"Khong Tim Thay Ma Lop !!",16,28,25,40);		
			}
			break;
		case KEY_ESC:
			delete lop;
			VeNutChucNang(5,MENUCHUCNANG,15,16);
			int kq=HopThoaiYESNO((char *)"Ban co muon Luu Du Lieu Vao File ?",COKHONG,19,7,3,15,15,15);
			if(kq==1) 
			{
				if(Luu_LOP(listLOP,tenfilelop)==1)
				{
					ThongBao((char *)"Luu File Thanh Cong !!",16,28,25,40);	
				}
				else
				{
				   ThongBao((char *)"Luu File That Bai !!",16,28,25,40);		
				}
			}
			if(kq==1||kq==0)
			return;
			break;	
	}
   
  }	
} 

void HienThiGoiYLop(list_LOP &listLOP ,int background,int textcolor,int x,int y){
	int tongtrang,trang=0;
	char key;
    if(listLOP.n ==0)
	{
		ThongBao((char *)"Chua co lop trong danh sach !",16,28,25,15);
	}
	else
	{
	if(listLOP.n < 15){
		tongtrang=1;
	}
	else
	{
		tongtrang =listLOP.n/15 +1;
	}
XUAT:
    	
    setcolor(background,textcolor);
	BangLOP(15,x,y);
	setcolor(16,15);
	int dong=-1;
	
	for(int i=trang*15;i<15+15*trang&&i<listLOP.n;i++)
	{
		gotoxy(x+3,y+4+dong); cout<< ( i +1 );
		gotoxy(x+9,y+4+dong); cout<<listLOP.lop[i]->MALOP ;
		gotoxy(x+23,y+4+dong); cout<<listLOP.lop[i]->TENLOP ;
		gotoxy(x+56,y+4+dong); cout<<listLOP.lop[i]->NIEMKHOA ;
		dong++;
	}
	HienThiTrang( tongtrang, trang , x+5 ,y+19 ,16,14 , 15);
	cout<<"["<<(char)24<<"]"<<" Tro Lai | Tiep Theo ["<<(char)25<<"]";
	do
	{
		key=getch();
	}
	while(key!=KEY_ESC&&key!=KEY_DOWN&&key!=KEY_UP);
	switch(key)
	{
		case KEY_ESC:
			return ;
			break;
		case KEY_DOWN:
			if(tongtrang > 1 && (trang + 1 )< tongtrang)
				trang++;
			goto XUAT;
		    break;	
		case KEY_UP:
		   if ( tongtrang > 1 && (trang > 0 ) ) 
				trang --;
			goto XUAT; 	
		    break;    
	}
}
}
void NhapMaLOpSV(int x,int y){
	char c;
	int vitri=-1;
	char malop[30];
	char textmenu[][30]={"THOAT","XEM LOP"};
	char menu[][30]={"ESC","F5"};
	for(int i=0;i<2;i++)
	{
	 setcolor(28,15);
	 gotoxy(x+20*i,y);
	 cout<<"      ";
	 gotoxy(x+20*i,y+1);
	 cout<<"      ";
	 gotoxy(x+20*i,y+2);
	 cout<<"      ";
	 gotoxy(x+20*i,y+1);
	 cout<<"  "<<menu[i];
	 
	 setcolor(16,15);
	 gotoxy((x+7)+20*i,y);
	 cout<<"      ";
	 gotoxy((x+7)+20*i,y+1);
	 cout<<"      ";
	 gotoxy((x+7)+20*i,y+2);
	 cout<<"      ";
	 gotoxy((x+7)+20*i,y+1);
	 cout<<""<<textmenu[i];
     }
     VeEditText(30,5,(char *)"    Nhap Ma Lop    ");
}    
//*******Thao tac menu SV**************////////////
void thaotacmenuSV(list_LOP &listLOP,PTRDIEM &listDIEM)
{
	setcolor(16,15);
	system("cls");
	int tongtrang,trang=0;
	int vitri=-1;
	int vtmasv=0,vttensv=0,vthosv=0,vtgioitinh=0,vtsdt=0;
	char menu[][30]={"ESC","F5"};
	int x=20;
	int y=18;
	int kq=0;
	char masv[30],malop[30],sdt[30];
	int stclt,stcth;
	char COKHONG[][10]={"CO","KHONG"};
	char key,c;
	char tenfilelop[]="LOP.txt";
	char tenfilesv[]="SINHVIEN.txt";
	listLOP.n=0;
	LayDS_LOP(listLOP,tenfilelop);
	LayDS_SV(listLOP,tenfilesv);
//	char tenfile[]="DIEM.txt";
//	LayDS_DIEM(listLOP,tenfile);
	
	setcolor(28,15);
    gotoxy(25,1);cout<<"                              ";
	gotoxy(25,2);cout<<"      DANH SACH SINH VIEN     ";
	gotoxy(25,3);cout<<"                              ";
NHAPMALOP:
	NhapMaLOpSV(20,18);
	c=HamNhapDuLieu(32,6,10,malop,0);
    switch(c)
	 {
	  	case KEY_F5:
	  		setcolor(15,28);
	        gotoxy(x+20,y);
	        cout<<"      ";
	        gotoxy(x+20,y+1);
	        cout<<"      ";
	        gotoxy(x+20,y+2);
	        cout<<"      ";
	        gotoxy(x+20,y+1);
	        cout<<"  "<<menu[1];
	        
	        HienThiGoiYLop(listLOP,16,15,x-5,5+y);
	        
	        setcolor(16,16);
			for ( int i = 0 ; i <  x+5 ; i++)
			{
				for ( int j = 0 ; j < y+50 ; j++ )
				{
					 gotoxy (3 + j,21 + i  ) ;cout<<" ";
				}
					Sleep(25);
			}
	        goto NHAPMALOP;
	  		break;
	  	case KEY_ESC :
	  		return;
	  		break;
	  	case KEY_ENTER:
	  		vitri=KiemTra_Lop(listLOP,malop);
	  		if(vitri==-1)
			  {
	  			ThongBao((char *)"Khong Tim Thay Ma Lop !",16,28,25,15);
	  			goto NHAPMALOP;
	  		  }
		    break;		
	  }	
	while(1)
	{
XUATDS:	
    vtmasv=0;
	vthosv=0;
	vttensv=0;
	vtgioitinh=0;
	vtsdt=0;
    setcolor(16,15);
    system("cls");
    setcolor(28,15);
    gotoxy(25,1);cout<<"                              ";
	gotoxy(25,2);cout<<"      DANH SACH SINH VIEN     ";
	gotoxy(25,3);cout<<"                              ";
	setcolor(16,14);
	gotoxy(3,5);  cout<<" LOP : "<<listLOP.lop[vitri]->TENLOP ;
    int soluong=0;
	SINHVIEN sv[MAXLIST];
	Sapxep_SV(listLOP,vitri);
	for(PTRSV p=listLOP.lop[vitri]->contro;p!=NULL;p=p->next)
	{
		sv[soluong]=p->sv; soluong++;
	}
	if(soluong < 15)
	{
		tongtrang=1;
	}
	else
	{
		tongtrang =soluong/15 +1;
	}
	BangSV(15,4,6);
    HienThiTrang( tongtrang, trang , 20 ,25 ,16,14 , 15);
    cout<<"["<<(char)24<<"]"<<" Tro Lai | Tiep Theo ["<<(char)25<<"]";
	setcolor(16,15);
	int dong=-1;
	
	for(int i=trang*15;i<15+15*trang&&i<soluong;i++)
	{
		gotoxy(6, 10+dong); cout<< ( i +1 );
		gotoxy(13,10+dong); cout<<sv[i].MASV ;
		gotoxy(28,10+dong); cout<<sv[i].HO ;
		gotoxy(45,10+dong); cout<<sv[i].TEN ;
		gotoxy(65,10+dong); cout<<sv[i].PHAI ;
		gotoxy(76,10+dong); cout<<sv[i].SDT ;
		dong++;
	}
	if(listLOP.lop[vitri]->contro ==NULL)
	{
		ThongBao((char *)"Chua Sinh Vien Trong Lop Nay !",16,28,25,38);
	}
	MenuChucNang(MENUCHUCNANG,MENUCHUCNANGCHU,28,15,15,2,16,6,1);
	do
	{
		key=getch();
	}
		while(key!=KEY_F1&&key!=KEY_F2&&key!=KEY_F3&&key!=KEY_F4&&key!=KEY_ESC&&key!=KEY_DOWN&&key!=KEY_UP);
	
	switch(key){
		SINHVIEN sv;
		case KEY_DOWN:
			if( tongtrang > 1  && trang + 1 < tongtrang )
				{
					trang ++ ;
					goto XUATDS;
				}
			break;
		case KEY_UP:
			if( tongtrang > 1  && trang > 0 )
				{
					trang -- ;
					goto XUATDS;
				}
			break;	
		case KEY_F1:
			VeNutChucNang(0,MENUCHUCNANG,15,16);
			NhapSinhVien();
	NHAPMASV:   
		    c=HamNhapDuLieu2(32,6,vtmasv,10,sv.MASV,0);
	        if(c==KEY_ESC)
			{
	        	goto XUATDS;
	        }
	        while(strlen(sv.MASV)==0&&(c==KEY_ENTER||c==KEY_DOWN))
			{
	        	ThongBao((char *)"Ban Chua Nhap Ma SV !!",16,28,25,38);
	        	c=HamNhapDuLieu2(32,6,vtmasv,10,sv.MASV,0);
	        }
	        while(Kiemtra_SV(listLOP,sv.MASV)!=NULL)
			{
				ThongBao((char *)"Ma SV da ton tai !!",16,28,25,38);
	        	goto NHAPMASV;
	        }
	        if(c==KEY_UP)
			{
				goto NHAPMASV;
	        }
	        if(c==KEY_DOWN)
			{
				goto NHAPHOSV;
	        }
	NHAPHOSV:       
		    c=HamNhapDuLieu2(32,9,vthosv,20,sv.HO,1);
	        if(c==KEY_ESC)
			{
	        	goto XUATDS;
	        }
	        while(strlen(sv.HO)==0&&(c==KEY_ENTER||c==KEY_DOWN))
			{
	        	ThongBao((char *)"Ban Chua Nhap Ho SV !!",16,28,25,38);
	        	goto NHAPHOSV;
	        }
	        if(c==KEY_DOWN)
			{
				goto NHAPTENSV;
	        }
	        if(c==KEY_UP)
			{
				goto NHAPMASV;
	        }
	
	NHAPTENSV:        
		    c=HamNhapDuLieu2(32,12,vttensv,20,sv.TEN,1);
	        if(c==KEY_ESC)
			{
	        	goto XUATDS;
	        }
	        while(strlen(sv.TEN)==0&&(c==KEY_ENTER||c==KEY_DOWN))
			{
	        	ThongBao((char *)"Ban Chua Nhap Ten SV !!",16,28,25,38);
	        	goto NHAPTENSV;
	        }
	        if(c==KEY_DOWN)
			{
				goto NHAPGTSV;
	        }
	        if(c==KEY_UP)
			{
				goto NHAPHOSV;
	        }
	    
	NHAPGTSV:      
		    c=HamNhapDuLieu2(32,15,vtgioitinh,30,sv.PHAI,1);
	        if(c==KEY_ESC)
			{
	        	goto XUATDS;
	        }
	        while(strlen(sv.PHAI)==0&&c==KEY_ENTER)
			{
	        	ThongBao((char *)"Ban Chua Nhap Gioi Tinh SV !!",16,28,25,38);
	        	goto NHAPGTSV;
	        }
	        if(c==KEY_UP)
			{
				goto NHAPTENSV;
	        }
	        if(c==KEY_DOWN)
			{
				goto NHAPSDT;
	        }
	       
//	        if(ThemDau_SV(listLOP.lop[vitri].contro,sv))
//			{
//	        	ThongBao((char *)"Them Sinh Vien Thanh cong !!",16,28,25,38);
//	        }
//			else
//			{
//	        	ThongBao((char *)"Het Bo Nho Lop !!",16,28,25,38);	
//	        }
		NHAPSDT:      
		    c=HamNhapDuLieu2(32,18,vtsdt,30,sv.SDT,1);
	        if(c==KEY_ESC)
			{
	        	goto XUATDS;
	        }
	        while(strlen(sv.SDT)==0&&c==KEY_ENTER)
			{
	        	ThongBao((char *)"Ban Chua Nhap Sdt SV !!",16,28,25,38);
	        	goto NHAPSDT;
	        }
	        if(c==KEY_UP)
			{
				goto NHAPGTSV;
	        }
	        if(c==KEY_DOWN)
			{
				goto NHAPSDT;
	        }
	       
	        if(ThemDau_SV(listLOP.lop[vitri]->contro,sv))
			{
	        	ThongBao((char *)"Them Sinh Vien Thanh cong !!",16,28,25,38);
	        }
			else
			{
	        	ThongBao((char *)"Het Bo Nho Lop !!",16,28,25,38);	
	        }
			break;
		case KEY_F2:
			vtmasv=0;
			VeNutChucNang(1,MENUCHUCNANG,15,16);
			VeEditText(30,5,(char *)"       Nhap Ma SV        ");
			c=HamNhapDuLieu(32,6,10,masv,0);
	        if(c==KEY_ESC)
			{
	        	goto XUATDS;
	        }
	        while(strlen(masv)==0&&c==KEY_ENTER)
			{
	        	ThongBao((char *)"Ban Chua Nhap Ma SV !!",16,28,25,38);
	        	c=HamNhapDuLieu(32,6,10,masv,0);
	        }
			kq=Sua_SV(listLOP,masv);
			if(kq==1)
			{
	            ThongBao((char *)"Sua Thanh Cong Lop !!",16,28,25,38);
			}
			if(kq==0)
			{
				ThongBao((char *)"Khong Tim Thay SV !!",16,28,25,40);		
			}
			break;	
		case KEY_F3:
			vtmasv=0;
			VeNutChucNang(2,MENUCHUCNANG,15,16);
			VeEditText(30,5,(char *)"    Nhap Ma SV     ");
			c=HamNhapDuLieu(32,6,10,masv,0);
	        if(c==KEY_ESC)
			{
	        	goto XUATDS;
	        }
	        while(strlen(masv)==0&&c==KEY_ENTER)
			{
	        	ThongBao((char *)"Ban Chua Nhap Ma SV !!",16,28,25,38);
	        	c=HamNhapDuLieu(32,6,10,masv,0);
	        }
			if(Kiemtra_SV(listLOP,masv)!=NULL){
				 kq=HopThoaiYESNO((char *)"Ban Co Muon Xoa SV ?",COKHONG,24,7,3,15,15,15);
				if(kq==1)
				{
					int n=Xoa_SV(listLOP,masv);
					if(n==1)
					{
//			           Xoa_ALL_DIEM(listDIEM,masv);
					   ThongBao((char *)"Xoa Thanh Cong SV !!",16,28,25,38);
					}
					else
					{
						ThongBao((char *)"Xoa That Bai SV !!",16,28,25,38);
					}
					}
			}
			else
			{
				ThongBao((char *)"Khong Tim Thay Ma Lop !!",16,28,25,38);		
			}
			break;	
			
		case KEY_F4:
			vtmasv=0;
			VeNutChucNang(3,MENUCHUCNANG,15,16);
			VeEditText(30,5,(char *)"    Nhap Ma SV     ");
			c=HamNhapDuLieu(32,6,10,masv,0);
	        if(c==KEY_ESC)
			{
	        	goto XUATDS;
	        }
	        while(strlen(masv)==0&&c==KEY_ENTER)
			{
	        	ThongBao((char *)"Ban Chua Nhap Ma SV !!",16,28,25,38);
	        	c=HamNhapDuLieu(32,6,10,masv,0);
	        }
			if(Kiemtra_SV(listLOP,masv)!=NULL)
			{
				BangSV(2,4,40);
				TimKiem_SV(listLOP,masv);
				do{
					c=getch();
				  }
				while(c!=KEY_ENTER&&c!=KEY_ESC);
				for ( int i = 0 ; i <  9 ; i++)
			    {
				  for ( int j = 0 ; j < 80 ; j++ )
				  {
					 gotoxy (3 + j,40 + i  ) ;cout<<" ";
				  } 
				  Sleep(50);
			    }
				goto XUATDS; 	
			}
			else
			{
				ThongBao((char *)"Khong Tim Thay Ma Lop !!",16,28,25,38);		
			}
			break;
		case KEY_ESC:
			VeNutChucNang(5,MENUCHUCNANG,15,16);
			int kq=HopThoaiYESNO((char *)"Ban Co Muon Luu Du Lieu Vao File ?",COKHONG,19,7,3,15,15,15);
			if(kq==1) 
			{
				if(LuuDS_SV(listLOP,tenfilesv)==1)
				{
//					LuuDS_DIEM(listLOP,tenfile);
					ThongBao((char *)"Luu File Thanh Cong !!",16,28,25,38);	
				}
				else
				{
				   ThongBao((char *)"Luu File That Bai !!",16,28,25,38);		
				}
			}
			if(kq==1||kq==0)
			return;
			break;	
	}
  }	
}

//*******Xuat danh sach mon hoc**************////////////	
void thaotacmenuMH(PTRMONHOC &listMH,PTRDIEM &listDIEM, list_LOP &listLOP){
	char tenfile[]="DIEM.txt";
	char tenfile2[]="LOP.txt";
	char tenfile3[]="MONHOC.txt";
	char tenfile4[]="SINHVIEN.txt";
//	listMH.n=0;
//	DocFileMonHoc(list_MH);
//	int nmh=0;
//	MONHOC listMH[MAXLIST];
//	DSTTMonHoc(list_MH, listMH,nmh);
	
	int vtmasv=0;
	listLOP.n=0;
	listDIEM=NULL;
	LayDS_LOP(listLOP,tenfile2);
	LayDS_SV(listLOP,tenfile4);
	int tongtrang,trang=0;
	int vitri=-1;

	char stcth[4],stclt[4];
	char COKHONG[][10]={"CO","KHONG"};
	char key,c;
	char tenfileMH[]="MONHOC.txt";
//	char tenfile[]="DIEM.txt";
	LayDS_DIEM(listLOP,tenfile);
	DocFileMonHoc(listMH);
	MONHOC listmh[MAXLIST];
	int nmh=0;
	DSTTMonHoc(listMH, listmh, nmh);
	while(1){
XUATDS:
	nmh=0;
	DSTTMonHoc(listMH, listmh, nmh);	
    int vtmamh=0,vttenmh=0,vtstclt=0,vtstcth=0;
    setcolor(16,15);
    system("cls");
    setcolor(28,15);
    gotoxy(25,1);cout<<"                              ";
	gotoxy(25,2);cout<<"      DANH SACH MON HOC       ";
	gotoxy(25,3);cout<<"                              ";
	if(TongSoMH(listMH) < 15)
	{
		tongtrang=1;
	}
	else
	{
		tongtrang =TongSoMH(listMH)/15 +1;
	}
	BangMH(15,2,5);
    HienThiTrang( tongtrang, trang , 20 ,24 ,16,14 , 15);
    cout<<"["<<(char)24<<"]"<<" Tro Lai | Tiep Theo ["<<(char)25<<"]";
	setcolor(16,15);
	int dong=-1;
	
	for(int i=trang*15;i<15+15*trang&&i<TongSoMH(listMH);i++)
	{
		gotoxy(5, 9+dong); cout<< ( i +1 );
		gotoxy(13,9+dong); cout<<listmh[i].MAMH ;
		gotoxy(28,9+dong); cout<<listmh[i].TENMH ;
		gotoxy(58,9+dong); cout<<listmh[i].STCLT ;
		gotoxy(69,9+dong); cout<<listmh[i].STCTH ;
		dong++;
	}
	if(TongSoMH(listMH) ==0)
	{
		ThongBao((char *)"Chua co mon hoc trong danh sach !",16,28,25,35);
	}
	MenuChucNang(MENUCHUCNANG,MENUCHUCNANGCHU,28,15,15,2,15,6,1);
	do{
		key=getch();
	}while(key!=KEY_F1&&key!=KEY_F2&&key!=KEY_F3&&key!=KEY_F4&&key!=KEY_ESC&&key !=KEY_DOWN&&key !=KEY_UP);
	
	switch(key){
		char mamh[30],tenmh[40];
		MONHOC mh;
		case KEY_DOWN:
		if( tongtrang > 1  && trang + 1 < tongtrang )
				{
					trang ++ ;
					goto XUATDS;
				}
			break;
			case KEY_UP:
			if( tongtrang > 1  && trang > 0 )
				{
					trang -- ;
					goto XUATDS;
				}
			break;	
	case KEY_F1:
			VeNutChucNang(0,MENUCHUCNANG,15,16);
			NhapMonHoc();
	NHAPMAMH:   
		    c=HamNhapDuLieu2(32,6,vtmamh,10,mh.MAMH,0);
	        if(c==KEY_ESC)
			{
	        	goto XUATDS;
	        }
	        while(strlen(mh.MAMH)==0&&(c==KEY_ENTER||c==KEY_DOWN))
			{
	        	ThongBao((char *)"Ban Chua Nhap Ma MH !!",16,28,25,38);
	        	c=HamNhapDuLieu2(32,6,vtmamh,10,mh.MAMH,0);
	        }
	        while(SearchMaMH(listMH,mamh))
			{
				ThongBao((char *)"Ma MH Da Ton Tai !!",16,28,25,38);
	        	goto NHAPMAMH;
	        }
	        if(c==KEY_UP)
			{
				goto NHAPMAMH;
	        }
	        if(c==KEY_DOWN)
			{
				goto NHAPTENMH;
	        }
   NHAPTENMH:	        
	        c=HamNhapDuLieu2(32,9,vttenmh,30,mh.TENMH,1);
	        if(c==KEY_ESC)
			{
	        	goto XUATDS;
	        }
	        while(strlen(mh.TENMH)==0&&(c==KEY_ENTER||c==KEY_DOWN)){
	        	ThongBao((char *)"Ban Chua Nhap Ten Mon Hoc !!",16,28,25,40);
	        	goto NHAPTENMH;
	        }
	        if(c==KEY_UP)
			{
				goto NHAPMAMH;
	        }
	        if(c==KEY_DOWN)
			{
				goto NHAPSTCLTMH;
	        }
NHAPSTCLTMH:        
	        c=nhap_so2(32,12,vtstclt,stclt);
	        if(c==KEY_ESC)
			{
	        	goto XUATDS;
	        }
	        while(strlen(stclt)==0&&(c==KEY_ENTER||c==KEY_DOWN)){
	        	ThongBao((char *)"Ban Chua Nhap STCLT Mon Hoc !!",16,28,25,40);
	        	goto NHAPSTCLTMH;
	        }
	        if(c==KEY_UP)
			{
				goto NHAPTENMH;
	        }
	        if(c==KEY_DOWN)
			{
				goto NHAPSTCTHMH;
	        }
   NHAPSTCTHMH:	        
	        c=nhap_so2(32,15,vtstcth,stcth);
	        if(c==KEY_ESC)
			{
	        	goto XUATDS;
	        }
	        if(c==KEY_UP)
			{
				goto NHAPSTCLTMH;
	        }
	        if(c==KEY_DOWN)
			{
				goto NHAPSTCTHMH;
	        }
	        while(strlen(stcth) ==0&&c==KEY_ENTER){
	        	ThongBao((char *)"Ban Chua Nhap STCTH Mon Hoc !!",16,28,25,40);
	        	goto NHAPSTCTHMH;
	        }
	        mh.STCLT=atoi(stclt);
	        mh.STCTH=atoi(stcth);
	        if(Insert_node(listMH,mh)){
	        	ThongBao((char *)"Them Mon Hoc Thanh cong !!",16,28,25,40);
	        }else{
	        	ThongBao((char *)"Het Bo Nho Mon Hoc !!",16,28,25,40);	
	        	}
			break;	
		case KEY_F2:
			VeNutChucNang(1,MENUCHUCNANG,15,16);
			VeEditText(30,5,(char *)"    Nhap Ma MH     ");
			c=HamNhapDuLieu(32,6,10,mamh,0);
	        if(c==KEY_ESC)
			{
	        	goto XUATDS;
	        }
	        while(strlen(mamh) ==0&&c==KEY_ENTER){
	        	ThongBao((char *)"Ban Chua Nhap Ma Mon Hoc !!",16,28,25,40);
	        	c=HamNhapDuLieu(32,6,10,mamh,0);
	        }
			if(SearchMaMH(listMH,mamh)!= NULL)
			{
				VeEditText(22,8,(char *)"            Nhap Ten MH            ");
            	VeEditText(30,11,(char *)"     Nhap STCLT    ");
             	VeEditText(30,14,(char *)"     Nhap STCTH    ");
				if(Sua_MH(listMH,mamh)==1)
				{
	                ThongBao((char *)"Sua Thanh Cong Mon Hoc !!",16,28,25,40);
	            }else
				{
	            	goto XUATDS;
	            }
	            
			}
			else
			{
				ThongBao((char *)"Khong Tim Thay Ma Mon Hoc !!",16,28,25,40);		
			}
			break;	
		case KEY_F3:
			VeNutChucNang(2,MENUCHUCNANG,15,16);
			VeEditText(30,5,(char *)"    Nhap Ma MH     ");
			c=HamNhapDuLieu(32,6,10,mamh,0);
	        if(c==KEY_ESC)
			{
	        	goto XUATDS;
	        }
			if(SearchMaMH(listMH,mamh)!= NULL){
				int kq=HopThoaiYESNO((char *)"Ban Co Muon Xoa Mon Hoc ?",COKHONG,25,5,16,15,15,15);
				if(kq==1){
					if(HamXoaMonHoc(listMH,SearchMaMH(listMH,mamh)) == 1){
					   if(listDIEM!=NULL)
					   {
					      Xoa_MH_DIEM(listDIEM,mamh);
					   }
					   ThongBao((char *)"Xoa Thanh Cong Mon Hoc !!",16,28,25,40);
					}else{
						ThongBao((char *)"Xoa That Bai Mon Hoc !!",16,28,25,40);
					}
					}
			}
			else
			{
				ThongBao((char *)"Khong Tim Thay Ma Mon Hoc !!",16,28,25,40);		
			}
			break;	
			
		case KEY_F4:
			VeNutChucNang(3,MENUCHUCNANG,15,16);
			VeEditText(30,5,(char *)"    Nhap Ma MH     ");
			c=HamNhapDuLieu(32,6,10,mamh,0);
	        if(c==KEY_ESC)
			{
	        	goto XUATDS;
	        }
			if(SearchMaMH(listMH,mamh)!= NULL){
				BangMH(2,2,40);
				Timkiem_MH(listMH,SearchMaMH(listMH,mamh));
				do{
					c=getch();
					}while(c!=KEY_ENTER&&c!=KEY_ESC);
				goto XUATDS; 	
			}
			else
			{
				ThongBao((char *)"Khong Tim Thay Ma Mon Hoc !!",16,28,25,40);		
			}
			break;
		case KEY_ESC:
			VeNutChucNang(5,MENUCHUCNANG,15,16);
			int kq=HopThoaiYESNO((char *)"Ban Co Muon Luu Du Lieu Vao File ?",COKHONG,19,7,3,15,15,15);
			if(kq==1) 
			{
				OpenFileMH();
				GhiFileTongMonHoc(listMH);
				GhiFileMonHoc(listMH);
				CloseFileMH();
				// if(1)
				// {
					if(listDIEM !=NULL)
					{
						LuuDS_DIEM(listLOP,tenfile);
					}
					ThongBao((char *)"Luu File Thanh Cong !!",16,28,25,40);	
				// }
				// else
				// {
				//    ThongBao((char *)"Luu File That Bai !!",16,28,25,40);		
				// }
			}
			if(kq==1||kq==0)
			return;
			break;	
   }
  }	
}

void HienThiGoiYSV(list_LOP &listLOP ,int background,int textcolor,int x,int y){
	int tongtrang,trang=0,soluong=0;
	SINHVIEN sv[MAXLIST];
	char key;
    if(listLOP.n ==0)
	{
		ThongBao((char *)"Chua co lop trong danh sach !",16,28,25,15);
	}
	else
	{
	 for(int i=0;i<listLOP.n;i++)
	 {
	 	for(PTRSV p=listLOP.lop[i]->contro;p!=NULL;p=p->next)
		{
			sv[soluong]=p->sv; soluong++;
	 	}
	 }
	if(soluong == 0)
	{
		ThongBao((char *)"Chua sinh vien nao het !",16,28,25,15);
	}
	else
	{
	if(soluong < 15){
		tongtrang=1;
	}
	else
	{
		tongtrang =soluong/15 +1;
	}
XUAT:
    	
    setcolor(background,textcolor);
	BangSV(15,x,y);
	setcolor(16,15);
	int dong=-1;
	
	for(int i=trang*15;i<15+15*trang&&i<soluong;i++)
	{
		gotoxy(x+3, y+4+dong); cout<< ( i+1 );
		gotoxy(x+8,y+4+dong); cout<<sv[i].MASV ;
		gotoxy(x+22,y+4+dong); cout<<sv[i].HO ;
		gotoxy(x+39,y+4+dong); cout<<sv[i].TEN ;
		gotoxy(x+62,y+4+dong); cout<<sv[i].PHAI ;
		dong++;
	}
	HienThiTrang( tongtrang, trang , x+15 ,y+19 ,16,14 , 15);
	cout<<"["<<(char)24<<"]"<<" Tro Lai | Tiep Theo ["<<(char)25<<"]";
	do
	{
		key=getch();
	}
	while(key!=KEY_ESC&&key!=KEY_DOWN&&key!=KEY_UP);
	switch(key)
	{
		case KEY_ESC:
			return ;
			break;
		case KEY_DOWN:
			if(tongtrang > 1 && (trang + 1 )< tongtrang)
				trang++;
			goto XUAT;
		    break;	
		case KEY_UP:
		   if ( tongtrang > 1 && (trang > 0 ) ) 
				trang --;
			goto XUAT; 	
		    break;    
	}
   }
  }
}
void HienThiGoiYMH(PTRMONHOC &treemh, MONHOC listMH[] ,int background,int textcolor,int x,int y){
	int tongtrang,trang=0,soluong=0;
	char key;
	int tongmh= TongSoMH(treemh);
    if(tongmh ==0)
	{
		ThongBao((char *)"Chua co mon hoc trong danh sach !",16,28,25,15);
	}
	else
	{
	
	if(tongmh < 15){
		tongtrang=1;
	}
	else
	{
		tongtrang =tongmh/15 +1;
	}
XUAT:
    	
    setcolor(background,textcolor);
	BangMH(15,x,y);
	setcolor(16,15);
	int dong=-1;
	
	for(int i=trang*15;i<15+15*trang&&i<tongmh;i++)
	{
		gotoxy(x+3, y+4+dong); cout<< ( i+1 );
		gotoxy(x+8,y+4+dong); cout<<listMH[i].MAMH ;
		gotoxy(x+24,y+4+dong); cout<<listMH[i].TENMH ;
		gotoxy(x+57,y+4+dong); cout<<listMH[i].STCLT ;
		gotoxy(x+68,y+4+dong); cout<<listMH[i].STCTH ;
		dong++;
	}
	HienThiTrang( tongtrang, trang , x+10 ,y+19 ,16,14 , 15);
	cout<<"["<<(char)24<<"]"<<" Tro Lai | Tiep Theo ["<<(char)25<<"]";
	do
	{
		key=getch();
	}
	while(key!=KEY_ESC&&key!=KEY_DOWN&&key!=KEY_UP);
	switch(key)
	{
		case KEY_ESC:
			return ;
			break;
		case KEY_DOWN:
			if(tongtrang > 1 && (trang + 1 )< tongtrang)
				trang++;
			goto XUAT;
		    break;	
		case KEY_UP:
		   if ( tongtrang > 1 && (trang > 0 ) ) 
				trang --;
			goto XUAT; 	
		    break;    
	}
   }
}

void NhapMaLOpDiem(int x,int y){
	char c;
	int vitri=-1;
	char malop[30];
	char textmenu[][30]={"THOAT","XEM LOP","XEM MON HOC"};
	char menu[][30]={"ESC","F4","F5"};
	for(int i=0;i<3;i++)
	{
	 setcolor(28,15);
	 gotoxy(x+20*i,y);
	 cout<<"      ";
	 gotoxy(x+20*i,y+1);
	 cout<<"      ";
	 gotoxy(x+20*i,y+2);
	 cout<<"      ";
	 gotoxy(x+20*i,y+1);
	 cout<<"  "<<menu[i];
	 
	 setcolor(16,15);
	 gotoxy((x+7)+20*i,y);
	 cout<<"      ";
	 gotoxy((x+7)+20*i,y+1);
	 cout<<"      ";
	 gotoxy((x+7)+20*i,y+2);
	 cout<<"      ";
	 gotoxy((x+7)+20*i,y+1);
	 cout<<""<<textmenu[i];
     }
} 

int CapNhatDanhSachDiem(PTRDIEM &listDIEM,char * MAMH,int soluong,char lan1[][4],char lan2[][4],SINHVIEN sv[],char *tenfile, list_LOP &listLOP){
	int check=0;
	int demLan1 = 0, demLan2 =0;
	
	for(int i=0;i< soluong;i++)
	{
		check=0;
		DIEM diem1,diem2;
	
		if(lan1[i][0]!='\0')
		{
//		  strcpy(diem1.MASV,sv[i].MASV);
		  strcpy(diem1.MAMH,MAMH);
		  diem1.LAN=1;
		  diem1.DIEMSV=atof(lan1[i]);
		  for(int j=0; j<listLOP.n; j++) {
		  	demLan1 = 0;
		  	for(PTRSV p = listLOP.lop[j]->contro; p != NULL; p=p->next) {
		  		
		  		 for(PTRDIEM q = p->sv.contro;q!=NULL;q=q->next)
				  {
					if(strcmp(MAMH,q->diem.MAMH)==0&&q->diem.LAN==1 && demLan1 == i)
					{
						q->diem.DIEMSV=diem1.DIEMSV;
						check=1;
					}
					
				  }
				if(check==0 && demLan1 == i){
					ThemDau_DIEM(p->sv.contro,diem1);
				}
				demLan1 ++;
				
			  }
		  }
//		 
//		  if(check==0){
//		  	ThemDau_DIEM(listDIEM,diem1);
//		  }
	   }
	   check =0;
	   if(lan2[i][0]!='\0')
		{
//		  strcpy(diem2.MASV,sv[i].MASV);
		  strcpy(diem2.MAMH,MAMH);
		  diem2.LAN=2;
		  diem2.DIEMSV=atof(lan2[i]);
		  for(int j=0; j<listLOP.n; j++) {
		  	demLan2 = 0;
		  	for(PTRSV p = listLOP.lop[j]->contro; p != NULL; p=p->next) {
		  		 for(PTRDIEM q=p->sv.contro;q!=NULL;q=q->next)
				  {
					if(strcmp(MAMH,q->diem.MAMH)==0&&q->diem.LAN==2 && demLan2 ==i)
					{
						q->diem.DIEMSV=diem2.DIEMSV;
						check=1;
					}
					
				  }
				  
				  
				if(check==0 && demLan2 == i){
					ThemDau_DIEM(p->sv.contro,diem2);
				}
				demLan2++;
			  }
		  }
//		  if(check==0){
//		  	ThemDau_DIEM(listDIEM,diem2);
//		  }
	   }
	}
	int kq= LuuDS_DIEM(listLOP,tenfile);
	return kq;
}
int KiemTraNhapDiem(int soluong,char lan1[][4],char lan2[][4],int &vitri,int &toadoY,int &trang,int &loidiem1,int &loidiem2)
{
	int dong=0,vitritrang=0;
	for(int i=0;i<soluong;i++)
	{
		if(dong==15)
		{
			dong=0;
			vitritrang++;
		}
		if(strlen(lan1[i])==0&&strlen(lan2[i]) > 0)
		{
			ThongBao((char *)"Ban Chua Nhap Diem Thi Lan 1",16,28,25,38);
			vitri=i;
			toadoY =dong;
			trang=vitritrang;
			loidiem1=1;
			return 1;
		}
		dong++;
	}
	dong=0;vitritrang=0;
	for(int i=0;i<soluong;i++)
	{
		if(dong==15)
		{
			dong=0;
			vitritrang++;
		}
		if(lan1[i]!='\0'&&atof(lan1[i]) > 10)
		{
			ThongBao((char *)"Ban Nhap Sai Diem Thi Lan 1 (0 <= Diem <= 10)",16,28,25,38);
			vitri=i;
			toadoY =dong;
			trang=vitritrang;
			loidiem1=1;
			return 1;
		}
		if(lan2[i]!='\0'&&atof(lan2[i]) > 10)
		{
			ThongBao((char *)"Ban Nhap Sai Diem Thi Lan 2 (0 <= Diem <= 10)",16,28,25,38);
			vitri=i;
			toadoY =dong;
			trang=vitritrang;
			loidiem2=1;
			return 1;
		}
		dong++;
	}
	return 0;
}

//*******Thao tac menu diem**************////////////
void thaotacmenuDIEM(PTRDIEM &listDIEM,PTRMONHOC &list_MH,list_LOP &listLOP)
{
	setcolor(16,15);
	system("cls");
	char chucnangdiem,ch;
	char tenfile[]="DIEM.txt";
	char tenfile2[]="LOP.txt";
	char tenfile3[]="MONHOC.txt";
	char tenfile4[]="SINHVIEN.txt";
//	listMH.n=0;
	DocFileMonHoc(list_MH);
	int nmh=0;
	MONHOC listMH[MAXLIST];
	DSTTMonHoc(list_MH, listMH,nmh);
	
	int vtmasv=0;
	listLOP.n=0;
	listDIEM=NULL;
	LayDS_LOP(listLOP,tenfile2);
	LayDS_SV(listLOP,tenfile4);
//	LayDS_MH(listMH,tenfile3);
	LayDS_DIEM(listLOP,tenfile);
	int tongtrang,trang=0;
	int vitrilop=-1,vitrimh=-1;
	char menu[][30]={"ESC","F4","F5"};
	int x=20;
	int y=18;
	int kq=0;
	int loidiem1=0,loidiem2=0;
	int vtMALOP=0,vtMAMH=0;
	char masv[30],malop[30],mamh[30];
	int stclt,stcth;
	char COKHONG[][10]={"CO","KHONG"};
	char key,c;
	setcolor(28,15);
    gotoxy(25,1);cout<<"                              ";
	gotoxy(25,2);cout<<"        DANH SACH DIEM        ";
	gotoxy(25,3);cout<<"                              ";
	VeEditText(30,5,(char *)"    Nhap Ma Lop    ");
    VeEditText(30,7,(char *)"  Nhap Ma Mon Hoc  ");
    gotoxy(5,36);                                  
NHAPMALOP:
	NhapMaLOpDiem(10,18);
	c=HamNhapDuLieu2(32,6,vtMALOP,10,malop,0);
    switch(c)
	 {
	  	case KEY_F5:           
	        setcolor(15,28);
	        gotoxy(x+30,y);
	        cout<<"      ";
	        gotoxy(x+30,y+1);
	        cout<<"      ";
	        gotoxy(x+30,y+2);
	        cout<<"      ";
	        gotoxy(x+30,y+1);
	        cout<<"  "<<menu[2];
	        HienThiGoiYMH(list_MH, listMH,16,15,x-18,5+y);
	        setcolor(16,16);
			for ( int i = 0 ; i <  x+5 ; i++)
			{
				for ( int j = 0 ; j < y+60 ; j++ )
				{
					 gotoxy (1 + j,21 + i  ) ;cout<<" ";
				}
					Sleep(25);
			}
	        goto NHAPMALOP;
	  		break;
	  	case KEY_F4:
	  		setcolor(15,28);
	        gotoxy(x+10,y);
	        cout<<"      ";
	        gotoxy(x+10,y+1);
	        cout<<"      ";
	        gotoxy(x+10,y+2);
	        cout<<"      ";
	        gotoxy(x+10,y+1);
	        cout<<"  "<<menu[1];
	        
	        HienThiGoiYLop(listLOP,16,15,x-5,5+y);
	        
	        setcolor(16,16);
			for ( int i = 0 ; i <  x+5 ; i++)
			{
				for ( int j = 0 ; j < y+50 ; j++ )
				{
					 gotoxy (3 + j,21 + i  ) ;cout<<" ";
				}
					Sleep(25);
			}
	        goto NHAPMALOP;
	  		break;	
	  	case KEY_ESC :
	  		return;
	  		break;
	  	case KEY_ENTER:
	  		while(strlen(malop)==0)
			{
				ThongBao((char *)"Chua Nhap Ma Lop!",16,28,25,15);
				goto NHAPMALOP;
	  		}
	  		vitrilop=KiemTra_Lop(listLOP,malop);
	  		if(vitrilop==-1)
			  {
	  			ThongBao((char *)"Khong Tim Thay Ma Lop !",16,28,30,15);
	  			goto NHAPMALOP;
	  		  }
		    break;
		case KEY_UP:
			goto NHAPMALOP;
			break;
			
		case KEY_DOWN:
			while(strlen(malop)==0)
			{
				ThongBao((char *)"Chua Nhap Ma Lop!",16,28,30,15);
				goto NHAPMALOP;
	  		}
	  		vitrilop=KiemTra_Lop(listLOP,malop);
	  		if(vitrilop==-1)
			  {
	  			ThongBao((char *)"Khong Tim Thay Ma Lop !",16,28,30,15);
	  			goto NHAPMALOP;
	  		  }
			goto NHAPMAMH;
			break;					
	  }	
NHAPMAMH:
    NhapMaLOpDiem(10,18);	  
	c=HamNhapDuLieu2(32,8,vtMAMH,10,mamh,0);
    switch(c)
	 {
	  	case KEY_F5:
	        setcolor(15,28);
	        gotoxy(x+30,y);
	        cout<<"      ";
	        gotoxy(x+30,y+1);
	        cout<<"      ";
	        gotoxy(x+30,y+2);
	        cout<<"      ";
	        gotoxy(x+30,y+1);
	        cout<<"  "<<menu[2];
	        HienThiGoiYMH(list_MH, listMH,16,15,x-18,5+y);
	        setcolor(16,16);
			for ( int i = 0 ; i <  x+5 ; i++)
			{
				for ( int j = 0 ; j < y+60 ; j++ )
				{
					 gotoxy (1 + j,21 + i  ) ;cout<<" ";
				}
					Sleep(25);
			}
	        goto NHAPMAMH;
	  		break;
	  	case KEY_F4:
	  		setcolor(15,28);
	        gotoxy(x+10,y);
	        cout<<"      ";
	        gotoxy(x+10,y+1);
	        cout<<"      ";
	        gotoxy(x+10,y+2);
	        cout<<"      ";
	        gotoxy(x+10,y+1);
	        cout<<"  "<<menu[1];
	        HienThiGoiYSV(listLOP,16,15,x-16,5+y);
	        setcolor(16,16);
			for ( int i = 0 ; i <  x+5 ; i++)
			{
				for ( int j = 0 ; j < y+60 ; j++ )
				{
					 gotoxy (1 + j,21 + i  ) ;cout<<" ";
				}
					Sleep(25);
			}
	        goto NHAPMAMH;
	  		break;	
	  	case KEY_ESC :
	  		return;
	  		break;
	  	case KEY_ENTER:
	  		while(strlen(mamh)==0)
			{
				ThongBao((char *)"Chua Nhap Ma Mon Hoc!",16,28,25,15);
				goto NHAPMAMH;
	  		}
	  		vitrimh=SearchMaMH(listMH, mamh, TongSoMH(list_MH));
	  		if(vitrimh==-1)
			  {
	  			ThongBao((char *)"Khong Tim Thay Ma MH !",16,28,25,15);
	  			goto NHAPMAMH;
	  		  }
		    break;
		    
		case KEY_UP:
			while(strlen(mamh)==0)
			{
				ThongBao((char *)"Chua Nhap Ma Mon Hoc!",16,28,25,15);
				goto NHAPMAMH;
	  		}
			    goto NHAPMALOP;
			break;
			
		case KEY_DOWN:
			    goto NHAPMAMH;
			break;		
	  }	
LAYDIEM:
	int soluong=0;
	int sluongSV=Dem_SV(listLOP,vitrilop);
	SINHVIEN sv[sluongSV];
//	Sapxep_SV(listLOP,vitrilop);
	for(PTRSV p=listLOP.lop[vitrilop]->contro;p!=NULL;p=p->next)
	{
		sv[soluong]=p->sv; soluong++;
	 }
	char diemlan1[soluong][4];
	char diemlan2[soluong][4];
	int vitridiem1[30],vitridiem2[30];
	int vitri=0,toadoY=0;
	for ( int i = 0 ; i < soluong ; i++ )
		{
			for(int j=0;j<4;j++)
			{
				diemlan1[i][j]  = '\0';
				diemlan2[i][j]  = '\0';
			}
		}
	char sothuc[4];
//	for(PTRDIEM q =listDIEM;q!=NULL;q=q->next)
//		 {
		   for(int i=0;i<listLOP.n;i++)
		   {
		   		int j = 0;
		   		for (PTRSV p = listLOP.lop[i]->contro; p !=NULL; ) { 
			   			for (PTRDIEM q =p->sv.contro;q!=NULL;q=q->next ) {
					   		if(strcmp(mamh,q->diem.MAMH)==0&&q->diem.LAN==1)
								{
									if(q->diem.DIEMSV ==10)
									{
										snprintf(sothuc, sizeof(sothuc), "%d", (int)(q->diem.DIEMSV));
									}
									else
									{
									    snprintf(sothuc, sizeof(sothuc), "%0.2f", q->diem.DIEMSV);
									}
									
							        strcpy(diemlan1[j],sothuc);
			//				        break;
							    }
						   	  	if(strcmp(mamh,q->diem.MAMH)==0&&q->diem.LAN==2)
								{
									if(q->diem.DIEMSV ==10)
									{
										snprintf(sothuc, sizeof(sothuc), "%d", (int)(q->diem.DIEMSV));
									}
									else
									{
										
									    snprintf(sothuc, sizeof(sothuc), "%0.2f", q->diem.DIEMSV);
									}
									
							        strcpy(diemlan2[j],sothuc);
			//				        break;
						   	  	}
				   			}
				   			 p= p->next;
				   			 j++;
		   			}
			}
//	   	  }
	if(soluong < 15)
	{
		tongtrang=1;
	}
	else
	{
		tongtrang =soluong/15 +1;
	}  
while(1)
	{
XUATDS:	
    setcolor(16,15);
    system("cls");
    setcolor(28,15);
    gotoxy(25,1);cout<<"                              ";
	gotoxy(25,2);cout<<"        DANH SACH DIEM        ";
	gotoxy(25,3);cout<<"                              ";
	setcolor(16,14);
	gotoxy(3,5);  cout<<" LOP : "<<listLOP.lop[vitrilop]->TENLOP ;
	gotoxy(3,6);  cout<<" MON HOC  : "<<listMH[vitrimh].TENMH ;
	setcolor(16,15);
	BangDiem(15,4,7);
    HienThiTrang( tongtrang, trang , 20 ,26 ,16,14 , 15);
    cout<<"["<<(char)24<<"]"<<" Tro Lai | Tiep Theo ["<<(char)25<<"]";
	setcolor(16,15);
	int dong=-1;
	
	for(int i=trang*15;i<15+15*trang&&i<soluong;i++)
	{
		gotoxy(6, 11+dong); cout<< ( i +1 );
		gotoxy(11,11+dong); cout<<sv[i].MASV;
		gotoxy(24,11+dong); cout<<sv[i].HO;
		gotoxy(39,11+dong); cout<<sv[i].TEN;
		if ( diemlan1[i][0]  != '\0')
		{
			gotoxy(56,11+dong);  cout<<diemlan1[i];
		}
		if ( diemlan2[i][0]  != '\0')
		{
			gotoxy(68,11+dong);  cout<<diemlan2[i];
		}
		dong++;
	} 
	if(sluongSV ==0)
	{
		ThongBao((char *)"Chua Co Sinh Vien Trong Lop Nay !",16,28,25,38);
	}
	MenuChucNangDiem(MENUCHUCNANGDIEM,MENUCHUCNANGCHUDIEM,28,15,15,5,15,3);
	if(loidiem1 ==0&&loidiem2==0)
	{
	   do
	   {
		  key=getch();
	   }
	   while(key!=KEY_F1&&key!=KEY_F2&&key!=KEY_ESC&&key!=KEY_DOWN&&key!=KEY_UP);
	}
	else
	{
	   key =KEY_F1;	
	}
	
	switch(key){
		
		case KEY_DOWN:
			if( tongtrang > 1  && trang + 1 < tongtrang )
				{
					trang ++ ;
					goto XUATDS;
				}
			break;
		case KEY_UP:
			if( tongtrang > 1  && trang > 0 )
				{
					trang -- ;
					goto XUATDS;
				}
			break;	
		case KEY_F1:
			if(loidiem1 ==0&&loidiem2==0)
			{
			  vitri=trang*15;
			  toadoY=0;
		    }
			VeNutChucNangDiem(1,MENUCHUCNANGDIEM,15,16);
			if(loidiem1==1)
	        {
		       goto NHAPDIEM1;
	        }
	        if(loidiem2==1)
	        {
		       goto NHAPDIEM2;
	        }
	NHAPDIEM1:	
			vitridiem1[vitri]=strlen(diemlan1[vitri]);
			c=HamNhapDiem(56,10+toadoY,vitridiem1[vitri],3,diemlan1[vitri]);
			switch(c)
			{
				case KEY_ESC:
					goto XUATDS;
					break;
				case KEY_UP:
					
					if(toadoY > 0)
					{
					   vitri-- , toadoY--;
					}
					goto NHAPDIEM1;
					
				    break;	
				case KEY_DOWN:
					
					if ( toadoY < 14 && toadoY < (soluong - trang*15 -1 ) )
					{
						vitri++ , toadoY++;
					}
					goto NHAPDIEM1;	
					
				    break;
				    
				case KEY_LEFT:
					goto NHAPDIEM1;	
				    break;
				    
				case KEY_RIGHT:
					goto NHAPDIEM2;	
				    break;		
							
			}
	NHAPDIEM2:	
			vitridiem2[vitri]=strlen(diemlan2[vitri]);
			c=HamNhapDiem(68,10+toadoY,vitridiem2[vitri],3,diemlan2[vitri]);
			switch(c)
			{
				case KEY_ESC:
					goto XUATDS;
					break;
				case KEY_UP:
					
					if(toadoY > 0)
					{
					   vitri-- , toadoY--;
					}
					goto NHAPDIEM2;
					
				    break;	
				case KEY_DOWN:
					
					if ( toadoY < 14 && toadoY < (soluong - trang*15 -1 ) )
					{
						vitri++ , toadoY++;
					}
					goto NHAPDIEM2;	
					
				    break;
				    
				case KEY_LEFT:
					goto NHAPDIEM1;	
				    break;	
				    
				case KEY_RIGHT:
					goto NHAPDIEM2;	
				    break;				
			}
			if(KiemTraNhapDiem(soluong,diemlan1,diemlan2,vitri,toadoY,trang,loidiem1,loidiem2)==1)
			{
				goto XUATDS;
			}
			loidiem1=0,loidiem2=0;
		    break;	
		case KEY_F2:
			VeNutChucNangDiem(2,MENUCHUCNANGDIEM,15,16);
			VeEditText(30,10,(char *)"    Nhap Ma SV     ");
	NHAPMASV:   
		    c=HamNhapDuLieu2(32,11,vtmasv,10,masv,0);
	        if(c==KEY_ESC)
			{
	        	goto XUATDS;
	        }
	        while(strlen(masv)==0)
			{
	        	ThongBao((char *)"Ban Chua Nhap Ma SV !!",16,28,25,38);
	        	c=HamNhapDuLieu2(32,11,vtmasv,10,masv,0);
	        }
	        while(Kiemtra_SV(listLOP,masv)==NULL)
			{
				ThongBao((char *)"Ma SV khong ton tai !!",16,28,25,38);
	        	goto NHAPMASV;
	        }
//	        if(Xoa_ALL_DIEM_MH(listDIEM,masv,mamh)!=0){
//	        	ThongBao((char *)"Xoa Diem Thanh Cong !!",16,28,25,38);
//	        	goto LAYDIEM;
//	        }else{
//	        	ThongBao((char *)"Sinh Vien Khong Co Diem Mon Nay !!",16,28,25,38);
//	        	goto XUATDS;
//	        }
		    break;    
			
		case KEY_ESC:
			VeNutChucNangDiem(0,MENUCHUCNANGDIEM,15,16);
			int kq=HopThoaiYESNO((char *)"Ban Co Muon Luu Du Lieu Vao File ?",COKHONG,19,7,3,15,15,15);
			if(kq==1)
			{
			   kq =CapNhatDanhSachDiem(listDIEM,mamh,soluong,diemlan1,diemlan2,sv,tenfile, listLOP);
			   if(kq==1)
			       ThongBao((char *)"Luu File Thanh Cong !!",16,28,25,38);
			     else
			      ThongBao((char *)"Luu File That Bai !!",16,28,25,38);
			}
			return;
			break;	
	}
  }	
}   
void DiemTongKetLop(PTRDIEM &listDIEM,PTRMONHOC &list_MH,list_LOP &listLOP)
{
	setcolor(16,15);
	system("cls");
	char chucnangdiem,ch;
	char tenfile[]="DIEM.txt";
	char tenfile2[]="LOP.txt";
	char tenfile3[]="MONHOC.txt";
	char tenfile4[]="SINHVIEN.txt";
//	listMH.n=0;
	DocFileMonHoc(list_MH);
	int nmh=0;
	MONHOC listMH[MAXLIST];
	DSTTMonHoc(list_MH, listMH,nmh);
	int tongMH = TongSoMH(list_MH);
	listDIEM=NULL;
	listLOP.n=0;
	LayDS_LOP(listLOP,tenfile2);
	LayDS_SV(listLOP,tenfile4);
//	LayDS_MH(listMH,tenfile3);
	LayDS_DIEM(listLOP,tenfile);
	int vitri=-1;
	char menu[][30]={"ESC","F5"};
	int x=20;
	int y=18;
	int kq=0;
	int vtMALOP=0,vtMAMH=0;
	char masv[30],malop[30],mamh[30];
	char COKHONG[][10]={"CO","KHONG"};
	char p[]="   Ban co muon thoat ?   ";
	char key,c;
	setcolor(28,15);
    gotoxy(20,1);cout<<"                                       ";
	gotoxy(20,2);cout<<"        TONG KET DIEM SINH VIEN        ";
	gotoxy(20,3);cout<<"                                       ";
	VeEditText(30,5,(char *)"    Nhap Ma Lop    ");
	gotoxy(5,36);
NHAPMALOP:
	NhapMaLOpSV(20,18);
	c=HamNhapDuLieu(32,6,10,malop,0);
    switch(c)
	 {
	  	case KEY_F5:
	  		setcolor(15,28);
	        gotoxy(x+20,y);
	        cout<<"      ";
	        gotoxy(x+20,y+1);
	        cout<<"      ";
	        gotoxy(x+20,y+2);
	        cout<<"      ";
	        gotoxy(x+20,y+1);
	        cout<<"  "<<menu[1];
	        HienThiGoiYLop(listLOP,16,15,x-5,5+y);
	        setcolor(16,16);
			for ( int i = 0 ; i <  x+5 ; i++)
			{
				for ( int j = 0 ; j < y+50 ; j++ )
				{
					 gotoxy (3 + j,21 + i  ) ;cout<<" ";
				}
					Sleep(25);
			}
	        goto NHAPMALOP;
	  		break;
	  	case KEY_ESC :
	  		return;
	  		break;
	  	case KEY_ENTER:
	  		vitri=KiemTra_Lop(listLOP,malop);
	  		if(vitri==-1)
			  {
	  			ThongBao((char *)"Khong Tim Thay Ma Lop !",16,28,25,15);
	  			goto NHAPMALOP;
	  		  }
		    break;		
	  }
	int soluong=0;
	int sluongSV=Dem_SV(listLOP,vitri);
	if(sluongSV ==0)
	{
		ThongBao((char *)"Chua Sinh Vien Trong Lop Nay !",16,28,25,38);
		return;
	}
	int trangSV=0,trangMH=0,tongtrang=0,vitriMH=0;
	SINHVIEN sv[sluongSV];
	int tcmonhoc[tongMH];
	float diemMH[sluongSV];
	int tongsotc[sluongSV];
	Sapxep_SV(listLOP,vitri);
	int reset=0;
	for(PTRSV p=listLOP.lop[vitri]->contro;p!=NULL;p=p->next)
	{
		sv[soluong]=p->sv; soluong++;
		diemMH[reset]=0;
		tongsotc[reset]=0;
		reset++;
	}
	char TongKetDiem[tongMH][soluong][4];
	for(int i=0;i<tongMH;i++)
	{
		tcmonhoc[i]=0;
		for(int j=0 ; j < soluong ; j++)
		{
		   for(int n=0 ; n<4 ; n++)
		   {
		   	   TongKetDiem[i][j][n]='\0';
		   }
		}
	}
//	for(PTRDIEM p=listDIEM ; p!=NULL;p=p->next)
//	{
	
	for(int i = 0; i < listLOP.n ; i++)
		{
		  	for (PTRDIEM p = listLOP.lop[i]->contro->sv.contro; p !=NULL;p=p->next) {
		  		char diem[4];
				vitriMH =SearchMaMH(listMH, p->diem.MAMH,tongMH);
				if(vitriMH !=-1)
				{		
					tcmonhoc[vitriMH] = (listMH[vitriMH].STCLT+listMH[vitriMH].STCTH);
					if((p->diem.DIEMSV) >= atof(TongKetDiem[vitriMH][i]))
					{
					  if(p->diem.DIEMSV==10)
					  {
					  	 snprintf(diem, sizeof(diem), "%d", (int)(p->diem.DIEMSV));
					  }
					  else
					  {
					     snprintf(diem, sizeof(diem), "%0.2f", p->diem.DIEMSV);
				      }
					  strcpy(TongKetDiem[vitriMH][i],diem);
					  break;
				    }
		  		}
			  }		
		}
//	}
	for(int i= 0 ; i < soluong ; i++)
	 {
	 	for (int j = 0; j < tongMH; j ++)
		{
		   if (TongKetDiem[j][i][0] != '\0')
			{
				if(tcmonhoc[j]!=0)
				{
			       tongsotc[i]+=tcmonhoc[j];
			       diemMH[i]+= (float)(atof(TongKetDiem[ j ][i])*tcmonhoc[j]);
		        }
			}
		}
	 }
	if(soluong < 15)
	{
		trangSV =0;
		tongtrang=1;
	}
	else 
	{
		tongtrang=(soluong/15) +1;
	}
	while (1)
	{
XUATDS :
	 int check=0; 
     setcolor(16,15);
	 system("cls");
	 setcolor(28,15);
     gotoxy(20,1);cout<<"                                       ";
	 gotoxy(20,2);cout<<"        TONG KET DIEM SINH VIEN        ";
	 gotoxy(20,3);cout<<"                                       ";
	 setcolor(16,14);
	 gotoxy(3,6);  cout<<" LOP : "<<listLOP.lop[vitri]->TENLOP ;
	 setcolor(16,15);
	 BangDiemTongKet(15,2,7);
	 vitriMH = 3 * trangMH ;
	 for(int i = 0 ; i < 3 ; i++)
	 {
		if(vitriMH < tongMH)
		{
		  gotoxy ( 46 + i * 11 , 8) ;
		  cout<<listMH[vitriMH].MAMH ;
		}
		vitriMH ++;
		if (vitriMH > tongMH)
		{
		  x=46 + (i) * 11 , y=8;
		  gotoxy ( x , y) ;
		  cout<<"DIEM TB" ;
		  check=1;
		  break;
		}
	 }
	 int dong=0;
	 for(int i= 0 + trangSV*15 ; i < 15 + trangSV*15 && i< soluong ; i++)
	 {
	 	vitriMH = 3*trangMH;
	 	gotoxy(1,10+dong );
	    gotoxy(4,10+dong); cout<< ( i +1 );
		gotoxy(7,10+dong);  cout<<sv[i].MASV;
		char HO[30],TEN[30];
		strcpy(HO,sv[i].HO);
		strcpy(TEN,sv[i].TEN);
		gotoxy(20,10+dong); cout<<strcat(strcat(HO," "),TEN);
		for (int j = 0; j < 3; j ++)
		{
		   
		   if (vitriMH < tongMH&&TongKetDiem[vitriMH][i][0] != '\0')
			{
				gotoxy (48 + j * 11 , 10 + dong) ;
				cout<<TongKetDiem[ vitriMH ][i];
			}
			vitriMH++;
		}
		dong++;
	 }
	 if(check==1)
	 {
	   dong=0;
	   for(int i= 0 + trangSV*15 ; i < 15 + trangSV*15 && i< soluong ; i++)
	   {
	   	 if(tongsotc[i] > 0)
	   	 {
	   	 	gotoxy(x,y );
	   	 	gotoxy ( x+2 , (y+2) +dong) ;
	   	 	char diemtb[4];
			snprintf(diemtb, sizeof(diemtb), "%0.2f", (diemMH[i])/(tongsotc[i]));
		    cout<<diemtb;
	   	 }
	 	 dong++;
	   }
	   check=0;	
     }
     x=20,y=18;
	 HienThiTrang( tongtrang, trangSV , x+10 ,26 ,16,14 , 15);
	 gotoxy(2,27);
	 cout<<"["<<(char)24<<"]"<<" Danh Sach Sinh Vien ["<<(char)25<<"]";	
	 gotoxy(50,27);
	 cout<<"["<<(char)27<<"]"<<" Danh Sach Mon Hoc ["<<(char)26<<"]";
	 MenuChucNangDiem(MENUCHUCNANGTONGDIEM,MENUCHUCNANGCHUTONGDIEM,28,15,15,2,3,2);
	 do
	 {
		key=getch();
	 }
	 while(key!=KEY_F1&&key!=KEY_LEFT&&key!=KEY_RIGHT&&key!=KEY_ESC&&key!=KEY_DOWN&&key!=KEY_UP);
	 switch(key)
	 {
	 	case KEY_UP:
	 		if(trangSV > 0 && tongtrang > 1)
	 		{
	 			trangSV--;
	 			goto XUATDS;
	 		}
	 		break;
	 	case KEY_DOWN:
	 		if(trangSV+1 < tongtrang && tongtrang > 1)
	 		{
	 			trangSV++;
	 			goto XUATDS;
	 		}
	 		break;
		case KEY_LEFT:
			if(trangMH > 0)
	 		{
	 			trangMH--;
	 			goto XUATDS;
	 		}
	 		break;
		case KEY_RIGHT:
			if(trangMH < ((tongMH)/3))
	 		{
	 			trangMH++;
	 			goto XUATDS;
	 		}
	 		break;
		case KEY_F1:
			VeNutChucNangDiem(1,MENUCHUCNANGTONGDIEM,15,16);
			HienThiGoiYMH(list_MH, listMH,16,15,x-18,18+y);
	        setcolor(16,16);
			for ( int i = 0 ; i <  x+5 ; i++)
			{
				for ( int j = 0 ; j < y+60 ; j++ )
				{
					 gotoxy (1 + j,36 + i  ) ;cout<<" ";
				}
					Sleep(25);
			}
	        goto XUATDS;
	 		break;
		case KEY_ESC:
			VeNutChucNangDiem(0,MENUCHUCNANGTONGDIEM,15,16);
			int kq=HopThoaiYESNO(p,COKHONG,25,5,3,15,15,15);
			if(kq==1)
			{
			  
			  return;
			}
	 		break;	 	 	 	 	
	 }
	}
	
	  	
}
void TaoMenuDiem(PTRDIEM &listDIEM,PTRMONHOC &list_MH,list_LOP &listLOP){
	char key;
	int chon=-1;
	int nmh=0;
	MONHOC listMH[MAXLIST];
	DSTTMonHoc(list_MH,listMH,nmh);
	MauMenuConMacDinh(15,25,2,MENUDIEM);
	do{
		key =getch();
		switch(key)
		{
			case KEY_UP:
				MauMenuConMacDinh(15,25,2,MENUDIEM);
				chon--;
				if(chon<0)
				{
					chon=1;
				}
				ToMauMenuCon(28,15,chon,MENUDIEM);
				break;
			case KEY_DOWN:
				MauMenuConMacDinh(15,25,2,MENUDIEM);
				chon++;
				if(chon > 1)
				{
					chon=0;
				}
				ToMauMenuCon(28,15,chon,MENUDIEM);
			    break;	
			 case KEY_ENTER:
			 	if(chon==0)
			 	{
			 		thaotacmenuDIEM(listDIEM,list_MH,listLOP);
			 	}
				else
				{
					DiemTongKetLop(listDIEM,list_MH,listLOP);
				}
			 	return;
			    break;   
		}
		
	}
	while(key!=KEY_ESC);
}
void ChonMenuChinh(int vitri){
	PTRSV listSV=NULL;
	PTRDIEM listDIEM=NULL;
	PTRMONHOC listMH=NULL;
	list_LOP listLOP;
	char COKHONG[][10]={"CO","KHONG"};
	char p[]="Ban co muon thoat khoi chuong trinh ?";
	switch(vitri)
	{
		case 0:
			thaotacmenuLOP(listLOP);
			break;
		case 1:
			thaotacmenuSV(listLOP,listDIEM);
			break;
		case 2:
			thaotacmenuMH(listMH,listDIEM, listLOP);
			break;
		case 3:
			TaoMenuDiem(listDIEM,listMH,listLOP);
			break;
		case 4:
			int kq=HopThoaiYESNO(p,COKHONG,25,5,16,15,15,15);
			system("cls");
			if(kq==1)
			{
			  exit(1);
			}
			break;
	}
}  

void ChonMenu(){
	char key;
	int chon=-1;
	system("cls");
	ColorMenuNormal();
	do
	{
		setcolor(28,15);
	    gotoxy(25,1);cout<<"                              ";
	    gotoxy(25,2);cout<<"  DE TAI : QUAN LY SINH VIEN  ";
	    gotoxy(25,3);cout<<"                              ";
		ColorMenuNormal();
		ToMauMenuChinh(15,25,chon);
		key=getch();
		switch(key){
			case KEY_UP:
				chon--;
				if(chon<0){
					chon=4;
				}
				break;
			case KEY_DOWN:
				chon++;
				if(chon >4){
					chon=0;
				}
			    break;	
		   case KEY_ENTER:
		   	    ChonMenuChinh(chon);
		   	    chon =-1;
		   	    setcolor(16,15);
		   	    system("cls");
		   	    break;
		}
	}
	 while(1);
	}
int main(){
	resizeConsole(1330, 768);
	ChonMenu();
//    DiemTongKetLop();
//    TaoMenuDiem();
//	BangDiemTongKet(15,2,10);
	}
