#include <iostream>

using namespace std;

int main()
{
    string ip = "", buffer = "";
    cin >> ip;
    int size_s = ip.length();
    if (size_s < 7 || size_s > 15 || ip[size_s - 1] == '.')
    {
        cout << "NO";
        return 0;
    }
    int dot_counter = 0;
    for (int i = 0; i < size_s; ++i)
    {
        //Check for non digits
        if ((ip[i] < '0' || ip[i] > '9') && ip[i] != '.'){
            cout << "NO";
            return 0;
        }
        if (ip[i] != '.' && i != size_s - 1)
            buffer += ip[i];
        else
        {
            if (i == size_s - 1){
                buffer += ip[i];
                --dot_counter;
            }
            int buff_size = buffer.length();
            if (dot_counter < 3 && buff_size < 4 && buff_size > 0){
                if (buff_size == 3){
                    if (buffer[0] == '0'){
                        cout << "NO";
                        return 0;
                    } else if (buffer[0] == '1'){
                        if (buffer[1] >= '0' && buffer[1] <= '9' && buffer[2] >= '0' && buffer[2] <= '9'){
                            buffer = "";
                            ++dot_counter;
                        } else {
                            cout << "NO";
                            return 0;
                        }
                    } else if (buffer[0] == '2'){
                        if (buffer[1] >= '0' && buffer[1] <= '5' && buffer[2] >= '0' && buffer[2] <= '5'){
                            buffer = "";
                            ++dot_counter;
                        } else {
                            cout << "NO";
                            return 0;
                        }
                    }
                } else if (buff_size == 2){
                     if (buffer[0] != '0'){
                        buffer = "";
                        ++dot_counter;
                    }
                    else {
                        cout << "NO";
                        return 0;
                    }
                } else {
                    buffer = "";
                    ++dot_counter;
                }
            }
            else
            {
               // cout << dot_counter << " " << buffer << " " << buff_size << " " << i << endl;
                cout << "NO";
                return 0;
            }
        }
    }
    dot_counter == 0  || dot_counter < 3? cout << "NO" : cout << "YES";
    return 0;
}
