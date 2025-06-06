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

// Funcao para ler os imoveis
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

// Funcao para exibir o menu
void exibirMenu(int& opcao) {
    cout << "========== MENU DE IMOVEIS ==========" << endl;
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
}

// Funcao para incluir um novo imovel no vetor
void incluirImovel(Imovel& imovel) {
    cout << "Digite o tipo do imovel: ";            cin >> imovel.tipo;
    cout << "Digite a finalidade do imovel: ";      cin >> imovel.finalidade;
    cout << "Digite o endereco do imovel: ";        cin >> imovel.endereco;
    cout << "Digite o bairro do imovel: ";          cin >> imovel.bairro;
    cout << "Digite a cidade do imovel: ";          cin >> imovel.cidade;
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

// Função para salvar os novos imóveis no arquivo txt
void salvarImoveisNoArquivo(Imovel imoveis[], int quantidade, const char* caminhoArquivo) {
    ofstream saida(caminhoArquivo); // Apaga o arquivo e reescreve tudo com o imóvel já adicionado
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

// Funcao para exibir os imoveis
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
    const int MAX = 200; // Definindo o tamanho maximo do array de imoveis
    int quantidade = 0; // Variavel para armazenar a quantidade de imoveis lidos
    
    int i, opcao;

    // Ifstream e ofstream para manipular arquivos externos
    ifstream info("../../data/BD_Imoveis2.txt");
    // Verifica se o arquivo foi aberto corretamente
    if(!info.is_open()){
        cout << "Erro ao abrir o arquivo" << endl; 
        return 1;
    }

    Imovel imoveis[MAX]; // Definindo o vetor de imoveis

    // Ler os imoveis do arquivo ate encontrar imoveis.tipo == "fim" ou atingir o limite de MAX
    i = 0;
    while (i < MAX && info >> imoveis[i].tipo && imoveis[i].tipo != "fim") {
        lerImovel(imoveis[i], info);
        quantidade++;
        i++;
    }
    info.close(); // Fechar o arquivo

    opcao = 1; // Inicializando a opcao com um valor para entrar no loop
    while (opcao != 0){
        // Exibir o menu
        exibirMenu(opcao);

        // Case para cada opcao do menu
        switch (opcao) {
            case 1:
                // Incluir novo imovel
                if (quantidade < MAX) {
                    incluirImovel(imoveis[quantidade]);
                    quantidade++;
                    salvarImoveisNoArquivo(imoveis, quantidade, "../../data/BD_Imoveis2.txt");
                    cout << "\nImovel incluido com sucesso!" << endl;
                } else {
                    cout << "\nLimite de imoveis atingido. Nao e possivel incluir mais." << endl;
                }
                break;
            case 2:
                // Buscar e excluir um imóvel pela rua
                {
                    char userEnd[30] = {0};
                    cout << "Buscar e excluir imovel\nDigite o nome da rua: ";
                    cin.ignore();
                    cin.getline(userEnd, 30);

                    // Troca espaços por underline para padronizar igual ao arquivo
                    for (int k = 0; k < 30; k++) {
                        if (userEnd[k] == ' ')
                            userEnd[k] = '_';
                    }

                    // Converte o char[] para string para facilitar a comparação
                    string nomeRua(userEnd);
                    
                    bool removido = false;
                    // Percorre todos os imóveis cadastrados
                    for (i = 0; i < quantidade; i++) {
                        // Se encontrar o endereço igual ao digitado pelo usuário
                        if (nomeRua == imoveis[i].endereco) {
                            // Remove o imóvel deslocando os próximos para "cima" no array
                            for (int j = i; j < quantidade - 1; j++) {
                                imoveis[j] = imoveis[j+1];
                            }
                            quantidade--;    // Diminui a quantidade total de imóveis
                            removido = true; // Marca que removeu pelo menos um imóvel
                            i--;             // Decrementa i para não pular o próximo imóvel
                        }
                    }

                    // Se removeu algum imóvel, salva o novo vetor no arquivo
                    if (removido) {
                        salvarImoveisNoArquivo(imoveis, quantidade, "../../data/BD_Imoveis2.txt");
                        cout << "Imovel removido com sucesso!" << endl;
                    } else {
                        cout << "Nenhum imovel encontrado com esse endereco." << endl;
                    }
                }
                break;
            case 3:
                // Buscar por faixa de valor
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
                // Exibir os imoveis lidos
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