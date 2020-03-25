#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#define DOSENTEXIST -1
#define info(msg, value) cout << msg " = " << value << endl;
using namespace std;

struct Resistor
{
    int start_node = DOSENTEXIST;
    double resistence = DOSENTEXIST;
    int finish_node = DOSENTEXIST;
};

bool cmp1(Resistor a, Resistor b){
    return b.start_node > a.start_node;
}

bool cmp2(Resistor a, Resistor b){
    return a.start_node == b.start_node && b.finish_node < a.finish_node;
}

void solving(Resistor * chain){

}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    Resistor chain[300];
    string s = "";
    int iter = -1;
    int startNode = 0;
    int endNode = 0;
    bool exist_start = false, exist_end = false;
    // Fulfillment of an array
    while(getline(fin, s))
    {
        unsigned size_s = s.size();
        int number = 0, field = 1;
        for (size_t i = 0; i < size_s; ++i){
            if (s[i] >= '0' && s[i] <= '9'){
                number = (number * 10) + (s[i] - '0');
                i == size_s - 1 && iter != -1 ? chain[iter].finish_node = number : 0;
                i == size_s - 1 && iter == -1 ? endNode = number : 0;
                if (number == startNode && field != 2 && iter != -1)
                exist_start = true;
                if (number == endNode && field != 2 && iter != -1)
                exist_end = true;
            }
            else if (iter == -1){
                switch (field){
                case 1 :
                    startNode = number;
                    break;
                case 2 :
                    endNode = number;
                    break;
                }
                field++; number = 0;
            }
            else {
                switch (field){
                case 1 :
                    chain[iter].start_node = number;
                    break;
                case 2 :
                    chain[iter].resistence = number;
                    break;
                case 3 :
                    chain[iter].finish_node = number;
                    break;
                }
                field++; number = 0;
            }
        }
        iter++;
    }
    if (!exist_end || !exist_start){
        fout << "WN";
        return 0; }

    int resistors = 0;
    for (int i = 0; i < iter; ++i)
        if (chain[i].start_node != DOSENTEXIST && chain[i].resistence != DOSENTEXIST && chain[i].finish_node != DOSENTEXIST)
            ++resistors;


    sort(chain, chain + resistors, cmp1);
    sort(chain, chain + resistors, cmp2);

    double overall_resistance = 0;
    Resistor prev_resistor = chain[0];
    for (int i = 1; i < resistors; ++i){
        if (prev_resistor.start_node == chain[i].start_node && prev_resistor.finish_node == chain[i].finish_node){
            overall_resistance += (prev_resistor.resistence * chain[i].resistence) / (prev_resistor.resistence + chain[i].resistence);
        } else
            overall_resistance += prev_resistor.resistence + chain[i].resistence;
        prev_resistor = chain[i];
    }
    fout << setprecision(3) << fixed << overall_resistance;
    //for (int i = 0; i < resistors; ++i)
     //  cout << chain[i].start_node << " " << chain[i].resistence << " " << chain[i].finish_node << endl;
    //fout << startNode << " " << endNode << endl;
    return 0;
}
