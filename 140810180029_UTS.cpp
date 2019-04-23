/**
 * Nama : Asep Budiyana M
 * Kelas: A
 * NPM  : 140810180029
*/
#include <iostream>
using namespace std;
//chubu miyazaki
//furano hokaido
//hirado nagasaki
//minamiwa ehine
//toho suginami
//nankatsu sizuoka
struct Data{ 
    int no_urut;
    string nama_tim;
    string asal_daerah;
    int gol;
    Data* next;
};
typedef Data* pointer;
typedef pointer List;

void createList(List& First){
    First=NULL;
}

void createData(pointer& pBaru){
    pBaru = new Data;
    cout<<"No Urut\t: ";cin>>pBaru->no_urut;
    cout<<"Nama Tim\t: ";cin>>pBaru->nama_tim;
    cout<<"Asal Daerah\t: ";cin>>pBaru->asal_daerah;
    pBaru->gol = 0;
    pBaru->next = NULL; 
}

void insertLast(List& First,pointer pBaru){
    pointer pBantu = First;
    if (First==NULL){
        First=pBaru;
    }
    else{
        while(pBantu->next!=NULL){
            pBantu = pBantu->next;
        }
        pBantu->next = pBaru;
    }
}

void traversal(List First){
    pointer p = First;
    while(p!=NULL){
        cout<<p->no_urut<<"\t"<<p->nama_tim<<"\t"<<p->gol<<endl;
        p = p->next;
    }
}

void search(List& First,string key,int& ketemu,pointer& p){
    p = First;
    while(p!=NULL&&ketemu==0){
        if (p->nama_tim == key){
            ketemu = 1;
            break;
        }
        p = p->next;
    }
}

void update(List& First){
    char input;
    do{
        pointer pHasil;
        int ketemu = 0;
        string key;
        cout<<"Masukan Nama Tim:\n";cin>>key;
        search(First,key,ketemu,pHasil);
        if(ketemu){
            cout<<"Found!!";
            cout<<endl;
            cout<<pHasil->no_urut<<" "<<pHasil->nama_tim<<"=> jumlah Gol = ";cin>>pHasil->gol;
        }
        else{
            cout<<"Not Found!!";
        }
        cout<<"\nInput Lagi (y/n): ";cin>>input;
    }while(input=='y'||input=='Y');
}

void tukar(pointer& a,pointer& b){
    int temp = a->gol;
    string sem = a->nama_tim;
    int no = a->no_urut;
    a->gol = b->gol;
    a->nama_tim = b->nama_tim;
    a->no_urut = b->no_urut;
    b->gol = temp;
    b->nama_tim = sem;
    b->no_urut = no;

}

void sorting(List& First){
    int swapped, i;
    pointer ptr1;
    pointer lptr = NULL;

    if (First == NULL)
        return;

    do{
        swapped = 0;
        ptr1 = First;

        while(ptr1->next!=lptr){
            if (ptr1->gol<ptr1->next->gol){
                tukar(ptr1,ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while(swapped);
}

int main()
{
    List f;
    pointer p;
    int n;
    createList(f);
    cout<<"Banyak Data: ";cin>>n;
    for (int i=0;i<n;i++){
        createData(p);
        insertLast(f,p);
    }
    cout<<"\nData awal:\n";
    traversal(f);
    update(f);
    cout<<"SORTED DESCENDING:\n";
    sorting(f);
    traversal(f);
    return 0;
}
