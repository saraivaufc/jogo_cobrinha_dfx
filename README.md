# Jogo da Cobrinha (Snake Game)

Bem-vindo ao **Jogo da Cobrinha**! Este é um jogo clássico de snake desenvolvido em C, projetado para rodar exclusivamente em sistemas operacionais baseados em Linux.

[![Assista ao vídeo](https://i9.ytimg.com/vi_webp/76ce4Ye2bxU/sddefault.webp?v=677404ce&sqp=CMSL0LsG&rs=AOn4CLDJASIP_z12iDM8rlmafngGKO7ObA)](https://www.youtube.com/watch?v=76ce4Ye2bxU)

## Requisitos

Antes de iniciar, verifique se o sistema atende aos seguintes requisitos:

- **Sistema operacional**: Linux (não compatível com Windows ou macOS).
- **Dependência**: Biblioteca X11.

## Instalação

Siga estas etapas para configurar e executar o jogo:

1. **Instale a dependência necessária**:

```bash
   sudo apt-get install libx11-dev
```

2. **Configure permissões**: Conceda permissões de leitura e escrita para todos os arquivos do projeto:

```bash
chmod +rw *
```

3. **Compile o jogo**: Entre no diretório onde os arquivos do jogo estão localizados e execute:

```bash
make
```

4. **Execute o jogo**: Após a compilação, inicie o jogo com o comando:

```bash
./Cobrinha
```

Caso seja solicitado, insira sua senha de usuário.

## Estrutura do Projeto
O projeto contém os seguintes arquivos:

* Cobrinha.c: Arquivo principal do jogo.
* Makefile: Script para compilar o jogo.
* Record.txt: Registros de pontuações.
* desenhos.c e desenhos.h: Arquivos relacionados ao desenho dos elementos na tela.
* dfx.c e dfx.h: Funções auxiliares relacionadas à interface gráfica.
* funcoes1.c e funcoes1.h: Funções adicionais do jogo.
* funcoes2.c e funcoes2.h: Funções suplementares.

## Observações
Este jogo foi desenvolvido para fins educacionais e recreativos.
Caso encontre algum problema ou tenha sugestões, sinta-se à vontade para abrir uma issue.

## Licença
Este projeto é de código aberto. Use e modifique conforme necessário.
