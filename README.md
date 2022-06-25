# lendo_arquivos
Atividade da cadeira de laboratório de programação.
Esse código recebe um arquivo da B3 contendo a lista de todos os instrumentos negociados 
(acessavel em   www.b3.com.br/pt_br/market-data-e-indices/servicos-de-dados/market-data/historico/mercado-a-vista/series-historicas/) 
e devolve um arquivo "Bolsa.csv" com informações do Código, Tipo, NomeResumido, Preço de Fechamento, Quantidade, Preço de Exercicio e Vencimento de cada ativo.
    
    O código funciona lendo o arquivo linha por linha e atribuindo os valores com base na sua posição no texto
    
EXEMPLO:
    
O input:
    
        012022050502A1AP34      010ADVANCE AUTODRN          R$  000000000634200000000063570000000006342000000000634600000000063570000000000000000000000000000003000000000000000004000000000000025385000000000000009999123100000010000000000000BRA1APBDR001110
        
Retorna:   
    
        A1AP34; VISTA; ADVANCE AUTO; 63,57; 4; 0,00; 99991231
