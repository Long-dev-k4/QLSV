#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
using namespace std;
int dem = 0;
struct SinhVien
{
	int mssv;
    char ten[30];
    char gioitinh[10];
    char diachi[20];
    char nganh[30];
    double diem1,diem2,diem3;

    void nhap()
	{
    cout << "Nhap ma so sinh vien: ";
    cin >> mssv;
    cout << "Nhap ho va ten sinh vien: ";
    fflush(stdin);
    gets(ten);
    cout << "Nhap gioi tinh sinh vien: ";
    fflush(stdin);
    gets(gioitinh);
    cout << "Nhap dia chi: "; cin >> diachi;
    cout << "Nhap chuyen nganh hoc: "; cin >> nganh;
        do
        {
            cout << "Nhap diem 1: "; cin >> diem1;
            cout << "Nhap diem 2: "; cin >> diem2;
            cout << "Nhap diem 3: "; cin >> diem3;

            if(diem1<0||diem2<0||diem3<0||diem1>10||diem2>10||diem3>10)
		    cout << "Moi ban nhap lai diem khong dung\n";
        } while(diem1<0||diem2<0||diem3<0||diem1>10||diem2>10||diem3>10);
    }
//tinh diem TB cua 3 mon
    double diemTB()
    {
        return(diem1 + diem2 + diem3)/3;
    }

    string HocLuc()
    {
	    string hl;
	    if(diemTB()>=9)
	        hl = "Xuat sac";
	    else if(diemTB()>=8)
	        hl = "Gioi";
     	else if(diemTB()>=6.5)
	        hl = "Kha";
	    else if (diemTB()>=5)
	        hl = "TB";
	    else hl = "Yeu";
	
	    return hl; 
    }
    void xuat()
    {
	    cout << setw(2) << ++dem << setw(8) << mssv << setw(10) << ten << setw(8) << gioitinh << setw(12) << diachi << setw(20) << nganh << setw(12) << diem1;
	    cout << setw(12) << diem2 << setw(12) << diem3 << setw(12) << diemTB() << setw(12) << HocLuc() << endl;	
    }
};
typedef SinhVien SV;

	
//nhap so luong sv
	void nhapsl(int &n){
		do{
			cout<<"Nhap so luong sinh vien: ";cin>>n;
		if(n < 0){
			cout<<"Nhap sai vui long nhap lai!";
		}
		}while(n < 0);
	}

//nhap thong tin sv
void NSV(SV *sv, int n)
{
	int res = 0;
	do
		{
	for (int i=0;i<n;i++)
	{
			cout <<"Nhap thong tin sinh vien thu "<<i+1<<": "<<endl;
			sv[i].nhap();
			for(int j=0;j<i;j++)
			{
				if(sv[j].mssv == sv[i].mssv)
				{
					cout <<"Moi ban nhap lai"<<endl;
					res++;
				}
			}	
		}		
	}while(res!=0);
}
			
//ham hien thi tieu de
void TieuDe()
{
	cout<<setw(2)<<"STT"<<setw(8)<<"MSSV"<<setw(10)<<"Ho ten"<<setw(8)<<"Gioi tinh"<<setw(12)<<"Dia chi"<<setw(20)<<"Nganh hoc"<<setw(12)<<"Diem 1";
	cout<<setw(12)<<"Diem 2"<<setw(12)<<"Diem 3"<<setw(12)<<"Diem TB"<<setw(12)<<"Hoc Luc"<<endl;
}   

//xuat thong tin cua sv
void XuatSV(SV *sv, int &n)
{
	TieuDe();
	for (int i = 0; i < n; i = i + 1)
	{
		sv[i].xuat();
	}
}		

//them sv
void Them(SV *sv, int &n)
{
    n++;
	int res = 0;
	do
	{
		res = 0;
		sv[n-1].nhap();
		for(int i=0; i<n-1; i++)
		{
			if(sv[i].mssv == sv[n-1].mssv)
			{
				cout<<"MSSV khong duoc trung! Moi ban nhap lai"<<endl;
				res++;
			}
		}
	}while(res!= 0);
}

//xoa sv
void Xoa(SV *sv, int &n)
{
	int res = 0;
	int soct;
	cout << "Nhap ma so sinh vien can xoa: "; cin >> soct;
	for (int i = 0; i < n; i = i + 1)
	{
		if(sv[i].mssv == soct);
		{
			res++;
			for (int j = 0; j < n; j = j + 1)
			{
				sv[j] = sv[j + 1];
			}
		}		
	}
	if (res == 0)
	    cout << "Ma so sinh vien khong ton tai\n";
	else n--;    
}
//sua thong tin cua sv
void ChinhSua(SV *sv, int &n)
{
	int soct;
	cout << "Nhap ma so sinh vien can sua: "; cin >> soct;
	for (int i = 0; i < n; i = i + 1)
	{
		if(sv[i].mssv == soct);
		{
			sv[i].nhap();
		}
	}
}
//diem TB lon nhat trong danh sach sv
double max(SV *sv, int &n)
{
	double max = sv[0].diemTB();
	for (int i = 0; i < n; i = i + 1)
	{
		if(sv[i].diemTB()>max)
		   max = sv[i].diemTB();
	}
	return max;
}
//diem TB nho nhat trong danh sach sv
double min(SV *sv, int &n)
{
	double min = sv[0].diemTB();
	for (int i = 0; i < n; i = i + 1)
	{
		if(sv[i].diemTB()<min)
		   min = sv[i].diemTB();
	}
	return min;
}
//in danh sach sv co diem TB cao nhat
void InMax(SV *sv, int &n)
{
	dem = 0;
	TieuDe();
	cout << "In danh sach sv co diem cao nhat: "<< endl;
	for	(int i = 0; i < n; i = i + 1)
	{
		if(sv[i].diemTB() == max(sv,n)){
		   sv[i].xuat();
		}
	}
}

//in danh sach sv co diem TB thap nhat
void InMin(SV *sv, int &n)
{
	dem = 0;
	TieuDe();
	cout << "In danh sach sv co diem thap nhat: "<< endl;
	for	(int i = 0; i < n; i = i + 1)
	{
		if(sv[i].diemTB() == min(sv,n))
		   sv[i].xuat();
	}
}

//sap xep cac sv trong danh sach theo bang chu cai
void SapXep(SV *sv, int &n)
{
	cout << "Nhap danh sach sv theo alphabet: "<<endl;

	for(int i = 0; i < n - 1; i = i + 1)
	{
		for(int j = j + 1; j < n; j = j + 1)
		{
			if((sv[i].ten && sv[j].ten) > 0)
			{
				swap(sv[i],sv[j]);
			}
		}
	}
	XuatSV(sv, n);
}				
void menu()
{
        cout << "CHUONG TRINH QUAN LY SINH VIEN C++\n";
        cout << "*************************MENU**************************\n";
        cout << "**  1. Them sinh vien.                               **\n";
        cout << "**  2. Xoa sinh vien.                                **\n";
        cout << "**  3. Nhap danh sach sinh vien.                     **\n";
        cout << "**  4. Sua thong tin sinh vien.                      **\n";
        cout << "**  5. In danh sach sinh vien.                       **\n";
        cout << "**  6. In danh sach sinh vien co diem cao nhat.      **\n";
        cout << "**  7. In danh sach sinh vien co diem thap nhat.     **\n";
        cout << "**  8. Sap xep sinh vien theo alphabet.              **\n";
        cout << "**  0. Ket thuc chuong trinh.                        **\n";
        cout << "*******************************************************\n";
}
		   	
int main()
{
	int n = 0;
	SV *sv;
	sv = new SV[100];
	int luachon;
	char chon;
	do
	{
		menu();
		cout << "Moi ban nhap lua chon: "; cin >> luachon;
		switch(luachon)
		{
			case 1:
				Them(sv, n);
				break;
			case 2:
				Xoa(sv, n);
				break;
			case 3:
				nhapsl(n);
				NSV(sv, n);
				break;		
			case 4:
				ChinhSua(sv, n);
				break;
			case 5:
				XuatSV(sv, n);
				break;
			case 6:
				InMax(sv, n);
				break;
			case 7:
				InMin(sv, n);
				break;
			case 8:
				SapXep(sv, n);
				break;
			case 0:
                cout << "Chuong trinh da thoat." << endl;
                break;	
		default:
			cout << "Ban da nhap sai lua chon!" << endl;
			break;
		}
		cout << "Ban co muon nhap lua chon khong(yes/no):";
		cin>>chon;
	}while(chon == 'y');			
	return 0;			
}
