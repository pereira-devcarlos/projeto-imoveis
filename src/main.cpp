#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Imovel{
    string tipo;           // casa, apartamento, terreno, sala_comercial, galpao
    string finalidade;     // venda, aluguel, temporada
    string endereco;       // endereco do imovel
    string bairro;         // bairro do imovel
    string cidade;         // cidade do imovel
    int area;              // area do imovel em m2
    int valor;             // valor do imovel
    string iptu;           // IPTU do imovel (pode ser valor ou texto, ex: "300/dia")
    int quartos;           // numero de quartos
    int suites;            // numero de suites
    int banheiros;         // numero de banheiros
    int vagas;             // numero de vagas
    string cozinha;        // sim ou nao
    string sala;           // sim ou nao
    string varanda;        // sim ou nao
    string areaServico;    // sim ou nao
    string piso;           // tipo de piso
    string conservacao;    // novo, usado, reformado
    string armarios;       // sim ou nao
    string arCondicionado; // sim ou nao
    string aquecedor;      // sim ou nao
    string ventilador;     // sim ou nao
};

int main(){
    int i;
    const int MAX = 200; // Definindo o tamanho maximo do array de imoveis
    int quantidade = 0; // Variavel para armazenar a quantidade de imoveis lidos

    ifstream info("../../data/BD_Imoveis2.txt");
    if(!info.is_open()){
        cout << "Erro ao abrir o arquivo" << endl;
        return 1;
    }

    Imovel imoveis[MAX];
    i = 0;

    // Ler os imoveis do arquivo
    info >> imoveis[i].tipo;
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

    for (i = 0; i < quantidade; i++){
        cout << "Imovel " << i + 1 << ":" << endl;
        cout << "Tipo: " << imoveis[i].tipo << endl;
        cout << "Finalidade: " << imoveis[i].finalidade << endl;
        cout << "Endereco: " << imoveis[i].endereco << endl;
        cout << "Bairro: " << imoveis[i].bairro << endl;
        cout << "Cidade: " << imoveis[i].cidade << endl;
        cout << "Area: " << imoveis[i].area << " m2" << endl;
        cout << "Valor: R$ " << imoveis[i].valor << endl;
        cout << "IPTU: " << imoveis[i].iptu << endl;
        cout << "Quartos: " << imoveis[i].quartos << endl;
        cout << "Suites: " << imoveis[i].suites << endl;
        cout << "Banheiros: " << imoveis[i].banheiros << endl;
        cout << "Vagas: " << imoveis[i].vagas << endl;
        cout << "Cozinha: " << imoveis[i].cozinha << endl;
        cout << "Sala: " << imoveis[i].sala << endl;
        cout << "Varanda: " << imoveis[i].varanda << endl;
        cout << "Area de Servico: " << imoveis[i].areaServico << endl;
        cout << "Piso: " << imoveis[i].piso << endl;
        cout << "Conservacao: " << imoveis[i].conservacao << endl;
        cout << "Armarios: " << imoveis[i].armarios << endl;
        cout << "Ar Condicionado: " << imoveis[i].arCondicionado << endl;
        cout << "Aquecedor: " << imoveis[i].aquecedor << endl;
        cout << "Ventilador: " << imoveis[i].ventilador << endl;
        cout << endl;
    }

    return 0;
}