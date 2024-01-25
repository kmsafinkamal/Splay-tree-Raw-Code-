#include<bits/stdc++.h>
#include "splay.h"
using namespace std;

int main()
{
    SPLAY *s = new SPLAY();
    node *root = NULL;

    while(1)
    {
    cout<<"1. Insert "<<endl<<"2. Delete"<<endl
        <<"3. Search"<<endl<<"4. Display"<<endl
        <<"5. Exit"<<endl;
    int option,data,pos;
    cout<< "enter your option:"<<endl;
    cin>>option;
    switch(option)
    {
        case 1:
                cout<< "enter data:"<<endl;
                cin>>data;
                root = s->insert(root, data);;
                break;

        case 2:
                cout<< "enter data:"<<endl;
                cin>>data;
                root = s->delete_key(root, data);;
                break;
        case 3:
                cout<< "enter data:"<<endl;
                cin>>data;
                root = s->search(root, data);;
                break;
        case 4:
                s->preOrder(root);
                cout<<endl;
                break;
        case 5: break;
    }


    }
    return 0;
}
