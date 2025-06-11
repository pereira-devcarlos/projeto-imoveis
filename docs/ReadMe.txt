Projeto Imóveis - Sistema de Gerenciamento de Imóveis

Descrição Geral

Este projeto é um sistema de cadastro, consulta, exclusão e geração de relatórios de imóveis, desenvolvido em C++. Ele permite o gerenciamento de imóveis residenciais e comerciais, armazenando os dados em um arquivo texto. O sistema é totalmente interativo via terminal, com menus e instruções em português.


Funcionalidades Principais

- Cadastro de novos imóveis (casa, apartamento, terreno, sala comercial, galpão)
- Consulta de imóveis por rua (endereço), faixa de valor, características, quantidade de quartos e suítes
- Exclusão de imóveis por endereço
- Listagem de todos os imóveis cadastrados
- Relatórios estatísticos sobre os imóveis cadastrados (por finalidade, casas com suítes, salas comerciais com piso de cerâmica)
- Armazenamento persistente dos dados em arquivo texto


Estrutura dos Dados

- Os imóveis são armazenados no arquivo `BD_Imoveis2.txt`.
- Cada linha representa um imóvel, com os campos separados por espaço.
- Campos booleanos (como cozinha, sala, varanda, etc.) são salvos como "sim" ou "não".
- O arquivo é atualizado automaticamente a cada inclusão ou exclusão.
- O arquivo é criado automaticamente se não existir.


Como Compilar e Executar

1. **Pré-requisitos**
   - Ter um compilador C++ instalado (g++ recomendado).
   - Estar em um sistema operacional compatível (Linux recomendado).

2. **Compilação**
   - No terminal, navegue até a pasta principal do projeto.
   - Execute o comando:
     ```
     g++ main.cpp -o imoveis
     ```

3. **Execução**
   - Ainda no terminal, execute:
     ```
     ./imoveis
     ```


Como Utilizar o Sistema

- Ao iniciar, o sistema carrega os imóveis do arquivo de dados.
- O menu principal será exibido com as opções:
    1. Incluir novo imóvel
    2. Buscar e excluir por rua
    3. Buscar por faixa de valor
    4. Buscar por características (armários, ar-condicionado, aquecedor, ventilador)
    5. Buscar por quartos e suítes
    6. Relatório estatístico
    7. Listar todos os imóveis
    0. Sair

- **Inclusão:** Escolha a opção 1 e preencha todos os campos solicitados.
- **Busca/Exclusão:** Siga as instruções do menu para buscar ou excluir imóveis.
- **Relatórios:** A opção 6 mostra estatísticas sobre os imóveis cadastrados.
- **Listagem:** A opção 7 exibe todos os imóveis cadastrados no sistema.


Observações Importantes

- O sistema aceita até 200 imóveis cadastrados simultaneamente.
- Utilize apenas caracteres simples (sem acentuação) para nomes de arquivos e pastas.
- Os campos booleanos devem ser sempre "sim" ou "não" (com acento).
- Para evitar problemas de acentuação no arquivo, ao salvar, o sistema converte "não" para "nao".
- O arquivo de dados deve estar (ou será criado) em `data/BD_Imoveis2.txt`.


Autor e Licença

- Desenvolvido por: Carlos Eduardo Pereira dos Santos
- Registro do Aluno: 2024.2.08.001
- Projeto desenvolvido para fins acadêmicos.

Bom uso!