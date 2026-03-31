#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, caso = 1;

    cin>>N;
    while(N--)
    {
        long long Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;

        cin>> Ax>> Ay>> Bx>> By>>Cx>> Cy;

        // calcular determinante
        Dx = Ax + (Cx- Bx);
        Dy = Ay + (Cy-By);

        // Area es det(AB, AD)
        /* AB = ( Bx-Ax, AD = ( Dx-Ax,
                 By-Ay)        Dy - Ay)

        */
        long long area = abs((Bx-Ax) * (Dy-Ay) - (Dx-Ax)*(By-Ay));
        cout<<"Case "<<caso<<": "<<Dx<<" "<<Dy<<" "<<area<<"\n";
        caso++;
    }
    return 0;
}

/*
3
0 0 10 0 10 10
0 0 10 0 10 -20
-12 -10 21 21 1 40
*/
