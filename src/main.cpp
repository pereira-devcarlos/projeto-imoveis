#include <iostream>
#include <fstream>
#include <string>
#include <cctype> // No topo do arquivo

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
    int op;
    // Menu tipo do imovel
    do { // Do While para validar a opcao digitada
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
    // Switch case para imovel receber o tipo escolhido
    switch(op) {
        case 1: imovel.tipo = "casa"; break;
        case 2: imovel.tipo = "apartamento"; break;
        case 3: imovel.tipo = "terreno"; break;
        case 4: imovel.tipo = "sala_comercial"; break;
        case 5: imovel.tipo = "galpao"; break;
    }

    // Menu finalidade do imovel
    op = 0;
    do { // Do While para validar a opcao digitada
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
    // Switch case para imovel receber a finalidade escolhida
    switch(op) {
        case 1: imovel.finalidade = "venda"; break;
        case 2: imovel.finalidade = "aluguel"; break;
        case 3: imovel.finalidade = "locacao"; break;
        case 4: imovel.finalidade = "temporada"; break;
    }

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

    cout << "Digite a area do imovel (em m2): ";    cin >> imovel.area;
    cout << "Digite o valor do imovel: ";           cin >> imovel.valor;
    cout << "Digite o IPTU do imovel: ";            cin >> imovel.iptu;
    cout << "Digite o numero de quartos: ";         cin >> imovel.quartos;
    cout << "Digite o numero de suites: ";          cin >> imovel.suites;
    cout << "Digite o numero de banheiros: ";       cin >> imovel.banheiros;
    cout << "Digite o numero de vagas: ";           cin >> imovel.vagas;

    // Quiz Cozinha
    do {
        cout << "Possui cozinha? [1] - Sim  [2] - Nao: ";
        cin >> op;
    } while (op != 1 && op != 2);
    imovel.cozinha = (op == 1) ? "sim" : "nao";

    // Quiz Sala
    do {
        cout << "Possui sala? [1] - Sim  [2] - Nao: ";
        cin >> op;
    } while (op != 1 && op != 2);
    imovel.sala = (op == 1) ? "sim" : "nao";

    // Quiz Varanda
    do {
        cout << "Possui varanda? [1] - Sim  [2] - Nao: ";
        cin >> op;
    } while (op != 1 && op != 2);
    imovel.varanda = (op == 1) ? "sim" : "nao";

    // Quiz Area de servico
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

    // Quiz Armarios
    do {
        cout << "Possui armarios? [1] - Sim  [2] - Nao: ";
        cin >> op;
    } while (op != 1 && op != 2);
    imovel.armarios = (op == 1) ? "sim" : "nao";

    // Quiz Ar condicionado
    do {
        cout << "Possui ar condicionado? [1] - Sim  [2] - Nao: ";
        cin >> op;
    } while (op != 1 && op != 2);
    imovel.arCondicionado = (op == 1) ? "sim" : "nao";

    // Quiz Aquecedor
    do {
        cout << "Possui aquecedor? [1] - Sim  [2] - Nao: ";
        cin >> op;
    } while (op != 1 && op != 2);
    imovel.aquecedor = (op == 1) ? "sim" : "nao";

    // Quiz Ventilador
    do {
        cout << "Possui ventilador? [1] - Sim  [2] - Nao: ";
        cin >> op;
    } while (op != 1 && op != 2);
    imovel.ventilador = (op == 1) ? "sim" : "nao";
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

void exibirImovel(Imovel& imovel, int indice) {
    // Troca underline por espaco no endereco, bairro e cidade
    for (size_t i = 0; i < imovel.endereco.size(); i++) { // Uso do tipo size_t para o método .size()
        if (imovel.endereco[i] == '_')
            imovel.endereco[i] = ' ';
    }
    for (size_t i = 0; i < imovel.bairro.size(); i++) {
        if (imovel.bairro[i] == '_')
            imovel.bairro[i] = ' ';
    }
    for (size_t i = 0; i < imovel.cidade.size(); i++) {
        if (imovel.cidade[i] == '_')
            imovel.cidade[i] = ' ';
    }    

    // Exibir os imoveis com os texto formatados
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

    i = 0;
    while (i < MAX && info >> imoveis[i].tipo && imoveis[i].tipo != "fim") {
        lerImovel(imoveis[i], info);
        quantidade++;
        i++;
    }
    info.close();

    opcao = 1;
    while (opcao != 0){
        exibirMenu(opcao); // Exibe o menu principal e recebe a opcao do usuario

        switch (opcao) {
            case 1:
                // Incluir novo imovel
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
                    // Buscar e excluir imovel pela rua
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
                    string nomeRua(userEnd); // Transformando char em string para facilitar a comparação

                    // Exibe todos os imoveis encontrados com o endereco informado
                    for (i = 0; i < quantidade; i++){
                        if(nomeRua == imoveis[i].endereco){
                            exibirImovel(imoveis[i], i);
                        }
                    }
                    // Pergunta se deseja excluir o imovel encontrado
                    do{
                        if(opcao < 1 || opcao > 2){
                            cout << "Opçao inválida!!" << endl;
                        }
                        cout << "\nDeseja excluir esse imovel?\nDigite [1]Sim ou [2]Não: ";
                        cin >> opcao;
                    } while (opcao < 1 || opcao > 2);
                    if(opcao == 1){
                        // Remove todos os imoveis com o endereco informado
                        for (i = 0; i < quantidade; i++) {
                            if (nomeRua == imoveis[i].endereco) {
                                // Remove o imovel deslocando os proximos para esquerda no array
                                for (int j = i; j < quantidade - 1; j++) {
                                    imoveis[j] = imoveis[j+1];
                                }
                                quantidade--;
                                i--;
                            }
                        }
                        salvarImoveisNoArquivo(imoveis, quantidade);
                        cout << "\nImovel removido com sucesso!" << endl;
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

                    cout << "Na faixa de R$" << userFaixa[0] << " a R$" << userFaixa[1] << " possui:" << endl;
                    for (i = 0, j = 0; i < quantidade; i++){
                        if((imoveis[i].finalidade == "locacao" ||
                            imoveis[i].finalidade == "aluguel" ||
                            imoveis[i].finalidade == "temporada") &&
                           (imoveis[i].valor > userFaixa[0]) && 
                           (imoveis[i].valor < userFaixa[1])){
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
                // Busca de imóveis pelas características: armários, ar-condicionado, aquecedor e ventilador
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
                // Busca de imóveis pelo número de quartos e suítes
                // (implementar aqui se desejar)
                break;
            case 6:
                // Relatorio estatistico
                // (implementar aqui se desejar)
                break;
            case 7:
                // Listar todos os imoveis cadastrados
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