#include <iostream>

using namespace std;

string arabtoroman(unsigned discharge, string discharge_s, string symbol_1, string symbol_2, string symbol_3)
{
    if (discharge < 4){
        while (discharge--)
            discharge_s += symbol_1;
    } else if (discharge > 3 && discharge < 10)
    {
        if (discharge == 5)
            discharge_s += symbol_2;
        else if (discharge == 4)
            discharge_s += symbol_1 + symbol_2;
        else if (discharge == 9)
            discharge_s += symbol_1 + symbol_3;
        else
        {
            discharge_s += symbol_2;
            while (--discharge >= 5)
                discharge_s += symbol_1;
        }
    }
    return discharge_s;
}

int main()
{
    // 'M' = 1000, 'D' = 500, 'C' = 100, 'L' = 50, 'X' = 10, 'V' = 5, 'I' = 1
    unsigned number = 0;
    cin >> number;
    string arab_answer = "";
    string units_s = "";
    string tens_s = "";
    string hundreds_s = "";
    string thousands_s = "";
    unsigned units = number % 10;
    unsigned tens = (number % 100 - units) / 10;
    unsigned hundreds = (number % 1000 - tens - units) / 100;
    unsigned thousands = (number % 10000 - hundreds - tens - units) / 1000;
    units_s = arabtoroman(units, units_s, "I", "V", "X");
    tens_s = arabtoroman(tens, tens_s, "X", "L", "C");
    hundreds_s = arabtoroman(hundreds, hundreds_s, "C", "D", "M");
    while(thousands--)
        thousands_s += "M";
    arab_answer += thousands_s + hundreds_s + tens_s + units_s;
    cout << arab_answer;
    return 0;
}
