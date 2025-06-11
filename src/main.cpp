#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Imovel{
    string tipo;
    string finalidade;
    string endereco;
    string bairro;
    string cidade;
    int area;
    int valor;
    string iptu;
    int quartos;
    int suites;
    int banheiros;
    int vagas;
    string cozinha;
    string sala;
    string varanda;
    string areaServico;
    string piso;
    string conservacao;
    string armarios;
    string arCondicionado;
    string aquecedor;
    string ventilador;
};

void lerImovel(Imovel& imovel, ifstream& info) {
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

void exibirMenu(int& opcao) {
    cout << "\n========== MENU DE IMOVEIS ==========" << endl;
    cout << "[1] Incluir novo imovel" << endl;
    cout << "[2] Buscar e excluir por rua" << endl;
    cout << "[3] Buscar por faixa de valor" << endl;
    cout << "[4] Buscar por caracteristicas" << endl;
    cout << "[5] Buscar por quartos e suites" << endl;
    cout << "[6] Relatorio estatistico" << endl;
    cout << "[7] Listar todos os imoveis" << endl;
    cout << "[0] Sair" << endl;
    cout << "======================================" << endl;
    cout << "Escolha uma opcao: ";
    cin >> opcao;
    cout << endl;
}

void incluirImovel(Imovel& imovel) {
    cout << "Digite o tipo do imovel: ";            cin >> imovel.tipo;
    cout << "Digite a finalidade do imovel: ";      cin >> imovel.finalidade;

    cout << "Digite o endereco do imovel: ";
    cin.ignore(); // Limpa o buffer se usou cin >> antes
    getline(cin, imovel.endereco);
    // Troca espacos por underline no endereco
    for (int i = 0; i < imovel.endereco.size(); i++) {
        if (imovel.endereco[i] == ' ')
            imovel.endereco[i] = '_';
    }

    cout << "Digite o bairro do imovel: ";
    cin.ignore(); // Limpa o buffer se usou cin >> antes
    getline(cin, imovel.bairro);
    // Troca espacos por underline em bairro
    for (int i = 0; i < imovel.bairro.size(); i++) {
        if (imovel.bairro[i] == ' ')
            imovel.bairro[i] = '_';
    }

    cout << "Digite a cidade do imovel: ";
    cin.ignore(); // Limpa o buffer se usou cin >> antes
    getline(cin, imovel.cidade);
    // Troca espacos por underline em cidade
    for (int i = 0; i < imovel.cidade.size(); i++) {
        if (imovel.cidade[i] == ' ')
            imovel.cidade[i] = '_';
    }

    cout << "Digite a area do imovel (em m2): ";    cin >> imovel.area;
    cout << "Digite o valor do imovel: ";           cin >> imovel.valor;
    cout << "Digite o IPTU do imovel: ";            cin >> imovel.iptu;
    cout << "Digite o numero de quartos: ";         cin >> imovel.quartos;
    cout << "Digite o numero de suites: ";          cin >> imovel.suites;
    cout << "Digite o numero de banheiros: ";       cin >> imovel.banheiros;
    cout << "Digite o numero de vagas: ";           cin >> imovel.vagas;
    cout << "Possui cozinha? (sim/nao): ";          cin >> imovel.cozinha;
    cout << "Possui sala? (sim/nao): ";             cin >> imovel.sala;
    cout << "Possui varanda? (sim/nao): ";          cin >> imovel.varanda;
    cout << "Possui area de servico? (sim/nao): ";  cin >> imovel.areaServico;
    cout << "Digite o tipo de piso: ";              cin >> imovel.piso;
    cout << "Digite a conservacao do imovel: ";     cin >> imovel.conservacao;
    cout << "Possui armarios? (sim/nao): ";         cin >> imovel.armarios;
    cout << "Possui ar condicionado? (sim/nao): ";  cin >> imovel.arCondicionado;
    cout << "Possui aquecedor? (sim/nao): ";        cin >> imovel.aquecedor;
    cout << "Possui ventilador? (sim/nao): ";       cin >> imovel.ventilador;
}

void salvarImoveisNoArquivo(Imovel imoveis[], int quantidade) {
    ofstream saida("../../data/BD_Imoveis2.txt");
    for (int i = 0; i < quantidade; i++) {
        saida << imoveis[i].tipo << " "
              << imoveis[i].finalidade << " "
              << imoveis[i].endereco << " "
              << imoveis[i].bairro << " "
              << imoveis[i].cidade << " "
              << imoveis[i].area << " "
              << imoveis[i].valor << " "
              << imoveis[i].iptu << " "
              << imoveis[i].quartos << " "
              << imoveis[i].suites << " "
              << imoveis[i].banheiros << " "
              << imoveis[i].vagas << " "
              << imoveis[i].cozinha << " "
              << imoveis[i].sala << " "
              << imoveis[i].varanda << " "
              << imoveis[i].areaServico << " "
              << imoveis[i].piso << " "
              << imoveis[i].conservacao << " "
              << imoveis[i].armarios << " "
              << imoveis[i].arCondicionado << " "
              << imoveis[i].aquecedor << " "
              << imoveis[i].ventilador << endl;
    }
    saida << "fim" << endl;
    saida.close();
}

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
    const int MAX = 200;
    int quantidade = 0;
    int i, j, opcao;

    ifstream info("../../data/BD_Imoveis2.txt");
    if(!info.is_open()){
        cout << "Erro ao abrir o arquivo" << endl;
        return 1;
    }

    Imovel imoveis[MAX];

    opcao = 1;
    while (opcao != 0){
        // Ler os imoveis do arquivo ate encontrar imoveis.tipo == "fim" ou atingir o limite de MAX
        i = 0;
        while (i < MAX && info >> imoveis[i].tipo && imoveis[i].tipo != "fim") {
            lerImovel(imoveis[i], info);
            quantidade++;
            i++;
        }
        info.close();

        exibirMenu(opcao);

        switch (opcao) {
            case 1:
                if (quantidade < MAX) {
                    incluirImovel(imoveis[quantidade]);
                    quantidade++;
                    salvarImoveisNoArquivo(imoveis, quantidade);
                    cout << "\nImovel incluido com sucesso!" << endl;
                } else {
                    cout << "\nLimite de imoveis atingido. Nao e possivel incluir mais." << endl;
                }
                break;
            case 2:
                {
                    char userEnd[30] = {0};
                    cout << "\nBuscar e excluir imovel pela rua\nDigite o nome da rua: ";
                    cin.ignore();
                    cin.getline(userEnd, 30);

                    // Troca espacos por underline para padronizar igual ao arquivo
                    for (int k = 0; k < 30; k++) {
                        if (userEnd[k] == ' ')
                            userEnd[k] = '_';
                    }

                    string nomeRua(userEnd); // Transformando char em string para facilitar a comparação

                    int removido = 0;
                    // Percorre todos os imoveis cadastrados
                    for (i = 0; i < quantidade; i++) {
                        // Se encontrar o endereco igual ao digitado pelo usuario
                        if (nomeRua == imoveis[i].endereco) {
                            // Remove o imovel deslocando os proximos para cima no array
                            for (int j = i; j < quantidade - 1; j++) {
                                imoveis[j] = imoveis[j+1];
                            }
                            quantidade--;
                            removido++;
                            i--;
                        }
                    }

                    // Se removeu algum imovel, salva o novo vetor no arquivo
                    if (removido >= 1) {
                        salvarImoveisNoArquivo(imoveis, quantidade);
                        cout << "\nImovel removido com sucesso!" << endl;
                    } else {
                        cout << "\nNenhum imovel encontrado com esse endereco." << endl;
                    }
                }
                break;
            case 3:
                {
                    int userFaixa[2];
                    cout << "Buscar imovel por faixa de valor:\nDigite o 1 valor: ";
                    cin >> userFaixa[0];
                    cout << "Digite o 2 valor: ";
                    cin >> userFaixa[1];
                    cout << endl;

                    cout << "No intervalo de R$" << userFaixa[0] << " a R$" << userFaixa[1] << " possui:" << endl;
                    for (i = 0, j = 0; i < quantidade; i++){
                        if(imoveis[i].valor > userFaixa[0] && imoveis[i].valor < userFaixa[1]){
                            exibirImovel(imoveis[i], i);
                            j++;
                        }
                    }
                    if(j == 0){
                        cout << "Nao possui imovel nessa faixa de valores." << endl;
                    }
                }
                break;
            case 4:
                // Buscar por caracteristicas
                break;
            case 5:
                // Buscar por quartos e suites
                break;
            case 6:
                // Relatorio estatistico
                break;
            case 7:
                // Listar todos os imoveis
                for (i = 0; i < quantidade; i++){
                    exibirImovel(imoveis[i], i);
                }
                break;
            case 0:
                // Sair
                break;
            default:
                cout << "\nOpcao invalida. Tente novamente." << endl;
                break;
        }
    }

    return 0;
}