#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

// Estrutura que representa um imovel
struct Imovel{
    string tipo;
    string finalidade;
    string endereco;
    string bairro;
    string cidade;
    int area;
    string valor; 
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

// Le os dados de um imovel a partir de um arquivo
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

// Exibe o menu principal e recebe a opcao do usuario
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
    cout << "=====================================" << endl;
    cout << "Escolha uma opcao: ";
    cin >> opcao;
    cout << endl;
}

// Função para incluir um novo imovel preenchendo todos os campos
void incluirImovel(Imovel& imovel) {
    int op;
    // Menu tipo do imovel
    do {
        cout << "Escolha o tipo do imovel:" << endl;
        cout << "[1] - Casa" << endl;
        cout << "[2] - Apartamento" << endl;
        cout << "[3] - Terreno" << endl;
        cout << "[4] - Sala comercial" << endl;
        cout << "[5] - Galpao" << endl;
        cout << "Digite a opcao: ";
        cin >> op;
        cout << endl;
        if(op < 1 || op > 5) {
            cout << "Opcao invalida! Tente novamente." << endl;
        }
    } while(op < 1 || op > 5);
    // Define o tipo do imovel
    switch(op) {
        case 1: imovel.tipo = "casa"; break;
        case 2: imovel.tipo = "apartamento"; break;
        case 3: imovel.tipo = "terreno"; break;
        case 4: imovel.tipo = "sala_comercial"; break;
        case 5: imovel.tipo = "galpao"; break;
    }

    // Menu finalidade do imovel
    op = 0;
    do {
        cout << "Escolha a finalidade do imovel:" << endl;
        cout << "[1] - Venda" << endl;
        cout << "[2] - Aluguel" << endl;
        cout << "[3] - Locacao" << endl;
        cout << "[4] - Temporada" << endl;
        cout << "Digite a opcao: ";
        cin >> op;
        cout << endl;
        if(op < 1 || op > 4) {
            cout << "Opcao invalida! Tente novamente." << endl;
        }
    } while(op < 1 || op > 4);
    // Define a finalidade do imovel
    switch(op) {
        case 1: imovel.finalidade = "venda"; break;
        case 2: imovel.finalidade = "aluguel"; break;
        case 3: imovel.finalidade = "locacao"; break;
        case 4: imovel.finalidade = "temporada"; break;
    }

    // Recebe os dados de endereco, bairro e cidade, trocando espacos por underline
    cout << "Digite o endereco do imovel: ";
    cin.ignore();
    getline(cin, imovel.endereco);
    for (size_t i = 0; i < imovel.endereco.size(); i++)
        if (imovel.endereco[i] == ' ') imovel.endereco[i] = '_';

    cout << "Digite o bairro do imovel: ";
    getline(cin, imovel.bairro);
    for (size_t i = 0; i < imovel.bairro.size(); i++)
        if (imovel.bairro[i] == ' ') imovel.bairro[i] = '_';

    cout << "Digite a cidade do imovel: ";
    getline(cin, imovel.cidade);
    for (size_t i = 0; i < imovel.cidade.size(); i++)
        if (imovel.cidade[i] == ' ') imovel.cidade[i] = '_';

    // Recebe os demais dados do imovel
    cout << "Digite a area do imovel (em m2): ";    cin >> imovel.area;
    cout << "Digite o valor do imovel: ";           cin >> imovel.valor;
    cout << "Digite o IPTU do imovel: ";            cin >> imovel.iptu;
    cout << "Digite o numero de quartos: ";         cin >> imovel.quartos;
    cout << "Digite o numero de suites: ";          cin >> imovel.suites;
    cout << "Digite o numero de banheiros: ";       cin >> imovel.banheiros;
    cout << "Digite o numero de vagas: ";           cin >> imovel.vagas;

    // Pergunta se possui cozinha
    do {
        cout << "Possui cozinha? [1] - Sim  [2] - Nao: ";
        cin >> op;
    } while (op != 1 && op != 2);
    imovel.cozinha = (op == 1) ? "sim" : "nao";

    // Pergunta se possui sala
    do {
        cout << "Possui sala? [1] - Sim  [2] - Nao: ";
        cin >> op;
    } while (op != 1 && op != 2);
    imovel.sala = (op == 1) ? "sim" : "nao";

    // Pergunta se possui varanda
    do {
        cout << "Possui varanda? [1] - Sim  [2] - Nao: ";
        cin >> op;
    } while (op != 1 && op != 2);
    imovel.varanda = (op == 1) ? "sim" : "nao";

    // Pergunta se possui area de servico
    do {
        cout << "Possui area de servico? [1] - Sim  [2] - Nao: ";
        cin >> op;
    } while (op != 1 && op != 2);
    imovel.areaServico = (op == 1) ? "sim" : "nao";

    cout << "Digite o tipo de piso: ";      
    cin >> imovel.piso;

    // Menu para conservacao
    op = 0;
    do {
        cout << "Qual a conservacao do imovel?" << endl;
        cout << "[1] - Novo" << endl;
        cout << "[2] - Usado" << endl;
        cout << "[3] - Reformado" << endl;
        cout << "Digite a opcao: ";
        cin >> op;
        if(op < 1 || op > 3) {
            cout << "Opcao invalida! Tente novamente." << endl;
        }
    } while(op < 1 || op > 3);

    switch(op) {
        case 1: imovel.conservacao = "novo"; break;
        case 2: imovel.conservacao = "usado"; break;
        case 3: imovel.conservacao = "reformado"; break;
    }

    // Pergunta se possui armarios
    do {
        cout << "Possui armarios? [1] - Sim  [2] - Nao: ";
        cin >> op;
    } while (op != 1 && op != 2);
    imovel.armarios = (op == 1) ? "sim" : "nao";

    // Pergunta se possui ar condicionado
    do {
        cout << "Possui ar condicionado? [1] - Sim  [2] - Nao: ";
        cin >> op;
    } while (op != 1 && op != 2);
    imovel.arCondicionado = (op == 1) ? "sim" : "nao";

    // Pergunta se possui aquecedor
    do {
        cout << "Possui aquecedor? [1] - Sim  [2] - Nao: ";
        cin >> op;
    } while (op != 1 && op != 2);
    imovel.aquecedor = (op == 1) ? "sim" : "nao";

    // Pergunta se possui ventilador
    do {
        cout << "Possui ventilador? [1] - Sim  [2] - Nao: ";
        cin >> op;
    } while (op != 1 && op != 2);
    imovel.ventilador = (op == 1) ? "sim" : "nao";
}

// Salva todos os imoveis do vetor no arquivo
void salvarImoveisNoArquivo(Imovel imoveis[], int quantidade) {
    ofstream saida("../data/BD_Imoveis2.txt");
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

// Exibe os dados de um imovel formatados para o usuario
void exibirImovel(const Imovel& imovel, int indice) {
    // Cria copias locais para exibir sem alterar o original
    string endereco = imovel.endereco;
    string bairro = imovel.bairro;
    string cidade = imovel.cidade;

    // Troca underline por espaco para exibir
    for (size_t i = 0; i < endereco.size(); i++)
        if (endereco[i] == '_') endereco[i] = ' ';
    for (size_t i = 0; i < bairro.size(); i++)
        if (bairro[i] == '_') bairro[i] = ' ';
    for (size_t i = 0; i < cidade.size(); i++)
        if (cidade[i] == '_') cidade[i] = ' ';

    cout << "Imovel " << indice + 1 << ":" << endl;
    cout << "Tipo: " << imovel.tipo << endl;
    cout << "Finalidade: " << imovel.finalidade << endl;
    cout << "Endereco: " << endereco << endl;
    cout << "Bairro: " << bairro << endl;
    cout << "Cidade: " << cidade << endl;
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
    const int MAX = 200; // Limite maximo de imoveis
    int quantidade = 0;
    int i, j, opcao;

    // Abre o arquivo de dados dos imoveis
    ifstream info("../data/BD_Imoveis2.txt");
    if(!info.is_open()){
        cout << "Erro ao abrir o arquivo" << endl;
        return 1;
    }

    Imovel imoveis[MAX];

    // Le todos os imoveis do arquivo para o vetor em memoria
    i = 0;
    while (i < MAX && info >> imoveis[i].tipo && imoveis[i].tipo != "fim") {
        lerImovel(imoveis[i], info);
        quantidade++;
        i++;
    }
    info.close(); // Fecha o arquivo apos a leitura inicial

    opcao = 1;
    while (opcao != 0){
        exibirMenu(opcao); // Exibe o menu principal e recebe a opcao do usuario

        switch (opcao) {
            case 1:
                // Inclui novo imovel no vetor e salva no arquivo
                if (quantidade < MAX) {
                    incluirImovel(imoveis[quantidade]);
                    quantidade++;
                    salvarImoveisNoArquivo(imoveis, quantidade); // Atualiza o arquivo apos inclusao
                    cout << "\nImovel incluido com sucesso!" << endl;
                } else {
                    cout << "\nLimite de imoveis atingido. Nao e possivel incluir mais." << endl;
                }
                break;
            case 2:
                {
                    // Busca e exclusao de imovel pela rua
                    char userEnd[30] = {0};
                    cout << "\nBuscar e excluir imovel pela rua\nDigite o nome da rua: ";
                    cin.ignore();
                    cin.getline(userEnd, 30);

                    cout << "Resultado da busca por " << userEnd << ":\n" << endl;                 
                    // Troca espacos por underline para padronizar igual ao arquivo
                    for (int k = 0; k < 30; k++) {
                        if (userEnd[k] == ' ')
                            userEnd[k] = '_';
                    }
                    string nomeRua(userEnd); // Converte para string para facilitar comparacao

                    // Exibe todos os imoveis encontrados com o endereco informado
                    j=0;
                    for (i = 0; i < quantidade; i++){
                        if(nomeRua == imoveis[i].endereco){
                            exibirImovel(imoveis[i], i);
                            j++;
                        }
                    }
                    if(j == 0){
                        cout << "Nao possui nenhum imovel com esse endereco!" << endl;
                    }
                    else {
                        // Pergunta se deseja excluir o imovel encontrado
                        do{
                            if(opcao < 1 || opcao > 2){
                                cout << "Opcao invalida!!" << endl;
                            }
                            cout << "\nDeseja excluir esse imovel?\nDigite [1]Sim ou [2]Nao: ";
                            cin >> opcao;
                        } while (opcao < 1 || opcao > 2);
                        if(opcao == 1){
                            // Remove todos os imoveis com o endereco informado
                            for (i = 0; i < quantidade; i++) {
                                if (nomeRua == imoveis[i].endereco) {
                                    // Remove o imovel deslocando os proximos para esquerda no array
                                    for (j = i; j < quantidade - 1; j++) {
                                        imoveis[j] = imoveis[j+1];
                                    }
                                    quantidade--;
                                    i--;
                                }
                            }
                            salvarImoveisNoArquivo(imoveis, quantidade); // Atualiza o arquivo apos exclusao
                            cout << "\nImovel removido com sucesso!" << endl;
                        }
                    }
                }
                break;
            case 3:
                {
                    // Busca de imoveis por faixa de valor para locacao, aluguel ou temporada
                    int userFaixa[2];
                    cout << "Buscar imovel por faixa de valor para locacao, aluguel  ou  temporada:\nDigite o 1 valor: ";
                    cin >> userFaixa[0];
                    cout << "Digite o 2 valor: ";
                    cin >> userFaixa[1];
                    cout << endl;

                    cout << "Na faixa de R$" << userFaixa[0] << " a R$" << userFaixa[1] << " possui:\n" << endl;
                    for (i = 0, j = 0; i < quantidade; i++){
                        // Busca apenas imoveis com finalidade locacao, aluguel ou temporada
                        if((imoveis[i].finalidade == "locacao" ||
                            imoveis[i].finalidade == "aluguel" ||
                            imoveis[i].finalidade == "temporada")) {

                            // Extrai apenas o valor numerico do campo valor
                            int valorNumerico = 0;
                            stringstream ss(imoveis[i].valor);
                            ss >> valorNumerico; // Vai pegar so o numero do inicio da string

                            if(valorNumerico > userFaixa[0] && valorNumerico < userFaixa[1]){
                                exibirImovel(imoveis[i], i);
                                j++;
                            }
                        }
                    }
                    if(j == 0){
                        cout << "Nao possui imovel nessa faixa de valores." << endl;
                    }
                }
                break;
            case 4:
                // Busca de imoveis pelas caracteristicas: armarios, ar-condicionado, aquecedor e ventilador
                do{
                    if(opcao < 1 || opcao > 4){
                        cout << "Opcao invalida!!\n" << endl;
                    }
                    cout << "Busca de imoveis por caracteristicas:" << endl;
                    cout << "[1]-Armarios\t\t[3]-Aquecedor" << endl;
                    cout << "[2]-Ar Condicionado\t[4]-Ventilador" << endl;
                    cout << "Digite qual opcao voce deseja: ";
                    cin >> opcao;
                    cout << endl;
                } while (opcao < 1 || opcao > 4);
                cout << "Com essas caracteristicas foram encontrados:" << endl;
                // Exibe todos os imoveis que possuem a caracteristica escolhida
                for (j = 0, i = 0; i < quantidade; i++) {
                    if ((opcao == 1 && imoveis[i].armarios == "sim") ||
                        (opcao == 2 && imoveis[i].arCondicionado == "sim") ||
                        (opcao == 3 && imoveis[i].aquecedor == "sim") ||
                        (opcao == 4 && imoveis[i].ventilador == "sim")) {
                        exibirImovel(imoveis[i], i);
                        j++;
                    }
                }
                if (j == 0){
                    cout << "Nenhum imovel encontrado com essa caracteristica." << endl;
                }
                break;
            case 5:
                // Busca de imoveis pelo numero de quartos e suites
                int userQuartos, userSuites;
                cout << "Buscar imovel por numero de quartos e suites:\nDigite o numero de quartos: ";
                cin >> userQuartos;
                cout << "Digite o numero de suites: ";
                cin >> userSuites;
                cout << endl;
                cout << "Com " << userQuartos << " quartos e " << userSuites << " suites foram encontrados:\n" << endl;
                // Exibe todos os imoveis que possuem a quantidade de quartos e suites informada
                for (j = 0, i = 0; i < quantidade; i++) {
                    if (imoveis[i].quartos == userQuartos && imoveis[i].suites == userSuites) {
                        exibirImovel(imoveis[i], i);
                        j++;
                    }
                }
                if (j == 0) {
                    cout << "Nenhum imovel encontrado com essa quantidade de quartos e suites." << endl;
                }
                break;
            case 6:
                // Relatorio estatistico sobre os imoveis cadastrados
                {
                    int venda = 0, aluguel = 0, locacao = 0, temporada = 0;
                    int casasComSuites = 0, totalCasas = 0;
                    int salasComCeramica = 0, totalSalasComerciais = 0;

                    for (i = 0; i < quantidade; i++) {
                        if (imoveis[i].finalidade == "venda") venda++;
                        else if (imoveis[i].finalidade == "aluguel") aluguel++;
                        else if (imoveis[i].finalidade == "locacao") locacao++;
                        else if (imoveis[i].finalidade == "temporada") temporada++;

                        if (imoveis[i].tipo == "casa") {
                            totalCasas++;
                            if (imoveis[i].suites > 0) casasComSuites++;
                        } else if (imoveis[i].tipo == "sala_comercial") {
                            totalSalasComerciais++;
                            if (imoveis[i].piso == "ceramica" && imoveis[i].sala == "sim") salasComCeramica++;
                        }
                    }

                    cout << fixed << setprecision(2);

                    cout << "\nRelatorio Estatistico:\n" << endl;
                    cout << "Porcentagem de imoveis por finalidade:" << endl;
                    cout << "----------------------------------------" << endl;
                    cout << "Venda: " << (venda * 100.0 / quantidade) << "%" << endl;
                    cout << "----------------------------------------" << endl;
                    cout << "Aluguel: " << (aluguel * 100.0 / quantidade) << "%" << endl;
                    cout << "----------------------------------------" << endl;
                    cout << "Locacao: " << (locacao * 100.0 / quantidade) << "%" << endl;
                    cout << "----------------------------------------" << endl;
                    cout << "Temporada: " << (temporada * 100.0 / quantidade) << "%" << endl;
                    cout << "----------------------------------------" << endl;

                    cout << "Porcentagem de casas com suites: ";
                    if (totalCasas > 0)
                        cout << (casasComSuites * 100.0 / totalCasas) << "%" << endl;
                    else
                        cout << "Nenhuma casa cadastrada." << endl;

                    cout << "----------------------------------------" << endl;
                    cout << "Porcentagem de salas comerciais com \npiso de ceramica e sala: ";
                    if (totalSalasComerciais > 0)
                        cout << (salasComCeramica * 100.0 / totalSalasComerciais) << "%" << endl;
                    else
                        cout << "Nenhuma sala comercial cadastrada." << endl;
                }
                cout << "----------------------------------------" << endl;
                cout << "\nRelatorio estatistico concluido." << endl;
                break;
            case 7:
                // Lista todos os imoveis cadastrados
                cout << "Todos os imoveis cadastrados no sistema estao abaixo:\n" << endl;
                for (i = 0; i < quantidade; i++){
                    exibirImovel(imoveis[i], i);
                }
                break;
            case 0:
                // Sair e agradecer o usuario
                cout << "Programa encerrado. Volte sempre!" << endl;
                break;
            default:
                // Caso o usuario digite uma opcao invalida
                cout << "\nOpcao invalida. Tente novamente." << endl;
                break;
        }
    }

    return 0;
}