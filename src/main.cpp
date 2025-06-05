#include <iostream>
#include <fstream>
#include <locale.h>
#include <string> 

using namespace std;

struct Imovel{
    string tipo;           // casa, apartamento, terreno, sala_comercial, galp�o
    string finalidade;     // venda, aluguel, temporada
    string endereco;       // endere�o do im�vel
    string bairro;         // bairro do im�vel
    string cidade;         // cidade do im�vel
    int area;              // �rea do im�vel em m�
    int valor;             // valor do im�vel
    string iptu;           // IPTU do im�vel (pode ser valor ou texto, ex: "300/dia")
    int quartos;           // n�mero de quartos
    int suites;            // n�mero de su�tes
    int banheiros;         // n�mero de banheiros
    int vagas;             // n�mero de vagas
    string cozinha;        // sim ou n�o
    string sala;           // sim ou n�o
    string varanda;        // sim ou n�o
    string areaServico;    // sim ou n�o
    string piso;           // tipo de piso
    string conservacao;    // novo, usado, reformado
    string armarios;       // sim ou n�o
    string arCondicionado; // sim ou n�o
    string aquecedor;      // sim ou n�o
    string ventilador;     // sim ou n�o
};


int main(){
    int i;
    const int MAX = 200; // Definindo o tamanho m�ximo do array de im�veis
    int quantidade = 0; // Vari�vel para armazenar a quantidade de im�veis lidos

    setlocale(LC_ALL, "Portuguese");
    ifstream info("../../data/BD_Imoveis2.txt");
    if(!info.is_open()){
        cout << "Erro ao abrir o arquivo" << endl;
        return 1;
    }

    Imovel imoveis[MAX]; // tamanho maior para garantir espa�o
    i = 0;

    // Ler os im�veis do arquivo
    info >> imoveis[i].tipo; // L� o tipo do primeiro im�vel
    while (imoveis[i].tipo != "fim"){
        info >> imoveis[i].finalidade;
        info >> imoveis[i].endereco;
        info >> imoveis[i].bairro;
        info >> imoveis[i].cidade;
        info >> imoveis[i].area;
        info >> imoveis[i].valor;
        info >> imoveis[i].iptu;
        info >> imoveis[i].quartos;
        info >> imoveis[i].suites;
        info >> imoveis[i].banheiros;
        info >> imoveis[i].vagas;
        info >> imoveis[i].cozinha;
        info >> imoveis[i].sala;
        info >> imoveis[i].varanda;
        info >> imoveis[i].areaServico;
        info >> imoveis[i].piso;
        info >> imoveis[i].conservacao;
        info >> imoveis[i].armarios;
        info >> imoveis[i].arCondicionado;
        info >> imoveis[i].aquecedor;
        info >> imoveis[i].ventilador;
        i++;

        info >> imoveis[i].tipo;
        quantidade++;
    }
    info.close();

    // Exibir o primeiro im�vel
    cout << "Im�vel 1:" << endl;
    cout << "Tipo: " << imoveis[0].tipo << endl;
    cout << "Finalidade: " << imoveis[0].finalidade << endl;
    cout << "Endere�o: " << imoveis[0].endereco << endl;
    cout << "Bairro: " << imoveis[0].bairro << endl;
    cout << "Cidade: " << imoveis[0].cidade << endl;
    cout << "�rea: " << imoveis[0].area << " m�" << endl;
    cout << "Valor: R$ " << imoveis[0].valor << endl;
    cout << "IPTU: " << imoveis[0].iptu << endl;
    cout << "Quartos: " << imoveis[0].quartos << endl;
    cout << "Su�tes: " << imoveis[0].suites << endl;
    cout << "Banheiros: " << imoveis[0].banheiros << endl;
    cout << "Vagas: " << imoveis[0].vagas << endl;
    cout << "Cozinha: " << imoveis[0].cozinha << endl;
    cout << "Sala: " << imoveis[0].sala << endl;
    cout << "Varanda: " << imoveis[0].varanda << endl;
    cout << "�rea de Servi�o: " << imoveis[0].areaServico << endl;
    cout << "Piso: " << imoveis[0].piso << endl;
    cout << "Conserva��o: " << imoveis[0].conservacao << endl;
    cout << "Arm�rios: " << imoveis[0].armarios << endl;
    cout << "Ar Condicionado: " << imoveis[0].arCondicionado << endl;
    cout << "Aquecedor: " << imoveis[0].aquecedor << endl;
    cout << "Ventilador: " << imoveis[0].ventilador << endl;
    cout << endl;

    cout << quantidade << endl; // quantidade � a quantidade de im�veis lidos

    return 0;
}