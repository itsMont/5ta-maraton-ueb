
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
        string IP, ip, ans = "Yes";
        cin>>IP>>ip;

        // Separar
        string binary[4] = {ip.substr(0, 8),ip.substr(9, 8), ip.substr(18, 8), ip.substr(27, 8)};

        // Separar string decimales por punto
        int n = IP.size();

        int N[4] = {0,0,0,0};
        int idx = 0;
        string element = "";
        for(int i = 0; i <n; i++)
        {
            if(IP[i] == '.')
            {
                N[idx] = stoi(element);
                element = "";
                idx++;
                continue;
            }
            element += IP[i];
        }
        N[idx] = stoi(element);

        // Pasar binario a decimal
        //cout<<binDec(a);
        for(int i = 0; i < 4; i++)
        {
            if(N[i] != stoi(binary[i], nullptr, 2))
            {
                ans="No";
                break;
            }
        }
        cout<<"Case "<<caso<<": "<<ans<<"\n";
        caso ++;
    }

    return 0;
}


/*test

2
192.168.0.100
11000000.10101000.00000000.11001000
65.254.63.122
01000001.11111110.00111111.01111010
*/
