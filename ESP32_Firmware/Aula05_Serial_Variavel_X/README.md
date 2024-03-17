# Aula 05 - Funções acessadas via Comando Serial, com variável para controle

### Controle de saídas através de comandos enviados via porta serial. 
* Quando recebe o caractere 'A', acende todos os LEDs em sequência e mantém a condição de acionamento até receber o caractere 'a', que apaga todos os LEDs. 
* O estado de acionamento é controlado pela variável booleana `X`, que é ativada (1) ao receber 'A' e desativada (0) ao receber 'a'.

⚠️ Siga a montagem de hardware como proposto abaixo:

https://github.com/andresima0/ESP32-SENAI/assets/111400782/63505a4f-1f83-4061-a556-be7b25e2c16b
