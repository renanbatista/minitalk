# Minitalk - Comunicação Simplificada entre Processos

## Visão Geral
**Minitalk** é um projeto de sistema de comunicação entre processos que utiliza sinais UNIX para transmitir mensagens de texto entre um servidor e um cliente. Desenvolvido como parte do currículo da [42 School](https://www.42.fr/), este projeto demonstra a habilidade de manipular sinais, processos e comunicação inter-processos (IPC) em um ambiente Unix-like.

## Funcionalidades
- **Comunicação em Tempo Real**: Envio e recebimento de mensagens de texto entre processos em tempo real.
- **Uso de Sinais UNIX**: Implementa `SIGUSR1` e `SIGUSR2` para a transmissão de dados.
- **Eficiência e Confiabilidade**: Otimizado para garantir uma comunicação eficiente e confiável entre o cliente e o servidor.

## Como Utilizar
Para experimentar o Minitalk, siga estes passos:

1. Clone o repositório:
   ```
   git clone https://github.com/renanbatista/minitalk.git
   ```
2. Navegue até a pasta do projeto e compile o código:
   ```
   cd minitalk
   make
   ```
3. Execute o servidor para obter o PID e mantenha-o rodando:
   ```
   ./server
   ```
4. Em outro terminal, use o PID para enviar uma mensagem do cliente para o servidor:
   ```
   ./client [PID do servidor] "Sua mensagem aqui"
   ```

## Exemplo de Uso
Após iniciar o servidor, ele exibirá seu PID. Utilize este PID para conectar o cliente e transmitir uma mensagem.

## Contribuições
Contribuições para Minitalk são bem-vindas, seja para otimizar o código, melhorar a funcionalidade ou corrigir possíveis bugs. Para contribuir, faça um fork do projeto, crie suas alterações em uma nova branch e submeta um pull request.

## Observações
Minitalk é meticulosamente desenvolvido seguindo as normas de codificação da 42 School, focando em criar um código limpo, eficiente e modular.

## Licença
Minitalk é disponibilizado sob a MIT License, favorecendo a inovação e a colaboração aberta na comunidade de desenvolvimento.
