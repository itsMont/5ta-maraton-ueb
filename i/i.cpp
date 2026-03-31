#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, caso = 1;
    cin>>T;
    while(T--)
    {
        string ans = "no thief", name;
        int n, largo, ancho, alto;
        vector <string> names;
        vector <int> vols;
        cin>>n;
        cin>>name>>largo>>ancho>>alto;
        string thief = name , stolen = name;
        names.push_back(name);
        vols.push_back(largo*ancho*alto);
        int stolenIdx = 0;
        int thiefIdx = 0;
        int vol = largo*ancho*alto;
        int maxVol = vol;
        int minVol = vol;

        while(n-- >1)
        {
            cin>>name>>largo>>ancho>>alto;
            names.push_back(name);
            vols.push_back(largo*ancho*alto);
            if(vol != largo*ancho*alto)
            {
                if(largo*ancho*alto > maxVol )
                {
                    thief = name;
                    maxVol = largo*ancho*alto;
                }
                if(largo*ancho*alto < minVol )
                {
                    stolen = name;
                    minVol = largo*ancho*alto;
                }
            }
            vol = largo*ancho*alto;
        }

        // Verifica que haya ladrón
        if(stolen != thief)
            ans = thief + " took chocolate from " + stolen;
        cout<<"Case "<<caso<<": "<<ans<<"\n";
        caso++;
    }

    return 0;
}
/*
2
11
atq 3 4 3
mun 10 4 1
sam1 6 6 1
sam2 18 2 1
mub 1 36 1
tan 1 4 9
sha 4 3 3
di 3 12 1
nab 2 2 9
all 8 4 1
fah 3 2 6
2
ja 10 10 10
em 2 50 10


*/
