#include <bits/stdc++.h>
using namespace std;

// Volver minuscula
char asciitolower(char l) {
    if (l <= 'Z' && l >= 'A')
        return l - ('Z' - 'z');
    return l;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, caso = 1;
    cin>>T;
    while(T--)
    {
        string str1;
        string str2;
        string ans;
        // Limpiar
        if(caso==1)
            getline(cin, ans);

        getline(cin, str1);
        getline(cin, str2);

        string copy1 = "", copy2="", T;

        stringstream X(str1);

        while (getline(X, T, ' '))
            copy1+=T;

        X.str("");
        X.clear();
        stringstream ss(str2);
        while (getline(ss, T, ' '))
            copy2+=T;
        ss.str("");
        ss.clear();

        // Tener todo en minuscula y sin espacio
        transform(copy1.begin(), copy1.end(), copy1.begin(), asciitolower);
        transform(copy2.begin(), copy2.end(), copy2.begin(), asciitolower);

        // Encontrar caracteres y eliminar
        for(int i = 0; i < copy1.size(); i++)
        {
            int idx = copy2.find(copy1[i]);

            if(idx >= 0)
            {
                copy2.erase(idx, 1);
            }
            else
                break;
        }
        // Verificar si queda vacia
        if(!copy2.empty())
            ans="No";
        else
            ans="Yes";
        cout<<"Case "<<caso<<": "<<ans<<"\n";
        caso++;
    }
    return 0;
}
/*
3
Tom Marvolo Riddle
I am Lord Voldemort
I am not Harry Potter
Hi Pretty Roar to man
Harry and Voldemort
Tom and Jerry and Harry
*/
