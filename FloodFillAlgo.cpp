#include<bits/stdc++.h>
using namespace std;
int R, C;
int dx[] ={-1,0,1,0};
int dy[] = {0,-1,0,1};
void floodfill(char mat[][50],int i,int j,char ch,char color){
// base case is matrix bounds
if(i<0||j<0||i>=R||j>=C){
return ;
}
// figure boundry conditions 
if(mat[i][j]!=ch){
    return;
}
// Recursive call
mat[i][j] = color;
for(int k= 0;k<4;k++){
    floodfill(mat,i+dx[k],j+dy[k],ch,color);
}
}
void printMat(char mat[][50]){
   for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout<<mat[i][j];
        }
    cout<<endl;
    }
}
int main(int argc, char const *argv[])
{
    
    cin>>R>>C;
    char input[15][50];
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin>>input[i][j];
        }
    }
    printMat(input);
    floodfill(input,8,3,'.','r');
    floodfill(input, 0, 0, '.', '!');
    printMat(input);
    return 0;
}
