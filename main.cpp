#include <cstdlib>
#include <iostream>
#include <string.h>

using namespace std;

typedef struct{
	int left;
	int straight;
	int right;
}struct_flow;


int main(int argc, char *argv[])
{
	int f1;
	int f2;
	int f3;
	int f4;
	int i;
	int j;
	int posisi=0;
	
	struct_flow flow[6][4];
	struct_flow sub[4];
	char temp[2]="";
	char solusi[13]="";
	char subsolusi[13]="";
	char temp2[4]="";
	int temp_hitung[4];
	int DS=0;
	int hitungDS=0;
	int den[4];
	
	
	flow[0][0].left = 1;
	flow[0][0].straight = 1;
	flow[0][0].right = 1;
	
	flow[0][1].left = 0;
	flow[0][1].straight = 0;
	flow[0][1].right = 0;
	
	flow[0][2].left = 0;
	flow[0][2].straight = 0;
	flow[0][2].right = 0;
	
	flow[0][3].left = 1;
	flow[0][3].straight = 0;
	flow[0][3].right = 0;
	
	//--------------------- 1
	
	flow[1][0].left = 1;
	flow[1][0].straight = 0;
	flow[1][0].right = 0;
	
	flow[1][1].left = 1;
	flow[1][1].straight = 1;
	flow[1][1].right = 1;

	flow[1][2].left = 0;
	flow[1][2].straight = 0;
	flow[1][2].right = 0;
	
	flow[1][3].left = 0;
	flow[1][3].straight = 0;
	flow[1][3].right = 0;
	
	//--------------------- 2
	
	flow[2][0].left = 0;
	flow[2][0].straight = 0;
	flow[2][0].right = 0;
	
	flow[2][1].left = 1;
	flow[2][1].straight = 0;
	flow[2][1].right = 0;
	
	flow[2][2].left = 1;
	flow[2][2].straight = 1;
	flow[2][2].right = 1;
	
	flow[2][3].left = 0;
	flow[2][3].straight = 0;
	flow[2][3].right = 0;
	
	//--------------------- 3
	
	flow[3][0].left = 0;
	flow[3][0].straight = 0;
	flow[3][0].right = 0;
	
	flow[3][1].left = 0;
	flow[3][1].straight = 0;
	flow[3][1].right = 0;
	
	flow[3][2].left = 1;
	flow[3][2].straight = 0;
	flow[3][2].right = 0;
	
	flow[3][3].left = 1;
	flow[3][3].straight = 1;
	flow[3][3].right = 1;
	
	//--------------------- 4
	
	flow[4][0].left = 1;
	flow[4][0].straight = 1;
	flow[4][0].right = 0;
	
	flow[4][1].left = 0;
	flow[4][1].straight = 0;
	flow[4][1].right = 0;
	
	flow[4][2].left = 1;
	flow[4][2].straight = 1;
	flow[4][2].right = 0;
	
	flow[4][3].left = 0;
	flow[4][3].straight = 0;
	flow[4][3].right = 0;
	
	//--------------------- 5
	
	flow[5][0].left = 0;
	flow[5][0].straight = 0;
	flow[5][0].right = 0;
	
	flow[5][1].left = 1;
	flow[5][1].straight = 1;
	flow[5][1].right = 0;

	flow[5][2].left = 0;
	flow[5][2].straight = 0;
	flow[5][2].right = 0;
	
	flow[5][3].left = 1;
	flow[5][3].straight = 1;
	flow[5][3].right = 0;
	
	//--------------------- 6


	cout<<"Pengaturan lampu lalu lintas menggunakan greedy"<<endl;
	cout<<endl;
	cout<<"Silahkan masukan jumlah kendaraan pada setiap jalur : "<<endl;
	cout<<"(Pada implementasinya jumlah kendaraan didapat dari sensor di setiap jalur)"<<endl;
	cout<<"Masukkan jumlah kendaraan di Jalur 1 : ";cin>>den[0];
	cout<<"Masukkan jumlah kendaraan di Jalur 2 : ";cin>>den[1];
	cout<<"Masukkan jumlah kendaraan di Jalur 3 : ";cin>>den[2];
	cout<<"Masukkan jumlah kendaraan di Jalur 4 : ";cin>>den[3];
	
	cout<<endl;
	cout<<"Himpunan Kandidat  "<<endl;
	cout<<"J1  J2  J3  J4"<<endl;
	cout<<"LSR LSR LSR LSR "<<endl;
	
	cout<<endl;
	//menampilkan 
	for (i=0;i<6;i++){
		for(j=0;j<4;j++){
			cout<<flow[i][j].left;
			cout<<flow[i][j].straight;
			cout<<flow[i][j].right;
			cout<<" ";
			
		}
		cout<<endl;
	}
	cout<<""<<endl;
	
	cout<<"Keterangan : L = Left; S = Straight; R = Right "<<endl;
	//algoritma greedy
	for (i=0;i<6;i++){
		//memasukkan kandidat ke solusi
		strcpy(solusi,"");
		for(j=0;j<4;j++){
			
			itoa(flow[i][j].left,temp,10);
			strcat(solusi,temp);
		
			itoa(flow[i][j].straight,temp,10);
			strcat(solusi,temp);
		
			itoa(flow[i][j].right,temp,10);
			strcat(solusi,temp);
		}
	
	
		sub[0].left = flow[i][0].left;
		sub[0].straight = flow[i][0].straight;
		sub[0].right = flow[i][0].right;
	
		sub[1].left = flow[i][1].left;
		sub[1].straight = flow[i][1].straight;
		sub[1].right = flow[i][1].right;
	
		sub[2].left = flow[i][2].left;
		sub[2].straight = flow[i][2].straight;
		sub[2].right = flow[i][2].right;
	
		sub[3].left = flow[i][3].left;
		sub[3].straight = flow[i][3].straight;
		sub[3].right = flow[i][3].right;
	
		for (j=0;j<4;j++){
			temp_hitung[j] = sub[j].left + sub[j].straight + sub[j].right;
			temp_hitung[j] = temp_hitung[j]*30;
			temp_hitung[j] = den[j] - temp_hitung[j];
			if (temp_hitung[j] < 0){
				temp_hitung[j] = 0;
			}
		
		
		}
	
		hitungDS = temp_hitung[0] + temp_hitung[1] + temp_hitung[2] + temp_hitung[3];
		if (DS == 0){
			DS = hitungDS;
			posisi = i;
		} else if(hitungDS <= DS){
			DS = hitungDS;
			posisi = i;
		}
		
	
	}
	//cout<<posisi<<endl;
	cout<<"solusi : ";
	for(i=0;i<4;i++){
		cout<<flow[posisi][i].left;
		cout<<flow[posisi][i].straight;
		cout<<flow[posisi][i].right;
		cout<<" ";
			
	}
	cout<<endl;
	
	
	strcpy(solusi,"");
	for(j=0;j<4;j++){
			
		itoa(flow[posisi][j].left,temp,10);
		strcat(solusi,temp);
	
		itoa(flow[posisi][j].straight,temp,10);
		strcat(solusi,temp);
		
		itoa(flow[posisi][j].right,temp,10);
		strcat(solusi,temp);
	}
	cout<<"DS : "<<DS<<endl;
	//cout<<"Solusi : "<<solusi<<endl;
	
	
	system("pause");
	return 0;
}
