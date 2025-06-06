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

// Função para ler os imóveis
void lerImovel(Imovel& imovel, ifstream& info) {
    // imovel.tipo deve ser lido primeiro no while para verificar se possui o valor "fim"
    info >> imovel.finalidade;
    info >> imovel.endereco;
    info >> imovel.bairro;
    info >> imovel.cidade;
    info >> imovel.area;
    info >> imovel.valor;
    info >> imovel.iptu;
    info >> imovel.quartos;
    info >> imovel.suites;
    info >> imovel.banheiros;
    info >> imovel.vagas;
    info >> imovel.cozinha;
    info >> imovel.sala;
    info >> imovel.varanda;
    info >> imovel.areaServico;
    info >> imovel.piso;
    info >> imovel.conservacao;
    info >> imovel.armarios;
    info >> imovel.arCondicionado;
    info >> imovel.aquecedor;
    info >> imovel.ventilador;
}

// Função para exibir os imóveis
void exibirImovel(const Imovel& imovel, int indice) {
    cout << "Imovel " << indice + 1 << ":" << endl;
    cout << "Tipo: " << imovel.tipo << endl;
    cout << "Finalidade: " << imovel.finalidade << endl;
    cout << "Endereco: " << imovel.endereco << endl;
    cout << "Bairro: " << imovel.bairro << endl;
    cout << "Cidade: " << imovel.cidade << endl;
    cout << "Area: " << imovel.area << " m2" << endl;
    cout << "Valor: R$ " << imovel.valor << endl;
    cout << "IPTU: " << imovel.iptu << endl;
    cout << "Quartos: " << imovel.quartos << endl;
    cout << "Suites: " << imovel.suites << endl;
    cout << "Banheiros: " << imovel.banheiros << endl;
    cout << "Vagas: " << imovel.vagas << endl;
    cout << "Cozinha: " << imovel.cozinha << endl;
    cout << "Sala: " << imovel.sala << endl;
    cout << "Varanda: " << imovel.varanda << endl;
    cout << "Area de Servico: " << imovel.areaServico << endl;
    cout << "Piso: " << imovel.piso << endl;
    cout << "Conservacao: " << imovel.conservacao << endl;
    cout << "Armarios: " << imovel.armarios << endl;
    cout << "Ar Condicionado: " << imovel.arCondicionado << endl;
    cout << "Aquecedor: " << imovel.aquecedor << endl;
    cout << "Ventilador: " << imovel.ventilador << endl;
    cout << endl;
}

int main(){
    int i;
    const int MAX = 200; // Definindo o tamanho maximo do array de imoveis
    int quantidade = 0; // Variavel para armazenar a quantidade de imoveis lidos

    ifstream info("../../data/BD_Imoveis2.txt");
    ofstream saida("../../data/BD_Imoveis_Saida.txt");
    if(!info.is_open()){
        cout << "Erro ao abrir o arquivo" << endl;
        return 1;
    }

    Imovel imoveis[MAX];
    i = 0;
    // Ler os imoveis do arquivo até encontrar imoveis.tipo == "fim" ou atingir o limite de MAX
    while (i < MAX && info >> imoveis[i].tipo && imoveis[i].tipo != "fim") {
        lerImovel(imoveis[i], info);
        quantidade++;
        i++;
    }

    info.close(); // Fechar o arquivo

    // Exibir os imoveis lidos
    for (i = 0; i < quantidade; i++){
        exibirImovel(imoveis[i], i);
    }

    return 0;
}