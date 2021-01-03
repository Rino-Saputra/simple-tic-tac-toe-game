#include<iostream>
#include<cstdlib>
using namespace std;
void show();
void print_game(char *t,int,int,int);
int user_input(int*,int*,char*);
int get_win(char*);
int full_sm(char*,int[],int[],int&);//check if cell full and nobody win and user input insert same cell;
int main()
{
    int input_1=0;
    int input_2=0;
    int u_win=0;
    int win_1=0;
    int win_2=0;
    int count_game=0;
    char r;
    do
    {
        char t_arr[10]={NULL};
        show();
        print_game(t_arr,win_1,win_2,count_game);
        u_win=user_input(&input_1,&input_2,t_arr);
        if(u_win==1)
        {
            win_1++;
            count_game++;
            system("cls");
            show();
            print_game(t_arr,win_1,win_2,count_game);
            cout<<"player 1 win\n";
        }
        else if(u_win==2)
        {
            win_2++;
            count_game++;
            system("cls");
            show();
            print_game(t_arr,win_1,win_2,count_game);
            cout<<"player 2 win\n";
        }
        else
        {
            count_game++;
            system("cls");
            show();
            print_game(t_arr,win_1,win_2,count_game);
            cout<<"draw game\n";
        }
        cout<<"play again? Y/N : ";
        cin>>r;
        system("cls");
    }
    while(r=='y'||r=='Y');
    if(win_1>win_2)
        cout<<"player 1 is the winner\n\n";
    else if(win_1<win_2)
        cout<<"player 2 is the winner\n\n";
    else
        cout<<"draw game\n\n";
    system("pause");
    return 0;
}
void show()
{
    cout<<"================\n";
    cout<<"TIC TAC TOE GAME\n";
    cout<<"================\n";
    cout<<"player 1 = X\n\n";
    cout<<"player 2 = O\n\n";
}
int user_input(int* user_1,int* user_2,char* t)
{
    int win=0;
    int con=1;
    int ind_user=0;
    int i_p1[5]={0};//if both user get same indeks
    int i_p2[5]={-1,-1,-1,-1,-1};
    int con_arr=0;
    int full_cell=0;
    int t1=0;
    int t2=0;
    int t_g=0;
    while(con)
    {
        label_1:
        cout<<"user 1: ";
        cin>>*user_1;
        i_p1[ind_user]=*user_1;
        full_cell=full_sm(t,i_p1,i_p2,con_arr);
        if(con_arr==1)
        {
            con_arr=0;
            system("cls");
            show();
            print_game(t,t1,t2,t_g);
            goto label_1;
        }
        else
        {
            *user_1-=1;
            t[*user_1]='X';
            system("cls");
            show();
            print_game(t,t1,t2,t_g);
            win=get_win(t);//get return value
        }
        ///////////
        if(win==1||win==2||full_cell==1){
            con=0;
            break;}

        label_2:
        cout<<"user 2: ";
        cin>>*user_2;
        i_p2[ind_user]=*user_2;
        full_cell=full_sm(t,i_p1,i_p2,con_arr);
        if(con_arr==1)
        {
            con_arr=0;
            system("cls");
            show();
            print_game(t,t1,t2,t_g);
            goto label_2;
        }
        else
        {
            *user_2-=1;
            t[*user_2]='O';
            system("cls");
            show();
            print_game(t,t1,t2,t_g);
            win=get_win(t);//get return value
        }
        ////////////
        if(win==1||win==2||full_cell==1)
            con=0;
        ind_user++;
    }
    return win;
}
void print_game(char *t,int p1,int p2,int game)
{
    cout<<" ------------------\n";
    cout<<"|     |     |     |"<<"    player 1 score :  "<<p1<<"\n";
    cout<<"|  "<<t[0]<<"  |  "<<t[1]<<"  |  "<<t[2]<<"  |\n";
    cout<<"|     |     |     |\n";
    cout<<" ------------------\n";
    cout<<"|     |     |     |\n";
    cout<<"|  "<<t[3]<<"  |  "<<t[4]<<"  |  "<<t[5]<<"  |\n";
    cout<<"|     |     |     |"<<"    player 2 score :  "<<p2<<"\n";
    cout<<" ------------------\n";
    cout<<"|     |     |     |\n";
    cout<<"|  "<<t[6]<<"  |  "<<t[7]<<"  |  "<<t[8]<<"  |\n";
    cout<<"|     |     |     |"<<"    game :  "<<game<<"\n";
    cout<<" ------------------\n\n";
    cout<<"---------------------------------------\n\n";
}
int get_win(char* arr)
{
    //player 1
    if(arr[0]=='X'&&arr[1]=='X'&&arr[2]=='X')
        return 1;
    else if(arr[3]=='X'&&arr[4]=='X'&&arr[5]=='X')
        return 1;
    else if(arr[6]=='X'&&arr[7]=='X'&&arr[8]=='X')
        return 1;
    else if(arr[0]=='X'&&arr[3]=='X'&&arr[6]=='X')
        return 1;
    else if(arr[1]=='X'&&arr[4]=='X'&&arr[7]=='X')
        return 1;
    else if(arr[2]=='X'&&arr[5]=='X'&&arr[8]=='X')
        return 1;
    else if(arr[0]=='X'&&arr[4]=='X'&&arr[8]=='X')
        return 1;
    else if(arr[2]=='X'&&arr[4]=='X'&&arr[6]=='X')
        return 1;
    //player 2
    else if(arr[0]=='O'&&arr[1]=='O'&&arr[2]=='O')
        return 2;
    else if(arr[3]=='O'&&arr[4]=='O'&&arr[5]=='O')
        return 2;
    else if(arr[6]=='O'&&arr[7]=='O'&&arr[8]=='O')
        return 2;
    else if(arr[0]=='O'&&arr[3]=='O'&&arr[6]=='O')
        return 2;
    else if(arr[1]=='O'&&arr[4]=='O'&&arr[7]=='O')
        return 2;
    else if(arr[2]=='O'&&arr[5]=='O'&&arr[8]=='O')
        return 2;
    else if(arr[0]=='O'&&arr[4]=='O'&&arr[8]=='O')
        return 2;
    else if(arr[2]=='O'&&arr[4]=='O'&&arr[6]=='O')
        return 2;
}
int full_sm(char* ful,int p1[],int p2[],int& c_arr)
{
    int i;
    int lim=0;

    for(i=0;i<10;i++)
    {
        if(ful[i]!=NULL)
            lim++;
    }
    
    if(lim==8)
        i=1;//cell is full
    //if user input same other user cell
    for(i=0;i<5;i++)
    {
        for(int k=0;k<5;k++)
        {
            if(p1[i]==p2[k]||p2[i]==p1[k])
                c_arr=1;
        }
    }
    return i;
}
