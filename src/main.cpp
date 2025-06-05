#include <iostream>
#include <fstream>
#include <locale.h>
#include <string> 

using namespace std;

struct Imovel{
    string tipo;           // casa, apartamento, terreno, sala_comercial, galpão
    string finalidade;     // venda, aluguel, temporada
    string endereco;       // endereço do imóvel
    string bairro;         // bairro do imóvel
    string cidade;         // cidade do imóvel
    int area;              // área do imóvel em m²
    int valor;             // valor do imóvel
    string iptu;           // IPTU do imóvel (pode ser valor ou texto, ex: "300/dia")
    int quartos;           // número de quartos
    int suites;            // número de suítes
    int banheiros;         // número de banheiros
    int vagas;             // número de vagas
    string cozinha;        // sim ou não
    string sala;           // sim ou não
    string varanda;        // sim ou não
    string areaServico;    // sim ou não
    string piso;           // tipo de piso
    string conservacao;    // novo, usado, reformado
    string armarios;       // sim ou não
    string arCondicionado; // sim ou não
    string aquecedor;      // sim ou não
    string ventilador;     // sim ou não
};


int main(){
    int i;
    const int MAX = 200; // Definindo o tamanho máximo do array de imóveis
    int quantidade = 0; // Variável para armazenar a quantidade de imóveis lidos

    setlocale(LC_ALL, "Portuguese");
    ifstream info("../../data/BD_Imoveis2.txt");
    if(!info.is_open()){
        cout << "Erro ao abrir o arquivo" << endl;
        return 1;
    }

    Imovel imoveis[MAX]; // tamanho maior para garantir espaço
    i = 0;

    // Ler os imóveis do arquivo
    info >> imoveis[i].tipo; // Lê o tipo do primeiro imóvel
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

    // Exibir o primeiro imóvel
    cout << "Imóvel 1:" << endl;
    cout << "Tipo: " << imoveis[0].tipo << endl;
    cout << "Finalidade: " << imoveis[0].finalidade << endl;
    cout << "Endereço: " << imoveis[0].endereco << endl;
    cout << "Bairro: " << imoveis[0].bairro << endl;
    cout << "Cidade: " << imoveis[0].cidade << endl;
    cout << "Área: " << imoveis[0].area << " m²" << endl;
    cout << "Valor: R$ " << imoveis[0].valor << endl;
    cout << "IPTU: " << imoveis[0].iptu << endl;
    cout << "Quartos: " << imoveis[0].quartos << endl;
    cout << "Suítes: " << imoveis[0].suites << endl;
    cout << "Banheiros: " << imoveis[0].banheiros << endl;
    cout << "Vagas: " << imoveis[0].vagas << endl;
    cout << "Cozinha: " << imoveis[0].cozinha << endl;
    cout << "Sala: " << imoveis[0].sala << endl;
    cout << "Varanda: " << imoveis[0].varanda << endl;
    cout << "Área de Serviço: " << imoveis[0].areaServico << endl;
    cout << "Piso: " << imoveis[0].piso << endl;
    cout << "Conservação: " << imoveis[0].conservacao << endl;
    cout << "Armários: " << imoveis[0].armarios << endl;
    cout << "Ar Condicionado: " << imoveis[0].arCondicionado << endl;
    cout << "Aquecedor: " << imoveis[0].aquecedor << endl;
    cout << "Ventilador: " << imoveis[0].ventilador << endl;
    cout << endl;

    cout << quantidade << endl; // quantidade é a quantidade de imóveis lidos

    return 0;
}