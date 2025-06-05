#include <iostream>
#include <fstream>

using namespace std;

struct Imovel{
    char tipo[10]; // 1-casa, 2-apartamento, 3-terreno, 4-sala comerciial, 5-galpão
    char finalidade[10]; // 1-venda, 2-locação
    char endereco[50]; // endereço do imóvel
    char bairro[20]; // bairro do imóvel
    char cidade[20]; // cidade do imóvel
    int area; // área do imóvel em m²
    int valor; // valor do imóvel
    int quartos; // número de quartos
    int suites; // número de suítes
    int banheiros; // número de banheiros
    int vagas; // número de vagas
    char cozinha[4]; // 1-sim, 0-não
    char sala[4]; // 1-sim, 0-não
    char varanda[4]; // 1-sim, 0-não
    char areaServico[4]; // 1-sim, 0-não
    char piso[20]; // tipo de piso
    char estado[10]; // 1-novo, 2-usado, 3-reformado
    char armarios[4]; // 1-sim, 0-não
    char arCondicionado[4]; // 1-sim, 0-não
    char aquecedor[4]; // 1-sim, 0-não
    char ventilador[4]; // 1-sim, 0-não
};


int main(){
    int quantidade = 5; // Quantidade registrados de imóveis

    ifstream info("../../data/BD_Imoveis2.txt");
    if(!info.is_open()){
        cout << "Erro ao abrir o arquivo" << endl;
        return 1;
    }

    Imovel imoveis[quantidade];

    for (int i = 0; i < quantidade; i++){
        info >> imoveis[i].tipo;
        info >> imoveis[i].finalidade;
        info >> imoveis[i].endereco;
        info >> imoveis[i].bairro;
        info >> imoveis[i].cidade;
        info >> imoveis[i].area;
        info >> imoveis[i].valor;
        info >> imoveis[i].quartos;
        info >> imoveis[i].suites;
        info >> imoveis[i].banheiros;
        info >> imoveis[i].vagas;
        info >> imoveis[i].cozinha;
        info >> imoveis[i].sala;
        info >> imoveis[i].varanda;
        info >> imoveis[i].areaServico;
        info >> imoveis[i].piso;
        info >> imoveis[i].estado;
        info >> imoveis[i].armarios;
        info >> imoveis[i].arCondicionado;
        info >> imoveis[i].aquecedor;
        info >> imoveis[i].ventilador;
    }
    return 0;
}
