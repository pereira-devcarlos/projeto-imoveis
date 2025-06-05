#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream info("../../data/BD_Imoveis2.txt");
    if(!info.is_open()){
        cout << "Erro ao abrir o arquivo" << endl;
        return 1;
    }

    return 0;
}
